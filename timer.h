#ifndef TIMER_H
#define TIMER_H

#include <memoire_borne.h>
#include <donnees_borne.h>

class timer 
{
 	 public : 
  	
  
  	
  	int time_raz;
  	
  	void timer_initialiser();
  	
  	int timer_valeur();
  	
  	void timer_memoria();
  	
  	int t_raz() {return time_raz;}
  	
  	void zero_t_raz(){ time_raz=0;}
  	
  	void one_t_raz(){ time_raz=1;}
  	
  	
  	
  	timer(): time_raz(1)
  	{ }

  	private:
  	
  	int depart_timer;
  	
  	int temps_ecoule;

	entrees *io;
	
	int shmid;
	
};



#endif // TIMER_H