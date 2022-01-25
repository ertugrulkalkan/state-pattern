#pragma once

class Context;

class State
{
protected:
	const std::string m_StateName;
	Context *m_Context;
public:
	State() = delete;
	State(const State&) = delete;
	State(const State&&) = delete;
	State& operator=(const State&) = delete;
	
	State(const std::string& stateName);
	virtual ~State();

	virtual void cyclicJob() = 0;
	virtual void messageHandler(const std::string& message) = 0;

	const std::string& getStateName();
	void setContext(Context *context);
};
