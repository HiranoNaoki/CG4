#include "Guraf.h"

using namespace KamataEngine;

Guraf::Guraf() {}

Guraf::~Guraf() {}

void Guraf::Initialize() {
	textureHandle_ = TextureManager::Load("./Resources/white1x1.png");

	for (int i = 0; i < maxHP; ++i) {

		
		auto guraf = KamataEngine::Sprite::Create(textureHandle_, startPos);
		guraf->SetSize(size);

		if (i == red) {
			guraf->SetColor(Vector4(1.0f, 0.0f, 0.0f, 1.0f)); 
		} else if (i == Green) {
			guraf->SetColor({0.24f, 0.70f, 0.44f, 1.0f}); 
		}
		GurafSprite_.push_back(guraf);
	}
}

void Guraf::Update() {

	for (int i = 0; i < GurafSprite_.size(); ++i) {

		if (i == Green) {
			GurafSprite_[i]->SetSize(Vector2(GurafSprite_[i]->GetSize().x - 1, GurafSprite_[i]->GetSize().y));
			if (GurafSprite_[i]->GetSize().x < 0) {
				GurafSprite_[i]->SetSize(size);
			}
		}
	}
}

void Guraf::Draw() {

	
	for (int i = 0; i < maxHP; i++) {
		GurafSprite_[i]->Draw();
	}
}