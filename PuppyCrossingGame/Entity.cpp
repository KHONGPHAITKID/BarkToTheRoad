#include "Entity.h"

void Entity::render(RenderState& rs) {
	if (m_position.X != m_new_position.X) {
		m_position.X += m_velocity_x;
	}

	if (m_position.Y != m_new_position.Y) {
		m_position.Y += m_velocity_y;
	}

	m_shape.render(m_position.X, m_position.Y, rs);
}

void Entity::move(COORD pos)
{
	m_velocity_x = (pos.X - m_position.X) / 60.;
	m_velocity_y = (pos.Y - m_position.Y) / 60.;
	m_new_position = pos;
}

bool Entity::isImpact(const Entity& obj) const
{
	return false;
}
