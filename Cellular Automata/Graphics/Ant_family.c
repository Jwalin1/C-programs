#include <graphics.h>

int main()
{
    int i,d=3,r,gd,gm,x=700,y=350;
	char A[16],text[80];  
    printf("enter rule : ");
    gets(A);
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	sprintf(text,"rule : %s",A);
	outtextxy(0, 0, text);
	sprintf(text,"iterations : ",A);
	outtextxy(0, 10, text);	
	r=strlen(A);		
    for(i=0;i<16&&i<r;i++)
    {
    	if(A[i]=='l'||A[i]=='L')
    		A[i]=3;
    	else if(A[i]=='r'||A[i]=='R')	
    		A[i]=1;
    }
    delay(2000);
    for(i=0;;i++)
    {
    	d=(d+A[getpixel(x,y)])%4;
		putpixel(x,y,(getpixel(x,y)+1)%r);	
		sprintf(text,"%d",i);
		outtextxy(100, 10, text);	
		if(d==0)	
			y=y-1;
    	else if(d==1)
			x=x+1;
    	else if(d==2)
    		y=y+1;
		else if(d==3)
			x=x-1;
		if(GetAsyncKeyState(VK_MENU)||GetAsyncKeyState(VK_LBUTTON))
			delay(1);	
	}
	getch();
    closegraph();
    return 0;
}
