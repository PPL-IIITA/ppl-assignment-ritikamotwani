
//!< Output stored in file happ_comp.txt
//!< In this class data is filled from the subclass to the parent class.
#include <iostream>
#include <ctime>
#include "couple.h"
#include "gift.h"
#include <stdlib.h>
#include <string.h>
#include "inh_pair.h"
#include "girl.h"
#include "boy.h"
#include <stdio.h>
#include "Fill.h"
#include <exception>
using namespace std;
void MakePair :: input()
{
	int i, j;
	fobj.fill_data(b, go);
	int num_boy = fobj.num_boys;
	int  num_girl = fobj.num_girls;
	k = 0;

	int p,in;
	for(i=0;i<=num_girl;i++)
	//!<The criteria of all the girls in choosing a boy
	{
		in=1;p=0;
		for(j=0;j<num_boy;j++)
		{
			if(b[j].committed==1||b[j].budget<go[i].maint||b[j].min_attr>go[i].attractive)
				continue;
			if(go[i].check == 0)
			{
				if(b[j].attractive>b[in].attractive)
				{
				
					in = j;
					p=1;
				}
			}
			else if(go[i].check == 1)
			{
				if(b[j].budget>b[in].budget)
				{
				
					in=j;
					p=1;
				}
			}
			else if(go[i].check == 2)
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
			go[i].committed = 1;
			c[k].g = go[i];
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
	//fclose(stdout);
}
//!< In this function gifting is done on the basis of boy's budget.
//!< Exception handling used in this function if the number of gifts is 0.
void MakePair::giftin()
{
	int num_gift,i,j,g;
	FILE *f1,*f2;
	try
	{
		f1 = fopen("gifts_l.txt","r");
		fscanf(f1,"%d",&num_gift);
		if(num_gift == 0)
			throw 10;
		Gift gf[54];
		for(i=0;i<=num_gift;i++)
					fscanf(f1,"%d %d %d %d %d %d %d %d\n",&gf[i].value,&gf[i].price,&gf[i].type,&gf[i].which,&gf[i].luxury_rate,&gf[i].difficulty,&gf[i].utility_value,&gf[i].utility_class);
		freopen("happ_comp.txt","w",stdout);
		int l = 1,total_budget,tb1;
		int Min = 0;
		for(i = 1; i <num_gift; i++)
		{
			if(gf[i].price < gf[Min].price)
				Min = i;
		}
		for(i = 0; i < k; i++)
		{
			int min = 0;
			l = 1;
			if(c[i].b.type == 0)
			{
				total_budget = c[i].g.maint + ((c[i].b.budget - c[i].g.maint)/3);
			}
			else if(c[i].b.type == 1)
			{
				total_budget = c[i].b.budget;
			}
			else if(c[i].b.type == 2)
			{
				total_budget = c[i].g.maint + ((c[i].b.budget-c[i].g.maint)/3);
				tb1 = total_budget;
			}
			while(total_budget > 0)
			{
				if(c[i].b.type == 1)
					gf[0].price = 0;
				else
					gf[0].price = 11000;
				min = 0;
				for(j = 1;j < num_gift;j++)
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
						if(total_budget < gf[Min].price)
							break;
						else
						{
							if(gf[j].price>gf[min].price&&gf[j].price<=total_budget)
							{
								min = j;
							}
						}
					}
				}
				if(total_budget >= gf[min].price && min != 0)
				{
					gf[min].which = 1;
					cg[i][l] = gf[min];
					total_budget = total_budget - gf[min].price;
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
					total_budget = 0;
					l++;
					break;
				}

			}
			if(c[i].b.type == 2)
			{
				int tb2;
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
			cout<<"Excception . The file has 0 gifts";
	}

}
//!< k happy couples are seen. 
void MakePair::find_happiness()
{
	//freopen("happ_comp.txt","w",stdout);
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
		//printf ("Girl  %d   Boy  %d\n",c[i].g.happy,c[i].b.happy);
		//printf("Girl   %d   Boy   %d\n",c[i].g.type,c[i].b.type);
		c[i].happiness();
		c[i].compatibility();
				//		printf("Couple's  : Happiness %d && Compatibility %d\n",c[i].happy,c[i].compatible);
	}
}
void MakePair::print()
{
	int i;
/*	for(i = 0;i < k;i++)
		printf("%s %s ",c[i].g.name,c[i].b.name);*/
	int q,j;

	cin>>q;
	if(q > k )
		cout<<" The value of k should be less than "<<k;
	char n[10],m[10],x[10],y[10];
	int a,b,a1=30000,b1=30000;
	printf("\n \n \n \n \n \n \n HAPPINESS and COMPATIBILITY\n\n");
	for(i=0;i<q;i++)
	{
		a =0;
		b = 0;
		for(j=0;j<k;j++)
		{
			if(c[j].happy>a && c[j].happy < a1)
			{
				
				a = c[j].happy;
				strcpy(n,c[j].g.name);
				//printf("%s ",c[j].g.name);
				strcpy(m,c[j].b.name);
			}

			if(c[j].compatible > b && c[j].compatible<b1)
			{
				b = c[j].compatible;
				strcpy(x,c[j].g.name);
				strcpy(y,c[j].b.name);
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
	fclose(stdout);

}
//!< Break Up of k less happy Couples is performed in the break_up_function.
void MakePair::break_up_function()
{
	int q;
	cout<<"Enter the value of  k\n";
	cin >> q;
	int i,j,temp;
	char n[10],m[10];
	for(i = 0;i < k; i++)
	{
		for(j=0;j<k-1;j++)
		{
			if(c[j].happy > c[j+1].happy)
			{
				temp = c[j].happy;
				c[j].happy = c[j+1].happy;
				c[j+1].happy = temp;
				strcpy(n,c[j].g.name);
				strcpy(c[j].g.name,c[j+1].g.name);
				strcpy(c[j+1].g.name,n);
				strcpy(n,c[j].b.name);
				strcpy(c[j].b.name,c[j+1].b.name);
				strcpy(c[j+1].b.name,n);

			}
		}
	}
	for(i = 0;i < q;i++)
	{
		//printf("%s   %s   %d\n",c[i].b.name,c[i].g.name,c[i].happy);
		c[i].g.committed = 0;
		strcpy(c[i].g.no,c[i].b.name);
	}

}
//!< Happiness of all couples is calculated and couple who are less happy breakup and find a new partner from the remaining single peeople
void MakePair::form_couple()
{
	freopen("new_couple.txt","w",stdout);
	int i,num_boy,j,in,p;
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
		for(j=0;j<k;j++)
		{
			if(!(strcmp(b[i].name,c[j].b.name)))
			{
				b[i].committed = c[j].b.committed;
			}
		}
	}
	for(i = 0; i < k; i++)
	{
		if(c[i].g.committed == 0)
		{
			in = 0;
			p = 0;
			for(j=1;j<=num_boy;j++)
			{
				if(b[j].committed==1||b[j].budget<c[i].g.maint||b[j].min_attr>c[i].g.attractive||(!(strcmp(b[j].name,c[i].g.no))))
					continue;
				if(c[i].g.check == 0)
				{
					if(b[j].attractive>b[in].attractive)
					{
				
						in = j;
						p=1;
					}
				}
				else if(c[i].g.check == 1)
				{
					if(b[j].budget>b[in].budget)
					{
				
						in=j;
						p=1;
					}
				}
				else if(c[i].g.check == 2)
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
				c[i].b = b[in];
				c[i].g.committed = 1;
			}
		}
	}
	printf("%d\n",k);
	for(i = 0;i <k;i++)
	{
		time_t now = time(0);
		char *ct = ctime(&now);
		cout<<"\n\n";
		cout<<ct<<"\n\n";
		printf("%s %d %d %d %d %d %d\n",c[i].g.name,c[i].g.committed,c[i].g.type,c[i].g.attractive,c[i].g.intell_g,c[i].g.maint,c[i].g.check);
		printf("%s %d %d %d %d %d %d\n",c[i].b.name,c[i].b.committed,c[i].b.type,c[i].b.attractive,c[i].b.intell_b,c[i].b.budget,c[i].b.min_attr);
	}
}
