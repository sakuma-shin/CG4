#pragma once
#include "KamataEngine.h"

class FireWorks {
public:

	void Initialize(KamataEngine::Model* model);
	void Update();
	void Draw(KamataEngine::Camera& camera);

	KamataEngine::Vector3 GetPos() const { return worldTransform_.translation_; }
	bool isFinished() const { return isFinished_;}

private:
	//爆発するまでの時間(秒)
	const float kDuration = 1.5f;

	float counter_ = 0.0f;

	KamataEngine::WorldTransform worldTransform_;

	KamataEngine::Model* model_ = nullptr;

	// 色変更オブジェクト
	KamataEngine::ObjectColor objectColor_;
	// 色の数値
	KamataEngine::Vector4 color_;

	bool isFinished_ = false;

};
