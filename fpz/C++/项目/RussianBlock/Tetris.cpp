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
	//�����������
	srand(time(NULL));

	// ������Ϸ����
	initgraph(938, 896);


	// ���ر���ͼƬ
	loadimage(&imgBg, "res/bg2.png");

	//��ʼ����Ϸ���е�����
	char data[20][10];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			map[i][j] = 0;
		}
	}



}

void Tetris::play() {
	init();

	//��ʱ��
	int timer = 0;
	while (1) {
		// �����û�����  ���Ҫ��������¼�
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
		// ��Ⱦ��Ϸ����
		updateWindow();
		// ������Ϸ����
		clearLine();

		}



	}
}

void Tetris::keyEvent() {}

void Tetris::updateWindow() 
{
	putimage(0, 0, &imgBg); //���Ʊ���ͼƬ

	//����ͼƬ
	Block block;
	block.draw(leftMargin,topMargin);
}


//  ��һ�ε��÷���0
//  ���ؾ�����һ�ε��ã�����˶���ms
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
