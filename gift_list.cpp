//!< Finds the type of the gift and generates all its parametrs
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
	int value[51],price[51],type[51],which[51],luxury_rate[51];
	int difficulty[51],utility_value[51],utility_class[51],i,j;
	srand(time(NULL));
	freopen("gifts_l.txt","w",stdout);
	for(i=1;i<=50;i++)
	{
		value[i] = rand() % 51;
		type[i] = rand() % 3;
		which[i] = 0;
		if(type[i] == 0)
		{
			price[i] = 200 + (rand()%1501);
			difficulty[i] = -1;
			luxury_rate[i] = -1;
			utility_value[i] = -1;
			utility_class[i] = -1;
		}
		else if(type[i] == 1)
		{
			price[i] = 3000 + (rand()%1001);
			luxury_rate[i] = rand()%11;
			difficulty[i] = rand()%10;
			utility_value[i] = -1;
			utility_class[i] = -1;
		}
		else if(type[i] == 2)
		{
			price[i] = 4500 + (rand()%1001);
			luxury_rate[i] = -1;
			difficulty[i] = -1;
			utility_value[i] = rand()%11;
			utility_class[i] = rand()%5;
		}

	}
	printf("50\n");
	value[0] = -1;
	price[0] = 0;
	which[0] = 0;
	type[0] = -1;
	luxury_rate[0] = -1;
	difficulty[0] = -1;
	utility_value[0] = 0;
	utility_class[0] = -1;
	for(i=0;i<=50;i++)
	{
		printf("%d %d %d %d %d %d %d %d \n",value[i],price[i],type[i],which[i],luxury_rate[i],difficulty[i],utility_value[i],utility_class[i]);
	}
	return 0;
}
