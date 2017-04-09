//!< Hash table formed for storing the couples. Linear Probing is implemented.
#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<cstdio>
#include<string.h>
#include<math.h>
#include"boy.h"
#include"girl.h"
#include"couple.h"
#include"hash.h"
#include"inh_pair.h"
using namespace std;
void hash :: function()
{
	
		int i,j;
		MakePair pr;
		pr.input();
	Couple hash_table[20];
	int arr[20];
	for (i = 0; i < pr.k;i++)
	{
		arr[i] = 0;
	}
	for(i=0;i<pr.k;i++)
	{
		int m = 0;
		int z;
		z = pr.c[i].b.intell_b % pr.k;
		if(arr[z] == 0)
		{
			hash_table[z] = pr.c[i];
			arr[z] = 1;
		}
		else
		{
			for(j = z+1;j < pr.k;j++)
			{
				if(arr[j] == 0)
				{
					hash_table[j] = pr.c[i];
					arr[j] = 1;
					m = 1;
					break;
				}
			}
			if(m == 0)
			{
				for(j = 0;j < z;j++)
				{
					if(arr[j] == 0)
					{
						hash_table[j] = pr.c[i];
						arr[j] = 1;
						m = 1;
						break;
					}
				}
			}
		}
	}
	freopen("Three_Ways.txt","w",stdout);
	printf("%d\n",pr.k);
	printf("The values are in the order name,type,attractiveness,intelligence,budget\n");
	for(i=0;i<pr.k;i++)
	{
		if(arr[i] == 1)
		{
			cout<<"\n\n";
			time_t now = time(0);
			char *ct = ctime(&now);
			cout<<ct<<"\n\n";
			printf("%s %d %d %d %d \n",hash_table[i].b.name,hash_table[i].b.type,hash_table[i].b.attractive,hash_table[i].b.intell_b,hash_table[i].b.budget);
		}
	}

}