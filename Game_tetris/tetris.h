#ifndef TETRIS_H_
#define TETRIS_H_

typedef struct
{
	int s1[2];
	int s2[2];
	int s3[2];
	int s4[2];
}TSquare;

class Tetris
{
private:
	TSquare square;
	int type;
	int state;
	int x_offset;    
	int y_offset;      
	int R;
	int G;
	int B;
public:
	Tetris(int t = 0, int s = 0);
	TSquare creat(int t, int s, int x, int y);
	void spin();
	void set_offset(int x, int y);  
	void right_move(int x);
	void down_move(int y = 20);
	int getXCoord(int n);
	int getYCoord(int n);
	void one_down_move(int n, int y = 20);
	int trans_to_yindex(int n);
	int trans_to_xindex(int n);
	int check_iswhich(int x, int y);  
	void set_coord_to_zero(int n);
	int getR() { return R; }
	int getG() { return G; }
	int getB() { return B; }
};

#endif