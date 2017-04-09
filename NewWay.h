#ifndef NEWWAY_H_
#define NEWWAY_H_
#include"couple.h"
#include"gift.h"
#include"boy.h"
#include"girl.h"
class NewWay
{
	public :
		int k;
		Couple c[30];
		void allocation();//!< This function is the second type of gift allocation in which every type of gift is given then the normal distribution is done according to the budget left.
};
#endif
