#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<iostream.h>
static int tx,ty,sx=20,sy,tcnt,cx,cy,scx,scy;
static int py=300;
int temp;
int w=1;
void drawdino()
{
	rectangle(25,py,65,py+50);
	circle(45,py-20,20);
	putpixel(35,py-25,15);
	putpixel(55,py-25,15);
	line(45,py-21,45,py-18);
	line(65,py,80,py+20);
	line(25,py,10,py+20);
	ellipse(45,py-15,180,360,10,5);
	if(py>=300)
	{
	if(w==0)
	{
	line(45,py+50,65,py+75);
	line(45,py+50,35,py+75);
	w=1;
	}
	else if(w==1)
	{
	line(45,py+50,55,py+75);
	line(45,py+50,25,py+75);
	w=0;
	}
	}
	else
	{
	line(45,py+50,65,py+75);
	line(45,py+50,25,py+75);
	}
}
void drawcloud()
{
	ellipse(cx,cy,0,360,scx,scy);
}
void drawplatform()
{
	line(0,375,800,375);
	for(int i=0;i<50;i++)
	{
		int x,y;
		x=rand() % 800;
		y=rand() % 20 + 376;
		putpixel(x,y,15);
	}
}
void drawtree()
{
	if(tcnt==0)
		rectangle(tx,ty+sy,tx+sx,ty+75);
	if(tcnt==1)
	{
	       rectangle(tx,ty+sy,tx+sx,ty+75);
	       rectangle(tx+sx,ty+sy+temp,tx+2*sx,ty+75);
	}
}
int main()
{
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
tx=400;
int del=100;
settextstyle(0,0,2);
outtextxy(0,150,"Press space to jump,esc to exit");
delay(5000);
cleardevice();
outtextxy(0,150,"Press 1 to autoplay,anything else to play");
char autoplay=getch();
int score=0;
tcnt=0;
char a;
cx=200;
cy=100;
scx=50;
scy=20;
while(1)
{

	cleardevice();
	if(kbhit())
		a=getch();
	if(a==27)
	{
		cleardevice();
		break;
	}
	if((a==32 && py>=260) || (tx<=90 && tx>=70 && autoplay=='1'))
	{
		py=150;
	}
	a=56;
	char sc[25];
	itoa(score,sc,10);
	outtextxy(150,400,"Score:");
	outtextxy(350,400,sc);
	drawdino();
	drawplatform();
	tx=tx-10;
	cx=cx-10;
	if(py<300)
	{
		py=py+8;
	}
	ty=300;
	if(tx<=65 && tx>=25 && (py+75)>=ty)
	{
		cleardevice();
		outtextxy(200,200,"GAME OVER");
		delay(5000);
		break;
	}
	if(tx<=0)
	{
		score++;
		tx=rand()%100 + 300;
		sx=rand()%20 + 15;
		sy=rand()%25 + 15;
		temp=rand()%20;
		tcnt=rand()%2;

	}
	if(cx<=0)
	{
		cx=rand()%350 + 200;
		cy=rand()%50 + 50;
		scx=rand()%20 + 50;
		scy=rand()%20 + 20;
	}
	drawtree();
	drawcloud();
	delay(del);
}
closegraph();
return 0;
}