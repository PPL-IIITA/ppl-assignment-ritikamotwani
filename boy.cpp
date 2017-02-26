//!< A class to calculate as boy's happiness in a relationship
#include<iostream>
#include"boy.h"
#include"girl.h"
using namespace std;
void Boy::happiness(int total_cost,Girl& g)
{
	if(type == 0)                    //!<miser
	{
		happy = budget - total_cost;
				
	}
	else if(type == 1)         //!<generous
	{
		happy = g.happy;
	}
	else if(type == 2)    //!<geek
	{
		happy = g.intell_g;
	}
}
