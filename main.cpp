#include <conio.h>
#include <iostream>
#include <winbgim.h>
#include <dos.h>
#include <time.h>
#include <stdlib.h>


using namespace std;

#define Negro 0
#define Amarillo 14
#define MAX_BOLITAS 10

class CGrafico
{
 private:
  int VHBG;
  int vhbg;
 public:
  CGrafico()
  {
   initwindow(800,600);
  }
  ~CGrafico()
  {
   closegraph();
  }
};

class CFiguras
{
 private:
  int PX[MAX_BOLITAS];
  int PY[MAX_BOLITAS];
  int RADIO[MAX_BOLITAS];
  int LUGAR[MAX_BOLITAS];
 public:
  CFiguras();
  void Figura1(int,int,int);
  void Figura2(int,int,int);
  void Figura3(int,int,int);
  void Figura4(int,int,int);
  void Figura5(int,int,int);
  void Figura6(int,int,int);
  void Figura7(int,int,int);
  void Figura8(int,int,int);
  void Figura9(int,int,int);
  void Animacion();
  void RotarFigura(int,int,int,int);
};


CFiguras::CFiguras()
{
 setfillstyle(6,9);
 bar(0,0,800,600);
 srand(time(NULL));
 for(int i=0;i<MAX_BOLITAS;i++)
 {
  PX[i]=random(800);
  PY[i]=random(600);
  RADIO[i]=random(40)+10;
  LUGAR[i]=random(10);
 }
};

void CFiguras::Figura1(int x, int y,int radio)
{
 setfillstyle(1,Negro);
 setcolor(Negro);
 sector(x,y,0,360,radio,radio);
 circle(x,y,radio);
 setfillstyle(1,Amarillo);
 setcolor(Amarillo);
 for(int i=0;i<0.8*radio;i++)
  ellipse(x,y,270,90,radio-0.5*i,radio);
}

void CFiguras::Figura2(int x, int y,int radio)
{
 setfillstyle(1,Negro);
 setcolor(Negro);
 sector(x,y,0,360,radio,radio);
 circle(x,y,radio);
 setfillstyle(1,Amarillo);
 setcolor(Amarillo);
 for(int i=0;i<0.8*radio;i++)
  ellipse(x,y,270,90,radio-0.5*i,radio);
}

void CFiguras::Figura3(int x, int y,int radio)
{
 setfillstyle(1,Negro);
 setcolor(Negro);
 sector(x,y,0,360,radio,radio);
 circle(x,y,radio);
 setfillstyle(1,Amarillo);
 setcolor(Amarillo);
 for(int i=0;i<0.8*radio;i++)
  ellipse(x,y,270,90,radio-i,radio);
}

void CFiguras::Figura4(int x, int y,int radio)
{
 setfillstyle(1,Amarillo);
 setcolor(Amarillo);
 sector(x,y,0,360,radio,radio);
 circle(x,y,radio);
 setfillstyle(1,Amarillo);
 setcolor(Negro);
 for(int i=0;i<0.8*radio;i++)
  ellipse(x,y,90,270,radio-0.5*i,radio);
}

void CFiguras::Figura5(int x, int y,int radio)
{
 setfillstyle(1,Amarillo);
 setcolor(Amarillo);
 sector(x,y,0,360,radio,radio);
 circle(x,y,radio);
 setfillstyle(1,Amarillo);
 setcolor(Negro);
 circle(x,y,radio);
}

void CFiguras::Figura6(int x, int y,int radio)
{
 setfillstyle(1,Amarillo);
 setcolor(Amarillo);
 sector(x,y,0,360,radio,radio);
 circle(x,y,radio);
 setfillstyle(1,Negro);
 setcolor(Negro);
 for(int i=0;i<0.8*radio;i++)
  ellipse(x,y,270,90,radio-0.5*i,radio);
}

void CFiguras::Figura7(int x, int y,int radio)
{
 setfillstyle(1,Amarillo);
 setcolor(Amarillo);
 sector(x,y,0,360,radio,radio);
 circle(x,y,radio);
 setfillstyle(1,Negro);
 setcolor(Negro);
 for(int i=0;i<0.8*radio;i++)
  ellipse(x,y,270,90,radio-i,radio);
}

void CFiguras::Figura8(int x, int y,int radio)
{
 setfillstyle(5,Negro);
 setcolor(Negro);
 sector(x,y,0,360,radio,radio);
 circle(x,y,radio);
 setfillstyle(1,Negro);
 setcolor(Amarillo);
 for(int i=0;i<0.8*radio;i++)
  ellipse(x,y,90,270,radio-0.5*i,radio);
}

void CFiguras::Figura9(int x, int y,int radio)
{
 setfillstyle(1,Negro);
 setcolor(Negro);
 sector(x,y,0,360,radio,radio);
 circle(x,y,radio);
 setfillstyle(1,Negro);
 setcolor(Amarillo);
 for(int i=0;i<0.8*radio;i++)
  ellipse(x,y,90,200,radio-0.5*i,radio);
}
void CFiguras::RotarFigura(int x, int y,int pos,int radio)
{
 switch(pos)
 {
  case 1:Figura1(x,y,radio);break;
  case 2:Figura1(x,y,radio);break;
  case 3:Figura1(x,y,radio);break;
  case 4:Figura1(x,y,radio);break;
  case 5:Figura1(x,y,radio);break;
  case 6:Figura1(x,y,radio);break;
  case 7:Figura1(x,y,radio);break;
  case 8:Figura1(x,y,radio);break;
  case 9:Figura1(x,y,radio);break;
 }
}

void CFiguras::Animacion()
{
 int i;
 while(!kbhit())
 {
  for(i=0;i<MAX_BOLITAS;i++)
   RotarFigura(PX[i],PY[i],LUGAR[i],RADIO[i]);

  for(i=0;i<MAX_BOLITAS;i++)
   LUGAR[i]++;

  for(i=0;i<MAX_BOLITAS;i++)
   if(LUGAR[i]==10)
    LUGAR[i]=1;
 }
}
 void mover(){


 }
int main()
{
 CGrafico G;
 CFiguras *F;
 F=new CFiguras;
 F->Animacion();
 getch();
 return 0;
}
