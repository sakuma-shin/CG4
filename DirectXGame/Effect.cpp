#include "Effect.h"
#include<cassert>
#include<algorithm>

void Effect::Initialize(KamataEngine::Model* model,KamataEngine::Vector3 scale, KamataEngine::Vector3 rotation) {
	assert(model);

	model_ = model;

	worldTransform_.Initialize();
	worldTransform_.scale_ = scale;
	worldTransform_.rotation_ = rotation;

	// 色の設定
	objectColor_.Initialize();
	color_ = {1, 1, 1, 1};
}

void Effect::Update() { 
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
	}

	// フェード処理
	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);
	
	objectColor_.SetColor(color_);
	
	worldTransform_.UpdateMatrix(); 
}

void Effect::Draw(KamataEngine::Camera& camera) { model_->Draw(worldTransform_, camera,&objectColor_); }
