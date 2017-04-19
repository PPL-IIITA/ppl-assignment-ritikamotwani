//!< New list of girls and boys are formed according to the value of k and are stored in new_list_boy.txt , new_list_girl.txt respectively.
//!< top k chosen according to the primary criteria and stored in a file.
//!< New list of gifts is stored in new_list_gift.txt.
#include<iostream>

#include<ctime>
#include<string.h>
#include<stdio.h>
#include "girl.h"
#include "boy.h"
#include "secondary.h"
#include"couple.h"
using namespace std;
void secondary :: newList()
{
	cout<<"Enter k(Less than total girls)\n";
	cin>>k;
	FILE *f1,*f2;
	f1 = fopen("girls_l.txt","r");
	f2 = fopen("boys_l.txt","r");
	int num_girl,num_boy,i,j;
	fscanf(f1, "%d",&num_girl);
	fscanf(f2, "%d",&num_boy);
	Girl g[20];
	Boy b[31];
	for(i=0;i<=num_girl;i++)
	{
		
		fscanf(f1,"%s %d %d %d %d %d %d",g[i].name,&g[i].committed,&g[i].type,&g[i].attractive,&g[i].intell_g,&g[i].maint,&g[i].check);
	}
	for(i=0;i<=num_boy;i++)
	{
		
		fscanf(f2,"%s %d %d %d %d %d %d",b[i].name,&b[i].committed,&b[i].type,&b[i].attractive,&b[i].intell_b,&b[i].budget,&b[i].min_attr);	
	}
	freopen("new_list_boy.txt","w",stdout);
	printf("%d\n",k);
	for(i = 1;i <= num_boy; i++)
	{
		for(j = 1; j < num_boy; j++)
		{
			if(b[j].budget > b[j+1].budget)
			{
				Boy b1;
				b1 = b[j];
				b[j] = b[j+1];
				b[j+1] = b1;
			}
		}
	}
	for(i = num_boy; i > num_boy-k; i--)
		printf("%s %d %d %d %d %d %d\n",b[i].name,b[i].committed,b[i].type,b[i].attractive,b[i].intell_b,b[i].budget,b[i].min_attr);
	fclose(stdout);

	freopen("new_list_girl.txt","w",stdout);
	printf("%d\n",k);
	for(i = 1;i <= num_girl; i++)
	{
		for(j = 1; j < num_girl; j++)
		{
			if(g[j].attractive > g[j+1].attractive)
			{
				Girl b1;
				b1 = g[j];
				g[j] = g[j+1];
				g[j+1] = b1;
			}
		}
	}
	for(i = num_girl; i > num_girl-k; i--)
		printf("%s %d %d %d %d %d %d\n",g[i].name,g[i].committed,g[i].type,g[i].attractive,g[i].intell_g,g[i].maint,g[i].check);
	fclose(stdout);
}
void secondary :: formPair()
{
	freopen("ques9.txt","w",stdout);
	FILE *f1,*f2;
	f1 = fopen("new_list_girl.txt","r");
	f2 = fopen("new_list_boy.txt","r");
	int num_girl,num_boy,i,j;
	fscanf(f1, "%d",&num_girl);
	fscanf(f2, "%d",&num_boy);
	Girl g[20];
	Boy b[31];
	for(i=0;i< num_girl;i++)
	{
		
		fscanf(f1,"%s %d %d %d %d %d %d",g[i].name,&g[i].committed,&g[i].type,&g[i].attractive,&g[i].intell_g,&g[i].maint,&g[i].check);
	}
	for(i=0;i<num_boy;i++)
	{
		
		fscanf(f2,"%s %d %d %d %d %d %d",b[i].name,&b[i].committed,&b[i].type,&b[i].attractive,&b[i].intell_b,&b[i].budget,&b[i].min_attr);	
	}
	int p,in;
	total = 0;
	for(i=0;i<num_girl;i++)
	/*The criteria of all the girls in choosing a boy*/
	{
		in=1;p=0;
		for(j=1;j<=num_boy;j++)
		{
			if(b[j].committed==1||b[j].budget<g[i].maint||b[j].min_attr>g[i].attractive)
				continue;
			if(g[i].check == 0)
			{
				if(b[j].attractive>b[in].attractive)
				{
				
					in = j;
					p=1;
				}
			}
			else if(g[i].check == 1)
			{
				if(b[j].budget>b[in].budget)
				{
				
					in=j;
					p=1;
				}
			}
			else if(g[i].check == 2)
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
			g[i].committed = 1;
			c[total].g = g[i];
			c[total].b = b[in];
			total++;	
		}
	}
	printf("%d\n",total);
	for(i=0;i<total;i++)
	{
		cout<<"\n";
		time_t now = time(0);
		char *ct = ctime(&now);
		cout<<ct;
		cout<<"\n";
		printf("%s %d %d %d %d %d %d\n",c[i].g.name,c[i].g.committed,c[i].g.type,c[i].g.attractive,c[i].g.intell_g,c[i].g.maint,c[i].g.check);
		printf("%s %d %d %d %d %d %d\n",c[i].b.name,c[i].b.committed,c[i].b.type,c[i].b.attractive,c[i].b.intell_b,c[i].b.budget,c[i].b.min_attr);
	}
	cout<<"\n\n";
}
void secondary::newGifts()
{
	int num_gift,i,j;
	FILE *f1;
	f1 = fopen("gifts_l.txt","r");
	fscanf(f1,"%d",&num_gift);
	for(i=0;i<=num_gift;i++)
		fscanf(f1,"%d %d %d %d %d %d %d %d\n",&gf[i].value,&gf[i].price,&gf[i].type,&gf[i].which,&gf[i].luxury_rate,&gf[i].difficulty,&gf[i].utility_value,&gf[i].utility_class);
	for(i = 1; i <= num_gift; i++)
	{
		for(j = 1; j < num_gift-1; j++)
		{
			if(gf[j].price > gf[j+1].price)
			{
				Gift temp;
				temp = gf[j];
				gf[j] = gf[j+1];
				gf[j+1] = temp;
			}
		}
	}
	freopen("new_list_gift.txt","w",stdout);
	cout<<k<<"\n";
	for(i = 1; i <= k; i++)
	{
		printf("%d %d %d %d %d %d %d %d\n", gf[i].value,gf[i].price,gf[i].type,gf[i].which,gf[i].luxury_rate,gf[i].difficulty,gf[i].utility_value,gf[i].utility_class);
	}
	fclose(stdout);
}
void secondary::gifting()
{
	int num_gift,i,j;
	FILE *f1;
	f1 = fopen("new_list_gift.txt","r");
	fscanf(f1,"%d",&num_gift);
	for(i=0;i<num_gift;i++)
		fscanf(f1,"%d %d %d %d %d %d %d %d\n",&gf[i].value,&gf[i].price,&gf[i].type,&gf[i].which,&gf[i].luxury_rate,&gf[i].difficulty,&gf[i].utility_value,&gf[i].utility_class);	
	for(i = 0; i < num_gift; i++)
	{
		for(j = 0; j <num_gift-1; j++)
		{
			Gift tmp;
			if(gf[j].value > gf[j+1].value)
			{
				tmp = gf[j];
				gf[j] = gf[j+1];
				gf[j+1] = tmp;
			}
		}
	}
	freopen("ques9_gifts.txt","w",stdout);
	for(i = 0; i < total; i++)
	{
		cout<<"Gifts exchanged by Couple"<<i+1<<"\n";
		cout<<"Value , Price, Type\n";
		int tb = c[i].b.budget;
		for(j = 0; j < num_gift; j++)
		{
			if(gf[j].which == 0 && tb > gf[j].price && tb >0)
			{
				cout<<gf[j].value<<" , "<<gf[j].price<<" , "<<gf[j].type<<"\n";
				gf[j].which = 1;
			}
		}
		for(j = 0; j < num_gift; j++)
			gf[j].which = 0;
		cout<<"\n\n\n";
	}
	

}