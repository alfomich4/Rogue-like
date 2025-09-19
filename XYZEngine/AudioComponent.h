#pragma once

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "Component.h"

namespace XYZEngine
{
class AudioComponent : public Component
{
  public:
    AudioComponent(GameObject *gameObject);
    ~AudioComponent();

    void Update(float deltaTime) override;
    void Render() override;

    void SetAudio(const sf::SoundBuffer &audio);
    void SetLoop(bool loop);

    void SetVolume(float volume);
    void Play();
    void Stop();
    void Pause();
    void Resume();
    bool IsPlaying() const
    {
        return sound->getStatus() == sf::SoundSource::Playing;
    }
   

  private:
    sf::Sound *sound;
   
};
} // namespace XYZEngine
