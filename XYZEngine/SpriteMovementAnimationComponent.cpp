#include "pch.h"
#include "SpriteMovementAnimationComponent.h"
#include"AttackComponent.h"


XYZEngine::SpriteMovementAnimationComponent::SpriteMovementAnimationComponent(GameObject* gameObject)
	: Component(gameObject)
{
	movement = gameObject->GetComponent<MovementComponent>();
	renderer = gameObject->GetComponent<SpriteRendererComponent>();
	attackComp = gameObject->GetComponent<AttackComponent>();

	if (movement == nullptr)
	{
		std::cout << "Need movement component for movement animation" << std::endl;
		gameObject->RemoveComponent(this);
	}
	else if (renderer == nullptr)
	{
		std::cout << "Need renderer component for movement animation" << std::endl;
		gameObject->RemoveComponent(this);
	}
	else if (attackComp == nullptr)
	{
		std::cout << "Need attack component for movement animation" << std::endl;
		gameObject->RemoveComponent(this);
	}

}



void XYZEngine::SpriteMovementAnimationComponent::Initialize(float newFramerate)
{

	for (int i = 0; i < ResourceSystem::Instance()->GetTextureMapElementsCount("player_walking"); i++)
	{
		playerWalkTex.push_back(ResourceSystem::Instance()->GetTextureMapElementShared("player_walking", i));
	}



	for (int i = 0; i < ResourceSystem::Instance()->GetTextureMapElementsCount("player_idle"); i++)
	{
		playerIdleTex.push_back(ResourceSystem::Instance()->GetTextureMapElementShared("player_idle", i));
	}





	secondsForFrame = 1.f / newFramerate;
}



void XYZEngine::SpriteMovementAnimationComponent::Update(float deltaTime)
{


	if (attackComp->IsAttacking())
	{
		return;
	}
	if (movement->GetAccelerationSquared() == 0.f)
	{

		renderer->SetTexture(*playerIdleTex[idleFrame]);
		idleCounter += deltaTime;
		if (idleCounter > secondsForFrame)
		{
			idleCounter = 0;
			idleFrame++;
			if (idleFrame == playerIdleTex.size())
			{
				idleFrame = 0;
			}


		}

		return;
	}


	walkCounter += deltaTime;
	if (walkCounter > secondsForFrame)
	{
		renderer->SetTexture(*playerWalkTex[walkFrame]);
		walkCounter = 0;
		walkFrame++;

		if (walkFrame == playerWalkTex.size())
		{
			walkFrame = 0;
		}



	}
}

void XYZEngine::SpriteMovementAnimationComponent::Render()
{

}
