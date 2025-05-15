#pragma once
#include "KamataEngine.h"

class Effect {
public:
	void Initialize(KamataEngine::Model* model,KamataEngine::Vector3 scale,KamataEngine::Vector3 rotation);
	void Update();
	void Draw(KamataEngine::Camera& camera);

	bool IsFinished() const { return isFinished_; }

private:
	KamataEngine::Model* model_ = nullptr;
	KamataEngine::WorldTransform worldTransform_;

	// 色変更オブジェクト
	KamataEngine::ObjectColor objectColor_;
	// 色の数値
	KamataEngine::Vector4 color_;

	// 終了フラグ
	bool isFinished_ = false;
	// 経過時間カウント
	float counter_ = 0.0f;
	// 存続時間(消滅までの時間)<秒>
	const float kDuration = 1.0f;
};
