#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
  int x,r,r2,to,bb,bt,bt2,bw,bw2,cbb,n;
  x=0; r=0; r2=0; to=0; bb=0; bt=0; bt2=0; bw=0; bw2=0; cbb=0; n=0;
  srand(time(NULL));
  clrscr();
  printf("           Cricketus\n");
  printf("Rules: \nEnter a number from 1 to 6,\nif the number matches then player is out,\nelse runs will be scored\n");
  printf("Toss\n");
  printf("Enter 1 for heads and 0 for tails : ");
  scanf("%d",&to);
  n=rand()%2;
  if(n==1){printf("It turns out to be heads\n");}
  if(n==0){printf("It turns out to be tails\n");}

  if (n==to)
  {
   printf("You won the toss\n");
   printf("Enter 1 to bat and 2 to bowl : ");
   scanf("%d",&bb);
   if (bb==1)
   {
    while (x==0)
    {
     printf("Enter your choice from 1 to 6 : ");
     scanf("%d",&bt);
     bw=rand()%6+1;
     if (bt>0&&bt<7)
     {
      printf("Computer chose %d\n",bw);
      if (bt==bw)
      {
       printf("Out\n");
       printf("You scored %d runs\n",r);
       x=1;
      }
      else
      {
        r=r+bt;
        printf("%d Runs\n",r);
       }
      }
     }
     
     if (x==1)
     {
      printf("Your Bowling\n");
      while (x==1)
      {
       printf("Enter your choice from 1 to 6 : ");
       scanf("%d",&bt2);
       bw2=rand()%6+1;
       if (bt2>0&&bt2<7)
       {
        printf("Computer chose %d\n",bw2);
        if (bt2==bw2)
        {
          if (r2==r)
          {
           printf("Out\n");
           printf("Tie\n");
          }
          if (r2<r)
          {
           printf("Out\n");
           printf("You win\n");
          }
          x=2;
         }
         r2=r2+bw2;
         if (r2>r&&x==1){printf("You lose\n"); x=2;}
         if (x==1&&r2<=r)
         {
          printf("%d runs required\n",((r-r2)+1));
         }
        }
       }
      }
     }
       
       
        
     if (bb==2)
     {
      while (x==0)
      {
        printf("Enter your choice from 1 to 6 : ");
        scanf("%d",&bw);
        bt=rand()%6+1;
        if (bw>0&&bw<7)
        {
         printf("Computer chose %d\n",bt);
         if (bt==bw)
         {
          printf("Out\n");
          printf("Computer scored %d runs\n",r);
          x=1;
         }
         else
         {
          r=r+bt;
          printf("%d Runs\n",r);
         }
        }
       }
       if (x==1)
       {
        printf("Your Batting\n");
        while (x==1)
        {
         printf("Enter your choice from 1 to 6 : ");
         scanf("%d",&bw2);
         bt2=rand()%6+1;
         if (bw2>0&&bw2<7)
         {
          printf("Computer chose %d\n",bt2);
          if (bt2==bw2)
          { 
           if (r2==r)
           {
            printf("Out\n");
            printf("Tie\n");
           }
           if (r2<r)
           {
            printf("Out\n");
            printf("You lose\n");
           }
           x=2;
          }
          r2=r2+bw2;
          if (r2>r&&x==1) {printf("You win\n"); x=2;}
          if (x==1&&r2<=r)
          {
            printf("%d runs required\n",((r-r2)+1));
           }
          }
         }
        }
       }
      }
           
           
           
      else
      {
       printf("Computer won the toss\n");
       cbb=rand()%2+1;
           
       if (cbb==1)
       {
        printf("Computer chose bowling\n");
        while (x==0)
        {
         printf("Enter your choice from 1 to 6 : ");
         scanf("%d",&bt);
         bw=rand()%6+1;
         if (bt>0&&bt<7)
         {
          printf("Computer chose %d\n",bw);
          if (bt==bw)
          {
            printf("Out\n");
            printf("You scored %d runs\n",r);
            x=1;
           }
           else
           { 
            r=r+bt;
            printf("%d Runs\n",r);
           }
          }
         }
         if (x==1)
         {
          printf("Your Bowling\n");
          while (x==1)
          {
            printf("Enter your choice from 1 to 6 : ");
            scanf("%d",&bt2);
            bw2=rand()%6+1;
            if (bt2>0&&bt2<7)
            {
             printf("Computer chose %d\n",bw2);
             if (bt2==bw2)
             {
               if (r2==r)
               {
                printf("Out\n");
                printf("Tie\n");
               }
               if (r2<r)
               {
                printf("Out\n");
                printf("You win\n");
               }
               x=2;
              }
              r2=r2+bw2;
              if (r2>r&&x==1) {printf("You lose\n"); x=2;}
              if (x==1&&r2<=r)
              {
               printf("%d runs required\n",((r-r2)+1));
              }
             }
            } 
           }
          }
               
               
                 
          if (cbb==2)
          {
           printf("Computer chose Batting\n");
           while (x==0)
           {
            printf("Enter your choice from 1 to 6 : ");
            scanf("%d",&bw);
            bt=rand()%6+1;
            if (bw>0&&bw<7)
            {
             printf("Computer chose %d\n",bt);
             if (bt==bw)
             {
              printf("Out\n");
              printf("Computer scored %d runs\n",r);
              x=1;
             }
             else
             { 
              r=r+bt;
              printf("%d Runs\n",r);
             }
            }
           }
           if (x==1)
           {
            printf("Your Batting\n");
            while (x==1)
            { 
              printf("Enter your choice from 1 to 6 : ");
              scanf("%d",&bw2);
              bt2=rand()%6+1;
              if (bw2>0&&bw2<7) 
              {
               printf("Computer chose %d\n",bt2);
               if (bt2==bw2)
               {
                if (r2>r)
                {
                 printf("You win\n");
                }
                if (r2==r)
               {
               printf("Out\n");
               printf("Tie\n");
              } 
              if (r2<r)
             { 
             printf("Out\n");
             printf("You lose\n");
            }
            x=2;
           }
           r2=r2+bw2;
           if (r2>r&&x==1) {printf("You win\n"); x=2;}
           if (x==1&&r2<=r)
           {
            printf("%d runs required\n",((r-r2)+1));
           }
          }
         }
        }
       }
      }
      getch();
}
