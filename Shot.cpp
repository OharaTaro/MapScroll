#include "Shot.h"
#include "DxLib.h"

Shot::Shot():
	m_handle(-1),
	m_isExist(false)
{
}

void Shot::Fire(Vec2 pos)
{
	m_isExist = true;
	m_pos = pos;
	m_vec.x = 6.0f;
	m_vec.y = -6.0f;
}

void Shot::Update()
{
	if (!m_isExist)	return;
	m_vec.y += 0.2f;
	m_pos += m_vec;
}

void Shot::Draw()
{
	if (!m_isExist)	return;

	double angle = 0.0;

	DrawRotaGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y),
		2.0, angle, m_handle, true
	);
}
