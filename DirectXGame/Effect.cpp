#include "Effect.h"
#include<cassert>
#include<algorithm>

using namespace KamataEngine;
using namespace MathUtility;

void Effect::Initialize(KamataEngine::Model* model, KamataEngine::Vector3 scale, KamataEngine::Vector3 rotation, KamataEngine::Vector3 position, KamataEngine::Vector4 color) {
	assert(model);

	model_ = model;

	worldTransform_.Initialize();

	scale.x *= kMaxScale.x;
	scale.y *= kMaxScale.y;
	scale.z *= kMaxScale.z;
	worldTransform_.scale_ = scale;
	worldTransform_.rotation_ = rotation;
	worldTransform_.translation_ = position;

	/*worldTransform_.scale_ = kMaxScale * 0.8f;*/

	// 色の設定
	objectColor_.Initialize();
	color_ =color;

	objectColor_.SetColor(color_);
}

void Effect::Update() { 
	// 終了なら何もしない
	if (isFinished_) {
		return;
	}
	// カウンターを1フレーム文の秒数進める
	counter_ += 1.0f / 60.0f;

	//表示時間半分まではフェードイン、半分すぎたらフェードアウト
	if (counter_ <= kDuration / 5.0f) {

	} else {
		// 透明度を下げる
		color_.w = std::clamp(1.0f-(counter_ / kDuration), 0.0f, 1.0f);
		objectColor_.SetColor(color_);
		
	}

	// 存続時間の上限に達しているか
	if (counter_ >= kDuration) {
		counter_ = kDuration;
		// 終了する
		isFinished_ = true;
	}
	
	
	worldTransform_.UpdateMatrix(); 
}

void Effect::Draw(KamataEngine::Camera& camera) { model_->Draw(worldTransform_, camera,&objectColor_); }
