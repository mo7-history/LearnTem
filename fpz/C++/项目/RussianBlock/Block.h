#pragma once
#include <graphics.h>


struct Point {
	int row; //��
	int col; //��
};

class Block 
{
public:
	Block();
	void drop();  //�½�
	void moveLeftRight(int offset); //�����ƣ����������������ƣ�С��������
	void rotate(); //��ת
	void draw(int leftMargin, int topMargin);  //������ �����󶥱߽�


private:
	int blockType; //��������
	Point smallBlocks[4];
	IMAGE *img;

	static IMAGE* imgs[7];
	static int size; //��ʾ��С

};

