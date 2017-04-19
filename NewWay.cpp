//!< The second type of gift system is shown. Gifts of each type is surely given .
//!< Exception handled if the file has no gifts or couples.
#include<iostream>
#include<ctime>
#include"couple.h"
#include"gift.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"NewWay.h"
#include"boy.h"
#include"girl.h"
#include<time.h>
using namespace std;
//!< Output in happ_comp_gift
void NewWay :: allocation()
{
	try
	{
		int num_gift,i,j,g;
		FILE *f1,*f2;
		f1 = fopen("gifts_l.txt","r");
		fscanf(f1,"%d",&num_gift);
		Gift gf[54];
		for(i=0;i<num_gift;i++)
			fscanf(f1,"%d %d %d %d %d %d %d %d\n",&gf[i].value,&gf[i].price,&gf[i].type,&gf[i].which,&gf[i].luxury_rate,&gf[i].difficulty,&gf[i].utility_value,&gf[i].utility_class);
		f2 = fopen("couple.txt","r");
			fscanf(f2,"%d",&k);
		if(num_gift == 0 || k == 0)
			throw 5;
		for(i = 0;i < k;i++)
		{
			fscanf(f2,"%s %d %d %d %d %d %d",c[i].g.name,&c[i].g.committed,&c[i].g.type,&c[i].g.attractive,&c[i].g.intell_g,&c[i].g.maint,&c[i].g.check);
			fscanf(f2,"%s %d %d %d %d %d %d",c[i].b.name,&c[i].b.committed,&c[i].b.type,&c[i].b.attractive,&c[i].b.intell_b,&c[i].b.budget,&c[i].b.min_attr);
		}
		int Min = 0;
		freopen("happ_comp_gift","w",stdout);
		int tb,min=0,tb1,tb2,br;
		for(i = 0; i < k; i++)
		{
			time_t now = time(0);
			char *ct = ctime(&now);
			cout<<ct<<"\n\n";
			printf("The value , price , type of gifts exchanged by couple %d\n",i+1);
			int extra1 = 0, extra2 = 0;
			
			if(c[i].b.type == 0)
				tb = c[i].g.maint + ((c[i].b.budget-c[i].g.maint)/3);
			else if(c[i].b.type == 1)
				tb = c[i].b.budget;
			else if(c[i].b.type == 2)
			{
				tb = c[i].g.maint + ((c[i].b.budget-c[i].g.maint)/3);
			}
			if(extra1 == 0)
			{
				for(j = 1;j < num_gift;j++)
				{
					if(gf[j].which == 0 && gf[j].type == 1)
					{
						gf[j].which = 1;
						printf("%d %d luxury\n",gf[j].price,gf[j].value);
						tb = tb - gf[j].price;
						extra1 = 1;
					}
					if(extra1 == 1)
						break;
				}
			}
			if(extra2 == 0)
			{
				for(j = 1;j < num_gift;j++)
				{
					if(gf[j].which == 0 && gf[j].type == 2)
					{
						gf[j].which = 1;
						printf("%d %d utility\n",gf[j].price,gf[j].value);
						tb = tb - gf[j].price;
						extra2 = 1;
					}
					if(extra2 == 1)
						break;
				}
			}
			if(tb > 0)
			{
				for(j = 0;j < num_gift; j++)
				{
					if(gf[j].which == 0 && gf[j].type == 0 && gf[j].price < tb)
					{
						gf[j].which = 1;
						tb = tb - gf[j].price;
						printf("%d %d normal\n",gf[j].price,gf[j].value);
						if(tb < 0)
							break;
					}
				}
			}
			for(j = 0; j < num_gift; j++)
			{
				gf[j].which = 0;
			}
		}
	}
	catch(int x)
	{
		if(x == 5)
			cout<<"File empty";
	}
}