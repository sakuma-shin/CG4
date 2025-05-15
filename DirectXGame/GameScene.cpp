#include "GameScene.h"
using namespace KamataEngine;

GameScene::~GameScene() { delete model_; }

void GameScene::Initialize() {
	model_ = new Model2();
	model_->Create();
}

void GameScene::Update() {}

void GameScene::Draw() {}
