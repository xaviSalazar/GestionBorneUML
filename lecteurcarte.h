#ifndef LECTEURCARTE_H
#define LECTEURCARTE_H

#include <lcarte.h>
#include "voyant.h"
#include "bouton.h"
#include "generateursave.h"
#include "prise.h"
#include "baseclient.h"

class LecteurCarte
{
  public : 
  
	void initialiser();
	void lire_carte();
	void attend_retrait_carte();
	void lire_numero_carte();
	int carte_inseree();
	void set_client_actif(int number) {client_actif=number;}
	int get_client_actif() {return client_actif;}
	void zero_affichage() { afficher_une_fois_debrancher_vehicule=0;}
	void one_affichage() { afficher_une_fois_debrancher_vehicule=1;}
	int affichage(){return afficher_une_fois_debrancher_vehicule;}
	
private :

	 int afficher_une_fois_debrancher_vehicule;
	int client_actif;
	voyant Voyant;
	bouton Bouton;
	generateursave Generateursave;
	prise Prise1;
	baseclient Baseclient;
};
#endif // LECTEURCARTE_H
