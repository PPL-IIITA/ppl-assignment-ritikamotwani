//!< Sorting on the basis of attractiveness is done .
#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<cstdio>
#include<string.h>
#include<math.h>
#include"boy.h"
#include"girl.h"
#include"couple.h"
#include "Sorted_Class.h"
#include"inh_pair.h"
using namespace std;
void Sorted_Class :: function()
{
	
		int i,j;
		MakePair pr;
		pr.input();
	Couple temp;
	for(i = 0;i<pr.k;i++)
	{
		for(j = 0;j<pr.k-1;j++)
		{
			if(pr.c[j].b.attractive > pr.c[j+1].b.attractive)
			{
				temp = pr.c[j];
				pr.c[j] = pr.c[j+1];
				pr.c[j+1] = temp;
			}
		}
	}
	freopen("Three_Ways.txt","w",stdout);
	printf("%d\n",pr.k);
	printf("The values are in the order name,type,attractiveness,intelligence,budget\n");
	for(i=0;i<pr.k;i++)
	{
		cout<<"\n\n";
		time_t now = time(0);
		char *ct = ctime(&now);
		cout<<ct<<"\n\n";

		printf("%s %d %d %d %d \n",pr.c[i].b.name,pr.c[i].b.type,pr.c[i].b.attractive,pr.c[i].b.intell_b,pr.c[i].b.budget);
	}
}