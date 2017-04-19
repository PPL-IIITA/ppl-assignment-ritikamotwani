#ifndef INH_PAIR_H_
#define INH_PAIR_H_
#include "couple.h"
#include "gift.h"
#include "boy.h"
#include "girl.h"
#include "Fill.h"
class MakePair
{
	public :
		Fill fobj;
		Boy b[100];
		Girl go[100];
		int k ;
		void input();  // !< couples formed 
		Couple c[30];
		Gift cg[100][100];
		void find_happiness(); //!< k happiest couples found.
		void print(); //!< printing the output in the file.
		void giftin(); //!< gifting done on the basis of the boy's budget.
		void break_up_function(); //!< k least happy couples break up 
		void form_couple(); //!< The couples which break up find a suitaablee partner for themselves if possible.
};
#endif
