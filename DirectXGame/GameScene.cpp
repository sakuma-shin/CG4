#include "GameScene.h"
#include <random>

using namespace KamataEngine;

using namespace MathUtility;

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

GameScene::~GameScene() {
	delete modelEffect_;
	for (Effect* effect : effects_) {
		delete effect;
	}

	delete modelParticle_;
	for (Particle* particle : particles_) {
		delete particle;
	}
	particles_.clear();
}

void GameScene::Initialize() {
	// シングルトンインスタンスを取得
	input_ = KamataEngine::Input::GetInstance();

	modelParticle_ = Model::CreateSphere(4, 4);
	modelEffect_ = Model::CreateFromOBJ("effect");
	camera_.Initialize();
	// 乱数の初期化
	srand((unsigned)time(NULL));

	scene_ = NONE;
}

void GameScene::EffectUpdate() {

	effects_.remove_if([](Effect* effect) {
		if (effect->IsFinished()) {
			delete effect;
			return true;
		}
		return false;
	});

	// 確率で発生
	if (rand() % 30 == 0) {
		// 位置
		Vector3 position = {distribution(randomEngine) * 30.0f, distribution(randomEngine) * 20.0f, 0};
		EffectBorn(position);
	}

	for (Effect* effect : effects_) {
		effect->Update();
	}
}

void GameScene::ParticleUpdate() {
	particles_.remove_if([](Particle* particle) {
		if (particle->IsFinished()) {
			delete particle;
			return true;
		}
		return false;
	});

	// 確率で発生
	if (rand() % 20 == 0) {
		// 位置
		Vector3 position = {distribution(randomEngine) * 30.0f, distribution(randomEngine) * 20.0f, 0};
		ParticleBorn(position);
	}

	for (Particle* particle : particles_) {
		particle->Update();
	}
}

void GameScene::Update() {
	switch (scene_) {
	case NONE:
		if (input_->TriggerKey(DIK_SPACE)) {
			scene_ = PARTICLE;
		}

		break;

	case PARTICLE:

		if (input_->TriggerKey(DIK_SPACE)) {
			scene_ =EFFECT;
		}

		ParticleUpdate();

		break;

	case EFFECT:

		if (input_->TriggerKey(DIK_SPACE)) {
			scene_ = PARTICLE;
		}

		EffectUpdate();

		break;
	}
}

void GameScene::EffectDraw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());
	for (Effect* effect : effects_) {
		effect->Draw(camera_);
	}
	Model::PostDraw();
}

void GameScene::ParticleDraw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());
	for (Particle* particle : particles_) {
		particle->Draw(camera_);
	}
	Model::PostDraw();
}

void GameScene::Draw() {
	switch (scene_) {
	case NONE:

		break;

	case PARTICLE:

		ParticleDraw();

		break;

	case EFFECT:

		EffectDraw();

		break;
	}
}

void GameScene::EffectBorn(KamataEngine::Vector3 position) {
	/*Vector4 color = {abs(distribution(randomEngine)), abs(distribution(randomEngine)), abs(distribution(randomEngine)), 1.0f};*/
	Vector4 color = {1.0f, 1.0f, 1.0f, 1.0f};
	for (int i = 0; i < 50; i++) {
		Vector3 scale = {abs(distribution(randomEngine)), abs(distribution(randomEngine)), abs(distribution(randomEngine))};
		float pi = 3.14f;
		Vector3 rotation = {0.0f, 0.0f, distribution(randomEngine) * pi};

		Effect* newEffect_ = new Effect();
		newEffect_->Initialize(modelEffect_, scale, rotation, position, color);
		effects_.push_back(newEffect_);
	}
}

void GameScene::ParticleBorn(KamataEngine::Vector3 position) {
	for (int i = 0; i < 50; i++) {

		Particle* particle = new Particle();

		// 移動量
		Vector3 velocity = {distribution(randomEngine), distribution(randomEngine), 0};

		Normalize(velocity);
		velocity *= distribution(randomEngine);
		velocity *= 0.1f;

		// 初期化
		particle->Initialize(modelParticle_, position, velocity);
		// リストに追加
		particles_.push_back(particle);
	}
}
