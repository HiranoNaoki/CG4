#include "KamataEngine.h"

using namespace KamataEngine;
using namespace MathUtility;

void WorldTransform::UpdateMatrix() {

	Matrix4x4 matscale = MakeScaleMatrix(scale_);

	Matrix4x4 matRotX = MakeRotateXMatrix(rotation_.x);
	Matrix4x4 matRotY = MakeRotateYMatrix(rotation_.y);
	Matrix4x4 matRotZ = MakeRotateZMatrix(rotation_.z);
	Matrix4x4 matRot = matRotX * matRotY * matRotZ;

	Matrix4x4 matTrans = MakeTranslateMatrix(translation_);

	matWorld_ = matscale * matRot * matTrans;

	TransferMatrix();
}

