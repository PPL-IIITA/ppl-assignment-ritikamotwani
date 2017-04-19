#include<iostream>
#include<ctime>
#include"couple.h"
#include"gift.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"make_pair.h"
#include"boy.h"
#include"girl.h"
#include <exception>
using namespace std;
void Pair::input()
// !< Reads the value from the files and sees the proper gift exchange happening //!<among the couples
//!< Exception Handling used for the case if the number of couples is 0 or there are no gifts .
{
	try{
			int num_gift,i,j,g;
			FILE *f1,*f2;
			f1 = fopen("gifts_l.txt","r");
			fscanf(f1,"%d",&num_gift);
			Gift gf[54];
			for(i=0;i<num_gift;i++)
				fscanf(f1,"%d %d %d %d %d %d %d %d\n",&gf[i].value,&gf[i].price,&gf[i].type,&gf[i].which,&gf[i].luxury_rate,&gf[i].difficulty,&gf[i].utility_value,&gf[i].utility_class);
			f2 = fopen("couple.txt","r");
			fscanf(f2,"%d",&k);
			if(k == 0 && num_gift == 0)
				throw 10;
			for(i = 0;i < k;i++)
			{
				fscanf(f2,"%s %d %d %d %d %d %d",c[i].g.name,&c[i].g.committed,&c[i].g.type,&c[i].g.attractive,&c[i].g.intell_g,&c[i].g.maint,&c[i].g.check);
				fscanf(f2,"%s %d %d %d %d %d %d",c[i].b.name,&c[i].b.committed,&c[i].b.type,&c[i].b.attractive,&c[i].b.intell_b,&c[i].b.budget,&c[i].b.min_attr);
			}
			
			int l=1;
			int Min = 0;
			freopen("happ_comp_gift","w",stdout);
			for(i = 1;i <= num_gift;i++)
			{
				if(gf[i].price < gf[Min].price)
					Min = i;
			}
			int tb,min=0,tb1,tb2,br;
			for(i = 0;i<k;i++)
			{
				min = 0;
				l = 1;
				if(c[i].b.type == 0)
					tb = c[i].g.maint + ((c[i].b.budget-c[i].g.maint)/3);
				else if(c[i].b.type == 1)
					tb = c[i].b.budget;
				else if(c[i].b.type == 2)
				{
					tb = c[i].g.maint + ((c[i].b.budget-c[i].g.maint)/3);
					tb1 = tb;
				}
				while(tb > 0)
				{
					if(c[i].b.type == 1)
						gf[0].price = 0;
					else
						gf[0].price =11000;
					min = 0;
					for(j=2;j<=num_gift;j++)
					{
						if(gf[j].which == 1)
							continue;
						if(c[i].b.type == 0||c[i].b.type ==2)
						{
							if(gf[j].price < gf[min].price)
								min = j;
						}
						else if(c[i].b.type == 1)
						{
							if(tb < gf[Min].price)
								break;
							else
							{
								if(gf[j].price>gf[min].price&&gf[j].price<=tb)
								{
									min = j;
								}
							}
						}
					}
					if(tb>=gf[min].price&&min!=0)
					{
						gf[min].which = 1;
						cg[i][l] = gf[min];
						tb = tb-gf[min].price;
						l++;
					}
					else
					{
						if(c[i].b.type == 1)
							break;
						if(c[i].b.type == 0)
						{
							c[i].b.budget+=(gf[l].price*2);
						}
						gf[min].which = 1;
						cg[i][l] = gf[min];
						tb = 0;
						l++;
						break;
					}
				}
				if(c[i].b.type == 2)
				{
					tb2 = c[i].b.budget - tb1;
					for(j=1;j<=num_gift;j++)
					{
						if(gf[j].which==1||gf[j].type==0||gf[j].type==2)
							continue;
						else
						{
							if(gf[j].type == 1 &&gf[j].price<=tb2)
							{
								gf[j].which=1;
								cg[i][l]=gf[j];
								l++;
								break;
							}
						}
					}
				}
				cg[i][0].price = l;
				for(j=0;j<num_gift;j++)
					gf[j].which = 0;
				printf("For Couple %d\n",i+1);
				for(g=1;g<l;g++)
				{
					time_t now = time(0);
					char *ct = ctime(&now);
					cout<<ct<<"\n\n";
					printf("\t\t\tGifts are with value,price,luxuryrate,difficult,utility_value and utility_class\n");
					printf("\t\t%d\t%d\t%d\t%d\t%d\t%d\n",cg[i][g].value,cg[i][g].price,cg[i][g].luxury_rate,cg[i][g].difficulty,cg[i][g].utility_value,cg[i][g].utility_class);
					cout<<"\n";
				}
				printf("\n \n \n \n");
			}
		}
		catch(int x)
		{
			if(x == 10)
				cout<<"Exception";
		}
}
// !<This function finds the happiness of the couple 
void Pair::find_happiness()
{
	int i,j;
	int total_cost = 0;
	int total_value = 0;

	for(i=0;i<k;i++)
	{
		total_cost=0;
		total_value=0;
		for(j=1;j<cg[i][0].price;j++)
		{
			total_cost+=cg[i][j].price;
			total_value+=cg[i][j].value;
		}
				//		printf("TOTAL Cost and value : %d  %d \n",total_cost,total_value);
		c[i].g.happiness(total_cost,total_value);

		c[i].b.happiness(total_cost,c[i].g);
				//		printf ("Girl  %d   Boy  %d\n",c[i].g.happy,c[i].b.happy);
				//		printf("Girl   %d   Boy   %d\n",c[i].g.type,c[i].b.type);
		c[i].happiness();
		c[i].compatibility();
				//		printf("Couple's  : Happiness %d && Compatibility %d\n",c[i].happy,c[i].compatible);
	}
}
