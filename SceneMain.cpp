#include "SceneMain.h"
#include "DxLib.h"

#include "Player.h"
#include "Map.h"

namespace
{
	const char* const kPlayerGraphFilename = "data/image/player000.png";
	const char* const kMapGraphFilename = "data/image/mapchip.png";
}

SceneMain::SceneMain():
	m_playerGraph(-1),
	m_mapGraph(-1)
{
}

SceneMain::~SceneMain()
{
}

void SceneMain::Init()
{
	m_playerGraph = LoadGraph(kPlayerGraphFilename);
	m_mapGraph = LoadGraph(kMapGraphFilename);

	m_pPlayer = std::make_shared<Player>();
	m_pPlayer->SetHandle(m_playerGraph);
	m_pPlayer->Init();

	m_pMap = std::make_shared<Map>();
	m_pMap->SetHandle(m_mapGraph);
	m_pMap->Init();
}

void SceneMain::End()
{
	DeleteGraph(m_playerGraph);
	DeleteGraph(m_mapGraph);
}

void SceneMain::Update()
{
	m_pMap->Update();
	m_pPlayer->Update();
}

void SceneMain::Draw()
{
	m_pMap->Draw();
	m_pPlayer->Draw();
}
