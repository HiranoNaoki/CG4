#pragma once
#include<string>//wstring,string
#include<d3dcompiler.h>//dxcapi
#include<d3d12.h>//ID3DBlob

#include<dxcapi.h>//IDxcBlobを利用するため

#pragma comment(lib, "dxcompiler.lib")


class Shader {
public:
	//シェーダファイルを読み込み、コンパイル済みデータを生成する
	void Load(const std::wstring& filePath, const std::wstring& shaderModel);
	void LoadDxc(const std::wstring& filePath, const std::wstring& shadermodel);
	//生成したコンパイル
	ID3DBlob* GetBlob();
	IDxcBlob* GetDxcBlob();
	//コンストラクタ
	Shader();
	//デストラクタ
	~Shader();
	
private:
	ID3DBlob* blob_ = nullptr;//コンパイル済みのシェーダーデータ＆コンストラクタで初期化しなくていい　※C++11以降
	IDxcBlob* dxcBlob_ = nullptr;//コンパイル済みのシェーダーデータ ※外部コンパイル版
};