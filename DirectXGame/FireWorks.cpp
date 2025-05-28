#include "FireWorks.h"
#include <cassert>
#include <algorithm>

using namespace KamataEngine;
using namespace MathUtility;

void FireWorks::Initialize(Model* model) {
	assert(model);

	model_ = model;

	worldTransform_.Initialize();

	worldTransform_.translation_ = {0.0f,-50.0f,0.0f};
	// 大きさ
	worldTransform_.scale_ = {0.5f, 0.5f, 0.5f};

	isFinished_ = false;

	counter_ = 0.0f;

	objectColor_.Initialize();

	color_ = {1, 0.2f, 0, 1};
	objectColor_.SetColor(color_);
}
void FireWorks::Update() {

	if (isFinished_) {
		return;
	}
	// 1フレーム分追加
	counter_ += 1.0f / 60.0f;

	if (counter_ >= kDuration) {
		counter_ = kDuration;
		isFinished_ = true;
	}

	worldTransform_.translation_.y = std::clamp(worldTransform_.translation_.y + counter_ / kDuration, -30.0f, 0.0f);

	worldTransform_.UpdateMatrix();
}
void FireWorks::Draw(Camera& camera) { 
	model_->Draw(worldTransform_, camera, &objectColor_); 
}