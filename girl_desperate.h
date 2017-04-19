#include "girl.h"
#include <stdio.h>
#include <string.h>
	//!< inheritance
class Desperate : public Girl {
	public :
		
		Desperate (char *namei, int atr, int intl, int man_cost, int criteria) {
			type = 1;
			strcpy (name, namei);
			attractive = atr;
			intell_g = intl;
			maint = man_cost;
			check = criteria;
			committed = 0;
		}
};