#include "Effect.h"

void Effect::Initialize(KamataEngine::Model* model) {
	assert(model);

	model_ = model;

	worldTransform_.Initialize();

	float pi = 3.14f;
	worldTransform_.rotation_ = { 0.0f, 0.0f,pi / 4.0f};
}

void Effect::Update() { worldTransform_.UpdateMatrix(); }

void Effect::Draw(KamataEngine::Camera& camera) { model_->Draw(worldTransform_, camera); }
