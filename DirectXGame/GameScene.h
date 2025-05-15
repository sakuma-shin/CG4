#pragma once
#include "KamataEngine.h"
#include "Particle.h"

class GameScene {
public:
	~GameScene();

	void Initialize();
	void Update();
	void Draw();

	void ParticleBorn(KamataEngine::Vector3 position);

private:
	KamataEngine::Model* modelParticle_ = nullptr;
	KamataEngine::Camera camera_;
	std::list<Particle*> particles_;
};
