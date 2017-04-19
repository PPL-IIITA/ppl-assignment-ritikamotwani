//!< The functions are in the file break_up_k.h
//!< break_up_function is a function that performs break up of k least happy couples and form_couple form new pairs
//!< Output is stored in new_couple.txt
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//#include "break_up_k.h"
#include"inh_pair.h"
using namespace std;
int main()
{

	//Break_Up_k b;
	MakePair b;
	b.input();
	b.giftin();
	b.find_happiness();
	b.break_up_function();
	b.form_couple();
}