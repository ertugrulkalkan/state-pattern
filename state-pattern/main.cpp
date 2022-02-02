#include "StateMachine.h"

int main()
{
	// create context with work state
	Context context(new WorkState);

	// pass a message to change state
	context.message("idle");

	// manually change the state
	context.transitionTo(new WorkState);

	// run
	context.run();

	// pass a message to change state
	context.message("idle");

	// wait 1 second
	std::this_thread::sleep_for(std::chrono::seconds(1));

	// pass	a message to change state
	context.message("work");

	// wait 1 second
	std::this_thread::sleep_for(std::chrono::seconds(1));
	
	// stop
	context.stop();

	// pass a message to change state
	context.message("idle");

	// run
	context.run();

	// wait 1 second
	std::this_thread::sleep_for(std::chrono::seconds(1));

	// stop
	context.stop();

	return 0;
}