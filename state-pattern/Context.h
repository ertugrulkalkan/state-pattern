#pragma once

#include <mutex>
#include <string>

#include "State.h"

class Context
{
private:
	State *m_pState;

	std::mutex context_lock;
public:
	Context(nullptr_t) = delete;
	Context(const Context&) = delete;
	Context(const Context&&) = delete;
	Context& operator=(Context&) = delete;

	Context(State *state);

	~Context();

	void transitionTo(State *state);
	void transitionTo(nullptr_t) = delete;

	void run();
	void message(const std::string& message);

};

