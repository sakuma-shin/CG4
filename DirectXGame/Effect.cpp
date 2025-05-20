#include "Effect.h"
#include<cassert>
#include<algorithm>

using namespace KamataEngine;

void Effect::Initialize(KamataEngine::Model* model, KamataEngine::Vector3 scale, KamataEngine::Vector3 rotation, KamataEngine::Vector3 position, KamataEngine::Vector4 color) {
	assert(model);

	model_ = model;

	worldTransform_.Initialize();
	worldTransform_.scale_ = scale;
	worldTransform_.rotation_ = rotation;
	worldTransform_.translation_ = position;

	// 色の設定
	objectColor_.Initialize();
	color_ =color;
}

void Effect::Update() { 
	// 終了なら何もしない
	if (isFinished_) {
		return;
	}
	// カウンターを1フレーム文の秒数進める
	counter_ += 1.0f / 60.0f;

	//表示時間の半分はそのまま表示
	if (counter_ >= kDuration / 2.0f) {

		//現在のscaleから縮める数を決定
		KamataEngine::Vector3 reduction = {worldTransform_.scale_.x / 60.0f * kDuration, worldTransform_.scale_.y / 60.0f * kDuration, worldTransform_.scale_.z / 60.0f * kDuration};

		//実際にscaleを小さくする
		worldTransform_.scale_.x -= reduction.x;
		worldTransform_.scale_.y -= reduction.y;
		worldTransform_.scale_.z -= reduction.z;

		//Z軸で回転させる
		worldTransform_.rotation_.z -= 0.3f;

		/*if (worldTransform_.scale_.x <= 0.0f) {
		    worldTransform_.scale_.x = 0.0f;
		}

		if (worldTransform_.scale_.y <= 0.0f) {
		    worldTransform_.scale_.y = 0.0f;
		}

		if (worldTransform_.scale_.z <= 0.0f) {
		    worldTransform_.scale_.z = 0.0f;
		}*/

		//// 存続時間の上限に達しているか
		// if (worldTransform_.scale_.x==0.0f && worldTransform_.scale_.y==0.0f && worldTransform_.scale_.z==0.0f) {
		//	counter_ = kDuration;
		//	// 終了する
		//	isFinished_ = true;
		// }

		// 存続時間の上限に達しているか
		if (counter_ >= kDuration) {
			counter_ = kDuration;
			// 終了する
			isFinished_ = true;
		}
	}

	// フェード処理
	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);
	
	objectColor_.SetColor(color_);

	
	
	worldTransform_.UpdateMatrix(); 
}

void Effect::Draw(KamataEngine::Camera& camera) { model_->Draw(worldTransform_, camera,&objectColor_); }
