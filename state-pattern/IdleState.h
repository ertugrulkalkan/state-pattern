#pragma once
#include "State.h"
class IdleState : public State
{
public:
    IdleState();

    virtual void cyclicJob() override;
    virtual void eventHandler() override;
    virtual void messageHandler(const std::string& message) override;
};

