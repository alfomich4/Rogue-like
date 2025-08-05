#pragma once
#include "GameObject.h"
#include "MovementComponent.h"
#include "SpriteRendererComponent.h"
#include "ResourceSystem.h"



namespace XYZEngine
{
	class AttackComponent;
	class SpriteMovementAnimationComponent : public Component
	{
	public:
		SpriteMovementAnimationComponent(GameObject* gameObject);


		void Initialize(float newFramerate);

		void Update(float deltaTime) override;
		void Render() override;
	private:
		MovementComponent* movement;
		SpriteRendererComponent* renderer;
		AttackComponent* attackComp;


		std::vector<const sf::Texture*> playerWalkTex;
		std::vector<const sf::Texture*> playerIdleTex;
		float secondsForFrame = 0.f;
		float walkCounter = 0.f;
		float idleCounter = 0.f;
		int walkFrame = 0;
		int idleFrame = 0;


	};
}
