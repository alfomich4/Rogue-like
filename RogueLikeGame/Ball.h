#pragma once
#include "SFML/Graphics.hpp"
#include "GameObject.h"
#include "Collidable.h"
#include "IObserver.h"

namespace RogueLikeGame
{
	class Ball final : public GameObject, public Colladiable, public IObservable
	{
	public:
		Ball(const sf::Vector2f& position);
		~Ball() = default;
		void Update(float timeDelta) override;

		void InvertDirectionX();
		void InvertDirectionY();

		bool GetCollision(std::shared_ptr<Colladiable> collidable) const  override;
		void ChangeAngle(float x);
		void restart() override;
	private:
		void OnHit();
		sf::Vector2f direction;
		float lastAngle = 90;
	};
}


