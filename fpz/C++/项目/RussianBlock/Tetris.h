#pragma once
class Tetris 
{
public:
	// ���캯��  ������ ���� ��߽� �����߽� �����С
	Tetris(int rows,int cols,int left,int top,int blockSize);
	// ��ʼ��
	void init();
	// ��ʼ��Ϸ
	void play();

private:
	void keyEvent();
	void updateWindow();// ������Ϸ����(����Ⱦ)


	int getDelay(); //���ؾ�����һ�ε��øú���������˶����¼�(ms)
	void drop();
	void clearLine();

private:
	int delay;
	bool update; //�Ƿ����


};

