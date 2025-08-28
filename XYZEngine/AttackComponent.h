#pragma once
#include "Component.h"
#include "StatsComponent.h"
#include "GameObject.h"

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
                targetStatsComponent->TakeDamage(damage);



            }

        }


    private:
        float attackPower = 0.f;




    };
}

