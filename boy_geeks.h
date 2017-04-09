#include "boy.h"
#include <stdio.h>
#include <string.h>
class Geek : public Boy {
	public :
		//!< Inheritance shown.
		Geek (char *namei, int atr, int intl, int budget1, int min_atr) {
			type = 2;
			strcpy (name, namei);
			attractive = atr;
			intell_b = intl;
			budget = budget1;
			min_attr = min_atr;
			committed = 0;
		}	
};