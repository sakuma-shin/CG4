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

	void ParticleBorn(Vector3 position);

private:
	Model* modelParticle_ = nullptr;
	Camera camera_;
	std::list<Particle*> particles_;
};
