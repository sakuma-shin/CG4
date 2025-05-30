#include "Particle.h"
#include <algorithm>
#include <cassert>

using namespace KamataEngine;
using namespace MathUtility;

void Particle::Initialize(Model* model, Vector3 position, Vector3 velocity) {
	assert(model);

	model_ = model;

	velocity_ = velocity;

	worldTransform_.Initialize();

	worldTransform_.translation_ = position;

	// 大きさ
	worldTransform_.scale_ = {0.2f, 0.2f, 0.2f};

	worldTransform_.rotation_ = {0.0f, velocity_.x * 30.0f, 0.0f};

	// 色の設定
	objectColor_.Initialize();
	color_ = {1, 0.2f, 0, 1};
}

void Particle::Update() {
	// 終了なら何もしない
	if (isFinished_) {
		return;
	}
	// カウンターを1フレーム文の秒数進める
	counter_ += 1.0f / 60.0f;

	// 存続時間の上限に達しているか
	if (counter_ >= kDuration) {
		counter_ = kDuration;
		// 終了する
		isFinished_ = true;
	} else if (counter_ >= kDropTime) {
		const float gravity = -0.008f;

		velocity_.y += gravity;

		// フェード処理
		color_.w = std::clamp(1.0f - (counter_ - kDropTime) / kDuration, 0.0f, 1.0f);
	}

	// 移動
	worldTransform_.translation_ += velocity_;

	// 行列を更新
	worldTransform_.UpdateMatrix();

	objectColor_.SetColor(color_);
}

void Particle::Draw(Camera& camera) { model_->Draw(worldTransform_, camera, &objectColor_); }
