#include "Particle.h"
#include<cassert>
#include<algorithm>

using namespace KamataEngine;
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
	//終了なら何もしない
	if (isFinished_) {
		return;
	}
	//カウンターを1フレーム文の秒数進める
	counter_ += 1.0f / 60.0f;

	//存続時間の上限に達しているか
	if (counter_ >= kDuration) {
		counter_ = kDuration;
		//終了する
		isFinished_ = true;
	}

		// フェード処理
	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);

	//移動
	worldTransform_.translation_ += velocity_;

	//行列を更新
	worldTransform_.UpdateMatrix();

	objectColor_.SetColor(color_);

}

void Particle::Draw(Camera& camera) { 
	model_->Draw(worldTransform_, camera, &objectColor_);
}
