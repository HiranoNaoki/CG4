#include "GameScene.h"

using namespace KamataEngine;

void GameScene::Initialize() { 
	modelParticle_ = Model::CreateSphere(4, 4); }

void GameScene::Update() {

}

void GameScene::Draw() {

}

GameScene::~GameScene() { delete modelParticle_; }