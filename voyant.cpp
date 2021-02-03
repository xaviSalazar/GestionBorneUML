#include "voyant.h"
#include <iostream>
using namespace std;


void voyant::voyant_initialiser()
{
io=acces_memoire(&shmid);
if (io==NULL) printf("Erreur pas de mem sh\n");
}


void voyant::set_voyant_dispo_VERT()
   {
   io->led_dispo=VERT;
   }
   
 void voyant::reset_voyant_dispo()
 	{
 	io->led_dispo=OFF;
 	}
 	
 void voyant::set_voyant_charge_ROUGE()
       {
       io->led_charge=ROUGE;
       }
       
void voyant::set_voyant_charge_VERT()
	{
	io->led_charge=VERT;
	}
	
void voyant::reset_voyant_charge()
	{
	io->led_charge=OFF;
	}
	
void voyant::clignoter_voyant_charge()
{
       voyant_initialiser();
	Timer.timer_memoria();
	Bouton.bouton_initialiser();
	
	int time =0;
	
	if( Timer.t_raz() == 1 )
	{
	Timer.zero_t_raz();
	Timer.timer_initialiser();
	}
	
	while(time <= 8)
	{
	Bouton.bouton_charge_raz();
	time = Timer.timer_valeur();
	if(time%2==0){io->led_charge=VERT;}
	if(time%2==1){io->led_charge=OFF;}
	}
	
	io->led_charge=OFF;
	
	Timer.one_t_raz();
} 
	
void voyant::clignoter_voyant_defaut()
	{
	
	voyant_initialiser();
	Timer.timer_memoria();
	Bouton.bouton_initialiser();
	
	int time =0;
	
	if( Timer.t_raz() == 1 )
	{
	Timer.zero_t_raz();
	Timer.timer_initialiser();
	}
	
	while(time <= 8)
	{
	Bouton.bouton_charge_raz();
	time = Timer.timer_valeur();
	if(time%2==0){io->led_defaut=ROUGE;}
	if(time%2==1){io->led_defaut=OFF;}
	}
	
	io->led_defaut=OFF;
	
	Timer.one_t_raz();
	
	}
	