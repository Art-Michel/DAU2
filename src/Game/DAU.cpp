// // DAU.cpp
// // #include "stdafx.h"
// #include <string>
// // #include "App\app.h"
// #include "entity.h"
// #include "player.h"
// #include "EntitiesManager.h"

// Entity entity;
// Entity entity2;
// Entity entity3;
// Player player;

// void Init()
// {
// 	entity = Entity();
// 	entity2 = Entity();
// 	entity3 = Entity();
// 	// player = Player();

// 	player.init(vec2(500, 400), ".\\Sprites\\char.png");
// 	auto *ent = static_cast<Entity *>(&player);
// 	EntitiesManager::GetInstance()->entities.push_back(ent);

// 	entity.init(vec2(500, 32), ".\\Sprites\\Square.png");
// 	entity2.init(vec2(564, 32), ".\\Sprites\\Square.png");
// 	entity3.init(vec2(628, 32), ".\\Sprites\\Square.png");
// 	EntitiesManager::GetInstance()->entities.push_back(&entity);
// 	EntitiesManager::GetInstance()->entities.push_back(&entity2);
// 	EntitiesManager::GetInstance()->entities.push_back(&entity3);
// }

// void Update(float deltaTime)
// {
// 	EntitiesManager::GetInstance()->Update(deltaTime);
// }

// void Render()
// {
// 	EntitiesManager::GetInstance()->Draw();

// 	// std::string str = "x: " + std::to_string(inputs.get_inputs().x) + "\n y: " + std::to_string(inputs.get_inputs().y);
// 	// App::Print(100, 100, str.c_str());

// 	// std::string str2 = "length: " + std::to_string(inputs.get_inputs().magnitude());
// 	// App::Print(100, 60, str2.c_str());
// }

// void Shutdown()
// {
// }

// //// Example data....
// // CSimpleSprite *testSprite;
// // enum anims
// //{
// //	ANIM_FORWARDS,
// //	ANIM_BACKWARDS,
// //	ANIM_LEFT,
// //	ANIM_RIGHT,
// // };
// //
// //
// //																			void init()
// //{
// //	// Example Sprite Code....
// //	testSprite = App::CreateSprite(".\\TestData\\Test.bmp", 8, 4);
// //	testSprite->SetPosition(400.0f, 400.0f);
// //	float speed = 1.0f / 15.0f;
// //	testSprite->CreateAnimation(ANIM_BACKWARDS, speed, { 0,1,2,3,4,5,6,7 });
// //	testSprite->CreateAnimation(ANIM_LEFT, speed, { 8,9,10,11,12,13,14,15 });
// //	testSprite->CreateAnimation(ANIM_RIGHT, speed, { 16,17,18,19,20,21,22,23 });
// //	testSprite->CreateAnimation(ANIM_FORWARDS, speed, { 24,25,26,27,28,29,30,31 });
// //	testSprite->SetScale(1.0f);
// // }
// //
// //																			void update(float deltaTime)
// //{
// //	// Example Sprite Code....
// //	testSprite->update(deltaTime);
// //	if (App::GetController().GetLeftThumbStickX() > 0.5f)
// //	{
// //		testSprite->SetAnimation(ANIM_RIGHT);
// //		float x, y;
// //		testSprite->GetPosition(x, y);
// //		x += 1.0f;
// //		testSprite->SetPosition(x, y);
// //	}
// //	if (App::GetController().GetLeftThumbStickX() < -0.5f)
// //	{
// //		testSprite->SetAnimation(ANIM_LEFT);
// //		float x, y;
// //		testSprite->GetPosition(x, y);
// //		x -= 1.0f;
// //		testSprite->SetPosition(x, y);
// //	}
// //     if (App::GetController().GetLeftThumbStickY() > 0.5f)
// //     {
// //         testSprite->SetAnimation(ANIM_FORWARDS);
// //         float x, y;
// //         testSprite->GetPosition(x, y);
// //         y += 1.0f;
// //         testSprite->SetPosition(x, y);
// //     }
// //	if (App::GetController().GetLeftThumbStickY() < -0.5f)
// //	{
// //		testSprite->SetAnimation(ANIM_BACKWARDS);
// //		float x, y;
// //		testSprite->GetPosition(x, y);
// //		y -= 1.0f;
// //		testSprite->SetPosition(x, y);
// //	}
// //	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_UP, false))
// //	{
// //		testSprite->SetScale(testSprite->GetScale() + 0.1f);
// //	}
// //	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_DOWN, false))
// //	{
// //		testSprite->SetScale(testSprite->GetScale() - 0.1f);
// //	}
// //	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_LEFT, false))
// //	{
// //		testSprite->SetAngle(testSprite->GetAngle() + 0.1f);
// //	}
// //	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_RIGHT, false))
// //	{
// //		testSprite->SetAngle(testSprite->GetAngle() - 0.1f);
// //	}
// //	if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, true))
// //	{
// //		testSprite->SetAnimation(-1);
// //	}
// //
// //
// //	// Sample Sound.
// //	if (App::GetController().CheckButton(APP_PAD_EMUL_BUTTON_ALT_A, true))
// //	{
// //		App::PlaySound(".\\TestData\\Test.wav");
// //	}
// // }
// //

// //// Add your display calls here (DrawLine,Print, DrawSprite.)
// //// See App.h
// //																			void Render()
// //{
// //	// Example Sprite Code....
// //	testSprite->draw();
// //
// //	// Example Text.
// //	App::Print(100, 100, "BOTTOM TEXT");
// //
// //	// Example Line Drawing.
// //	static float a = 0.0f;
// //	float r = 1.0f;
// //	float g = 1.0f;
// //	float b = 1.0f;
// //	a += 0.1f;
// //	for (int i = 0; i < 20; i++)
// //	{
// //
// //		float sx = 200 + sinf(a + i * 0.1f)*60.0f;
// //		float sy = 200 + cosf(a + i * 0.1f)*60.0f;
// //		float ex = 700 - sinf(a + i * 0.1f)*60.0f;
// //		float ey = 700 - cosf(a + i * 0.1f)*60.0f;
// //		g = static_cast<float>(i) / 20.0f;
// //		b = static_cast<float>(i) / 20.0f;
// //		App::DrawLine(sx, sy, ex, ey,r,g,b);
// //	}
// //}
// //
// //// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// //// Just before the app exits.
// //																			void Shutdown()
// //{
// //	// Example Sprite Code....
// //	delete testSprite;
// //}