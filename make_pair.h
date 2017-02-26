#ifndef MAKE_PAIR_H_
#define MAKE_PAIR_H_
#include"couple.h"
#include"gift.h"
#include"boy.h"
#include"girl.h"
class Pair
{
	public :
		int k;
		Couple c[30];
		Gift cg[100][100];
		void input();
		void find_happiness();
};
#endif
