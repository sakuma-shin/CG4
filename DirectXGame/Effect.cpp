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

//void Effect::Update() { 
//	// 終了なら何もしない
//	if (isFinished_) {
//		return;
//	}
//	// カウンターを1フレーム文の秒数進める
//	counter_ += 1.0f / 60.0f;
//
//	//表示時間半分まではフェードイン、半分すぎたらフェードアウト
//	if (counter_ <= kDuration / 5.0f) {
//
//	} else {
//		// 透明度を下げる
//		color_.w = std::clamp(1.0f-(counter_ / kDuration), 0.0f, 1.0f);
//		objectColor_.SetColor(color_);
//		
//	}
//
//	// 存続時間の上限に達しているか
//	if (counter_ >= kDuration) {
//		counter_ = kDuration;
//		// 終了する
//		isFinished_ = true;
//	}
//	
//	
//	worldTransform_.UpdateMatrix(); 
//}

void Effect::Update() {
	// 終了なら何もしない
	if (isFinished_) {
		return;
	}

	// カウンターを1フレーム文の秒数進める
	counter_ += 1.0f / 60.0f;

	// Z座標に応じて透明度を変化させる（Zが大きいほど透明）
	float zPos = worldTransform_.translation_.z;

	// Zの範囲と透明度の変換設定（例：z=0で不透明、z=100以上で完全透明）
	constexpr float zMin = -2.0f;
	constexpr float zMax = 2.0f;
	float zAlpha = 1.0f - std::clamp((zPos - zMin) / (zMax - zMin), 0.0f, 1.0f);

	// 表示時間に応じたフェード（現在の仕様）
	float timeAlpha = 1.0f;
	if (counter_ > kDuration / 5.0f) {
		timeAlpha = std::clamp(1.0f - (counter_ / kDuration), 0.0f, 1.0f);
	}

	// Z距離と時間の透明度を掛け合わせて最終透明度を決定
	color_.w = zAlpha * timeAlpha;
	objectColor_.SetColor(color_);

	// 存続時間の上限に達しているか
	if (counter_ >= kDuration) {
		counter_ = kDuration;
		isFinished_ = true;
	}

	worldTransform_.UpdateMatrix();
}


void Effect::Draw(KamataEngine::Camera& camera) { model_->Draw(worldTransform_, camera,&objectColor_); }
