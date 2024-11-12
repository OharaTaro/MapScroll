#pragma once
#include "Vec2.h"
class Player
{
public:
	Player();
	virtual ~Player();

	// 使用するグラフィックを設定する
	void SetHandle(int handle) { m_handle = handle; }

	void Init();
	void Update();
	void Draw();

	Vec2 GetPos() const { return m_pos; }

private:
	enum Dir
	{
		kDirDown,	// 下方向
		kDirLeft,	// 左方向
		kDirRight,	// 右方向
		kDirUp,		// 上方向
	};

private:
	int m_handle;

	Vec2 m_pos;
	Dir m_dir;

	int m_walkFrameCount;
};

