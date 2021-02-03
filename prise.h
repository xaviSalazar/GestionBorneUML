#ifndef PRISE_H
#define PRISE_H

#include <memoire_borne.h>
#include <donnees_borne.h>

class prise 
{
 	 public : 
  	
  	void prise_initialiser();
  	void verrouiller_TRAPPE();
  	void deverrouiller_TRAPPE();
  	void set_voyant_prise_VERT();
  	void reset_voyant_prise();

  	private:

	entrees *io;
	int shmid;
	
};



#endif // PRISE_H