#include "inputs.h"
#include "math.h"
#include "../imgui-sfml-2.6/imgui-1.90.1/imgui.h"
#include "../imgui-sfml-2.6/imgui-SFML.h"

Inputs::Inputs() = default;

void Inputs::register_inputs()
{
	inputs_.x = sf::Joystick::getAxisPosition(0, sf::Joystick::X) * 0.01f;
	if (inputs_.x > -0.1f && inputs_.x < 0.1f)
		inputs_.x = 0.0f;
	inputs_.y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y) * 0.01f;
	if (inputs_.y > -0.1f && inputs_.y < 0.1f)
		inputs_.y = 0.0f;

	ImGui::Begin("Player");
	std::string s = "Joystick.x = " + std::to_string(inputs_.x);
	ImGui::Text(s.c_str());
	std::string s2 = "Joystick.y = " + std::to_string(inputs_.y);
	ImGui::Text(s2.c_str());
	ImGui::End();

	if (sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) < -0.8)
		inputs_.x -= 1;
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) > 0.8)
		inputs_.x += 1;
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) < -0.8)
		inputs_.y += 1;
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) > 0.8)
		inputs_.y -= 1;
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
