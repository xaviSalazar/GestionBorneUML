#include "prise.h"

void prise::prise_initialiser()
{
io=acces_memoire(&shmid);
if (io==NULL) printf("Erreur pas de mem sh\n");
}

void prise::verrouiller_TRAPPE()
{
io->led_trappe=OFF;
}

void prise::deverrouiller_TRAPPE()
{
io->led_trappe=VERT;
}

void prise::set_voyant_prise_VERT()
{
io->led_prise=VERT;
}

void prise::reset_voyant_prise()
{
io->led_prise=OFF;
}
