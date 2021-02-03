#ifndef GEN_H
#define GEN_H

#include <memoire_borne.h>
#include <donnees_borne.h>
#include "prise.h"
#include "bouton.h"
#include "voyant.h"

class generateursave 
{
 	 public : 
 	 
 	int charge_terminee;
 	int stopCharge;
 	int signal;
 	
 	void one_charge_terminee() {charge_terminee=1;}
 	void zero_charge_terminee() {charge_terminee=0;}
 	int var_charge_terminee() {return charge_terminee;}
 	int valeur_tension();
 	void generer_pwm(int signal);
 	void set_signal(int senial) {signal=senial;}
 	int get_signal(){return signal;}
 	void fermer_AC();
 	void ouvrir_AC();
 	void mef();
 	void generateursave_initialiser();
        generateursave(): stopCharge(0)
  	{}
  	
  	private:
  	
	entrees *io;
	int shmid;
	prise Prise;
	bouton Bouton1;
	voyant Voyant1;
	
};

#endif // GEN_H