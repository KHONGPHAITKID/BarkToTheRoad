#pragma once
#include "windows.h"
#include "Global.h"
#include "LoadShape.h"
class Entity
{
private:
	int m_velo_x;
	int m_velo_y;

protected:
	COORD m_position;
	COORD m_new_position;
	Shape* m_shape;
public:
	Entity() = default;
	Entity(COORD pos, Shape* s);
	void render();
	void move(COORD pos);
	virtual bool checkCollision(const Entity& otherEntity) const;
};