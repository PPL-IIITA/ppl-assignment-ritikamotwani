//!< Output stored in order_couple.txt
//!< Exception Handled when the number of boys and number of girls in the text file is 0.
#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<stdio.h>
#include<cmath>
#include<string>
#include "girl.h"
#include "boy.h"
#include "couple.h"
#include <exception>
class NewCouple
{
public:
	void select()
	{
		try
		{
			int cnt = 0;
			FILE *f1,*f2;
			f1 = fopen("girls_l.txt","r");
			f2 = fopen("boys_l.txt","r");
			int num_girl,num_boy,i,j;
			fscanf(f1, "%d",&num_girl);
			fscanf(f2, "%d",&num_boy);
			if(num_boy == 0 && num_girl == 0)
				throw 10;
			Girl g[20];
			Boy b[31];
			for(i=0;i<num_girl;i++)
			{
			
				fscanf(f1,"%s %d %d %d %d %d %d",g[i].name,&g[i].committed,&g[i].type,&g[i].attractive,&g[i].intell_g,&g[i].maint,&g[i].check);
			}
			for(i=0;i<num_boy;i++)
			{
			
				fscanf(f2,"%s %d %d %d %d %d %d",b[i].name,&b[i].committed,&b[i].type,&b[i].attractive,&b[i].intell_b,&b[i].budget,&b[i].min_attr);	
			}
			Girl temp;
			for(i = 0; i < num_girl; i++)
			{
				for(j = 1; j< num_girl-1;j++)
				{
					if(g[j].maint > g[j+1].maint)
					{
						temp = g[j];
						g[j] = g[j+1];
						g[j+1] = temp;
					}
				}
			}
			freopen("order_couple.txt","w",stdout);
			Boy temp1;
			for(i = 0; i < num_boy; i++)
			{
				for(j = 0; j< num_boy-1;j++)
				{
					if(b[j].attractive > b[j+1].attractive)
					{
						temp1 = b[j];
						b[j] = b[j+1];
						b[j+1] = temp1;
					}
				}
			}
			for(i = 0;i < num_girl;i++)
			{
				printf("%s  %d\n",g[i].name,g[i].maint);
			}
			printf("\n\n");
			for(i = 0; i < num_boy; i++)
			{
				printf("%s   %d\n",b[i].name,b[i].attractive);
			}
			printf("\n\n");
			Couple c[20];
			int k = 0;
			int p,in;
			int tmp = num_girl;
			while(tmp--)
			{
				if(cnt%2 == 0)
				{
					for(i = 0;i < num_girl; i++)
					{
						in = 1;
						p = 0;
						if(g[i].committed == 0)
						{
							for(j=0;j<num_boy;j++)
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
						}
						if(p == 1)
						{
							if(b[in].committed == 1 || g[i].committed == 1)
								continue;
							b[in].committed = 1;
							g[i].committed = 1;
							c[k].g = g[i];
							c[k].b = b[in];
							k++;
							cnt = cnt + 1;
			//				printf("%s  %s\n",c[k-1].g.name,c[k-1].b.name);
							break;	
						}
					}
				}
				else
				{
					int ch;
					for(i = 0;i < num_boy;i++)
					{
						if(b[i].committed == 0) 
						{
							for(j = 0; j < num_girl;j++)
							{
								if(b[i].budget < g[j].maint || b[i].min_attr > g[j].attractive)
									continue;
								int max,o;
								if(g[j].committed == 0)
								{
									max = g[j].attractive;
									ch = j;
									for(o=j;o<=num_girl;o++)
									{
										if(g[o].committed == 0)
										{
											if(g[o].attractive > max)
											{
												max = g[j].attractive;
												ch = j;	
											}
										}
									}

								}

							}

						}
						if(b[i].committed == 1 || g[ch].committed == 1)
							continue;
						b[i].committed = 1;
						g[ch].committed = 1;
						c[k].b= b[i];
						c[k].g = g[ch];
						k++;
						cnt++;
			//			printf("%s   %s\n",c[k-1].b.name,c[k-1].g.name);
						break;
					}
				}
		
			}
			printf("\n");
			printf("%d\n",k);
			for(i = 0;i<k;i++)
			{
				time_t now = time(0);
				char *ct = ctime(&now);
				cout<<ct<<"\n\n";
				printf("%s %d %d %d %d %d %d\n",c[i].g.name,c[i].g.committed,c[i].g.type,c[i].g.attractive,c[i].g.intell_g,c[i].g.maint,c[i].g.check);
				printf("%s %d %d %d %d %d %d\n",c[i].b.name,c[i].b.committed,c[i].b.type,c[i].b.attractive,c[i].b.intell_b,c[i].b.budget,c[i].b.min_attr);
			}
		}
		catch(int x)
		{
			if(x == 10)
				cout<<"Number of boys and girls is 0";
		}
	}

};