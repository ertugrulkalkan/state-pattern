#include <iostream>
#include <string>
#include "State.h"

State::State(const std::string& stateName) : m_Context(nullptr), m_StateName(stateName)
{

}

State::~State()
{

}

void State::messageHandler(const std::string& message)
{
	std::cout << "Not a valid message `" << message << "`" << std::endl;
}

void State::setContext(Context *context)
{
	this->m_Context = context;
}

const std::string& State::getStateName()
{
	return this->m_StateName;
}