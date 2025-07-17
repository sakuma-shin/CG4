#include "Player.h"
#include <cassert>

using namespace KamataEngine;

void Player::Initialize(KamataEngine::Model2* model) {
	assert(model);
	model_ = model;

	worldTransform_.Initialize();
	worldTransform_.rotation_.y = 2.0f / 3.0f * pi;
	worldTransform_.scale_ = {3.0f, 3.0f, 3.0f};
	worldTransform_.UpdateMatrix();

	hp_ = kMaxHp;

	input_ = Input::GetInstance();
}

void Player::Update() {
	const float kSpeed = 0.5f;
	if (input_->PushKey(DIK_A)) {
		worldTransform_.translation_.x -= kSpeed;
	}

	if (input_->PushKey(DIK_D)) {
		worldTransform_.translation_.x += kSpeed;
	}

	if (input_->PushKey(DIK_W)) {
		worldTransform_.translation_.y += kSpeed;
	}

	if (input_->PushKey(DIK_S)) {
		worldTransform_.translation_.y -= kSpeed;
	}

	if (input_->PushKey(DIK_SPACE)) {
		hp_ -= 1.0f;
		if (hp_ <= 0.0f) {
			hp_ = 0.0f;
		}
	} else if (hp_ <= kMaxHp) {
		hp_ += 1.0f;
	}

	worldTransform_.UpdateMatrix();
}

void Player::Draw(KamataEngine::Camera& camera) { model_->Draw(worldTransform_, camera); }

Player::~Player() { }
