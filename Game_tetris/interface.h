#ifndef INTERFACE_H_
#define INTERFACE_H_
#include"tetris.h"

class Interface
{
private:
	int** sc;   //int sc[33][20]; ״̬���飬��0Ϊ�գ���1��ռ
	Tetris ArrayTe[400];
	int front;  
	int rear;
	bool canadd;
	int score;
	bool is_over;
public:
	Interface();
	~Interface();
	void add_square(Tetris& square);
	void draw();
	void draw(Tetris next);
	void update();
	void leftMove();
	void rightMove();
	void rotate();
	void downMove();
	bool can_add() { return canadd; }
	void close_add() { canadd = false; }
	bool is_gameover() { return is_over; }
	int get_score() { return score; }
};

#endif














