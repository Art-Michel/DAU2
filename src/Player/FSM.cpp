//#include "stdafx.h"
#include <map>
#include <string>
#include "player.h"
#include "FSM.h"
#include "playerstates.h"

FSM::FSM(Player& pl) :player(pl)
{
	add_state(std::make_unique<plst_grounded>(player));
	add_state(std::make_unique<plst_airborne>(player));
}

void FSM::add_state(std::unique_ptr<state>&& st)
{
	states.try_emplace(st->Name, std::move(st));
}

void FSM::change_state()
{
	state* next_state = nullptr;
}
