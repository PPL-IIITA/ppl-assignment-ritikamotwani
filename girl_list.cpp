// !< Generates random input values for all girls and all the parameters used
#include<iostream>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
	srand(time(NULL));
	freopen("girls_l.txt","w",stdout);
	char name[15][7];
	int i,j,k,committed[50],type[50],attractive[50],intell_g[50];
	int maint[50],check[50];
	for(i=1 ; i<=15 ; i++)
	{
		for(j=0 ; j<5; j++)
			name[i][j] = (rand()%26) + 97;
		name[i][j]='\0';
	}
	for(i=1;i<=15;i++)
	{
		type[i] = rand()%3;
		committed[i] = 0;
		attractive[i] = rand()%11;
		intell_g[i] = rand()%11;
		maint[i] = 5000 + (rand()%5000);
		check[i] = rand() % 3;
	}
	cout<<"15\n";
	strcpy(name[0]," ");
	committed[0] = 0;
	type[0] = 0;
	attractive[0] = -1;
	intell_g[0] = -1;
	maint[0] = 1;
	check[0] = -1;
	for(i = 0;i <= 15;i++)
		printf("%s %d %d %d %d %d %d\n",name[i],committed[i],type[i],attractive[i],intell_g[i],maint[i],check[i]);
	return 0;
}
