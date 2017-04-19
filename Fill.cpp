//!< Objects of subclass are created and are stored in the parents class' object.
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include "Fill.h"
using namespace std;
void Fill::fill_data(Boy b[], Girl go[]) {
	char dname[9];
	int datr;
	int dintl;
	int dbudget;
	int dmin_atr;
	int dstatus;
	int dmain_cost;
	int dcriteria;
	int dcommited;

	FILE *f1, *f2;
	f1 = fopen("boys_l.txt", "r");
	
	fscanf (f1, "%d", &num_boys);
	for(int i = 0; i <= num_boys; i++) {
		Boy *tmp;
		fscanf(f1,"%s %d %d %d %d %d %d", dname, &dcommited, &dstatus, &datr, &dintl, &dbudget, &dmin_atr);
		if(dstatus == 0) {
			tmp = new Miser(dname, datr, dintl, dbudget, dmin_atr);
		} else if(dstatus == 1) {
			tmp = new Generous(dname, datr, dintl, dbudget, dmin_atr);
		} else {
			tmp = new Geek(dname, datr, dintl, dbudget, dmin_atr);
		}
		b[i] = *tmp;
	}
	/*for (int i = 0; i < nb; i++) {
		printf ("%d %s %d %d %d %d %d %d\n", i, boy[i].name_id, boy[i].status, boy[i].commited, boy[i].atr, boy[i].intl, boy[i].budget, boy[i].min_atr);
	}*/
	f2 = fopen ("girls_l.txt", "r");
	fscanf (f2, "%d", &num_girls);
	for (int i = 0; i <= num_girls; i++) {
		Girl *temp;
		fscanf(f2,"%s %d %d %d %d %d %d", dname, &dcommited, &dstatus, &datr, &dintl, &dmain_cost, &dcriteria);
		if(dstatus == 0){
			temp = new Choosy(dname, datr, dintl, dmain_cost, dcriteria);
		} else if(dstatus == 1) {
			temp = new Normal(dname, datr, dintl, dmain_cost, dcriteria);
		} else {
			temp = new Desperate(dname, datr, dintl, dmain_cost, dcriteria);
		}
		go[i] = *temp;
	}
	/*for (int i = 0; i < ng; i++) {
		printf ("%d %s %d %d %d %d %d %d\n", i, girl[i].name_id, girl[i].status, girl[i].commited, girl[i].atr, girl[i].intl, girl[i].man_cost, girl[i].criteria);
	}*/
}