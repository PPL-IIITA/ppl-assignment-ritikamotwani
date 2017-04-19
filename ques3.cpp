//!< The class in file inh_pair shows inheritance
//!<question2 using inheritance
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"inh_pair.h"
#include<ctime>
#include "couple.h"
#include "gift.h"
#include "boy.h"
#include "girl.h"
#include "Fill.h"
using namespace std;
int main()
{
	MakePair p;
	p.input();
	p.giftin();
	p.find_happiness();
	p.print();
	
	return 0;
}
