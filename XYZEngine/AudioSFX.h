#pragma once
#include "GameObject.h"
#include "GameWorld.h"
#include "AudioComponent.h"
#include "ResourceSystem.h"
namespace XYZEngine
{
class AudioSFX
{

  public:
    AudioSFX(const std::string &soundName);

  private:
    XYZEngine::GameObject *gameObject;
};
} // namespace XYZEngine
