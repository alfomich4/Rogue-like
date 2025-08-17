#pragma once
#include "Component.h"
#include "StatsComponent.h"
#include "GameObject.h"
#include "InputComponent.h"
#include "SpriteRendererComponent.h"
#include "SpriteMovementAnimationComponent.h"
namespace XYZEngine
{
    class AttackComponent : public Component
    {
    public:
       
        void Initialize(float newFramerate);
        AttackComponent(GameObject* gameObject, float attackPower);
        float GetAttackPower() const { return attackPower; }
        void SetAttackPower(float newAttackPower) { attackPower = newAttackPower; }
        void Update(float deltaTime) override;
        void Render() override {}
        bool IsAttacking() const { return isAttacking; }
        void Attack(GameObject* target)
        {

            if (!target)
            {
                return;
            }
            auto targetStatsComponent = target->GetComponent<StatsComponent>();
            if (targetStatsComponent)
            {
                float damage = attackPower;
                targetStatsComponent->TakeDamage(attackPower);



            }

        }


    private:
        InputComponent* input;
        SpriteRendererComponent* renderer;
        std::vector<const sf::Texture*> playerAttackTex;
        float secondsForFrame = 0.f;
        float attackCounter = 0.f;
        int attackFrame = 0;
        bool isAttacking = false;
        float attackPower = 10.f;




    };
}

