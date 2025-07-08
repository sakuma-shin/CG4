#include "GameScene.h"
using namespace KamataEngine;

GameScene::~GameScene() {
	Model2::StaticFinalize();
	for (Sprite* sprite : bgSprite_) {
		delete sprite;
	}
	delete playerModel_;
	delete player_;
}

void GameScene::Initialize() {

	Model2::StaticInitialize();

	worldTransform_.Initialize();

	camera_.Initialize();

	input_ = Input::GetInstance();

	bgGH = TextureManager::Load("Background.png");

	playerModel_ = Model2::CreateFromOBJ("player");

	for (int i = 0; i < 2; i++) {
		Vector2 bgPos = {static_cast<float>(WinApp::kWindowWidth * i), 0.0f};
		bgPos_.push_back(bgPos);
		Sprite* sprite = Sprite::Create(bgGH, bgPos_[i]);
		bgSprite_.push_back(sprite);
	}

	player_ = new Player();
	player_->Initialize(playerModel_);

	hpGH = TextureManager::Load("white1x1.png");

	float spritePos = 490.0f;
	hpGreenSprite_ = Sprite::Create(hpGH, {spritePos, 60.0f});
	hpGreenSprite_->SetSize({player_->GetHp(), 60.0f});
	hpGreenSprite_->SetColor({0.0f, 1.0f, 0.0f, 0.9f});

	hpRedSprite_ = Sprite::Create(hpGH, {spritePos + Player::kMaxHp, 60.0f});
	hpRedSprite_->SetSize({0.0f, 60.0f});
	hpRedSprite_->SetColor({1.0f, 0.0f, 0.0f, 0.9f});
}

void GameScene::Update() {
	if (input_->TriggerKey(DIK_RETURN)) {
		bgSprite_.clear();
		bgPos_.clear();
		sceneNo = RESULT;
	}

	player_->Update();

	for (int i = 0; i < 2; i++) {
		bgPos_[i].x--;
		if (bgPos_[i].x <= -WinApp::kWindowWidth) {
			bgPos_[i] = {WinApp::kWindowWidth, 0.0f};
		}
		bgSprite_[i]->SetPosition(bgPos_[i]);
	}

	float playerHp = player_->GetHp();

	hpGreenSprite_->SetSize({playerHp, 60.0f});

	hpRedSprite_->SetSize({Player::kMaxHp - playerHp, 60.0f});
	hpRedSprite_->SetPosition({490.0f + playerHp, 60.0f});
}

void GameScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxCommon->GetCommandList());
	for (Sprite* sprite : bgSprite_) {
		sprite->Draw();
	}

	Sprite::PostDraw();

	dxCommon->ClearDepthBuffer();

	Model2::PreDraw(dxCommon->GetCommandList());

	player_->Draw(camera_);

	Model2::PostDraw();

	Sprite::PreDraw(dxCommon->GetCommandList());

	hpGreenSprite_->Draw();
	hpRedSprite_->Draw();

	Sprite::PostDraw();
}
