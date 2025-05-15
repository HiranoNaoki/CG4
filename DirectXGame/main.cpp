#include <Windows.h>
#include <KamataEngine.h>
#include "GameScene.h"

using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	
	KamataEngine::Initialize(L"LE3D_13_ヒラノ_ナオキ_CG4");


	DirectXCommon* dxcommon = DirectXCommon::GetInstance();

	int32_t w = dxcommon->GetBackBufferWidth();
	int32_t h = dxcommon->GetBackBufferHeight();
	DebugText::GetInstance()->ConsolePrintf();



	GameScene* gameScene = new GameScene();

	gameScene->Initialize();

	while (true) {
		if (KamataEngine::Update()) {
			break;
		}

		gameScene->Update();

		dxcommon->PreDraw();

		gameScene->Draw();

	    dxcommon->PostDraw();
	}


	KamataEngine::Finalize();

	
	delete gameScene;

	gameScene = nullptr;

	return 0;
}
