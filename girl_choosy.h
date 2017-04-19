#include "girl.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
	//!< A type of girl
class Choosy : public Girl {
	public :
		//!< Constructor
		Choosy (char *namei, int atr, int intl, int man_cost, int criteria) {
			type = 0;
			strcpy (name, namei);
			attractive = atr;
			intell_g = intl;
			maint = man_cost;
			check = criteria;
			committed = 0;
			
		}	
};