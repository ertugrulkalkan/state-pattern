#include "StateMachine.h"

int main()
{
	// create context with work state
	Context context(new WorkState);

	// pass a message to change state
	context.message("idle");

	// manually change the state
	context.transitionTo(new WorkState);
	
	context.run();

	return 0;
}