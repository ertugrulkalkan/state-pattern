#include <iostream>
#include "WorkState.h"
#include "Context.h"
#include "IdleState.h"

WorkState::WorkState() : State("WorkState")
{

}

void WorkState::cyclicJob()
{
    std::cout << "Cyclic Job of " << this->m_StateName << std::endl;
}

void WorkState::messageHandler(const std::string& message)
{
    if (message == "work")
    {
        std::cout << "Nothing changed" << std::endl;
        return;
    }
    else if (message == "idle")
    {
        this->m_Context->transitionTo(new IdleState);
    }
    else
    {
        __super::messageHandler(message);
    }
}