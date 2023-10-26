#include "Entity.h"

Entity::Entity(COORD pos, Shape* s)
{
	m_position = pos;
	m_shape = s;
}

void Entity::render() {
	if (m_position.X != m_new_position.X) {
		m_position.X += m_velo_x;
	}
	else {
		m_velo_x = 0;
	}
	if (m_position.Y != m_new_position.Y) {
		m_position.Y += m_velo_y;
	}
	else {
		m_velo_y = 0;
	}

	m_shape->render(m_position.X, m_position.Y);
}

void Entity::move(COORD pos) {
	m_new_position = pos;
	m_velo_x = (pos.X - m_position.X) / 30;
	m_velo_y = (pos.Y - m_position.Y) / 30;
}

bool Entity::isCollison(const Entity& e)
{
	int width, height; // my Entity size
	int eWidth, eHeight; // others Entity size

	// get size
	m_shape->getSize(width, height);
	e.m_shape->getSize(eWidth, eHeight);
	int thisLeft = m_position.X;
	int thisRight = m_position.X + width;
	int thisTop = m_position.Y;
	int thisBottom = m_position.Y + height;

	int otherLeft = e.m_position.X;
	int otherRight = e.m_position.X + eWidth;
	int otherTop = e.m_position.Y;
	int otherBottom = e.m_position.Y + eHeight;

	if (thisRight > otherLeft && thisLeft < otherRight &&
		thisBottom > otherTop && thisTop < otherBottom) {
		return true;
	}

	return false;
}
