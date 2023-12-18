#pragma once
#include "stdafx.h"
#include "state.h"
class Player;

class FSM
{
private:
	std::map<int, std::unique_ptr<state>> states;
	Player& player;

public:
	FSM(Player& pl);
	state* Current_State = nullptr;
	state* Previous_State = nullptr;

public:
	void add_state(std::unique_ptr<state>&& st);

	void change_state();
};