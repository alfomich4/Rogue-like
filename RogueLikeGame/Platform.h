#pragma once
#include "SFML/Graphics.hpp"
#include "GameObject.h"
#include "Collidable.h"

namespace RogueLikeGame
{
	class Platform : public GameObject, public Colladiable
	{
	public:
		Platform(const sf::Vector2f& position);
		void Update(float timeDelta) override;
		
		bool GetCollision(std::shared_ptr<Colladiable> collidable) const override;
		void OnHit() override {}
		bool CheckCollision(std::shared_ptr<Colladiable> collidable) override;
	private:
		void Move(float speed);
	};
}