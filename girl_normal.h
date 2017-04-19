#include "girl.h"
#include <stdio.h>
#include <string.h>
	
class Normal : public Girl {
	public :
		
		Normal (char *namei, int atr, int intl, int man_cost, int criteria) {
			type = 2;
			strcpy (name, namei);
			attractive = atr;
			intell_g = intl;
			maint = man_cost;
			check = criteria;
			committed = 0;
		}	
};