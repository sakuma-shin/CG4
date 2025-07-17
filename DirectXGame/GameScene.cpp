#include "GameScene.h"
using namespace KamataEngine;

GameScene::~GameScene() {
	Model2::StaticFinalize();
	for (Sprite* sprite : bgSprite_) {
		delete sprite;
	}
	delete playerModel_;
	delete player_;
	delete hpGreenSprite_;
	delete hpRedSprite_;
	for (int i = 0; i < 5; i++) {
		delete numSprite_[i];
	}
}

void GameScene::Initialize() {

	Model2::StaticInitialize();

	worldTransform_.Initialize();

	camera_.Initialize();

	input_ = Input::GetInstance();

	bgGH = TextureManager::Load("Background.png");

	playerModel_ = Model2::CreateFromOBJ("player");

	if (bgSprite_.size() < 2) {
		for (int i = 0; i < 2; i++) {
			Vector2 bgPos = {static_cast<float>(WinApp::kWindowWidth * i), 0.0f};
			bgPos_.push_back(bgPos);
			Sprite* sprite = Sprite::Create(bgGH, bgPos_[i]);
			bgSprite_.push_back(sprite);
		}
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

	numGH = TextureManager::Load("number.png");

	for (int i = 0; i < 5; i++) {
		numSprite_[i] = Sprite::Create(numGH, {100.0f + numSize.x * i, 5});
		numSprite_[i]->SetSize(numSize);
	}
	number = 0;
}

void GameScene::Update() {

	if (input_->TriggerKey(DIK_RETURN)) {

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

	for (int i = 0; i < 5; i++) {
		numSprite_[i]->SetTextureRect({0, 0}, numSize);
	}

	number = int(playerHp);

	int32_t digit = 10000;
	// 五桁分ループ
	for (int i = 0; i < 5; i++) {
		// 今の桁の数値を散りだす
		int nowNumber = number / digit;
		// 今の数値の部分を切り出すようにする
		numSprite_[i]->SetTextureRect({numSize.x * nowNumber, 0}, numSize);
		//次の処理のために残りの桁数の値にする
		number %= digit;
		//次の桁の処理のために割る数値を10で割って桁に応じた値にする
		digit /= 10;
	}
}

void GameScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxCommon->GetCommandList());
	for (Sprite* sprite : bgSprite_) {
		sprite->Draw();
	}

	for (int i = 0; i < 5; i++) {
		numSprite_[i]->Draw();
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
