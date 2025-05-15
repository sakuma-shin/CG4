#include "Effect.h"

void Effect::Initialize(KamataEngine::Model* model,KamataEngine::Vector3 scale, KamataEngine::Vector3 rotation) {
	assert(model);

	model_ = model;

	worldTransform_.Initialize();
	worldTransform_.scale_ = scale;
	worldTransform_.rotation_ = rotation;
}

void Effect::Update() { worldTransform_.UpdateMatrix(); }

void Effect::Draw(KamataEngine::Camera& camera) { model_->Draw(worldTransform_, camera); }
