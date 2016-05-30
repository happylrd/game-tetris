#ifndef INTERFACE_H_
#define INTERFACE_H_
#include"tetris.h"

class Interface
{
private:
	int** sc;   //int sc[33][20]; 状态数组，置0为空，置1被占
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














