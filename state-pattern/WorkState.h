#pragma once
#include "State.h"

class WorkState : public State
{
public:
    WorkState();

    virtual void cyclicJob() override;
    virtual void messageHandler(const std::string& message) override;
};
