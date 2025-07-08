#include "Player.h"
#include<cassert>
using namespace KamataEngine;

void Player::Initialize(KamataEngine::Model2* model) {
	assert(model);
	model_ = model;

	worldTransform_.Initialize();
	worldTransform_.rotation_.y = 2.0f/3.0f*pi;
	worldTransform_.scale_ = {3.0f, 3.0f, 3.0f};
	worldTransform_.UpdateMatrix();
}

void Player::Update() {

}

void Player::Draw(KamataEngine::Camera &camera) { model_->Draw(worldTransform_, camera); }
