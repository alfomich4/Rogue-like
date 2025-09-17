#pragma once

#include "ColliderComponent.h"
#include "SpriteRendererComponent.h"
#include "RenderSystem.h"
#include <SFML/Graphics/Sprite.hpp>

namespace XYZEngine
{

class SpriteColliderComponent : public ColliderComponent
{
  public:
    SpriteColliderComponent(GameObject *gameObject);
    ~SpriteColliderComponent();

    void Update(float deltaTime) override;
    void Render() override;
    void SetPadding(const Vector2Df &p);
    void SetOffset(const Vector2Df &o);
    void RecalcBounds();

  private:
    const sf::Sprite *sprite;
    Vector2Df padding{0.f, 0.f};
    Vector2Df offset{0.f, 0.f};
    TransformComponent *transform = nullptr;
    SpriteRendererComponent *spriteRenderer = nullptr;
};
} // namespace XYZEngine
