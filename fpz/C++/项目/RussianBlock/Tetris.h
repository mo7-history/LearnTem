#pragma once
class Tetris 
{
public:
	// 构造函数  参数有 行列 左边界 顶部边界 方块大小
	Tetris(int rows,int cols,int left,int top,int blockSize);
	// 初始化
	void init();
	// 开始游戏
	void play();

private:
	void keyEvent();
	void updateWindow();// 更新游戏画面(即渲染)


	int getDelay(); //返回距离上一次调用该函数，间隔了多少事件(ms)
	void drop();
	void clearLine();

private:
	int delay;
	bool update; //是否更新


};

