#include<graphics.h>
#include<math.h>

int main()
{
    int i,j,gd,gm;
    float a,b,ai,bi,af,bf,x,y,s,tmp;
    char text[80];
    printf("Initial\n");
    printf("a=");
    scanf("%f",&ai);
    printf("b=");
    scanf("%f",&bi);
    printf("\n\nFinal\n");
    printf("a=");
    scanf("%f",&af);
    printf("b=");
    scanf("%f",&bf);
    printf("\n\nzoom=");
    scanf("%f",&s);
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,NULL);
    delay(2000);
    for(i=1;i<=1000;i++)
    {
		a=ai+(i/1000.0)*(af-ai);
   		b=bi+(i/1000.0)*(bf-bi);
   		x=0; y=0;
   		cleardevice();
   		sprintf(text,"a=%f b=%f",a,b);
		outtextxy(0, 0, text);
		for(j=0;j<10000;j++)
    	{
	   		tmp=1-a*x*x+y;
	   		y=b*x;
	   		x=tmp; 
	   		putpixel((x*50*s)+600,(y*-50*s)+300,14);
		}
	}
    getch();
    closegraph();
    return 0;
}
