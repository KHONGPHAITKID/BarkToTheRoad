#include "Button.h"
#include<string>

void Button::render()
{
	if (isHovering()) setState(FOCUSED);
	else setState(NORMAL);

	m_shape[m_state].render(m_pos.X, m_pos.Y);
}

void Button::setPos(COORD pos)
{
	m_pos = pos;
}

bool Button::isInside(POINT p) const
{
	int height = 0, width = 0;
	m_shape->getSize(width, height);
	p.y = 720 - p.y;
	return (p.x >= m_pos.X && p.x <= m_pos.X + width 
		&& p.y >= m_pos.Y && p.y <= m_pos.Y + height);
}

bool Button::isHovering() const
{
	POINT mouse_pos;
	if (GetCursorPos(&mouse_pos) == 0) return false;
	ScreenToClient(Global::window, &mouse_pos);
	return isInside(mouse_pos);
}

COORD Button::getPos() const
{
	return m_pos;
}

void ChangeScreenButton::onClick()
{
	OutputDebugStringA("Clicked");
	if (m_show_dialog) *m_show_dialog = false;
	Global::current_screen = m_next_screen;
}

void PauseButton::onClick()
{
}
