#pragma once
#include "windows.h"
#include "Shape.h"
#include "RenderState.h"

class Entity
{
private:
	COORD m_position{};
	COORD m_new_position{};
	Shape m_shape{};
	int m_width{};
	int m_height{};
	double m_velocity_x{};
	double m_velocity_y{};

public:
	void render(RenderState& rs);
	void move(COORD pos);
	virtual bool isImpact(const Entity& obj) const;
};