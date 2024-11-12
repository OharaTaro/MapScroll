#pragma once
#include <memory>

class Player;
class Map;
class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	void Init();
	void End();

	void Update();
	void Draw();
private:
	int m_playerGraph;
	int m_mapGraph;

	std::shared_ptr<Player> m_pPlayer;
	std::shared_ptr<Map> m_pMap;
};

