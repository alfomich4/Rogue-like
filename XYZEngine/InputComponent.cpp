#include "pch.h"
#include "InputComponent.h"
#include "Logger.h"

namespace XYZEngine
{
InputComponent::InputComponent(GameObject *gameObject) : Component(gameObject)
{
}

void InputComponent::Update(float deltaTime)
{
    bool mouseDownNow = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    mouseClickedThisFrame = (mouseDownNow && !wasMouseDownLastFrame);
    wasMouseDownLastFrame = mouseDownNow;
    verticalAxis = 0.f;
    horizontalAxis = 0.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        verticalAxis += 1.0f;
        LOG_INFO("Move forward");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        verticalAxis -= 1.0f;
        LOG_INFO("Move backward");
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        horizontalAxis += 1.0f;
        LOG_INFO("Move right");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        horizontalAxis -= 1.0f;
        LOG_INFO("Move left");
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (mouseClickedThisFrame)
        {
            LOG_INFO("Left mouse button pressed");
        }
    }
}
void InputComponent::Render()
{
}

float InputComponent::GetHorizontalAxis() const
{
    return horizontalAxis;
}
float InputComponent::GetVerticalAxis() const
{
    return verticalAxis;
}
bool InputComponent::IsMousePressed() const
{

    return mouseClickedThisFrame;
}
}; // namespace XYZEngine