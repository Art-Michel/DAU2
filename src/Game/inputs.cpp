#include "inputs.h"
#include "math.h"

Inputs::Inputs() = default;

void Inputs::register_inputs()
{
	inputs_.x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
	inputs_.y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);

	if (sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) < -0.8)
		inputs_.x -= 1;
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) > 0.8)
		inputs_.x += 1;
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) < -0.8)
		inputs_.y -= 1;
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) > 0.8)
		inputs_.y += 1;
}

vec2 Inputs::get_inputs()
{
	vec2 new_inputs = inputs_.normalized();
	new_inputs = new_inputs * ((abs(inputs_.x) + abs(inputs_.y)));
	new_inputs = new_inputs.normalized() * clamp01(new_inputs.magnitude());

	// Three digits of precision
	new_inputs.x = roundf(new_inputs.x * 1000) * 0.001f;
	new_inputs.y = roundf(new_inputs.y * 1000) * 0.001f;

	return new_inputs;
}
