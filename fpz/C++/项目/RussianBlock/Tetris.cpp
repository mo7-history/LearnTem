#include "Tetris.h"
#include <stdlib.h>
#include <time.h>

Tetris::Tetris(int rows, int cols, int left, int top, int blockSize) {}

void Tetris::init() 
{
	delay = 30;
	//�����������
	srand(time(NULL));

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

void Tetris::updateWindow() {}

int Tetris::getDelay() {
	return 0;
}

void Tetris::drop() {}

void Tetris::clearLine() {}
