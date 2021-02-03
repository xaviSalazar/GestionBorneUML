#ifndef BOUTON_H
#define BOUTON_H

#include <memoire_borne.h>
#include <donnees_borne.h>
#include "timer.h"

class bouton 
{
 	 public : 
 	 
 	 void bouton_initialiser();
  	int bouton_charge_appuye_avant_une_minute;
  	int appui_bouton_charge();
  	void bouton_charge_raz();
  	int appui_bouton_stop();
  	void bouton_stop_raz();
  	void attente_appui_bouton_charge();
  	void set_bcharge() { bouton_charge_appuye_avant_une_minute  = 1;}
  	void zero_bcharge() {bouton_charge_appuye_avant_une_minute  = 0;}
  	int get_bcharge() { return bouton_charge_appuye_avant_une_minute;}
  bouton() : bouton_charge_appuye_avant_une_minute(0)
  	{}
 
  	private:
  	
	entrees *io;
	int shmid;
	timer Timer;
};

#endif // BOUTON_H