#ifndef BOY_H
#define BOY_H
#include"girl.h"
using namespace std;
class Boy
{
	public:
		int committed;
		int type;
		char name[10];
		int attractive;
		int intell_b;
		int budget;
		int min_attr;
		int happy;
		int not_choose;
		void happiness(int total_cost,Girl &g);
};
#endif
//!<All the variables and member functions are declared here
