#pragma once
#include "Lane.h"
#include "AsphaltObstacleFactory.h"

class AsphaltLane : public Lane
{
public:
    AsphaltLane() = default;
    AsphaltLane(COORD pos) : 
        Lane(pos)
    {
        m_fact = new AsphaltObstacleFactory();
        m_shape = *MyShape[ROAD];
    }

    using Lane::render;
private:
};

