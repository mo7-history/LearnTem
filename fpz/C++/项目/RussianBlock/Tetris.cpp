#include "Tetris.h"
#include <stdlib.h>
#include <time.h>
#include "Block.h"

const int SPEED_NORMAL = 500; //ms
const int SPEED_QUICK = 50; 


Tetris::Tetris(int rows, int cols, int left, int top, int blockSize) {
	this->cols = cols;
	this->rows = rows;
	this->leftMargin = left;
	this->topMargin = top;
	this->blockSize = blockSize;

	for (int i = 0; i < rows; i++) {
		vector<int> mapRow;
		for (int j = 0; j < cols; j++) {
			mapRow.push_back(0);
		}
		map.push_back(mapRow);
	}

}

void Tetris::init() 
{
	delay = SPEED_NORMAL;
	//配置随机种子
	srand(time(NULL));

	// 创建游戏窗口
	initgraph(938, 896);


	// 加载背景图片
	loadimage(&imgBg, "res/bg2.png");

	//初始化游戏区中的数据
	char data[20][10];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			map[i][j] = 0;
		}
	}



}

void Tetris::play() {
	init();

	//定时器
	int timer = 0;
	while (1) {
		// 接受用户输入  因此要创建点击事件
		keyEvent();

		timer += getDelay();
		if (timer > delay)
		{
			timer = 0;
			update = true;
			drop();
		}
		if (update)
		{   
		// 渲染游戏画面
		updateWindow();
		// 更新游戏数据
		clearLine();

		}



	}
}

void Tetris::keyEvent() {}

void Tetris::updateWindow() 
{
	putimage(0, 0, &imgBg); //绘制背景图片

	//测试图片
	Block block;
	block.draw(leftMargin,topMargin);
}


//  第一次调用返回0
//  返回距离上一次调用，间隔了多少ms
int Tetris::getDelay() {

	static unsigned long long lastTime = 0;
	unsigned long long currentTime = GetTickCount();

	if (lastTime == 0)
	{
		lastTime = currentTime;
		return 0;
	} 
	else
	{
		int ret = currentTime - lastTime;
		return ret;
	}
}

void Tetris::drop() {}

void Tetris::clearLine() {}
