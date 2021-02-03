#include "generateursave.h"
#include <iostream>
using namespace std;

enum etat {etatA, etatB, etatC, etatD};
enum etat etatPresent, etatSuivant;
int afficher_une_fois_appuyer_bouton_stop=1;

void generateursave::generateursave_initialiser()
{
io=acces_memoire(&shmid);
if (io==NULL) printf("Erreur pas de mem sh\n");
}

int generateursave::valeur_tension()
	{
	int tension;
	tension=io->gene_u;
	return tension;
	}

void generateursave::generer_pwm(int signal)
	{
	switch(signal) 
		{
	         case 0: io->gene_pwm =  STOP;
	         break;
	         case 1:  io->gene_pwm =  DC;
	         break;
	         case 2:  io->gene_pwm =  AC_1K;
	         break;
	         case 3:  io->gene_pwm =  AC_CL;
	         break;
		}
	}

void generateursave::ouvrir_AC()
	{
	io->contacteur_AC=0;
	}
	
void generateursave::fermer_AC()
	{
	io->contacteur_AC=1;
	}
	
	
void generateursave::mef()
{
generateursave_initialiser();
Prise.prise_initialiser();
Bouton1.bouton_initialiser();
Voyant1.voyant_initialiser();

	etatSuivant=etatPresent=etatA;
	stopCharge=0;
	while(stopCharge==0 && var_charge_terminee() ==0)
	//while(stopCharge==0) estaba antes
	//while(charge_terminee == 0 && stopCharge==0)
	//while(1)
	{ 
		switch(etatPresent)
		{
		case etatA:
		if(valeur_tension()==9) {etatSuivant=etatB;}
		break;
		
		case etatB:
		if(valeur_tension()==6) {etatSuivant=etatC;}
		
		else {
		
				if(Bouton1.appui_bouton_stop())
					 {
					 etatSuivant=etatD;
					 Bouton1.bouton_stop_raz();
					 //charge_terminee=0;
					 zero_charge_terminee();
					 stopCharge = 1;
					 }
				
			  } break;
			  
		case etatC:
		if(valeur_tension()==9) //{etatSuivant=etatD; charge_terminee=1; }
		{etatSuivant=etatD; one_charge_terminee(); }
		else 	{
		
				if(Bouton1.appui_bouton_stop())
					 {
					 etatSuivant=etatD;
					 Bouton1.bouton_stop_raz();
					 //charge_terminee=0;
					 zero_charge_terminee();
					 stopCharge = 1;
					 }
		
				} break;
				
		case etatD:break;
		}
		etatPresent=etatSuivant;
		
		if(etatPresent==etatA)
			{
			//cout<<"etat A"<<endl;
			zero_charge_terminee();
			//charge_terminee = 0;
			generer_pwm(1);
			//cout<<io->gene_pwm<<endl;
			Voyant1.set_voyant_charge_ROUGE();
			Prise.deverrouiller_TRAPPE();
			}
			
		if (etatPresent==etatB)
			{
			//cout<<"etat B"<<endl;
			zero_charge_terminee();
			//charge_terminee=0;
			generer_pwm(2);
			Prise.set_voyant_prise_VERT();
			Prise.verrouiller_TRAPPE();
			}
			
		if (etatPresent==etatC)
			{
			//cout<<"etat C"<<endl;
			zero_charge_terminee();
			//charge_terminee = 0;
			fermer_AC();
			Voyant1.set_voyant_charge_VERT();
			generer_pwm(3);
			}
		
		if(etatPresent==etatD)
			{
			//cout<<"etat D"<<endl;
			one_charge_terminee();
			//charge_terminee=1;
			ouvrir_AC();
			generer_pwm(1);
			}
	}cout<<"salida de la boucle"<<endl;
}

