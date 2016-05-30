#include"tetris.h"
#include"graphics.h"

Tetris::Tetris(int t, int s)
{
	type = t;
	state = s;
	x_offset = y_offset = 0;
	square = creat(type, state, x_offset, y_offset);
	randomize();
	R = random(256);
	G = random(256);
	B = random(256);
}

TSquare Tetris::creat(int t, int s, int x, int y)
{
	int s11, s12, s21, s22, s31, s32, s41, s42;
	switch (t)
	{
	case 0:  //田
		s11 = 210; s12 = 10;
		s21 = 230; s22 = 10;
		s31 = 210; s32 = 30;
		s41 = 230; s42 = 30;
		break;

	case 1:  //一条直线
		if (s == 0)
		{
			s11 = 210; s12 = 10;
			s21 = 230; s22 = 10;
			s31 = 250; s32 = 10;
			s41 = 270; s42 = 10;
			break;
		}
		else
		{
			s11 = 210; s12 = 10;
			s21 = 210; s22 = 30;
			s31 = 210; s32 = 50;
			s41 = 210; s42 = 70;
			break;
		}

	case 2:  //Z
		if (s == 0)
		{
			s11 = 210; s12 = 10;
			s21 = 230; s22 = 10;
			s31 = 230; s32 = 30;
			s41 = 250; s42 = 30;
			break;
		}
		else
		{
			s11 = 230; s12 = 10;
			s21 = 230; s22 = 30;
			s31 = 210; s32 = 30;
			s41 = 210; s42 = 50;
			break;
		}

	case 3:  //反Z
		if (s == 0)
		{
			s11 = 210; s12 = 30;
			s21 = 230; s22 = 30;
			s31 = 230; s32 = 10;
			s41 = 250; s42 = 10;
			break;
		}
		else
		{
			s11 = 210; s12 = 10;
			s21 = 210; s22 = 30;
			s31 = 230; s32 = 30;
			s41 = 230; s42 = 50;
			break;
		}

	case 4:  //L
		if (s == 0)
		{
			s11 = 210; s12 = 10;
			s21 = 210; s22 = 30;
			s31 = 210; s32 = 50;
			s41 = 230; s42 = 50;
			break;
		}
		else if (s == 1)
		{
			s11 = 210; s12 = 10;
			s21 = 230; s22 = 10;
			s31 = 250; s32 = 10;
			s41 = 210; s42 = 30;
			break;
		}
		else if (s == 2)
		{
			s11 = 210; s12 = 10;
			s21 = 230; s22 = 10;
			s31 = 230; s32 = 30;
			s41 = 230; s42 = 50;
			break;
		}
		else if (s == 3)
		{
			s11 = 210; s12 = 30;
			s21 = 230; s22 = 30;
			s31 = 250; s32 = 30;
			s41 = 250; s42 = 10;
			break;
		}

	case 5:  //反L  
		if (s == 0)
		{
			s11 = 210; s12 = 50;
			s21 = 230; s22 = 10;
			s31 = 230; s32 = 30;
			s41 = 230; s42 = 50;
			break;
		}
		else if (s == 1)
		{
			s11 = 210; s12 = 10;
			s21 = 210; s22 = 30;
			s31 = 230; s32 = 30;
			s41 = 250; s42 = 30;
			break;
		}
		else if (s == 2)
		{
			s11 = 210; s12 = 10;
			s21 = 210; s22 = 30;
			s31 = 210; s32 = 50;
			s41 = 230; s42 = 10;
			break;
		}
		else if (s == 3)
		{
			s11 = 210; s12 = 10;
			s21 = 230; s22 = 10;
			s31 = 250; s32 = 10;
			s41 = 250; s42 = 30;
			break;
		}

	case 6:  //T
		if (s == 0)
		{
			s11 = 210; s12 = 10;
			s21 = 230; s22 = 10;
			s31 = 250; s32 = 10;
			s41 = 230; s42 = 30;
			break;
		}
		else if (s == 1)
		{
			s11 = 210; s12 = 30;
			s21 = 230; s22 = 10;
			s31 = 230; s32 = 30;
			s41 = 230; s42 = 50;
			break;
		}
		else if (s == 2)
		{
			s11 = 210; s12 = 30;
			s21 = 230; s22 = 30;
			s31 = 250; s32 = 30;
			s41 = 230; s42 = 10;
			break;
		}
		else if (s == 3)
		{
			s11 = 210; s12 = 10;
			s21 = 210; s22 = 30;
			s31 = 210; s32 = 50;
			s41 = 230; s42 = 30;
			break;
		}

	default:
		s11 = s12 = s21 = s22 = s31 = s32 = s41 = s42 = 0;
	}
	square.s1[0] = s11 + x; square.s1[1] = s12 + y;
	square.s2[0] = s21 + x; square.s2[1] = s22 + y;
	square.s3[0] = s31 + x; square.s3[1] = s32 + y;
	square.s4[0] = s41 + x; square.s4[1] = s42 + y;
	return square;
}

void Tetris::spin()
{
	state++;
	switch (type)
	{
	case 0:
		return;
	case 1:
	case 2:
	case 3:
		state %= 2;
		break;
	case 4:
	case 5:
	case 6: 
		state %= 4;
		break;
	}
	square = creat(type, state, x_offset, y_offset);
}

void Tetris::set_offset(int x, int y)
{
	x_offset = x;
	y_offset = y;
	square = creat(type, state, x_offset, y_offset);
}

void Tetris::right_move(int x)
{
	x_offset += x;
	square = creat(type, state, x_offset, y_offset);
}

void Tetris::down_move(int y)
{
	y_offset += y;
	square = creat(type, state, x_offset, y_offset);
}

int Tetris::getXCoord(int n)
{
	switch (n)
	{
	case 0:
		return square.s1[0];
		break;
	case 1:
		return square.s2[0];
		break;
	case 2:
		return square.s3[0];
		break;
	case 3:
		return square.s4[0];
		break;
	default:
		break;
	}
}

int Tetris::getYCoord(int n)
{
	switch (n)
	{
	case 0:
		return square.s1[1];
		break;
	case 1:
		return square.s2[1];
		break;
	case 2:
		return square.s3[1];
		break;
	case 3:
		return square.s4[1];
		break;
	default:
		break;
	}
}

void Tetris::one_down_move(int n,int y)
{
	switch (n)
	{
	case 0:
		square.s1[1] += y;
		break;
	case 1:
		square.s2[1] += y;
		break;
	case 2:
		square.s3[1] += y;
		break;
	case 3:
		square.s4[1] += y;
		break;
	default:
		break;
	}
}

int Tetris::trans_to_yindex(int n)
{
	int y;
	switch (n)
	{
	case 0:
		y = square.s1[1];
		break;
	case 1:
		y = square.s2[1];
		break;
	case 2:
		y = square.s3[1];
		break;
	case 3:
		y = square.s4[1];
		break;
	default:
		break;
	}
	if (y < 670 && y > 20)
		return (670 - y) / 20;
	else
		return 0;
}

int Tetris::trans_to_xindex(int n)
{
	int x;
	switch (n)
	{
	case 0:
		x = square.s1[0];
		break;
	case 1:
		x = square.s2[0];
		break;
	case 2:
		x = square.s3[0];
		break;
	case 3:
		x = square.s4[0];
		break;
	default:
		break;
	}
	if (x > 30 && x <= 400)
		return (x - 30) / 20;
	else
		return 0;
}

int Tetris::check_iswhich(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		if (getXCoord(i) == x && getYCoord(i) == y)
			return i;
	}
	return -1;
}

void Tetris::set_coord_to_zero(int n) 
{
	switch (n)
	{
	case 0:
		square.s1[0] = 0;
		square.s1[1] = 0;
		break;

	case 1:
		square.s2[0] = 0;
		square.s2[1] = 0;
		break;

	case 2:
		square.s3[0] = 0;
		square.s3[1] = 0;
		break;

	case 3:
		square.s4[0] = 0;
		square.s4[1] = 0;
		break;

	default:
		break;
	}
}