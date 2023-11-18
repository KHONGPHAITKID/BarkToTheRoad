#include "Map.h"
#define NUM_LANE 8


LaneFactory* Map::m_fact;

Map::Map(LaneFactory* fact)
{
	m_fact = fact;
}

bool Map::checkCollision(Character& e)
{
	COORD pos = e.getPos();
	int i = pos.Y / 90;
	if (i >= m_lane_number || i < 0) return false;
	if (m_lane[i]->checkCollision(e)) return true;
	return false;
}

bool Map::checkCollisionWithStaticObstacle(Character& e)
{
	if (e.getPos().X < 0 || e.getPos().X >= 1260 || e.getPos().Y < 0) return true;
	COORD pos = e.getPos();
	int i = pos.Y / 90;
	if (i >= m_lane_number || i < 0) return false;
	if (m_lane[i]->checkCollision(e) && !m_lane[i]->isStaticLane()) return true;
	return false;
}

void Map::moveObstacle(Character& c)
{
	for (int i = 0; i < m_lane_number; ++i) {
		m_lane[i]->moveObstacle();
		m_lane[i]->moveObstacle(c);
	}
}

void Map::addObstacle()
{
	if (randomInt(0, 100) <= 90) return;
	int id = randomInt(0, 100);
	id %= m_lane_number;
	m_lane[id]->addObstacle();
}

void Map::removeObstacle()
{
	for (int i = 0; i < m_lane_number; ++i)
		m_lane[i]->removeObstacle();
}

void Map::update()
{
	for (int i = 0; i < MAX_LANE - 1; ++i)
	{
		m_lane[i] = m_lane[i + 1];
		m_lane[i]->setPos({ 0, static_cast<short>(90 * i) });
	}

	m_lane[MAX_LANE - 1] = m_fact->createLane({ 0 , static_cast<short>(90 * (MAX_LANE - 1)) });
	m_offset -= 90;
}

void Map::updateOffset(int speed)
{
	m_offset += speed;
}

COORD Map::jumpOnRaft(Character& c)
{
	COORD pos = c.getPos();
	for (SHORT k = -30; k <= 60; k += 90) {
		c.setPos({ pos.X + k, pos.Y });
		COORD pos = c.getPos();
		int i = pos.Y / 90;
		if (i >= m_lane_number || i < 0) continue;
		if (m_lane[i]->isRiverLane())
		{
			COORD pos = m_lane[i]->getCollision(c);
			COORD dummy = { -1, -1 };
			if (!(pos == dummy))
				return { pos.X + 40, pos.Y };
		}
	}
	return pos;
}

bool Map::isRiverLane(COORD pos)
{
	int i = pos.Y / 90;
	if (i >= m_lane_number || i < 0) return false;
	return m_lane[i]->isRiverLane();
}

void Map::render()
{
	for (int i = 0; i < m_lane_number; ++i)
		m_lane[i]->render(m_offset);
}

void Map::addLane()
{
	m_lane[0] = new GrassLane({ 0, static_cast<short>(0) });
	for (short i = 1; i < MAX_LANE; ++i)
	{
		m_lane[i] = m_fact->createLane({ 0 , static_cast<short>(90 * i) });
	}
	return;
}

void Map::loadGame(std::ifstream& fin)
{

}

void Map::saveGame(std::ofstream& fout)
{
	// output game state to file
	fout << m_lane_number << std::endl;
	for (int i = 0; i < m_lane_number; ++i)
	{
		//m_lane[i]->saveGame(fout);
	}
}

std::istream& operator>>(std::istream& in, Map& m)
{
	m.m_lane.clear();
	for (int i = 0; i < MAX_LANE; ++i)
	{
		int factoryIndex;
		in >> factoryIndex;
		Lane* lane;
		switch (factoryIndex)
		{
		case AsphaltFactory:
			lane = new AsphaltLane();
			break;
		case GrassFactory:
			lane = new GrassLane();
			break;
		case RiverFactory:
			lane = new RiverLane();
			break;
		case RailFactory:
			lane = new RailLane();
			break;
		default:
			lane = new GrassLane();
			break;	
		}
		lane->setFactoryIndex(factoryIndex);
		in >> *lane;
		m.m_lane.push_back(lane);
	}
	in >> m.m_offset;
	in >> m.m_factoryType;

	switch (m.m_factoryType)
	{
	case SUMMER:
		m.m_fact = new SummerLaneFactory();
		break;
	case SPRING:
		m.m_fact = new SpringLaneFactory();
		break;
	case WINTER:
		//m.m_fact = new WinterLaneFactory();
		break;
	case AUTUMN:
		//m.m_fact = new AutumnLaneFactory();
		break;
	default:
		break;
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Map& m)
{
	for (int i = 0; i < MAX_LANE; ++i)
	{
		out << m.m_lane[i]->getFactoryIndex() << std::endl;
		out << *m.m_lane[i] << std::endl;
	}
	out << m.m_offset << std::endl;
	out << m.m_factoryType << std::endl;
	return out;
}

