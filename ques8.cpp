//!< There are two types of gift allocation in this question
//!< 1. All three types of gifts are give (luxury, utility, normal)
//!< 2. Default typeas in question 2

#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<string>
#include<cmath>
#include"make_pair.h"
#include"NewWay.h"
using namespace std;
int main()
{
	int n;
	cout<<"Enter Choice for gift allocation:\n1. Each type of gift given\n2. Default\n";
	cin>>n;
	if(n == 1)
	{
		NewWay n;
		n.allocation();
	}
	else if(n == 2)
	{
		Pair p;
		p.input();
	}
}