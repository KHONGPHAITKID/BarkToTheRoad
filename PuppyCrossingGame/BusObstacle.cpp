#include "BusObstacle.h"

BusObstacle::BusObstacle(COORD pos)
{
	m_shape = new Shape("image/car_right.txt");
	m_position = pos;
}
