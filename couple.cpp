#include<iostream>
#include<string>
#include<cmath>
#include"boy.h"
#include"couple.h"
using namespace std;
void Couple::happiness()
{
	
	happy = g.happy + b.happy;   
	//!<Calculates Happiness of the couple	
	
}
void Couple::compatibility()
{
	compatible = (b.budget-g.maint)+abs(b.attractive-g.attractive)+abs(g.intell_g-b.intell_b);
	//!<Calculates couple's compatibility
}
