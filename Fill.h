#ifndef FILL_DATA_H
#define FILL_DATA_H
#include "couple.h"
	//!< Fills data in the array
class Fill {
	public:
		int num_boys;		//!< Number of boys
		int num_girls;		//!< Number of girls
		int num_gifts;		//!< Number of gifts
		void fill_data(Boy b[], Girl go[]);		//!<  will result in transferring information of all girls and boys into array
};
#endif