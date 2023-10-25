#pragma once
#include "Obstacle.h"
#include <time.h>

class GrassObstacle : public Obstacle
{
public:
	GrassObstacle() = default;
	GrassObstacle(COORD pos);
	bool checkCollision(const Entity& otherEntity) const override;
private:
};

