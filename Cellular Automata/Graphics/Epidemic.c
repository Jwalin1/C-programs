#include<graphics.h>
#include<math.h>
#include<time.h>
#define TAU 6.283185307

class Person
{
	public:
		int x,y;
		int status;	//0->susceptible, 1->infected, 2->recovered
		float recovery_time;
		
		Person()
		{
			status=0;
			recovery_time=15;
		}
};

int main()
{
	//parameters
	int n=500, n_S=0, n_I=0, n_R=0;
	float size=5, vel=4, radius=15, t=0, dt=0.05;
	
	int i,j,gd,gm;
	float a;
	char text[80];
	Person P[1000], tmp[1000];
	
	srand(time(NULL));
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	settextstyle(0,0,2);
	
	//initialize the population
	for(i=0; i<n; i++)
	{
		tmp[i].x = rand()%1365;
		tmp[i].y = rand()%705;
		n_S ++;
	}
	
	//infect 3 people from the population
	for(i=0; i<3; i++)
	{
		tmp[i].status = 1;
		n_I ++;
		n_S --;
	}
	
	delay(2000);
	
	while(n_I != 0)
	{
		cleardevice();
		
		n_S=0, n_I=0, n_R=0;
		//draw the population
		for(i=0; i<n; i++)
		{
			P[i] = tmp[i];
			
			if(P[i].status == 0)
			{
				setfillstyle(1,1);
				setcolor(1);
				n_S++;
			}
			else if(P[i].status == 1)
			{
				setfillstyle(1,4);
				setcolor(4);
				n_I++;
				setcolor(14);
				circle(P[i].x, P[i].y, radius);
			}
			else if(P[i].status == 2)
			{
				setfillstyle(1,8);
				setcolor(8);
				n_R++;
			}
			
			fillellipse(P[i].x, P[i].y, size, size);
		}
		
		//print stats
		setcolor(15);
		sprintf(text,"t=%.1f S=%.2f%% I=%.2f%% R=%.2f%%",t,n_S*100.0/n,n_I*100.0/n,n_R*100.0/n);
		outtextxy(0,0,text);
		
		//update status and positions
		for(i=0; i<n; i++)
		{
			if(P[i].status == 0)
			{
				//check for infections
				for(j=0; j<n; j++)
				{
					if( (i!=j) && (P[j].status==1) && (sqrt((P[i].x-P[j].x)*(P[i].x-P[j].x) + (P[i].y-P[j].y)*(P[i].y-P[j].y)) < radius) )
						tmp[i].status = 1;
				}
			}
			else if(P[i].status == 1)
			{
				tmp[i].recovery_time -= dt;
				
				if(P[i].recovery_time <= 0)
					tmp[i].status = 2;
			}
			
			a = TAU*rand()/RAND_MAX;
			tmp[i].x = (int)(1365 + P[i].x + vel*cos(a)) % 1365;
			tmp[i].y = (int)(705 + P[i].y + vel*sin(a)) % 705;
		}
		
		t += dt;
		Sleep(50);
	}
	
	getch();
	return 0;
}
