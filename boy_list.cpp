/*!< This program is generating the random input values for all the boys in the virtual world*/
#include<stdio.h>
#include<iostream>
#include<time.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main()
{
	srand(time(NULL));
	freopen("boys_l.txt","w",stdout);
	char name[30][10];
	int attractive[50],intell_b[50],budget[50],type[50],committed[50];
	int min_attr[50],i,k,j;
	for(i=1;i<=30;i++)
	{
		for(j=0;j<5;j++)
			name[i][j]=(rand()%26)+97;
		name[i][j]='\0';                                                //!<random generation of name
	}
	for(i=1;i<=30;i++)
	{
		type[i] = rand()%3;
		committed[i]=0;
		attractive[i]=rand()%11;                                  //!<Attributes of a boy are assigned here 
		intell_b[i]=rand()%11;
		budget[i]=5000+(rand()%9000);
		min_attr[i]=rand()%6;
	}
	printf("30\n");
	strcpy(name[0],"");
	committed[0]=0;
	type[0]=0;
	min_attr[0]=0;
	intell_b[0]=-1;
	budget[0]=-1;
	attractive[0]=-1;
	for(i=0;i<=30;i++)
	{
		printf("%s %d %d %d %d %d %d\n",name[i],committed[i],type[i],attractive[i],intell_b[i],budget[i],min_attr[i]);

	}
	return 0;
}
