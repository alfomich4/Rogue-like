#include "pch.h"
#include "AudioSFX.h"

namespace XYZEngine
{
AudioSFX::AudioSFX(const std::string &soundName)
{
    auto gameObject = GameWorld::Instance()->CreateGameObject(soundName);
    auto music = gameObject->AddComponent<AudioComponent>();
    music->SetAudio(*ResourceSystem::Instance()->GetSound(soundName));
    music->SetVolume(15000.f);
    music->Play();
    gameObject->AddComponent<DestroyStopAudio>();
   
}
} // namespace XYZEngine
