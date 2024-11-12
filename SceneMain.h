#pragma once
#include <memory>
#include "Vec2.h"

class Player;
class Map;
class Shot;
class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	void Init();
	void End();

	void Update();
	void Draw();

	void AddShot();

private:
	int m_playerGraph;
	int m_mapGraph;
	int m_shotGraph;

	std::shared_ptr<Player> m_pPlayer;
	std::shared_ptr<Map> m_pMap;
	std::shared_ptr<Shot> m_pShot;
};

