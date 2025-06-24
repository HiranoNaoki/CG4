#include <Windows.h>
#include <KamataEngine.h>
#include "Shader.h"
#include "GameScene.h"
#include <cassert>
#include "RootSignature.h"
#include "PipelineState.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
//#include <d3dcompiler.h>

using namespace KamataEngine;

void SetupPipelineState(PipelineState& pipelineState, RootSignature& rs, Shader& vs, Shader& ps);



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	
	KamataEngine::Initialize(L"LE3D_13_ヒラノ_ナオキ_CG5");


	DirectXCommon* dxcommon = DirectXCommon::GetInstance();

	int32_t w = dxcommon->GetBackBufferWidth();
	int32_t h = dxcommon->GetBackBufferHeight();
	DebugText::GetInstance()->ConsolePrintf(
		std::format("width: {}, height: {}\n", w,h).c_str());

	ID3D12GraphicsCommandList* commandList = dxcommon->GetCommandList();

	GameScene* gameScene = new GameScene();

	gameScene->Initialize();

	

	RootSignature rs;

	rs.Create();



	//InputLayout
	


	// 頂点シェーダの読み込みとコンパイル
	Shader vs;
	vs.LoadDxc(L"Resources/shaders/TestVS.hlsl", L"vs_6_0");
	assert(vs.GetDxcBlob() != nullptr);

	// ピクセルシェーダの読み込みとコンパイル
	Shader ps;
	ps.LoadDxc(L"Resources/shaders/TestPS.hlsl", L"ps_6_0");
	assert(ps.GetDxcBlob() != nullptr);

	PipelineState pipelineState;

	SetupPipelineState(pipelineState, rs, vs, ps);

	struct VertexDate {
		Vector4 position;
	};

	VertexDate vertices[] = {
	    {-1.0f,  1.0f, 0.0f, 1.0f}, // 左上
	    { 1.0f,  1.0f, 0.0f, 1.0f}, // 右上
	    { 1.0f, -1.0f, 0.0f, 1.0f}, // 右下
	    {-1.0f, -1.0f, 0.0f, 1.0f}, // 左下
	};


	//VertexResourceの生成
	
	VertexBuffer vb;
	//vd.Create(sizeof(Vector4) * 3, sizeof(Vector4));
	vb.Create(sizeof(vertices), sizeof(vertices[0]));


	VertexDate* pGpuVertices = nullptr;
	vb.Get()->Map(0, nullptr, reinterpret_cast<void**>(&pGpuVertices));
	for (int i = 0; i < _countof(vertices); ++i) {
		pGpuVertices[i] = vertices[i];
	}

	//頂点リソースのマップを解除する
	//vertexResource->Unmap(0, nullptr);

	uint16_t indices[] = {
	    0, 1, 2, 
	    2, 3, 0, 
	};

	IndexBuffer ib;
	ib.Create(sizeof(indices), sizeof(indices[0]));

	// 頂点リソースにデータを書き込む
	uint16_t* pGpuIndices = nullptr;
	ib.Get()->Map(0, nullptr, reinterpret_cast<void**>(&pGpuIndices));

	for (int i = 0; i < _countof(indices); ++i) {
		pGpuIndices[i] = indices[i];
	}
	

	while (true) {
		if (KamataEngine::Update()) {
			break;
		}

		gameScene->Update();

		dxcommon->PreDraw();

		//コマンドを詰む
		commandList->SetGraphicsRootSignature(rs.Get());//RootSignatureの設定
		commandList->SetPipelineState(pipelineState.Get());//PSOの設定をする
		commandList->IASetVertexBuffers(0, 1, vb.GetView());//VBVの設定をする
		commandList->IASetIndexBuffer(ib.GetView());
		//トポロジの設定
		commandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		//頂点数、インデックス数、インデックスの開始位置、インデックスのオフセット
		//commandList->DrawInstanced(3, 1, 0, 0);
		commandList->DrawIndexedInstanced(_countof(indices), 1, 0, 0, 0);

		gameScene->Draw();

	    dxcommon->PostDraw();
	}


	
	delete gameScene;

	gameScene = nullptr;

	
	



	KamataEngine::Finalize();

	

	return 0;
}





void SetupPipelineState(PipelineState& pipelineState, RootSignature& rs, Shader& vs, Shader& ps) {
	// InputLayout
	D3D12_INPUT_ELEMENT_DESC inputElementDescs[1] = {};
	inputElementDescs[0].SemanticName = "POSITION";
	inputElementDescs[0].SemanticIndex = 0;
	inputElementDescs[0].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	inputElementDescs[0].AlignedByteOffset = D3D12_APPEND_ALIGNED_ELEMENT;
	D3D12_INPUT_LAYOUT_DESC inputLayoutDesc{};
	inputLayoutDesc.pInputElementDescs = inputElementDescs;
	inputLayoutDesc.NumElements = _countof(inputElementDescs);

	#pragma region BlendState
	D3D12_BLEND_DESC blendDesc{};
	// すべての色素を書き込む
	blendDesc.RenderTarget[0].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
#pragma endregion

#pragma region RasterizeState
	D3D12_RASTERIZER_DESC rasterizerDesc{};
	// 裏面（反時計回り）をカリングする
	rasterizerDesc.CullMode = D3D12_CULL_MODE_BACK;
	// 塗りつぶしモードをソリッドにする（ワイヤーフレームならD3D12_FILL_MODE_WIREFRAME）
	rasterizerDesc.FillMode = D3D12_FILL_MODE_SOLID;
#pragma endregion

#pragma region PSO(PiplineStateObject)の生成
	D3D12_GRAPHICS_PIPELINE_STATE_DESC graphicsPipelineStateDesc{};
	graphicsPipelineStateDesc.pRootSignature = rs.Get();
	graphicsPipelineStateDesc.InputLayout = inputLayoutDesc;
	graphicsPipelineStateDesc.VS = {vs.GetDxcBlob()->GetBufferPointer(), vs.GetDxcBlob()->GetBufferSize()};
	graphicsPipelineStateDesc.PS = {ps.GetDxcBlob()->GetBufferPointer(), ps.GetDxcBlob()->GetBufferSize()};
	graphicsPipelineStateDesc.BlendState = blendDesc;
	graphicsPipelineStateDesc.RasterizerState = rasterizerDesc;
	// 書き込むRTVの情報
	graphicsPipelineStateDesc.NumRenderTargets = 1;
	graphicsPipelineStateDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;
	// 利用するトポロジ（形状）のタイプ。三角形
	graphicsPipelineStateDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
	// どのように画面に色を打ち込むのか設定
	graphicsPipelineStateDesc.SampleDesc.Count = 1;
	graphicsPipelineStateDesc.SampleMask = D3D12_DEFAULT_SAMPLE_MASK;

#pragma endregion

	pipelineState.Create(graphicsPipelineStateDesc);
}
