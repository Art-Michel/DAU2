#pragma once
#include "stdafx.h"
#include "core.h"

class Inputs
{
private:
	vec2 inputs_ = vec2(0.0f, 0.0f);

public:
	Inputs();
	void register_inputs();
	vec2 get_inputs();
};

