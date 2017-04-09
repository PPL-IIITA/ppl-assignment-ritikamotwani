//!<gifting is not limited to Valentines day alone, but t days in a calendar month, well-marked. After
//!< every such day, couples with happiness less than t break up and form new couples.
//!< Functions of question 4 also used .
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cmath>
#include "t_days.h"
using namespace std;
int main()
{
	int t;
	cout<<"Enter value of t\n";
	cin >> t;
	t_days a;
	int i;
	for( i =0;i < t;i++)
	{
		a.break_up_function(t);
	}
	a.print();
}