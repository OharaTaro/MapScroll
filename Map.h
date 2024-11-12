#pragma once
class Map
{
public:
	Map();
	virtual ~Map() {}

	void SetHandle(int handle);

	void Init();
	void Update();
	void Draw();

private:
	void DrawChip(int x, int y, int index);

private:
	int m_handle;
	int m_graphWidth;
	int m_graphHeight;
};

