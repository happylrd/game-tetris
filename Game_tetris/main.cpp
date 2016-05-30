#include <fstream>
#include <cstdlib>
#include"graphics.h"
#include"tetris.h"
#include "interface.h"
#include "startmovie.h"

#include <windows.h>  
#include "mmsystem.h"//导入声音头文件 
#pragma comment(lib,"winmm.lib")//导入声音头文件库 

bool newgame = true;
int speed = 6;
int top_ten[10];
char top[10][10];

void layout();
void start_menu();
void play_game();
void hero_list();
void trouble();

int main()
{
	layout();
	return 0;
}

void layout()
{
	initgraph(1200, 600);
	setcaption("俄罗斯方块");

	start_movie();
	delay_ms(3000);
	cleardevice();

	setbkcolor(EGERGB(255, 255, 255));
	start_menu();
}

void start_menu()
{
	PlaySound("..\\music\\startmenu.wav", NULL, SND_ASYNC | SND_NODEFAULT | SND_FILENAME);
	PIMAGE img_start = newimage();
	getimage(img_start, "..\\img\\startmenu.jpg");
	putimage(0, 0, img_start);

	setbkmode(TRANSPARENT);
	setfontbkcolor(TRANSPARENT, img_start);

	setfont(-30, 0, "楷体");
	setcolor(BLACK);

	xyprintf(210, 150, "开始游戏");
	xyprintf(225, 255, "英雄榜");
	xyprintf(210, 360, "难度选择");
	xyprintf(210, 470, "退出游戏");

	mouse_msg mouse1;
	for (;;)
	{
		mouse1 = getmouse();
		if (!mouse1.is_left()) continue;
		else if ((mouse1.x <= 330 && mouse1.x >= 210) && (mouse1.y <= 180 && mouse1.y >= 150))
		{
			closegraph();
			initgraph(600, 700);
			play_game();
			break;
		}
		else if ((mouse1.x <= 345 && mouse1.x >= 225) && (mouse1.y <= 285 && mouse1.y >= 255))
		{
			hero_list();

		}
		else if ((mouse1.x <= 330 && mouse1.x >= 210) && (mouse1.y <= 390 && mouse1.y >= 360))
		{
			trouble();
			closegraph();
			initgraph(600, 700);
			play_game();
			break;
		}
		else if ((mouse1.x <= 330 && mouse1.x >= 210) && (mouse1.y <= 500 && mouse1.y >= 470))
		{
			delay_ms(500);
			exit(EXIT_FAILURE);
		}

	}

	delimage(img_start);
	closegraph();

}

void play_game()
{
	std::ifstream list_("list.txt");
	std::ifstream name_("name.txt");
	for (int i = 0; i < 10; i++)
	{
		list_ >> top_ten[i];
		name_ >> top[i];
	}

	while (newgame)
	{
		PlaySound("..\\music\\playing.wav", NULL, SND_ASYNC | SND_NODEFAULT | SND_FILENAME);
		randomize();
		bool is_pause = false;
		Interface * new_interface = new Interface();
		newgame = false;
		Tetris now(random(7), random(4));

		for (; is_run(); delay_fps(speed))
		{
			if (newgame)
				break;
			if (new_interface->can_add())
			{
				new_interface->add_square(now);
				new_interface->close_add();
				now = Tetris(random(7), random(4));
			}
			if (kbhit())
			{
				int k = getch();
				if (k == 'd' || k == 'D')
				{
					new_interface->rightMove();
				}
				else if (k == 'a' || k == 'A')
				{
					new_interface->leftMove();
				}
				else if (k == 's' || k == 'S')
				{
					new_interface->downMove();
				}
				if (k == 'w' || k == 'W')
				{
					new_interface->rotate();
				}
			}

			if (!is_pause)
				new_interface->update();

			cleardevice();

			setcolor(EGERGB(148,0,211));


			PIMAGE img_gameback = newimage();
			getimage(img_gameback, "..\\img\\gameback.jpg");

			PIMAGE img_poolback = newimage();
			getimage(img_poolback, "..\\img\\poolback.jpg");

			putimage(0, 0, img_gameback);
			putimage_alphablend(img_poolback, img_gameback, 0, 0, 128);
			putimage(40, 80, img_poolback);

			PIMAGE img_score = newimage();
			getimage(img_score, "..\\img\\score.jpg");
			putimage_alphablend(img_score, img_gameback, 0, 0, 128);
			putimage(440, 250, img_score);

			PIMAGE img_pause = newimage();
			getimage(img_pause, "..\\img\\pause.png");
			putimage(480, 610, img_pause);

			setbkmode(TRANSPARENT);
			setfontbkcolor(TRANSPARENT, img_gameback);

			rectangle(40, 80, 400, 660);
			rectangle(450, 100, 550, 200);

			setfont(-20, 0, "楷体");
			xyprintf(450, 70, "Next :");
			xyprintf(450, 260, "当前分数:");
			xyprintf(450, 340, "当前称谓:");
			xyprintf(520, 0, "结束游戏");

			xyprintf(490, 295, "%d", new_interface->get_score());

			if (new_interface->get_score()<200 && new_interface->get_score() >= 100)
				xyprintf(470, 370, "初出茅庐");
			else if (new_interface->get_score() < 500 && new_interface->get_score() >= 200)
				xyprintf(470, 370, "牛刀小试");
			else if (new_interface->get_score()<1000 && new_interface->get_score() >= 500)
				xyprintf(470, 370, "登堂入室");
			else if (new_interface->get_score()<2000 && new_interface->get_score() >= 1000)
				xyprintf(470, 370, "鹤立鸡群");
			else if (new_interface->get_score()<3000 && new_interface->get_score() >= 2000)
				xyprintf(470, 370, "驾轻就熟");
			else if (new_interface->get_score()<5000 && new_interface->get_score() >= 3000)
				xyprintf(470, 370, "登峰造极");
			else if (new_interface->get_score()<10000 && new_interface->get_score() >= 5000)
				xyprintf(470, 370, "技冠群雄");
			else if (new_interface->get_score()<50000 && new_interface->get_score() >= 10000)
				xyprintf(470, 370, "震古烁今");
			else if (new_interface->get_score()<100000 && new_interface->get_score() >= 50000)
				xyprintf(470, 370, "超凡入圣");
			else if (new_interface->get_score()<1000000 && new_interface->get_score() >= 100000)
				xyprintf(470, 370, "天人合一");
			else if (new_interface->get_score() >= 1000000)
				xyprintf(470, 370, "羽化登仙");

			new_interface->draw();
			new_interface->draw(now);

			while (mousemsg())
			{
				mouse_msg r;
				r = getmouse();
				if (!r.is_down()) continue;
				if ((r.x <= 520 && r.x >= 480) && (r.y <= 665 && r.y >= 610))
				{
					setcolor(EGERGB(255,0,255));
					xyprintf(440, 670, "按任意键继续");
					getch();
					break;
				}
				else if ((r.x <= 600 && r.x >= 520) && (r.y <= 20 && r.y >= 0))
				{
					delay_ms(500);
					exit(EXIT_FAILURE);
					break;
				}
			}

			if (new_interface->is_gameover())
				break;

			delimage(img_gameback);
			delimage(img_poolback);
			delimage(img_pause);
			delimage(img_score);
		}

		if (new_interface->is_gameover())
		{

			PlaySound("..\\music\\gameover.wav", NULL, SND_ASYNC | SND_NODEFAULT | SND_FILENAME);
			PIMAGE img_over = newimage();
			getimage(img_over, "..\\img\\gameover.jpg");
			putimage(0, 0, img_over);

			if (new_interface->get_score() < top_ten[9])
			{

				setbkmode(TRANSPARENT);
				setfontbkcolor(TRANSPARENT, img_over);

				setcolor(BLACK);
				xyprintf(240, 320, "按 R 一雪前耻");
				xyprintf(225, 360, "按任意键返回菜单 ");
				char c;
				c = getch();
				if (c == 'r' || c == 'R')
					newgame = true;
				else
				{
					closegraph();
					initgraph(1200, 600);
					start_menu();
				}
			}
			else
			{
				std::ofstream list("list.txt");
				std::ofstream name("name.txt");
				for (int i = 0; i < 10; i++)
				{
					if (new_interface->get_score() >= top_ten[i])
					{
						for (int j = 0; j < 9 - i; j++)
						{
							top_ten[9 - j] = top_ten[8 - j];
							for (int k = 0; k < 10; k++)
							{
								top[9 - j][k] = top[8 - j][k];
							}
						}
						top_ten[i] = new_interface->get_score();
						getString(top[i], 10, "请输入你的名字");
						break;
					}
				}
				for (int i = 0; i < 10; i++)
				{
					list << top_ten[i] << std::endl;
					name << top[i] << std::endl;
				}
				list.close();
				name.close();


				std::ofstream rank("rank.txt");
				int r_5[5] = { 0 };
				for (int i = 0; i < 5; i++)
				{
					r_5[5 - i] = r_5[4 - i];
				}
				r_5[0] = new_interface->get_score();
				for (int i = 0; i < 5; i++){
					rank << r_5[i] << std::endl;
				}
				rank.close();
			}

			delimage(img_over);
		}

		delete new_interface;
	}
}

void hero_list()
{
	cleardevice();

	PIMAGE img_htback = newimage();
	getimage(img_htback, "..\\img\\htback.jpg");

	PIMAGE img_hthalf = newimage();
	getimage(img_hthalf, "..\\img\\hthalf.jpg");

	putimage_alphablend(img_hthalf, img_htback, 0, 0, 100);
	putimage(0, 0, img_hthalf);

	setbkmode(TRANSPARENT);
	setfontbkcolor(TRANSPARENT, img_hthalf);



	xyprintf(255, 50, "英雄榜");

	setcolor(BLACK);    //以后删掉
	line(600, 0, 600, 600);

	using namespace std;
	ifstream list("list.txt");
	ifstream name("name.txt");
	int scores[10];
	char name_[10][10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		list >> scores[i];
		name >> name_[i];
		xyprintf(60, 100 + 40 * i, "第%d名", i + 1);
		xyprintf(230, 100 + 40 * i, "%s", name_[i]);
		xyprintf(400, 100 + 40 * i, "%d", scores[i]);
	}

	xyprintf(800, 20, "最近⑤次的成绩");
	std::ifstream rank("rank.txt");
	int score[5] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		rank >> score[i];
	}
	for (int i = 0; i < 5; i++)
	{
		xyprintf(700 + 100 * i, (600 - score[i] / 100) - 30, "%d ", score[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		line(700 + 100 * i, 600 - (score[i] / 100), 800 + 100 * i, 600 - score[i + 1] / 100);
	}

	list.close();
	name.close();
	rank.close();

	for (;;)
	{
		int key_list = getch();
		if (key_list == 'B' || key_list == 'b')
		{
			start_menu();
			break;
		}
	}

	delimage(img_htback);
	delimage(img_hthalf);
}

void trouble()
{
	cleardevice();

	PIMAGE img_htback = newimage();
	getimage(img_htback, "..\\img\\htback.jpg");

	PIMAGE img_hthalf = newimage();
	getimage(img_hthalf, "..\\img\\hthalf.jpg");

	putimage_alphablend(img_hthalf, img_htback, 0, 0, 100);
	putimage(0, 0, img_hthalf);

	setbkmode(TRANSPARENT);
	setfontbkcolor(TRANSPARENT, img_hthalf);

	xyprintf(400, 240, "简单（让你感受下什么叫乌龟）");
	xyprintf(400, 280, "普通（如果你是正常人可以来这个）");
	xyprintf(400, 320, "冒险（新手慎入）");
	xyprintf(400, 360, "末日（想死那就来吧）");
	mouse_msg mouse1;
	for (;;)
	{
		mouse1 = getmouse();
		if (!mouse1.is_right()) continue;
		else if ((mouse1.x <= 790 && mouse1.x >= 400) && (mouse1.y <= 270 && mouse1.y >= 240))
		{
			speed = 4;
			break;
		}
		else if ((mouse1.x <= 850 && mouse1.x >= 400) && (mouse1.y <= 310 && mouse1.y >= 280))
		{
			speed = 6;
			break;
		}
		else if ((mouse1.x <= 610 && mouse1.x >= 400) && (mouse1.y <= 350 && mouse1.y >= 320))
		{
			speed = 8;
			break;
		}
		else if ((mouse1.x <= 670 && mouse1.x >= 400) && (mouse1.y <= 390 && mouse1.y >= 360)){
			speed = 16;
			break;
		}

	}

	delimage(img_htback);
	delimage(img_hthalf);
}

