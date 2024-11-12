#include "Player.h"
#include "DxLib.h"

#include "game.h"
#include "Pad.h"

namespace
{
	// キャラクターのサイズ
	constexpr int kWidth = 32;
	constexpr int kHeight = 32;

	// キャラクターの移動速度
	constexpr float kSpeed = 2.0f;

	// 歩きアニメーションで使用する順番
	constexpr int kWalkAnimNo[] = {0,1,2,1};
	constexpr int kWalkAnimNum = _countof(kWalkAnimNo);
	constexpr int kWalkAnimFrame = 6;
}

Player::Player():
	m_handle(-1),
	m_dir(kDirDown),
	m_walkFrameCount(0)
{
}

Player::~Player()
{
}

void Player::Init()
{
	m_pos.x = Game::kScreenWidth / 2;
	m_pos.y = Game::kScreenHeight / 2;
	m_dir = kDirDown;
}

void Player::Update()
{
	Vec2 move{ 0.0f, 0.0f };
	bool isMove = false;
	if(Pad::IsPress(PAD_INPUT_UP))
	{
		move.y = -1.0f;
		m_dir = kDirUp;
		isMove = true;
	}
	if (Pad::IsPress(PAD_INPUT_DOWN))
	{
		move.y = 1.0f;
		m_dir = kDirDown;
		isMove = true;
	}
	if (Pad::IsPress(PAD_INPUT_LEFT))
	{
		move.x = -1.0f;
		m_dir = kDirLeft;
		isMove = true;
	}
	if (Pad::IsPress(PAD_INPUT_RIGHT))
	{
		move.x = 1.0f;
		m_dir = kDirRight;
		isMove = true;
	}

	if(isMove)
	{
		move.Normalize();
		move *= kSpeed;

		m_pos += move;

		// 移動中のみ歩行アニメーションを進行させる
		m_walkFrameCount++;
		if (m_walkFrameCount >= kWalkAnimNum * kWalkAnimFrame)
		{
			m_walkFrameCount = 0;
		}
	}
}

void Player::Draw()
{
	int animIndex = m_walkFrameCount / kWalkAnimFrame;
	int animNo = kWalkAnimNo[animIndex];

	DrawRectGraph(m_pos.x - kWidth / 2, m_pos.y - kHeight / 2,
		animNo*kWidth, m_dir*kHeight,
		kWidth, kHeight, m_handle, true);
}
