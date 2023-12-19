#pragma once
//#include "stdafx.h"
#include "state.h"

class plst_grounded : public state
{
public:
	plst_grounded(Player& pl) :state(pl) {}
	void Begin();
	void Update();
	void End();
};

class plst_airborne : public state
{
public:
	plst_airborne(Player& pl) :state(pl){}
	void Begin();
	void Update();
	void End();
};