#pragma once
#include "Screen.h"
#include "MenuScreen.h"
#include "GameScreen.h"
class ScreenRegistry
{
public:
	Screen* getCurrentScreen() const {
		return m_screens[Global::current_screen];
	}

	void initialize(Gameplay* gp) {
		m_screens.push_back(new MenuScreen{ gp });
		m_screens.push_back(new GameScreen{ gp });
	}

	void addScreen(Screen* s) {
		m_screens.push_back(s);
	}
private:
	std::vector<Screen*> m_screens;
};

