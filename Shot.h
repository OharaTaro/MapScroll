#pragma once
#include "Vec2.h"

class Shot
{
public:
	Shot();
	virtual ~Shot() {}

	void SetHandle(int handle) { m_handle = handle; }

	void Fire(Vec2 pos);

	void Update();
	void Draw();

private:
	int m_handle;

	bool m_isExist;
	Vec2 m_pos;
	Vec2 m_vec;
};

