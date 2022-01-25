#include <iostream>
#include "IdleState.h"
#include "Context.h"
#include "WorkState.h"

IdleState::IdleState() : State("IdleState")
{

}

void IdleState::cyclicJob()
{
    std::cout << "Cyclic Job of " << this->m_StateName << std::endl;
}

void IdleState::messageHandler(const std::string& message)
{
    if (message == "work")
    {
        this->m_Context->transitionTo(new WorkState);
    }
    else if (message == "idle")
    {
        std::cout << "Nothing changed" << std::endl;
    }
    else
    {
        __super::messageHandler(message);
    }
}
