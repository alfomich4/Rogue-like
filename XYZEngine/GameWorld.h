#pragma once

#include "GameObject.h"
#include "PhysicsSystem.h"

namespace XYZEngine
{
class GameWorld
{
  public:
    static GameWorld *Instance();

    void Update(float deltaTime);
    void FixedUpdate(float deltaTime);
    void Render();
    void LateUpdate();
    bool IsGameOver() const
    {
        return gameOver;
    }
    void SetGameOver(bool isGameOver)
    {
        gameOver = isGameOver;
    }
    GameObject *FindObjectByName(const std::string &name);
    GameObject* FindClosestByName(const std::string& name,const Vector2Df& from,float maxDist);

    GameObject *CreateGameObject();
    GameObject *CreateGameObject(std::string name);
    void DestroyGameObject(GameObject *gameObject);
    void Clear();

    void Print() const;

  private:
    GameWorld()
    {
    }
    ~GameWorld()
    {
    }

    GameWorld(GameWorld const &) = delete;
    GameWorld &operator=(GameWorld const &) = delete;

    float fixedCounter = 0.f;

    bool gameOver = false;
    std::vector<GameObject *> gameObjects = {};
    std::vector<GameObject *> markedToDestroyGameObjects = {};

    void DestroyGameObjectImmediate(GameObject *gameObject);
};
} // namespace XYZEngine