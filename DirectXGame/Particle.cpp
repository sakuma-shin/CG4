#include "Particle.h"
#include<cassert>

using namespace MathUtility;

void Particle::Initialize(Model* model, Vector3 position, Vector3 velocity) {
	assert(model);

	model_ = model;

	velocity_ = velocity;

	worldTransform_.Initialize();

	worldTransform_.translation_ = position;

	//大きさ
	worldTransform_.scale_ = {0.2f, 0.2f, 0.2f};

	//色の設定
	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};
}

void Particle::Update() { 
	//移動
	worldTransform_.translation_ += velocity_;

	//行列を更新
	worldTransform_.UpdateMatrix();


	objectColor_.SetColor(color_);
}

void Particle::Draw(Camera& camera) { 
	model_->Draw(worldTransform_, camera, &objectColor_);
}
