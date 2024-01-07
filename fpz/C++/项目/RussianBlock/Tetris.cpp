#include "Tetris.h"
#include <stdlib.h>
#include <time.h>

Tetris::Tetris(int rows, int cols, int left, int top, int blockSize) {}

void Tetris::init() 
{
	delay = 30;
	//配置随机种子
	srand(time(NULL));

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

void Tetris::updateWindow() {}

int Tetris::getDelay() {
	return 0;
}

void Tetris::drop() {}

void Tetris::clearLine() {}
