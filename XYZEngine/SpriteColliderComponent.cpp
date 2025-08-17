#include "pch.h"
#include "SpriteColliderComponent.h"

namespace XYZEngine
{
	SpriteColliderComponent::SpriteColliderComponent(GameObject* gameObject) : ColliderComponent(gameObject)
	{
		spriteRenderer = gameObject->GetComponent<SpriteRendererComponent>();
		if (spriteRenderer == nullptr)
		{
			std::cout << "SpriteRenderer required to SpriteCollider." << std::endl;
			gameObject->RemoveComponent(this);
			return;
		}
		transform = gameObject->GetComponent<TransformComponent>();
		sprite = gameObject->GetComponent<SpriteRendererComponent>()->GetSprite();
		PhysicsSystem::Instance()->Subscribe(this);
	}
	SpriteColliderComponent::~SpriteColliderComponent()
	{
		if (&bounds != nullptr)
		{
			std::destroy_at(&bounds);
		}
		PhysicsSystem::Instance()->Unsubscribe(this);
	}

	void SpriteColliderComponent::Update(float deltaTime)
	{
		bounds = sprite->getGlobalBounds();
		RecalcBounds();
	}
	void SpriteColliderComponent::Render()
	{
		sf::RectangleShape rectangle(sf::Vector2f(bounds.width, bounds.height));
		rectangle.setPosition(bounds.left, bounds.top);
		rectangle.setFillColor(sf::Color::Transparent);
		rectangle.setOutlineColor(sf::Color::White);
		rectangle.setOutlineThickness(4);

		RenderSystem::Instance()->Render(rectangle);
	}

	void SpriteColliderComponent::SetPadding(const Vector2Df& p)
	{
		padding = p;
	}

	

	void SpriteColliderComponent::SetOffset(const Vector2Df& o)
	{
		offset = o;
	}

	void SpriteColliderComponent::RecalcBounds()
	{
		Vector2Df px = spriteRenderer->GetPixelSize();

		float width = std::max(0.f, px.x - padding.x);
		float height = std::max(0.f, px.y - padding.y);

		Vector2Df c = transform->GetWorldPosition();
		bounds.width = width;
		bounds.height = height;
		bounds.left = c.x - 0.5f * width + offset.x;
		bounds.top = c.y - 0.5f * height + offset.y;
		
	}
}