#pragma once
#include "KamataEngine.h"
#include "Effect.h"

class GameScene {
public:
	~GameScene();

	void Initialize();
	void Update();
	void Draw();

	void EffectBorn(KamataEngine::Vector3 position);

private:
	KamataEngine::Model* modelEffect_ = nullptr;
	KamataEngine::Camera camera_;

	std::list<Effect*> effects_;

};
