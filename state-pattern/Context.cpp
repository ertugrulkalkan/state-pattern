#include <iostream>
#include "Context.h"

Context::Context(State* state) : m_pState(nullptr)
{
	this->transitionTo(state);
}

Context::~Context()
{
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

void Context::run()
{
	while(true)
	{
		context_lock.lock();
		this->m_pState->cyclicJob();
		context_lock.unlock();
	}
}

void Context::message(const std::string& message)
{
	this->m_pState->messageHandler(message);
}
