//!< Couples are formed on the basis of a secondary criteria. Output is stored in ques9.txt and ques9_gifts.txt.
#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<string>
#include<cmath>
#include"secondary.h"
using namespace std;
int main()
{
	secondary s;
	s.newList();

	s.formPair();
	s.newGifts();
	s.gifting();
}