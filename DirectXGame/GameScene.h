#pragma once
#include "KamataEngine.h"
#include "Particle.h"


using namespace KamataEngine;
class GameScene {
public:
	~GameScene();

	void Initialize();
	void Update();
	void Draw();

private:
	Model* modelParticle_ = nullptr;
	Camera camera_;
	std::list<Particle*> particles_;
};
