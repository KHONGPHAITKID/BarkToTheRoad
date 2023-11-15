#pragma once
#include "LaneFactory.h"
#include "Character.h"

constexpr int MAX_LANE = 13;

class Map
{
private:
	int m_lane_number{ 10 };
	std::vector<Lane*> m_lane{ MAX_LANE };
	static LaneFactory* m_fact;
	int m_offset = 0;
public:
	Map() = default;
	Map(LaneFactory* fact);
  
	bool checkCollision(Character& e);
	bool checkCollisionWithStaticObstacle(Character& e);
	void moveObstacle(Character &c);
	void addObstacle();
	void removeObstacle();
	void update();
	void updateOffset(int speed);
	COORD jumpOnRaft(Character &c);

	bool isRiverLane(COORD pos);

	void render();
	void addLane();

	// load game from file
	void loadGame(std::ifstream& fin);

	// save game to file
	void saveGame(std::ofstream& fout);
};

