#include "SceneMain.h"
#include "DxLib.h"
#include "Pad.h"

#include "Player.h"
#include "Map.h"
#include "Shot.h"

namespace
{
	const char* const kPlayerGraphFilename = "data/image/player000.png";
	const char* const kMapGraphFilename = "data/image/mapchip.png";
	const char* const kShotGraphFilename = "data/image/arrow.png";
}

SceneMain::SceneMain():
	m_playerGraph(-1),
	m_mapGraph(-1),
	m_shotGraph(-1)
{
}

SceneMain::~SceneMain()
{
}

void SceneMain::Init()
{
	m_playerGraph = LoadGraph(kPlayerGraphFilename);
	m_mapGraph = LoadGraph(kMapGraphFilename);
	m_shotGraph = LoadGraph(kShotGraphFilename);

	m_pPlayer = std::make_shared<Player>();
	m_pPlayer->SetHandle(m_playerGraph);
	m_pPlayer->Init();

	m_pMap = std::make_shared<Map>();
	m_pMap->SetHandle(m_mapGraph);
	m_pMap->Init();

	m_pShot = std::make_shared<Shot>();
	m_pShot->SetHandle(m_shotGraph);
//	m_pShot->Init();
}

void SceneMain::End()
{
	DeleteGraph(m_playerGraph);
	DeleteGraph(m_mapGraph);
	DeleteGraph(m_shotGraph);
}

void SceneMain::Update()
{
	m_pMap->Update();
	m_pPlayer->Update();
	m_pShot->Update();
	if (Pad::IsTrigger(PAD_INPUT_1))
	{
		AddShot();
	}
}

void SceneMain::Draw()
{
	m_pMap->Draw();
	m_pPlayer->Draw();
	m_pShot->Draw();
}

void SceneMain::AddShot()
{
	m_pShot->Fire(m_pPlayer->GetPos());
}
