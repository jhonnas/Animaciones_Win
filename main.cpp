#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <graphics.h>
#include <dos.h>

#define Derecha 1000
#define Izquierda 1000

#define tiempo 1

#define ColorPoste 5
#define ColorPlato 10

#define alto 8

#define PXA 200
#define PYA 350

#define PXB PXA+150
#define PYB PYA

#define PXC PXA+300
#define PYC PYA

int n=6;

int PA;
int PB;
int PC;

int POSTEA[12];
int POSTEB[12];
int POSTEC[12];

int PX[12];
int PY[12];
int ANCHO[12];

void ModoGrafico()
{
 int SISTEMAS=DETECT,sistemas;
 initgraph(&SISTEMAS,&sistemas,"");
   // settextstyle(int font, int direction,int font_size);
  settextstyle(10,0,2);
    setcolor(3);
    outtextxy(220,50,".::Torre de Hanoi::.");
    outtextxy(200,380,"Cantidad de platos: 08");
//1
    setcolor(5);
	line(20,20,20,450);
	line(20+2,20,20+2,450);
	line(20-2,20,20-2,450);
	//2
	setcolor(5);
	line(20,20,600,20);
	line(20,20+2,600,20+2);
	line(20,20-2,600,20-2);
	//3
	setcolor(5);
	line(600,20,600,450);
	line(600+2,20,600+2,450);
	line(600-2,20,600-2,450);
	//4
	setcolor(5);
	line(20,450,600,450);
	line(20,450+2,600,450+2);
	line(20,450-2,600,450-2);


}

void DibujarPostes()
{
 setfillstyle(1,ColorPoste);
 bar(PXA-2,PYA,PXA+2,PYA-15*alto);
 bar(PXB-2,PYB,PXB+2,PYB-15*alto);
 bar(PXC-2,PYC,PXC+2,PYC-15*alto);
 setcolor(5);

 line(PXA-3,PYA,PXA-3,PYA-15*alto);
 line(PXA+3,PYA,PXA+3,PYA-15*alto);

 line(PXA-3,PYA,PXA+3,PYA);

 line(PXB-3,PYB,PXB-3,PYB-15*alto);
 line(PXB+3,PYB,PXB+3,PYB-15*alto);

 line(PXB-3,PYB,PXB+3,PYB);

 line(PXC-3,PYC,PXC-3,PYC-15*alto);
 line(PXC+3,PYC,PXC+3,PYC-15*alto);

 line(PXC-3,PYC,PXC+3,PYC);
}

void DibujarPlato(int x,int y,int ancho)
{
 setfillstyle(1,ColorPlato);
 bar(x-ancho/2,y-alto/2,x+ancho/2,y+alto/2);
 setcolor(3);
 rectangle(x-ancho/2,y-alto/2,x+ancho/2,y+alto/2);
}

void BorrarPlato(int x,int y,int ancho)
{
 setfillstyle(1,0);
 bar(x-ancho/2,y-alto/2,x+ancho/2,y+alto/2);

 setcolor(0);
 rectangle(x-ancho/2,y-alto/2,x+ancho/2,y+alto/2);
 setfillstyle(1,ColorPoste);
 bar(x-2,y-alto/2,x+2,y+alto/2);

 setcolor(15);
 line(x-3,y-alto/2,x-3,y+alto/2);
 line(x+3,y-alto/2,x+3,y+alto/2);

}

void BorrarPlato_(int x,int y,int ancho)
{
 setfillstyle(1,0);
 bar(x-ancho/2,y-alto/2,x+ancho/2,y+alto/2);
 setcolor(0);
 rectangle(x-ancho/2,y-alto/2,x+ancho/2,y+alto/2);
}

void DibujarTorres(int cant)
{
 for(int i=0;i<cant;i++)
 {
  DibujarPlato(PXA,PYA-alto*i,15*(cant-i));
  POSTEA[i]=cant-i;
  POSTEB[i]=0;
  POSTEC[i]=0;
 }
 PA=cant;
 PB=PC=0;
}

void MoverPlato(int posteinicio,int postefinal)
{
 delay(300);
 int valor;
 if(posteinicio==1)
 {
  BorrarPlato(PXA,PYA-alto*(PA-1),150);
  PA--;
  valor=POSTEA[PA];
  POSTEA[PA]=0;
 }
 if(posteinicio==2)
 {
  BorrarPlato(PXB,PYB-alto*(PB-1),150);
  PB--;
  valor=POSTEB[PB];
  POSTEB[PB]=0;
 }
 if(posteinicio==3)
 {
  BorrarPlato(PXC,PYC-alto*(PC-1),150);
  PC--;
  valor=POSTEC[PC];
  POSTEC[PC]=0;
 }

 if(postefinal==1)
 {
  DibujarPlato(PXA,PYA-alto*PA,15*valor);
  PA++;
  POSTEA[PA-1]=valor;
 }
 if(postefinal==2)
 {
  DibujarPlato(PXB,PYB-alto*PB,15*valor);
  PB++;
  POSTEB[PB-1]=valor;
 }
 if(postefinal==3)
 {
  DibujarPlato(PXC,PYC-alto*PC,15*valor);
  PC++;
  POSTEC[PC-1]=valor;
 }

 /*
 for(int i=0;i<n;i++)
 {
  gotoxy(i+1,1);
  cout<<POSTEA[i]<<"  ";
  gotoxy(i+1,2);
  cout<<POSTEB[i]<<"  ";
  gotoxy(i+1,3);
  cout<<POSTEC[i]<<"  ";
 }
 */
}

void Hanoi(int n,int frompeg,int topeg,int auxpeg)
{
 if(n==1)
 {
  MoverPlato(frompeg,topeg);
  return;
 }
 Hanoi(n-1,frompeg,auxpeg,topeg);
 MoverPlato(frompeg,topeg);
 Hanoi(n-1,auxpeg,topeg,frompeg);
}

void menu(){

   // settextstyle(int font, int direction,int font_size);
  settextstyle(10,0,2);
    setcolor(3);
    outtextxy(220,50,".::Tetris::.");

}


int main(){


    n=8;
    ModoGrafico();
    DibujarPostes();
    DibujarTorres(n);
    Hanoi(n,1,3,2);
}
