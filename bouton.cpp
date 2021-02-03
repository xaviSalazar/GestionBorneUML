#include "bouton.h"
#include <iostream>
using namespace std;

void bouton::bouton_initialiser()
{
io=acces_memoire(&shmid);
if (io==NULL) printf("Erreur pas de mem sh\n");
}

int bouton::appui_bouton_charge()
  {
  return io->bouton_charge;
  }
  
 void bouton::bouton_charge_raz()
    {
    io->bouton_charge=0;
    }
    
 int bouton::appui_bouton_stop()
    {
    return io->bouton_stop;
    }
    
    void bouton::bouton_stop_raz()
    {
    io->bouton_stop=0;
    }
    
    void bouton::attente_appui_bouton_charge()
{
    bouton_initialiser();
    Timer.timer_memoria();
    
    int time =0;
    
    if(Timer.t_raz()==1)
    {
    Timer.zero_t_raz();
    Timer.timer_initialiser();
    }
    
    cout<<"Vous devez appuyer sur le bouton CHARGE avant 1 min!!!"<<endl;
    
    while(time <= 60)
    {
    
    time=Timer.timer_valeur();
    
    if (appui_bouton_charge()==1)
    {
    //reset_voyant_dispo();
    io->led_dispo=OFF;
    bouton_charge_raz();
    set_bcharge();
    break;
    
    }
 
    }
    //timer_raz=1;
    Timer.one_t_raz();
}



