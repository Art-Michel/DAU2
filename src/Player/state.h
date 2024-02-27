#pragma once
// #include "stdafx.h"

struct state_list
{
	static const int GROUNDED = 0;
	static const int AIRBORNE = 1;
};

class Player;
class state
{
public:
	Player &myplayer;
	int Name;

private:
public:
	state(Player &plpt) : myplayer(plpt) {}

	virtual void init(int name, Player *plpt);
	virtual ~state() = default;

	virtual void Begin() {}
	virtual void Update() {}
	virtual void End() {}
};
