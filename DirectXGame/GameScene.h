#pragma once
#include "KamataEngine.h"
#include "Effect.h"
#include "Particle.h"
#include"FireWorks.h"

class GameScene {
public:
	~GameScene();

	void Initialize();

	void EffectUpdate();
	void ParticleUpdate();
	void Update();

	void EffectDraw();
	void ParticleDraw();
	void Draw();

	void EffectBorn(KamataEngine::Vector3 position);
	void ParticleBorn(KamataEngine::Vector3 position);
	void FireWorksBorn();

private:
	KamataEngine::Model* modelEffect_ = nullptr;
	KamataEngine::Model* modelParticle_ = nullptr;

	KamataEngine::Camera camera_;

	std::list<Effect*> effects_;
	std::list<Particle*> particles_;

	const int effectNum = 30;

	enum Scene {
		NONE,

		PARTICLE,
		EFFECT
	};

	Scene scene_ = NONE;

	// キー入力
	KamataEngine::Input* input_ = nullptr;

	FireWorks* fireworks_ = nullptr;

};
