
#ifndef SECONDARY_H_
#define SECONDARY_H_
#include"girl.h"
#include"boy.h"
#include"gift.h"
#include"couple.h"
class secondary
{
	public:
		Gift gf[40];
		Girl g[20];
		Boy b[31];
		Couple c[30];
		int k;
		int total;
		void newList();
		void formPair();
		void newGifts();
		void gifting();
};
#endif