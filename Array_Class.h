//!< Boys are stored in the form of an object array. 
//!< Inheritance is used .
#include<iostream>
#include<stdlib.h>
#include<cstdio>
#include<string.h>
#include<math.h>
#include"boy.h"
#include"girl.h"
#include"couple.h"
#include "inh_pair.h"
class Array_Class
{
	public:
	void function(){
	

		int i;
		MakePair pr;
		pr.input();
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
};
