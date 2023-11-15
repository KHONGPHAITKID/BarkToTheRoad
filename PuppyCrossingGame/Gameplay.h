#pragma once
#include "AsphaltLane.h"
#include "Character.h"
#include "Entity.h"
#include "Global.h"
#include "GrassLane.h"
#include "InputHandler.h"
#include "Map.h"
#include "MoveUpCommand.h"
#include "RailLane.h"
#include "RenderState.h"
#include "Shape.h"
#include "renderer.h"
#include "Button.h"
#include "ScreenRegistry.h"

class Gameplay
{
public:
	InputHandler ih;
	Command* command;
	Character* character;
	SummerLaneFactory fact;
	Map m;
	bool haveStarted = false;

	Gameplay();
	~Gameplay();
	void gameLogic();
	bool isStart();
	bool isEnd();

private:
	int m_speed = 1;
};

