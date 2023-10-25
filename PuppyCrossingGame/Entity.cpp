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

bool Entity::checkCollision(const Entity& otherEntity) const {
	int thisLeft = m_position.X;
	int thisRight = m_position.X + m_shape->getWidth();
	int thisTop = m_position.Y;
	int thisBottom = m_position.Y + m_shape->getHeight();

	int otherLeft = otherEntity.m_position.X;
	int otherRight = otherEntity.m_position.X + otherEntity.m_shape->getWidth();
	int otherTop = otherEntity.m_position.Y;
	int otherBottom = otherEntity.m_position.Y + otherEntity.m_shape->getHeight();

	if (thisRight > otherLeft && thisLeft < otherRight &&
		thisBottom > otherTop && thisTop < otherBottom) {
		return true;
	}

	return false;
}