#ifndef VOYANT_H
#define VOYANT_H

#include <memoire_borne.h>
#include <donnees_borne.h>
#include "timer.h"
#include "bouton.h"


class voyant 
{
 	 public : 
 	 
 	void voyant_initialiser();
	void set_voyant_dispo_VERT();
	void reset_voyant_dispo();
	void clignoter_voyant_charge();
 	void clignoter_voyant_defaut();
 	void set_voyant_charge_ROUGE();
 	void set_voyant_charge_VERT();
 	void reset_voyant_charge();
  	
  	
  	private:
  	
	entrees *io;
	int shmid;
	timer Timer;
	bouton Bouton;
	
};

#endif // VOYANT_H