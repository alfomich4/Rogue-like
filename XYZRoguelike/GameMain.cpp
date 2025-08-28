// ©2023, XYZ School. All rights reserved.
// Authored by Aleksandr Rybalka (polterageist@gmail.com)

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Engine.h"
#include "ResourceSystem.h"
#include "DeveloperLevel.h"
#include "Matrix2D.h"

using namespace XYZRoguelike;

int main()
{
	XYZEngine::RenderSystem::Instance()->SetMainWindow(new sf::RenderWindow(sf::VideoMode(1280, 720), "XYZRoguelike"));



	ResourceSystem::Instance()->LoadTextureMap("player_attack", "Resources/TextureMaps/Attack.png", { 100, 64 }, 9, false);
	ResourceSystem::Instance()->LoadTextureMap("player_hurt", "Resources/TextureMaps/Hurt.png", { 100, 64 }, 4, false);
	ResourceSystem::Instance()->LoadTextureMap("player_walking", "Resources/TextureMaps/Walking.png", { 100, 64 }, 7, false);
	ResourceSystem::Instance()->LoadTextureMap("player_idle", "Resources/TextureMaps/Idle.png", { 100, 64 }, 4, false);
	ResourceSystem::Instance()->LoadTextureMap("player_dying", "Resources/TextureMaps/Dying.png", { 100, 64 }, 6, false);
	ResourceSystem::Instance()->LoadTextureMap("level_floors", "Resources/TextureMaps/Floor.png", { 16, 16 }, 49, false);
	ResourceSystem::Instance()->LoadTextureMap("level_walls", "Resources/TextureMaps/Wall.png", { 16, 16 }, 48, false);
	ResourceSystem::Instance()->LoadTextureMap("cobald_idle", "Resources/TextureMaps/idleCob.png", { 148, 96 }, 6, false);
	ResourceSystem::Instance()->LoadTextureMap("cobald_walking", "Resources/TextureMaps/RUN.png", { 148, 96 }, 8, false);
	ResourceSystem::Instance()->LoadTextureMap("cobald_attacking", "Resources/TextureMaps/Attack1.png", { 148, 96 }, 5, false);

	ResourceSystem::Instance()->LoadSound("GamePlaymusic", "Resources/Sounds/trapped.wav");

	auto developerLevel = std::make_shared<DeveloperLevel>();
	developerLevel->Start();

	XYZEngine::Engine::Instance()->Run();

	return 0;
}
