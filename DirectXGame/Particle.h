#pragma once
#include "KamataEngine.h"
using namespace KamataEngine;

class Particle {
public:
	void Initialize(Model* model,Vector3 position,Vector3 velocity);
	void Update();
	void Draw(Camera& camera);

	bool IsFinished() { return isFinished_;}

private:
	WorldTransform worldTransform_;

	Model* model_ = nullptr;

	//色変更オブジェクト
	ObjectColor objectColor_;
	// 色の数値
	Vector4 color_;

	//移動量
	Vector3 velocity_;

	//終了フラグ
	bool isFinished_ = false;
	//経過時間カウント
	float counter_ = 0.0f;
	//存続時間(消滅までの時間)<秒>
	const float kDuration = 1.0f;
};
