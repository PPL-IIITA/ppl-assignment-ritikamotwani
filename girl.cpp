//!<Finds the happiness of every girl
#include<iostream>
#include"girl.h"
#include<cmath>
using namespace std;
void Girl::happiness(int total_cost,int total_value)
{
	{
		if(type == 0)  // !<choosy
		{
			happy = log(total_cost-maint);
		}
		else if(type == 1)  // !<normal
		{
			happy = (total_cost - maint) + total_value;
		}
		else if(type == 2)  // !<desperate
		{
			happy = (int)(exp((total_cost-maint)%10));
			// !<exponent makes the result exceed the range of integer hence the mod;
		}
	}
}
