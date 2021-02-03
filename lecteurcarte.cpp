#include <iostream>
#include "lecteurcarte.h"

using namespace std;

void LecteurCarte::initialiser()
{
}

void LecteurCarte::lire_carte()
{
    int numero_carte = 0;
    int en_attente_de_carte=1;
    int initialiser_ports=1;
    int vehicule_repris=0;
    Generateursave.zero_charge_terminee();
    one_affichage() ;
   
    	if(initialiser_ports == 1) 
    	{
    	initialiser_ports = 0;
    	initialisations_ports();
    	}
    	
    	Baseclient.creation_client();
    	
    
    
   	if(en_attente_de_carte == 1)
   	{
   	en_attente_de_carte=0;
   	attente_insertion_carte();
   	numero_carte=lecture_numero_carte();
   	client_actif=numero_carte;
   	cout<<"numero de carte: "<<numero_carte<<endl;
   	}
   
 
   if(Baseclient.validation_numero(numero_carte))   // AUTENTIFICACION
   {
   	cout<<"Usuario Identificado: OK "<<endl;
   	Voyant.clignoter_voyant_charge();
   	Bouton.attente_appui_bouton_charge();
  
 	 if(Bouton.get_bcharge() == 1)
   		{
   		Bouton.zero_bcharge();
   		while(!vehicule_repris)
   		{
   		 //Generateursave.zero_charge_terminee();
   		Prise1.prise_initialiser();
   		cout<<"entro en carga"<<endl;
   		Generateursave.mef();
   		//agrego desde aqui
   		
   		if(Generateursave.var_charge_terminee()==1)
   			{
   			Prise1.deverrouiller_TRAPPE();
   			
   			while(Generateursave.valeur_tension()!=12)
   				{
   				if( affichage()==1)
   					{
   					 //afficher_une_fois_debrancher_vehicule==0;
   					 zero_affichage();
   					 cout<<"Veillez debrancher le vehicule !!" <<endl;
   					}
   				}
   			Prise1.verrouiller_TRAPPE();
   			afficher_une_fois_debrancher_vehicule=1;
   			Prise1.reset_voyant_prise();
   			Voyant.reset_voyant_charge();
   			initialiser_ports=1;
   			en_attente_de_carte=1;
   			vehicule_repris=1;
   			client_actif=0;
   			numero_carte=0;
   			client_actif =  numero_carte;
   			cout<<"MERCI AU REVOIR !!"<<endl;
   			Voyant.set_voyant_dispo_VERT();
   		   	} else {
   		   	             Prise1.deverrouiller_TRAPPE();
   		   	             
   		   	             while(Generateursave.valeur_tension()!=12)
   						{
   						if( affichage()==1)
   							{
   					 		//afficher_une_fois_debrancher_vehicule==0;
   					 		zero_affichage();
   					 		cout<<"Veillez debrancher le vehicule !!" <<endl;
   							}
   						}
   					
   					afficher_une_fois_debrancher_vehicule=1;
   					Prise1.verrouiller_TRAPPE();
   					Prise1.reset_voyant_prise();
   					Voyant.reset_voyant_charge();
   					vehicule_repris=1;
   					initialiser_ports=1;
   					en_attente_de_carte=1;
   					
   					client_actif=0;
   					numero_carte=0;
   					client_actif =  numero_carte;
   					cout<<"MERCI AU REVOIR !!"<<endl;
   					Voyant.set_voyant_dispo_VERT();	
   		   		    }
   		   		    
   		    }//vehicule repris
   		
   		
   		} else //ELSE para Bouton.get_bcharge()
   			{
   			  cout<<"delai depasse !!"<<endl;
   			  cout<<"MERCI AU REVOIR!!!"<<endl;
   			  numero_carte=0;
   			  client_actif=numero_carte;
   			  initialiser_ports=1;
   			  en_attente_de_carte=1;
   			  Voyant.set_voyant_dispo_VERT();
   			}
   		
   } 
   else // ELSE para AUTENTIFICACION
   		{
   		numero_carte=0;
   		client_actif=0;
   		Voyant.clignoter_voyant_defaut();
   		cout<<"MERCI AU REVOIR!!!"<<endl;
   		initialiser_ports=1;
   		en_attente_de_carte=1;
   		Voyant.set_voyant_dispo_VERT();
   		} // End Else
   
   
} //end void


