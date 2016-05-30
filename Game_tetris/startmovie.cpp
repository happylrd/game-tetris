#include "graphics.h"

void logo()
{
	int alpha = 0;
	int time1 = 0;
	int time2 = 250;
	PIMAGE img_logo = newimage();
	getimage(img_logo, "..\\img\\logo.jpg");
	setbkcolor(EGERGB(255, 255, 255));

	PlaySound("..\\music\\aztecs.wav", NULL, SND_ASYNC | SND_NODEFAULT);

	do{
		delay_fps(90);
		alpha = alpha + 1;
		cleardevice();
		putimage_alphablend(NULL, img_logo, 250, 0, alpha, 0);
		time1++;
	} while (time1 <= 250);

	do{
		delay_fps(90);
		alpha = alpha - 1;
		cleardevice();
		putimage_alphablend(NULL, img_logo, 250, 0, alpha, 0);
		time2--;
	} while (time2 <= 250 && time2 >= 0);
	delimage(img_logo);
}

void e()
{
	int x = 0;

	PIMAGE e1 = newimage();
	getimage(e1, "..\\img\\e1.png");
	PIMAGE e2 = newimage();
	getimage(e2, "..\\img\\e2.png");
	PIMAGE e3 = newimage();
	getimage(e3, "..\\img\\e3.png");
	PIMAGE e4 = newimage();
	getimage(e4, "..\\img\\e4.png");
	PIMAGE e5 = newimage();
	getimage(e5, "..\\img\\e5.png");
	PIMAGE e6 = newimage();
	getimage(e6, "..\\img\\e6.png");
	PIMAGE e7 = newimage();
	getimage(e7, "..\\img\\e7.png");

	PlaySound("..\\music\\e.wav", NULL, SND_ASYNC | SND_NODEFAULT);
	do{
		delay_ms(0);
		x = x + 4;
		cleardevice();
		putimage_transparent(NULL, e1, x, 130, 0);
	} while (x <= 160);

	delay_fps(50);
	putimage_transparent(NULL, e2, 160, 130, 0);
	delay_ms(5);
	cleardevice();

	delay_fps(50);
	putimage_transparent(NULL, e3, 160, 130, 0);
	delay_ms(5);
	cleardevice();

	delay_fps(90);
	putimage_transparent(NULL, e4, 160, 130, 0);
	delay_ms(5);
	cleardevice();

	delay_fps(50);
	putimage_transparent(NULL, e5, 160, 130, 0);
	delay_ms(5);
	cleardevice();

	delay_fps(50);
	putimage_transparent(NULL, e6, 160, 130, BLACK);
	delay_ms(5);
	cleardevice();

	delay_fps(50);
	putimage_transparent(NULL, e7, 160, 130, BLACK);

	delimage(e1);
	delimage(e2);
	delimage(e3);
	delimage(e4);
	delimage(e5);
	delimage(e6);
	delimage(e7);
}

void luo()
{
	PIMAGE l1 = newimage();
	getimage(l1, "..\\img\\l1.png");
	PIMAGE l2 = newimage();
	getimage(l2, "..\\img\\l2.png");
	PIMAGE l3 = newimage();
	getimage(l3, "..\\img\\l3.png");
	PIMAGE l4 = newimage();
	getimage(l4, "..\\img\\l4.png");
	PIMAGE l5 = newimage();
	getimage(l5, "..\\img\\l5.png");
	PIMAGE l6 = newimage();
	getimage(l6, "..\\img\\l6.png");
	PIMAGE l7 = newimage();
	getimage(l7, "..\\img\\l7.png");
	PIMAGE l8 = newimage();
	getimage(l8, "..\\img\\l8.png");
	PIMAGE e7 = newimage();
	getimage(e7, "..\\img\\e7.png");

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l8, 140, 20, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l7, 180, 40, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l6, 220, 60, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l5, 260, 80, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l4, 300, 100, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);

	PlaySound("..\\music\\shoot.wav", NULL, SND_ASYNC | SND_NODEFAULT);
	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l3, 340, 120, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l2, 380, 140, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l1, 420, 160, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);

	delimage(l1);
	delimage(l2);
	delimage(l3);
	delimage(l4);
	delimage(l5);
	delimage(l6);
	delimage(l7);
	delimage(l8);
	delimage(e7);
}

void si()
{
	PIMAGE s1 = newimage();
	getimage(s1, "..\\img\\s1.png");
	PIMAGE s2 = newimage();
	getimage(s2, "..\\img\\s2.png");
	PIMAGE s3 = newimage();
	getimage(s3, "..\\img\\s3.png");
	PIMAGE s4 = newimage();
	getimage(s4, "..\\img\\s4.png");
	PIMAGE s5 = newimage();
	getimage(s5, "..\\img\\s5.png");
	PIMAGE s6 = newimage();
	getimage(s6, "..\\img\\s6.png");
	PIMAGE s7 = newimage();
	getimage(s7, "..\\img\\s7.png");
	PIMAGE s8 = newimage();
	getimage(s8, "..\\img\\s8.png");
	PIMAGE e7 = newimage();
	getimage(e7, "..\\img\\e7.png");
	PIMAGE l1 = newimage();
	getimage(l1, "..\\img\\l1.png");

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l1, 420, 160, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);
	putimage_transparent(NULL, s8, 300, 20, 0);

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l1, 420, 160, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);
	putimage_transparent(NULL, s7, 340, 40, 0);

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l1, 420, 160, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);
	putimage_transparent(NULL, s6, 380, 60, 0);

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l1, 420, 160, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);
	putimage_transparent(NULL, s5, 420, 80, 0);

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l1, 420, 160, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);
	putimage_transparent(NULL, s4, 460, 100, 0);

	PlaySound("..\\music\\shoot.wav", NULL, SND_ASYNC | SND_NODEFAULT);
	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l1, 420, 160, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);
	putimage_transparent(NULL, s3, 500, 120, 0);

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l1, 420, 160, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);
	putimage_transparent(NULL, s2, 540, 140, 0);

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l1, 420, 160, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);
	putimage_transparent(NULL, s1, 580, 160, 0);

	delimage(s1);
	delimage(s2);
	delimage(s3);
	delimage(s4);
	delimage(s5);
	delimage(s6);
	delimage(s7);
	delimage(s8);
	delimage(e7);
	delimage(l1);
}

void fang(){
	PIMAGE f1 = newimage();
	getimage(f1, "..\\img\\f1.png");
	PIMAGE f2 = newimage();
	getimage(f2, "..\\img\\f2.png");
	PIMAGE f3 = newimage();
	getimage(f3, "..\\img\\f3.png");
	PIMAGE f4 = newimage();
	getimage(f4, "..\\img\\f4.png");
	PIMAGE f5 = newimage();
	getimage(f5, "..\\img\\f5.png");
	PIMAGE f6 = newimage();
	getimage(f6, "..\\img\\f6.png");
	PIMAGE f7 = newimage();
	getimage(f7, "..\\img\\f7.png");
	PIMAGE f8 = newimage();
	getimage(f8, "..\\img\\f8.png");
	PIMAGE e7 = newimage();
	getimage(e7, "..\\img\\e7.png");
	PIMAGE l1 = newimage();
	getimage(l1, "..\\img\\l1.png");
	PIMAGE s1 = newimage();
	getimage(s1, "..\\img\\s1.png");

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l1, 420, 160, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);
	putimage_transparent(NULL, s1, 580, 160, 0);
	putimage_transparent(NULL, f8, 440, 20, 0);

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l1, 420, 160, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);
	putimage_transparent(NULL, s1, 580, 160, 0);
	putimage_transparent(NULL, f7, 480, 40, 0);

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l1, 420, 160, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);
	putimage_transparent(NULL, s1, 580, 160, 0);
	putimage_transparent(NULL, f6, 520, 60, 0);

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l1, 420, 160, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);
	putimage_transparent(NULL, s1, 580, 160, 0);
	putimage_transparent(NULL, f5, 560, 80, 0);

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l1, 420, 160, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);
	putimage_transparent(NULL, s1, 580, 160, 0);
	putimage_transparent(NULL, f4, 600, 100, 0);

	PlaySound("..\\music\\shoot.wav", NULL, SND_ASYNC | SND_NODEFAULT);
	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l1, 420, 160, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);
	putimage_transparent(NULL, s1, 580, 160, 0);
	putimage_transparent(NULL, f3, 640, 120, 0);

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l1, 420, 160, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);
	putimage_transparent(NULL, s1, 580, 160, 0);
	putimage_transparent(NULL, f2, 680, 140, 0);

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l1, 420, 160, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);
	putimage_transparent(NULL, s1, 580, 160, 0);
	putimage_transparent(NULL, f1, 720, 160, 0);

	delimage(f1);
	delimage(f2);
	delimage(f3);
	delimage(f4);
	delimage(f5);
	delimage(f6);
	delimage(f7);
	delimage(f8);
	delimage(e7);
	delimage(l1);
	delimage(s1);
}

void kuai()
{
	PIMAGE k1 = newimage();
	getimage(k1, "..\\img\\k1.png");
	PIMAGE k2 = newimage();
	getimage(k2, "..\\img\\k2.png");
	PIMAGE k3 = newimage();
	getimage(k3, "..\\img\\k3.png");
	PIMAGE k4 = newimage();
	getimage(k4, "..\\img\\k4.png");
	PIMAGE k5 = newimage();
	getimage(k5, "..\\img\\k5.png");
	PIMAGE k6 = newimage();
	getimage(k6, "..\\img\\k6.png");
	PIMAGE k7 = newimage();
	getimage(k7, "..\\img\\k7.png");
	PIMAGE k8 = newimage();
	getimage(k8, "..\\img\\k8.png");
	PIMAGE e7 = newimage();
	getimage(e7, "..\\img\\e7.png");
	PIMAGE l1 = newimage();
	getimage(l1, "..\\img\\l1.png");
	PIMAGE s1 = newimage();
	getimage(s1, "..\\img\\s1.png");
	PIMAGE f1 = newimage();
	getimage(f1, "..\\img\\f1.png");
	PIMAGE pkq = newimage();
	getimage(pkq, "..\\img\\pkq.png");

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l1, 420, 160, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);
	putimage_transparent(NULL, s1, 580, 160, 0);
	putimage_transparent(NULL, f1, 720, 160, 0);
	putimage_transparent(NULL, k8, 580, 160, 0);

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l1, 420, 160, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);
	putimage_transparent(NULL, s1, 580, 160, 0);
	putimage_transparent(NULL, f1, 720, 160, 0);
	putimage_transparent(NULL, k7, 620, 160, 0);

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l1, 420, 160, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);
	putimage_transparent(NULL, s1, 580, 160, 0);
	putimage_transparent(NULL, f1, 720, 160, 0);
	putimage_transparent(NULL, k6, 660, 160, 0);

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l1, 420, 160, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);
	putimage_transparent(NULL, s1, 580, 160, 0);
	putimage_transparent(NULL, f1, 720, 160, 0);
	putimage_transparent(NULL, k5, 700, 160, 0);

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l1, 420, 160, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);
	putimage_transparent(NULL, s1, 580, 160, 0);
	putimage_transparent(NULL, f1, 720, 160, 0);
	putimage_transparent(NULL, k4, 740, 160, 0);

	PlaySound("..\\music\\shoot.wav", NULL, SND_ASYNC | SND_NODEFAULT);
	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l1, 420, 160, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);
	putimage_transparent(NULL, s1, 580, 160, 0);
	putimage_transparent(NULL, f1, 720, 160, 0);
	putimage_transparent(NULL, k3, 780, 160, 0);

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l1, 420, 160, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);
	putimage_transparent(NULL, s1, 580, 160, 0);
	putimage_transparent(NULL, f1, 720, 160, 0);
	putimage_transparent(NULL, k2, 820, 160, 0);

	delay_fps(45);
	cleardevice();
	putimage_transparent(NULL, l1, 420, 160, 0);
	putimage_transparent(NULL, e7, 160, 130, 0);
	putimage_transparent(NULL, s1, 580, 160, 0);
	putimage_transparent(NULL, f1, 720, 160, 0);
	putimage_transparent(NULL, k1, 860, 160, 0);

	delimage(k1);
	delimage(k2);
	delimage(k3);
	delimage(k4);
	delimage(k5);
	delimage(k6);
	delimage(k7);
	delimage(k8);
	delimage(e7);
	delimage(l1);
	delimage(s1);
}

void pkq()
{
	PIMAGE e7 = newimage();
	getimage(e7, "..\\img\\e7.png");
	PIMAGE l1 = newimage();
	getimage(l1, "..\\img\\l1.png");
	PIMAGE s1 = newimage();
	getimage(s1, "..\\img\\s1.png");
	PIMAGE f1 = newimage();
	getimage(f1, "..\\img\\f1.png");
	PIMAGE pkq = newimage();
	getimage(pkq, "..\\img\\pkq.png");
	PIMAGE k1 = newimage();
	getimage(k1, "..\\img\\k1.png");

	PlaySound("..\\music\\pkq.wav", NULL, SND_ASYNC | SND_NODEFAULT);
	int x = 1200;
	do{
		delay_ms(0);
		x = x - 10;
		cleardevice();
		putimage_transparent(NULL, pkq, x, 20, 0);
		putimage_transparent(NULL, l1, 420, 160, 0);
		putimage_transparent(NULL, e7, 160, 130, 0);
		putimage_transparent(NULL, s1, 580, 160, 0);
		putimage_transparent(NULL, f1, 720, 160, 0);
		putimage_transparent(NULL, k1, 860, 160, 0);
	} while (x >= 820);

	delimage(e7);
	delimage(l1);
	delimage(s1);
	delimage(f1);
	delimage(k1);
	delimage(pkq);
}

void start_movie()
{
	logo();
	delay_ms(0);
	setbkcolor(EGERGB(255, 255, 255));
	e();
	delay_ms(0);
	luo();
	delay_ms(0);
	si();
	delay_ms(0);
	fang();
	delay_ms(0);
	kuai();
	delay_ms(500);
	pkq();
}
