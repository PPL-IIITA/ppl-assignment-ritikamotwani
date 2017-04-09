#ifndef COUPLE_H
#define COUPLE_H
#include"boy.h"
#include "girl.h"
#include "boy.h"
#include "gift.h"
#include "girl_choosy.h"
#include "girl_normal.h"
#include "girl_desperate.h"
#include "boy_geeks.h"
#include "boy_generous.h"
#include "boy_miser.h"
class Couple 
{
	public :
		Girl g;
		Boy b;
		int happy;
		int compatible;
		void happiness();
		void compatibility();
};
#endif
