//!< Output is in file ques6.txt. In this question gifyting is done for t days and  every day some couples break up and find new partners for themselves.

#include<iostream>
#include<ctime>
#include<string.h>
#include<stdio.h>
#include "girl.h"
#include "boy.h"
#include "t_days.h"
#include "inh_pair.h"
using namespace std;

void t_days :: break_up_function(int t)
{
	int i,num_boy,j,in,p;
	br.input();
	br.giftin();
	br.find_happiness();
	for(i = 0;i < br.k; i++)
	{
		if(br.c[i].happy < t)
		{
			br.c[i].g.committed = 0;
			strcpy(br.c[i].g.no,br.c[i].b.name);
		}
	}
	FILE *f2;
	f2 = fopen("boys_l.txt","r");
	fscanf(f2, "%d",&num_boy);
	Boy b[33];
	for(i=0;i <= num_boy;i++)
	{
		
		fscanf(f2,"%s %d %d %d %d %d %d",b[i].name,&b[i].committed,&b[i].type,&b[i].attractive,&b[i].intell_b,&b[i].budget,&b[i].min_attr);	
	}
	for(i = 1; i <= num_boy;i++)
	{
		for(j=0;j<br.k;j++)
		{
			if(!(strcmp(b[i].name,br.c[j].b.name)))
			{
				b[i].committed = br.c[j].b.committed;
			}
		}
	}
	for(i = 0; i < br.k; i++)
	{
		if(br.c[i].g.committed == 0)
		{
			in = 0;
			p = 0;
			for(j=1;j<=num_boy;j++)
			{
				if(b[j].committed==1||b[j].budget<br.c[i].g.maint||b[j].min_attr > br.c[i].g.attractive||(!(strcmp(b[j].name,br.c[i].g.no))))
					continue;
				if(br.c[i].g.check == 0)
				{
					if(b[j].attractive>b[in].attractive)
					{
				
						in = j;
						p=1;
					}
				}
				else if(br.c[i].g.check == 1)
				{
					if(b[j].budget>b[in].budget)
					{
				
						in=j;
						p=1;
					}
				}
				else if(br.c[i].g.check == 2)
				{
					if(b[j].intell_b>b[in].intell_b)
					{
					
						in=j;
						p=1;
					}
				}
			}
			if(p == 1)
			{
				b[in].committed = 1;
				br.c[i].b = b[in];
				br.c[i].g.committed = 1;
			}
		}
	}
}
void t_days :: print()
{
	freopen("ques6.txt","w",stdout);
	printf("%d\n",br.k);
	for(int i = 0;i <br.k;i++)
	{
		cout<<"\n\n";
		time_t now = time(0);
		char *ct = ctime(&now);
		cout<<ct<<"\n\n";
		printf("%s %d %d %d %d %d %d\n",br.c[i].g.name,br.c[i].g.committed,br.c[i].g.type,br.c[i].g.attractive,br.c[i].g.intell_g,br.c[i].g.maint,br.c[i].g.check);
		printf("%s %d %d %d %d %d %d \n",br.c[i].b.name,br.c[i].b.committed,br.c[i].b.type,br.c[i].b.attractive,br.c[i].b.intell_b,br.c[i].b.budget,br.c[i].b.min_attr);
	}
}