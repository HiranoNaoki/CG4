#include "Num.h"
#include <iomanip>

using namespace KamataEngine;

Num::Num() {}

Num::~Num() {
	
	for (auto sprite : NumSprite_) {
		delete sprite;
	}
	NumSprite_.clear();
}

void Num::Initialize() {
	textureHandle_ = TextureManager::Load("./Resources/number.png");

	for (int i = 0; i < 5; i++) {
		
		Vector2 pos = {startPos.x - size.x * i, startPos.y};

		Sprite* sprite = Sprite::Create(textureHandle_, pos);
		sprite->SetSize(size);
		sprite->SetColor(Vector4(1.0f, 0.0f, 1.0f, 1.0f));
		NumSprite_.push_back(sprite);
	}
}

void Num::Update() {
	number_++;

	if (number_ >= 10000) {
		number_ = 0;
	}

	SetNum(number_);
}

void Num::Draw() {
	for (int i = 0; i < NumSprite_.size(); i++) {
		NumSprite_[i]->Draw();
	}
}

void Num::SetNum(int value) {
	number_ = value;

	
	std::stringstream ss;
	ss << std::setw(5) << std::setfill('0') << number_;
	std::string numStr = ss.str();

	
	for (int i = 0; i < NumSprite_.size(); i++) {
		char digitChar = numStr[4 - i]; 
		int digit = digitChar - '0';
		Vector2 texPos = {size.x * digit, 0.0f};
		NumSprite_[i]->SetTextureRect(texPos, size);
	}
}