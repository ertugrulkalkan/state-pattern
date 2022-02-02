#include <iostream>
#include "Context.h"

Context::Context(State* state) : m_pState(nullptr)
{
	m_Thread = nullptr;
	m_Run = false;
	this->transitionTo(state);
}

Context::~Context()
{
	stop();
	delete this->m_pState;
}

void Context::transitionTo(State *state)
{
	context_lock.lock();
	if (m_pState != nullptr)
	{
		std::cout << "state changed to " << state->getStateName() << " from " << this->m_pState->getStateName() << std::endl;
		delete this->m_pState;
	}
	this->m_pState = state;
	this->m_pState->setContext(this);
	context_lock.unlock();
}

void Context::loop()
{
	while (m_Run)
	{
		context_lock.lock();
		if (m_pState != nullptr)
		{
			m_pState->cyclicJob();
		}
		context_lock.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

void Context::run()
{
	context_lock.lock();
	if(m_Thread == nullptr)
	{
		m_Run = true;
		m_Thread = new std::thread(&Context::loop, this);
	}
	context_lock.unlock();
}

void Context::stop()
{
	context_lock.lock();
	if (m_Thread != nullptr)
	{
		m_Run = false;
		m_Thread->join();
		delete m_Thread;
		m_Thread = nullptr;
	}
	context_lock.unlock();
}

void Context::message(const std::string& message)
{
	this->m_pState->messageHandler(message);
}