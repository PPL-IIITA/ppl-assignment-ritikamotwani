#ifndef T_DAYS_H_
#define T_DAYS_H_
#include "inh_pair.h"
class t_days
{
	public:
		MakePair br;
		void break_up_function(int t); // The break up function performed on every day (for t days) to find couples with happiness less than t.
		void print();// !< Printing the output in the file.
};
#endif