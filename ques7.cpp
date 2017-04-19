//!< Three classes are formed :
//!<1. To store the couples in an array format. The  class used is Array_Class.
//!<2. To store the couples in a sorted array. Sorting is done on the basis of attractiveness of the boy. The class used is Sorted_Calass.
//!<3. To store the couples in the form of a hash table.(Linear Probing used). The class ued is hash
//!< 4. Exception handled if the value of n is incorrect. 
#include"couple.h"
#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include"Array_Class.h"
#include "Sorted_Class.h"
#include "hash.h"
using namespace std;
//!< Output is in Three_Ways.txt
int main()
{
	try
	{
		int n;
		if(n > 4 || n <= 0)
			throw 5;
		cout<<"1. Array\n2. Sorted Array\n3. Hash Table\n ";
		cin>>n;
		if(n == 1)
		{
			Array_Class a;
			a.function();
		}
		else if(n == 2)
		{
			cout<<"Sorting on the basis of attractiveness of the boy\n";
			Sorted_Class d;
			d.function();
		}
		else if(n == 3)
		{
			cout<<"Linear Probing implemented and hash table mapped by the hash function on intelligence\n";
			hash h;
			h.function();
		}
	}
	catch(int x)
	{
		if(x == 5)
			cout<<"n entered is incorrect\n";
		return 0;
	}
}
