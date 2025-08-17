#include "pch.h"
#include "AttackComponent.h"

XYZEngine::AttackComponent::AttackComponent(GameObject* gameObject, float attackPower) :Component(gameObject), attackPower(attackPower)

{
	input = gameObject->GetComponent<InputComponent>();
	renderer = gameObject->GetComponent<SpriteRendererComponent>();
	
}

void XYZEngine::AttackComponent::Update(float deltaTime)
{
	if (input->IsMousePressed() && !isAttacking)
	{
		isAttacking = true;
		renderer->SetTexture(*playerAttackTex[0]);


	}

	if (isAttacking)
	{
		attackCounter += deltaTime;
		if (attackCounter > secondsForFrame)
		{
			attackCounter = 0;
			attackFrame++;
			if (attackFrame == playerAttackTex.size())
			{
				isAttacking = false;
				attackFrame = 0;
			}
			renderer->SetTexture(*playerAttackTex[attackFrame]);


		}
	}


}
void XYZEngine::AttackComponent::Initialize(float newFramerate)
{
	for (int i = 0; i < ResourceSystem::Instance()->GetTextureMapElementsCount("player_attack"); i++)
	{
		playerAttackTex.push_back(ResourceSystem::Instance()->GetTextureMapElementShared("player_attack", i));
	}

	secondsForFrame = 1.f / newFramerate;

}

