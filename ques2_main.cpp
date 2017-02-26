/*Question 2
It finds the first k happy and k most compatible couples formed */
#include<iostream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"make_pair.h"
#include<ctime>
using namespace std;
int main()
{
	Pair p;
	p.input();
	p.find_happiness();
	int q,i,j;
	cin>>q;
	char n[10],m[10],x[10],y[10];
	int a,b,a1=30000,b1=30000;
	printf("\n \n \n \n \n \n \n HAPPINESS and COMPATIBILITY\n\n");
	for(i=0;i<q;i++)
	{
		a =0;
		b = 0;
		for(j=0;j<p.k;j++)
		{
			if(p.c[j].happy>a&&p.c[j].happy < a1)
			{
				a=p.c[j].happy;
				strcpy(n,p.c[j].g.name);
				strcpy(m,p.c[j].b.name);
			}

			if(p.c[j].compatible>b&&p.c[j].compatible<b1)
			{
				b=p.c[j].compatible;
				strcpy(x,p.c[j].g.name);
				strcpy(y,p.c[j].b.name);
			}
		}
		a1=a;
		b1=b;
		time_t now = time(0);
		char *ct = ctime(&now);
		cout<<ct;
		printf("\t\tHAPPY %d.%s    %s  -> %d\n",(i+1),n,m,a);
		printf("\t\tCOMPATIBLE  %d.%s  %s ->%d\n",(i+1),x,y,b);
		printf("\n\n");
	}

	return 0;
}
