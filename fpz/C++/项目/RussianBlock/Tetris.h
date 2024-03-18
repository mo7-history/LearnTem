#pragma once
#include <vector>
#include <graphics.h>
using namespace std;

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

	//int map[20][10];
	//vector<int> map; //һά����
	//0���հױ�ʾû���κη���  5����ʾ�ǵ����ֶ���˹����
	vector<vector<int> > map;  //��ά����
	int rows;
	int cols;
	int leftMargin;
	int topMargin;
	int blockSize;
	IMAGE imgBg; //����ͼƬ


};

