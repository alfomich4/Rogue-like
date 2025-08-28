#pragma once
#include "GameObject.h"
#include "MovementComponent.h"
#include "SpriteRendererComponent.h"
#include "ResourceSystem.h"
#include "StatsComponent.h"




namespace XYZEngine
{
	class AttackComponent;
	class SpriteMovementAnimationComponent : public Component
	{
	public:
		SpriteMovementAnimationComponent(GameObject* gameObject);


		void Initialize(float newFramerate,float FramerateAttack);

		void Update(float deltaTime) override;
		void Render() override;
	private:
		MovementComponent* movement;
		SpriteRendererComponent* renderer;
		InputComponent* input;
		StatsComponent* stats = nullptr;
		bool isAttacking = false;
		

		std::vector<const sf::Texture*> playerWalkTex;
		std::vector<const sf::Texture*> playerIdleTex;
		std::vector<const sf::Texture*> playerAttackTex;
		std::vector<const sf::Texture*> playerHurtTex;
		std::vector<const sf::Texture*> playerDeathTex;
		float secondsForFrame = 0.f;
		float secondsForFrameAttack = 0.f;
		float counter = 0.f;
		int attackFrame = 0;
		int walkFrame = 0;
		int idleFrame = 0;
		int hurtFrame = 0;
		int deathFrame = 0;


	};
}
