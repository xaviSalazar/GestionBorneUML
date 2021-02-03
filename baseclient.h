#ifndef BASECLIENT_H
#define BASECLIENT_H

#include <lcarte.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;


class baseclient
{
  public : 
  
	bool validation_numero(int carta);
	void creation_client();
	void delete_client();
	
private :


};
#endif // BASECLIENT_H
