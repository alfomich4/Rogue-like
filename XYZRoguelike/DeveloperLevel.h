#pragma once

#include <iostream>
#include <array>
#include "Scene.h"
#include "Player.h"
#include "Cobald.h"
#include "Music.h"
#include "Floor.h"
#include "Wall.h"

using namespace XYZEngine;

namespace XYZRoguelike
{
	class DeveloperLevel : public Scene
	{
	public:
		void Start() override;
		void Restart() override;
		void Stop() override;
	private:
		std::unique_ptr<Player> player;
		std::unique_ptr<Cobald> cobald;
		std::unique_ptr<Music> music;

		std::vector<std::unique_ptr<Wall>> walls;
		std::vector<std::unique_ptr<Floor>> floors;
	};
}