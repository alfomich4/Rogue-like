#pragma once
#include "Component.h"
#include "Logger.h"


namespace XYZEngine
{
	class StatsComponent : public Component
	{
		
	public:
		StatsComponent(GameObject* gameObject, float health, float armor);
		float GetMaxHealth() const { return maxHealth; }
		float GetCurrentHealth() const { return currentHealth; }
		float GetArmor() const { return armor; }
		bool IsDead() const { return isDead; }
		bool IsHurt() const { return hurtTimer > 0.f; }
		void Update(float deltaTime) override;
		void Render() override {  }
		void TakeDamage(float damage);
		void Heal(float amount);
		void AddArmor(float amount);
		
		
		
	private:
		float maxHealth;
		float currentHealth;
		float armor;
        float maxArmor=100;
		float hurtTimer = 0.f;
		bool isDead = false;
		

	};
}


