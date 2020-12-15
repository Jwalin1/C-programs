#include<math.h>
#include<graphics.h>


void sort(int X[], int Y[], int n)
{
	int i,d1,d2,tmp;
	bool swapped;
	
	do
	{
		swapped=false;
		for(i=0; i<n*n-1; i++)
		{
			d1 = X[i]*X[i] + Y[i]*Y[i];
			d2 = X[i+1]*X[i+1] + Y[i+1]*Y[i+1];
			
			if ( (d1>d2) || ((d1==d2) && (X[i]>X[i+1])) )
			{
				tmp = X[i];
				X[i] = X[i+1];
				X[i+1] = tmp;
				
				tmp = Y[i];
				Y[i] = Y[i+1];
				Y[i+1] = tmp;
				
				swapped=true;
			}
		}
	} while(swapped);
	
}

bool step(int pattern[], int n, int step_size[])
{
	int i, a[n], carry = 0;
	
	for(i=0;i<n;i++)
	{
		a[i] = pattern[i] + step_size[i] + carry;
		carry = floor(a[i] / 2.0);
		a[i] = (a[i] +2) % 2;
	}
	
	if(carry!=0)
		return false;
	
	for(i=0;i<n;i++)
		pattern[i] = a[i];
	return true;	
}

int main()
{
	int i,j,n,n2,N;
	float spd,p_complete,p_filled;
	
	printf("enter the grid size : ");
	scanf("%d",&N);
	n = ceil(N/2.0);
	n2 = n*n;
	spd = 0.5;
	
	int gd,gm, bit=0, d=1, s=500/N;
	int G_prev[n][n], G[n][n], X[n2], Y[n2], pattern[n2], step_size[n2];
	char text[n2+100];
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			G_prev[i][j] = 0;
	
	
	for(i=0; i<n2; i++)	// initialize grid to empty
	{
		X[i] = i/n;
		Y[i] = i%n;
		pattern[i] = 0;
		step_size[i] = 0;
	}
	step_size[0] = 1;
	sort(X,Y,n);
	
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	settextstyle(0,0,2);
	sprintf(text,"grid size : %d x %d",N,N);
	outtextxy(0,30,text);
	sprintf(text,"total patterns = 2 ^ %d",n2);
	outtextxy(900,30,text);
	
	setcolor(14);
	for(i=0;i<=n;i++)	// draw lines containg the grid
	{
		line(0,350+i*s,1400,350+i*s);
		line(700+i*s,0,700+i*s,700);
		if (N%2==0 || i!=n)
		{
			line(0,350-i*s,1400,350-i*s);
			line(700-i*s,0,700-i*s,700);
		}
	}
	setcolor(15);
	
	delay(2000);
	
	while(true)
	{
		sprintf(text,"speed = %.5f%",spd);
		outtextxy(0,60,text);
		
		if(p_filled > 0 && p_filled < 100)
		{
			// caclulate percentage completed
			p_complete = 0.0;
			for (j=n2-1; j>=0 && j-n2>=-24; j--)
				p_complete += pow(2,j*pattern[j]-n2);
			p_complete *= 100;
			p_complete = trunc(p_complete*pow(10,5))/pow(10,5);
		}
		else
			p_complete = p_filled;
			
	
		if(N<=20)
		{
			settextstyle(0,0,1);
			sprintf(text,"pattern code = ");
			i=15;
			for (j=n2-1; j>=0; j--)
	   			i += sprintf(&text[i], "%d", pattern[j]);
			outtextxy(0,650,text);
			settextstyle(0,0,2);
			
		}		
		sprintf(text,"percentage completed = %.5f%% ",p_complete);
		outtextxy(0,0,text);
		sprintf(text,"percentage filled = %.5f%% ",p_filled);
		outtextxy(900,0,text);		
		

		if (GetAsyncKeyState(VK_UP))
		{
			if (spd >= 1.0)
			{
				if (bit < n2-1)
				{
					bit++;
					spd = 1 + bit/(n2-1.0);
				}
				Sleep(6250/n2);
			}
			else
			{
				spd = spd > 0.9 ? 1.0 : spd+0.1;	
				bit = 0;
				Sleep(150);
			}
			continue;
		}
		else if (GetAsyncKeyState(VK_DOWN)) 
		{
			if (spd > 1.0)
			{
				step_size[bit] = 0;
				bit--;
				spd = 1 + bit/(n2-1.0);
				Sleep(6250/n2);
			}
			else
			{
				spd = spd < 0.2 ? 0.0 : spd-0.1;
				Sleep(150);	
			}
			continue;
		}
		else if (GetAsyncKeyState(VK_LEFT))
		{
			d=-1;
			for(i=0; i<n2; i++)
				step_size[i] = step_size[i] == 1 ? -1 : step_size[i];
			sprintf(text,"direction : dec");
			outtextxy(900,60,text);
		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			d=1;
			for(i=0; i<n2; i++)
				step_size[i] = step_size[i] == -1 ? 1 : step_size[i];
			sprintf(text,"direction : inc");
			outtextxy(900,60,text);
		}
		else if (GetAsyncKeyState(0x50))	// pause
		{
			while(GetAsyncKeyState(0x50)){}
			while(!GetAsyncKeyState(0x50)){}
			while(GetAsyncKeyState(0x50)){}
			continue;
		}
		else if (GetAsyncKeyState(0x53))	// stop
		{
			spd = 0.0;
			continue;
		}
		else if (GetAsyncKeyState(0x52))	// restart
		{
			for(i=0; i<n2; i++)	// initialize grid to empty
				pattern[i] = 0;
			continue;
		}
		else if (GetAsyncKeyState(0x45))	// end
		{
			for(i=0; i<n2; i++)	// initialize grid to empty
				pattern[i] = 1;
			continue;
		}
		
		
		if(spd > 1.0)
		{
			step_size[bit] = d;
			if(!step(pattern,n2,step_size) && bit>0)
			{
				step_size[bit] = 0;
				bit--;
				spd = 1 + bit/(n2-1.0);
				continue;	
			}
		}
		else if(spd == 0.0)
		{
			if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_RIGHT))
			{
				for(i=0; i<n2; i++) { step_size[i] = 0; }
				step_size[0] = d;
				step(pattern,n2,step_size);
				Sleep(150);
			}
		}		
		else if(spd <= 1.0)
		{
			for(i=0; i<n2; i++) { step_size[i] = 0; }
			step_size[0] = d;
			step(pattern,n2,step_size);
			Sleep(-555.56*spd+555.56);
		}		
					
		// fill the grid with the pattern
		p_filled = 0.0;			
		for(i=0;i<n2;i++)
		{
			G[X[i]][Y[i]] = pattern[i];
			if(pattern[i] == 1)
				p_filled += 1;
		}
		p_filled *= 100.0/n2;
		p_filled = trunc(p_filled*pow(10,5))/pow(10,5);
			
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if (G_prev[i][j]==0 && G[i][j]==1)
					setfillstyle(1,10);
				else if (G_prev[i][j]==1 && G[i][j]==1)
					setfillstyle(1,1);
				else if (G_prev[i][j]==1 && G[i][j]==0)
					setfillstyle(1,4);
				else
					setfillstyle(1,0);
				G_prev[i][j] = G[i][j];
				
				bar(700+j*s,350+i*s,700+(1+j)*s,350+(1+i)*s);
				if (N%2 == 0)
				{
					bar(700+j*s,350-i*s,700+(1+j)*s,350-(1+i)*s);
					bar(700-j*s,350+i*s,700-(1+j)*s,350+(1+i)*s);
					bar(700-j*s,350-i*s,700-(1+j)*s,350-(1+i)*s);
				}
				else
				{
					bar(700+j*s,350-(i-1)*s,700+(1+j)*s,350-i*s);
					bar(700-(j-1)*s,350+i*s,700-j*s,350+(1+i)*s);
					bar(700-(j-1)*s,350-(i-1)*s,700-j*s,350-i*s);
				}
			}
		}
	}
	
	getch();
	closegraph();
	return 0;
}
