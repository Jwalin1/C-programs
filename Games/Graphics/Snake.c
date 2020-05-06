#include<graphics.h>
#include<time.h>

int main()
{
	int i,X[100],Y[100],rx,ry,gm,gd,l,d=2,s=16;
	srand(time(NULL));
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	setfillstyle(1,1);
	bar(s-s/2,s-s/2,(s/2)+s*(1350/s),s+s/2);
	bar(s-s/2,(-s/2)+s*(700/s),(s/2)+s*(1350/s),(s/2)+s*(700/s));
	bar(s-s/2,s-s/2,s+s/2,(s/2)+s*(700/s));
	bar((-s/2)+s*(1350/s),s-s/2,(s/2)+s*(1350/s),(s/2)+s*(700/s));
	X[0]=s*(1350/(2*s)); Y[0]=s*(700/(2*s));
    bar(X[0]-s/2,Y[0]-s/2,X[0]+s/2,Y[0]+s/2);
    l=5;
    for(i=1;i<l;i++)
    {
        X[i]=X[0]-(i*s);
        Y[i]=Y[0];
        bar(X[i]-s/2,Y[i]-s/2,X[i]+s/2,Y[i]+s/2);
    }
    rx=s; ry=s;
    setfillstyle(1,2);
    while(getpixel(rx,ry)!=0)
	{
		rx=s*(1+rand()%(1350/s-1));
		ry=s*(1+rand()%(700/s-1));
	}
	bar(rx-s/2,ry-s/2,rx+s/2,ry+s/2);
    delay(2000);
	while(1)
	{
    	setfillstyle(1,0);
		bar(X[l-1]-s/2,Y[l-1]-s/2,X[l-1]+s/2,Y[l-1]+s/2);
		for(i=l-1;i>0;i--)
    	{
    		X[i]=X[i-1];
    		Y[i]=Y[i-1];
		}
    	if(d==0)
			X[0]=X[0]-s;
		if(d==1)
			Y[0]=Y[0]-s;	
    	else if(d==2)
			X[0]=X[0]+s;
		else if(d==3)
			Y[0]=Y[0]+s;
		if(getpixel(X[0],Y[0])==1)
			break;
		if((GetAsyncKeyState(VK_RIGHT))&&(d!=0))
			d=2;
		else if((GetAsyncKeyState(VK_UP))&&(d!=3))
			d=1;
		else if((GetAsyncKeyState(VK_LEFT))&&(d!=2))
			d=0;
		else if((GetAsyncKeyState(VK_DOWN))&&(d!=1))
			d=3;
		if(getpixel(X[0],Y[0])==2)
		{
			rx=s; ry=s;
			setfillstyle(1,2);
			while(getpixel(rx,ry)!=0)
			{
				rx=s*(1+rand()%(1350/s-1));
				ry=s*(1+rand()%(700/s-1));
			}
			bar(rx-s/2,ry-s/2,rx+s/2,ry+s/2);
			l=l+1;
		}
		setfillstyle(1,1);
		for(i=0;i<l;i++)
       		bar(X[i]-s/2,Y[i]-s/2,X[i]+s/2,Y[i]+s/2);	
		delay(100);
    }
    printf("score : %d",l-5);
	while(!GetAsyncKeyState(VK_RETURN));
	closegraph();
	getch();
	return 0;	
}
