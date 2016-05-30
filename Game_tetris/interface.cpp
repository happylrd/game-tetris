#include "interface.h"
#include"graphics.h"
#include"tetris.h"

int trans_to_xcoord(int j)
{
	return 30 + 20 * j;
}

int trans_to_ycoord(int i)
{
	return 670 - 20 * i;
}

Interface::Interface()
{

	int i, j;
	sc = new int*[33];
	for (i = 0; i < 33; i++)
		sc[i] = new int[20];

	for (i = 0; i < 33; i++)
	{
		for (j = 0; j < 20; j++)
			sc[i][j] = 0;
	}
	for (i = 0; i < 33; i++)
	{
		sc[i][0] = 1;
	}
	for (i = 0; i < 33; i++)
	{
		sc[i][19] = 1;
	}
	for (i = 0; i < 20; i++){
		sc[0][i] = 1;
	}

	front = 0;
	rear = -1;
	score = 0;
	canadd = true;
	is_over = false;
}

void Interface::add_square(Tetris& te)
{
	rear++;
	rear %= 400;
	ArrayTe[rear] = te;
	ArrayTe[rear].set_offset(20, 20);  
}

void Interface::draw()
{
	int i, r = rear;
	if (rear == -1)
		return;

	for (i = front; i < r; i++)
	{  
		int k = (i < 400) ? i : i % 400;
		setfillcolor(EGERGB(ArrayTe[k].getR(), ArrayTe[k].getG(), ArrayTe[k].getB()));
		for (int j = 0; j < 4; j++)
		{
			if (sc[ArrayTe[i].trans_to_yindex(j)][ArrayTe[i].trans_to_xindex(j)] && ArrayTe[i].trans_to_yindex(j) && ArrayTe[i].trans_to_xindex(j))  //等于1才画
			{
				bar(ArrayTe[k].getXCoord(j) - 10, ArrayTe[k].getYCoord(j) - 10, ArrayTe[k].getXCoord(j) + 10, ArrayTe[k].getYCoord(j) + 10);
				setcolor(WHITE);
				rectangle(ArrayTe[k].getXCoord(j) - 10, ArrayTe[k].getYCoord(j) - 10, ArrayTe[k].getXCoord(j) + 10, ArrayTe[k].getYCoord(j) + 10);
			}
		}
	}
	for (int j = 0; j < 4; j++)  
	{   
		setfillcolor(EGERGB(ArrayTe[i].getR(), ArrayTe[i].getG(), ArrayTe[i].getB()));
		if (ArrayTe[i].getYCoord(j) >= 80)
		{
			bar(ArrayTe[i].getXCoord(j) - 10, ArrayTe[i].getYCoord(j) - 10, ArrayTe[i].getXCoord(j) + 10, ArrayTe[i].getYCoord(j) + 10);
			setcolor(WHITE);
			rectangle(ArrayTe[i].getXCoord(j) - 10, ArrayTe[i].getYCoord(j) - 10, ArrayTe[i].getXCoord(j) + 10, ArrayTe[i].getYCoord(j) + 10);
		}
	}

}

void Interface::draw(Tetris next)
{
	int j;
	next.set_offset(270, 110); 
	setfillcolor(EGERGB(next.getR(), next.getG(), next.getB()));
	for (j = 0; j < 4; j++)
	{
		bar(next.getXCoord(j) - 10, next.getYCoord(j) - 10, next.getXCoord(j) + 10, next.getYCoord(j) + 10);
		setcolor(WHITE);
		rectangle(next.getXCoord(j) - 10, next.getYCoord(j) - 10, next.getXCoord(j) + 10, next.getYCoord(j) + 10);
	}
}

void Interface::update()
{
	int release = 0, r[4] = { 0 };
	for (int i = 1; i < 30; i++)  //1-29从下往上遍历游戏界面y轴
	{
		bool can_remove = true;
		for (int j = 1; j < 19; j++)  //1-18 从左往右遍历游戏界面x轴
		{
			if (!sc[i][j])  
			{
				can_remove = false;
				break;
			}
		}
		if (can_remove)  
		{
			r[release] = i;   //i表示从下往上第i行
			release++;        // 总共可以消release行
		}
	}

	//   加分
	switch (release)
	{
	case 1:
		score += 100;

		break;
	case 2:
		score += 200;

		break;
	case 3:
		score += 400;

		break;
	case 4:
		score += 800;

		break;
	default:
		score += 0;
		break;
	}



	while (release)
	{
		for (int i = 1; i < 30; i++) 
		{
			for (int j = 1; j < 19; j++)
				sc[i][j] = 0;
		}
		
		int y = trans_to_ycoord(r[release-1]);
		for (int j = 1; j < 19; j++)
		{
			int x = trans_to_xcoord(j);
			for (int i = front; i < rear; i++)
			{
				int n = ArrayTe[i].check_iswhich(x, y);  
				if (n != -1)
				{
					ArrayTe[i].set_coord_to_zero(n);  //把被消行的小方块坐标全部置为(0, 0)
					break;
				}
			}
		}
		

		for (int i = front; i <= rear; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (ArrayTe[i].getYCoord(j) < y)
					ArrayTe[i].one_down_move(j);
			}
		}


		//加循环
		
		for (int k = front; k < rear; k++)
		{
			for (int i = 0; i < 4; i++)
			{
				if (ArrayTe[k].trans_to_yindex(i)>0 && ArrayTe[k].trans_to_yindex(i) < 30)
					sc[ArrayTe[k].trans_to_yindex(i)][ArrayTe[k].trans_to_xindex(i)] = 1;
			}
		}

		release--;    //可消行数减一
	}


	bool canFall = true;
	for (int i = 0; i < 4; i++)
	{
		if (ArrayTe[rear].trans_to_yindex(i) > 0)
		if (sc[ArrayTe[rear].trans_to_yindex(i) - 1][ArrayTe[rear].trans_to_xindex(i)])
		{
			canFall = false;
			break;
		}
	}
	if (canFall)
	{
		ArrayTe[rear].down_move();
	}
	else
	{                                          
		for (int i = 0; i < 4; i++)
		{                    //把对应数组值变成1
			sc[ArrayTe[rear].trans_to_yindex(i)][ArrayTe[rear].trans_to_xindex(i)] = 1;
		}
		
		
		for (int j = 1; j < 19; j++)
		{
			if (sc[30][j] == 1)  //判断是否 Gameover
			{
				is_over = true;
				canadd = false;
				break;
			}
		}
		
		//添加下一个方块
		canadd = true;
	}

}

void Interface::leftMove()
{
	Tetris copy = ArrayTe[rear];
	copy.right_move(-20);
	bool canMove = true;
	for (int i = 0; i < 4; i++)
	{
		if (sc[copy.trans_to_yindex(i)][copy.trans_to_xindex(i)])  
		{
			canMove = false;
			break;
		}
	}
	if (canMove)
		ArrayTe[rear].right_move(-20);
}

void Interface::rightMove()
{
	Tetris copy = ArrayTe[rear];
	copy.right_move(20);
	bool canMove = true;
	for (int i = 0; i < 4; i++)
	{
		if (sc[copy.trans_to_yindex(i)][copy.trans_to_xindex(i)]){
			canMove = false;
			break;
		}
	}
	if (canMove)
		ArrayTe[rear].right_move(20);
}

void Interface::rotate()
{
	Tetris copy = ArrayTe[rear];
	copy.spin();
	bool canMove = true;
	for (int i = 0; i < 4; i++)
	{
		if (sc[copy.trans_to_yindex(i)][copy.trans_to_xindex(i)])
		{
			canMove = false;
			break;
		}
	}
	if (canMove)
		ArrayTe[rear].spin();
}

void Interface::downMove()  
{
	bool canFall = true;

	for (int i = 0; i < 4; i++)
	{
		if (sc[ArrayTe[rear].trans_to_yindex(i) - 1][ArrayTe[rear].trans_to_xindex(i)])
		{
			canFall = false;
			break;
		}
	}

	if (canFall == true)
		ArrayTe[rear].down_move();   
}

Interface::~Interface()
{
	int i;
	for (i = 0; i < 33; i++)
	{
		delete[] sc[i];
	}
	delete[] sc;
}
