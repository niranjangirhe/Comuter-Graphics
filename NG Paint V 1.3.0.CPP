#include<conio.h>
#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
void floodfill(int x,int y,int cstore,int bg)
{
if(getpixel(x,y)==bg)
{
putpixel(x,y,cstore);
floodfill(x+1,y,cstore,bg);
floodfill(x-1,y,cstore,bg);
floodfill(x,y+1,cstore,bg);
floodfill(x,y-1,cstore,bg);
}
}
void main()
{
int gd = DETECT,gm;
int tmode,i=-1,p,q,x,y,sx,sy,bg,s=10,k,l,cflag=0;
float x1,H,K;
int data[100][5]={0};
int graphmode[100]={0};
int selecter=0,cstore=15;
char mode='c',color,select='z';
initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
int X = getmaxx();
int Y =getmaxy();
x=X/2;
y=Y/2;
for(int a=0;a<200;a++)
{
cleardevice();
setcolor(WHITE);
outtextxy(x-50,y,"Use W,A,S,D to Control and E to exit NG PAINT");
outtextxy(x-50,y+10,"Q to select & Z to deselect");
outtextxy(x-50,y+20," HIT enter to continue");
setcolor(YELLOW);
outtextxy(x+a-200,y-a,"NG PAINT in made by - Niranjan Girhe");
setcolor(CYAN);
outtextxy(x,y+100,"LOADING");
setcolor(5);
rectangle(x-20,y+120,x+205,y+140);
rectangle(x-15,y+125,x+a,y+135);
delay(20);
}
setcolor(WHITE);
char n = 'q';
getch();
cleardevice();
while(n!='e')
{
n=getch();
if(select=='z')
{
p=x;
q=y;
}
if(n=='w' || n=='W')
{
cleardevice();
y=y-s;
}
else if(n=='a' || n=='A')
{
cleardevice();
x=x-s;
}
else if(n=='s' || n=='S')
{
cleardevice();
y=y+s;
}
else if(n=='d'|| n=='D')
{
cleardevice();
x=x+s;
}
else if(n=='c' || n=='C')
{
mode='c';
}
else if(n=='l' || n=='L')
{
mode='l';
}
else if(n=='y' || n=='Y')
{
mode='y';
}
else if(n=='r' || n=='R')
{
mode='r';
}
else if(n=='E')
{
n='e';
}
else if(n=='p' || n=='P')
{
cleardevice();
mode='p';
}
else if(n==',')
{
mode=',';
}
else if(n=='.')
{
mode='.';
}
else if(n=='t' || n=='T')
{
cleardevice();
mode='t';
}
else if(n=='q' || n=='Q')
{
select='q';
selecter=1;
}
else if(n=='z' || n=='Z')
{
if(tmode==1)
{
tmode=0;
mode='r';
}
select='z';
}
else
{
color=n;
}
setcolor(YELLOW);
outtextxy(getmaxx()/2-20,getmaxy()-10,"Hit e to exit & P to colour mode");
outtextxy(getmaxx()/2-30,getmaxy()-60,"Hit Q to Select & Z to deselect");
setcolor(cstore);
if(mode=='c')
{
setcolor(WHITE);
outtextxy(getmaxx()/2-40,getmaxy()-50,"You entered in circle mode");
outtextxy(getmaxx()/2-40,getmaxy()-40,"HIT L to enter in line mode");
outtextxy(getmaxx()/2-40,getmaxy()-30,"HIT R to enter in rectangle mode");
outtextxy(getmaxx()/2-40,getmaxy()-20,"HIT Y to enter in ellipse mode");
setcolor(cstore);
}
if(mode=='l')
{
setcolor(WHITE);
outtextxy(getmaxx()/2-40,getmaxy()-50,"You entered in line mode");
outtextxy(getmaxx()/2-40,getmaxy()-40,"HIT C to enter in circle mode");
outtextxy(getmaxx()/2-40,getmaxy()-30,"HIT R to enter in rectangle mode");
outtextxy(getmaxx()/2-40,getmaxy()-20,"HIT Y to enter in ellipse mode");
setcolor(cstore);
}
if(mode=='r')
{
setcolor(WHITE);
outtextxy(getmaxx()/2-40,getmaxy()-50,"You entered in rectangle mode");
outtextxy(getmaxx()/2-40,getmaxy()-40,"HIT C to enter in circle mode");
outtextxy(getmaxx()/2-40,getmaxy()-30,"HIT L to enter in line mode");
outtextxy(getmaxx()/2-40,getmaxy()-20,"HIT Y to enter in ellipse mode");
setcolor(cstore);
}
if(mode==',')
{
cleardevice();
setcolor(WHITE);
outtextxy(getmaxx()/2-40,getmaxy()-50,"You entered in fill color mode");
outtextxy(getmaxx()/2-40,getmaxy()-40,"HIT . to fill the polygon");
setcolor(cstore);
}
if(mode=='t')
{
cleardevice();
setcolor(WHITE);
outtextxy(getmaxx()/2-40,getmaxy()-50,"You entered in Transform mode");
outtextxy(getmaxx()/2-40,getmaxy()-40,"HIT 1 to translate the polygon");
outtextxy(getmaxx()/2-40,getmaxy()-30,"HIT 2 to Scale the polygon");
outtextxy(getmaxx()/2-40,getmaxy()-20,"HIT 3 to Rotate the polygon");
setcolor(cstore);
}
if(mode=='y')
{
setcolor(WHITE);
outtextxy(getmaxx()/2-40,getmaxy()-50,"You entered in ellipse mode");
outtextxy(getmaxx()/2-40,getmaxy()-40,"HIT C to enter in circle mode");
outtextxy(getmaxx()/2-40,getmaxy()-30,"HIT L to enter in line mode");
outtextxy(getmaxx()/2-40,getmaxy()-20,"HIT R to enter in rectangle mode");
setcolor(cstore);
}
if(mode=='p')
{
setcolor(WHITE);
outtextxy(getmaxx()/2-40,getmaxy()-50,"You entered in Color mode");
outtextxy(getmaxx()/2-40,getmaxy()-40,"Enter No. 0-9 for color choice");
outtextxy(getmaxx()/2-40,getmaxy()-30,"Enter f,g,h,i,j,k for rest of color");
outtextxy(getmaxx()/2-40,getmaxy()-20,"HIT Q after selecting color");
setcolor(cstore);
}
if(mode=='t' && select=='q')
{
switch(color)
{
case '1': tmode=1;
	break;
case '2': tmode=2;
	break;
case '3': tmode=3;
	break;
}
}
if(mode=='p' && select=='q')
{
switch(color)
{
case '0': cstore=0;
	break;
case '1': cstore=1;
	break;
case '2': cstore=2;
	break;
case '3': cstore=3;
	break;
case '4': cstore=4;
	break;
case '5': cstore=5;
	break;
case '6': cstore=6;
	break;
case '7': cstore=7;
	break;
case '8': cstore=8;
	break;
case '9': cstore=9;
	break;
case 'f': cstore=10;
	break;
case 'g': cstore=11;
	break;
case 'h': cstore=12;
	break;
case 'i': cstore=13;
	break;
case 'j':cstore=14;
	break;
case 'k':cstore=15;
	break;
}
mode='c';
select='z';
}
putpixel(x,y,WHITE);
circle(x,y,10);
if(selecter==1)
{
i=i+1;
selecter=0;
}
if(mode=='c' && select=='q')
{
graphmode[i]=1;
circle(p,q,abs(x-p));
data[i][2]=abs(x-p);
data[i][0]=p;
data[i][1]=q;
data[i][4]=cstore;
}
if(mode=='l' && select=='q')
{
graphmode[i]=2;
line(p,q,x,y);
data[i][0]=p;
data[i][1]=q;
data[i][2]=x;
data[i][3]=y;
data[i][4]=cstore;
}
if(mode=='y' && select=='q')
{
graphmode[i]=4;
ellipse(p,q,0,360,x,y);
data[i][0]=p;
data[i][1]=q;
data[i][2]=x;
data[i][3]=y;
data[i][4]=cstore;
}
if(mode=='r' && select=='q')
{
graphmode[i]=3;
rectangle(p,q,x,y);
data[i][0]=p;
data[i][1]=q;
data[i][2]=x;
data[i][3]=y;
data[i][4]=cstore;
}
if(n==',')
{
sx=x;
sy=y;
cflag=1;
}
if(mode=='t' && select=='q')
{
if(tmode==1)
{
for(int t=0;t<20;t++)
{
if(graphmode[t]==2||graphmode[t]==3)
{
data[t][0]-=p-x;
data[t][2]-=p-x;
data[t][1]-=q-y;
data[t][3]-=q-y;
}
else
{
data[t][0]-=p-x;
data[t][1]-=q-y;

}
}
p=x;
q=y;
}
if(tmode==2 && select=='q')
{
for(int t=0;t<20;t++)
{
if(n=='d')
{
data[t][0]*=1.5;
data[t][1]*=1;
data[t][2]*=1.5;
data[t][3]*=1;
}
else if(n=='s')
{
data[t][0]*=1;
data[t][1]*=1.5;
data[t][2]*=1;
data[t][3]*=1.5;
}
else if(n=='a')
{
data[t][0]*=0.66;
data[t][1]*=1;
data[t][2]*=0.66;
data[t][3]*=1;
}
else if(n=='w')
{
data[t][0]*=1;
data[t][1]*=0.66;
data[t][2]*=1;
data[t][3]*=0.66;
}
}
}
}
if(tmode==3 && select=='q')
{
for(int t=0;t<20;t++)
{
if(graphmode[t]==2)
{
if(n=='a')
x1+=0.125;
else if(n=='d')
x1-=0.125;
H=data[t][2];
K=data[t][3];
H=(sqrt(pow(H-data[t][0],2)+pow(K-data[t][1],2))*cos(x1))+data[t][0];
K=(sqrt(pow(H-data[t][0],2)+pow(K-data[t][1],2))*sin(x1))+data[t][1];
data[t][2]=H;
data[t][3]=K;
}
}
}
for(int t=0;t<20;t++)
{
if(graphmode[t]==1)
{
setcolor(data[t][4]);
circle(data[t][0],data[t][1],data[t][2]);
setcolor(WHITE);
}
if(graphmode[t]==2)
{
setcolor(data[t][4]);
line(data[t][0],data[t][1],data[t][2],data[t][3]);
setcolor(WHITE);
}
if(graphmode[t]==3)
{
setcolor(data[t][4]);
rectangle(data[t][0],data[t][1],data[t][2],data[t][3]);
setcolor(WHITE);
}
if(graphmode[t]==4)
{
setcolor(data[t][4]);
ellipse(data[t][0],data[t][1],0,360,data[t][2],data[t][3]);
setcolor(WHITE);
}
}
if(n=='.' && cflag==1)
{
cflag=0;
bg=getpixel(sx,sy);
floodfill(sx,sy,cstore,bg);
}
}
closegraph();
}