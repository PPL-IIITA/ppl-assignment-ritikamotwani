// !<This is question 1 of the ssignment. It basically reads all the parameters of the girl and the boy and then checks which girl and boy can form a // !<couple and stores all the couple in a file
//!<The basic criteria are :
// !<1. the girl and the boy should be single
// !<2. maintenance cost of the girl should be less than the guy's budget
// !<3. the attractiveness of the girl should be more than the minimum atrractive value a boy wants; */
#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include"couple.h"
using namespace std;
int main()
{
	
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
	Couple c[20];
	int k = 0;
	int p,in;
	for(i=1;i<=num_girl;i++)
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
			c[k].g = g[i];
			c[k].b = b[in];
			k++;	
		}
	}
	freopen("couple.txt","w",stdout);
	printf("%d\n",k);
	for(i=0;i<k;i++)
	{
		printf("%s %d %d %d %d %d %d\n",c[i].g.name,c[i].g.committed,c[i].g.type,c[i].g.attractive,c[i].g.intell_g,c[i].g.maint,c[i].g.check);
		printf("%s %d %d %d %d %d %d\n",c[i].b.name,c[i].b.committed,c[i].b.type,c[i].b.attractive,c[i].b.intell_b,c[i].b.budget,c[i].b.min_attr);
	}
	return 0;

}
