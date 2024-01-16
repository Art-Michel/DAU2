#include "inputs.h"
#include "math.h"

Inputs::Inputs() = default;

void Inputs::register_inputs()
{
	// inputs_.x = App::GetController().GetLeftThumbStickX();
	inputs_.x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
	// if (inputs_.x > -0.3f && inputs_.x < 0.3f)
	//	inputs_.x = 0.0f;

	// inputs_.y = App::GetController().GetLeftThumbStickY();
	inputs_.y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
	// if (inputs_.y > -0.3f && inputs_.y < 0.3f)
	//	inputs_.y = 0.0f;

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
	return new_inputs;
}
