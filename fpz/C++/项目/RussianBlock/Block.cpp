#include "Block.h"
#include <stdlib.h>

IMAGE* Block::imgs[7] = { NULL };
int Block::size = 36;


Block::Block() 
{
	if (imgs[0]==NULL)
	{
		IMAGE imgTmp;
		loadimage(&imgTmp, "res/tiles.png");

	//设置切割对象  
		SetWorkingImage(&imgTmp);
		for (int i = 0; i < 7; i++) {
			imgs[i] = new IMAGE;
			getimage(imgs[i], i * size, 0, size, size);//存放位置  切割点x轴坐标 y轴坐标  切割长度 宽度
		}
		SetWorkingImage();

	}

	int blocks[7][4] = {
	1,3,5,7,
	2,4,5,7,
	3,5,4,6,
	3,5,4,7,
	2,3,5,7,
	3,5,7,6,
	2,3,4,5,
	};
	 
	//随机生成一种俄罗斯方块 值为1-7
	blockType = rand() % 7 + 1;

	for (int i = 0; i < 4; i++) {
		int value = blocks[blockType-1][i];
		smallBlocks[i].col = value / 2;
		smallBlocks[i].row = value % 2;
	}

    //配置方块图片
	img = imgs[blockType - 1];


}

void Block::drop() {}

void Block::moveLeftRight(int offset) {}

void Block::rotate() {}

void Block::draw(int leftMargin, int topMargin) {
	for (int i = 0; i < 4; i++) {
		int x = leftMargin + smallBlocks[i].col * size;
		int y = topMargin + smallBlocks[i].row * size;
		putimage(x, y, img);
	}

}
