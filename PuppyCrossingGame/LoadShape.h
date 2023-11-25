#pragma once
#include "Shape.h"

enum ShapeIndex
{
	HCTKCODECAINAY, CAR_RIGHT, CAR_LEFT, GRASS_0,
	GRASS_1, GRASS_2, GRASS_3, GRASS_4,
	STONE, STONE_1, BUSH_2, ROAD, TRAIN_RIGHT, TRAIN_LEFT, 
	DOG_STAY_1, DOG_STAY_2, DOG_JUMP_1, DOG_JUMP_2, DOG_JUMP_3, DOG_DIE,
	RAIL, LOG, RIVER, RED_LIGHT, GREEN_LIGHT, 
	BACKGROUND, NEW_GAME_BUTTON, NEW_GAME_BUTTON_HOVER,
	LOAD_GAME_BUTTON, LOAD_GAME_BUTTON_HOVER,
	RANK_BUTTON, RANK_BUTTON_HOVER, SETTING_BUTTON,
	SCORE, QUIT_BUTTON, QUIT_BUTTON_HOVER,
	PAUSE, PAUSE_HOVER, SAVE_GAME_BUTTON, SAVE_GAME_BUTTON_HOVER,
	HOME, HOME_HOVER, PAUSE_WINDOW, RESUME_BUTTON, RESUME_BUTTON_HOVER,
	CLOSE_DIALOG, GHOST, BACKGROUND_EMPTY, GAME_OVER, TROPHY_SMALL,
	TEXTBOX, LEADERBOARD
};
extern std::vector<Shape*> DogMovingShapes;
extern std::vector<Shape*> DogStayingShapes;
extern std::vector<Shape*> DogDyingShapes;
extern std::vector<Shape*> MyShape;
void initShape();
