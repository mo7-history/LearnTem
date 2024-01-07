#pragma once
#include <graphics.h>


struct Point {
	int row; //行
	int col; //列
};

class Block 
{
public:
	Block();
	void drop();  //下降
	void moveLeftRight(int offset); //左右移，给参数大于零右移，小于零左移
	void rotate(); //旋转
	void draw(int leftMargin, int topMargin);  //画方块 给定左顶边界


private:
	int blockType; //方块类型
	Point smallBlocks[4];
	IMAGE *img;

	static IMAGE* imgs[7];
	static int size; //表示大小

};

