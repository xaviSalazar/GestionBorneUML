#include "timer.h"

void timer::timer_memoria()
{
io=acces_memoire(&shmid);
if (io==NULL) printf("Erreur pas de mem sh\n");
}

void timer::timer_initialiser()
{
depart_timer = io->timer_sec; 
}

int timer::timer_valeur()
{

if (time_raz)
 {
 time_raz=0;
 timer_initialiser();
 }
 
temps_ecoule = io->timer_sec - depart_timer;
  //temps_ecoule = p_memoiressh->timer_sec - depart_timer;
 if(temps_ecoule == 65535)
   {
   timer_initialiser();
   }
   
   return temps_ecoule;
 
}

