#include "baseclient.h"


void baseclient::creation_client()
{
string istr;
string inicial = "LIST";
static vector<string> clients;
static vector<int> tarjeta;
static const char* filename = "basedesdonnees.txt";
static int conteo=1;
int linea=0;
string opcion;
unsigned borrar=0;
string line;


if(conteo==1)
{
conteo=0;
clients.insert(clients.begin(), inicial);
tarjeta.insert(tarjeta.begin(),0);
}
initialisations_ports();
int rompe=0;

while(1)
{      

cout<<"-------------------------------------------------------"<<endl;
	cout<<"------------------MENU PRINCIPAL-----------------------"<<endl;
	cout<<"* (1)AJOUTER client:"<<endl;
	cout<<"* (2)ENLEVER client:"<<endl;
	cout<<"* (3)CHARGER vehicule:"<<endl;
	cout<<"-------------------------------------------------------"<<endl;
	//cout<<"Taper option: ";
	//cin>>opcion;
	
while(rompe == 0)
{
cout<<"Veuiller entrer \"1\" ou \"2\" ou \"3\": ";
cin>>opcion;
if(opcion == "1") {rompe=1;}
if(opcion=="2"){rompe=1;}
if(opcion == "3") {rompe=1;}
}
rompe=0;
	
if(opcion=="3")break;

       if(opcion=="1")
       {
 
//POUR AJOUTER UN CLIENT
		while(1)
			{
			cout<<endl;
			cout<<"Enter your desired name OR quit to exit: "<<endl;
			cout<<"Enter: ";
			cin>>istr;
			cout<<endl;
			if(istr == "quit") break;
			attente_insertion_carte();
			int numero_carte=lecture_numero_carte();
			cout<<"*********************************************"<<endl;
			cout<<"Your name \""+ istr + "\" has been succesfully saved"<<endl;
			clients.insert(clients.end(),1,istr);
			cout<<"Client ID: "<<numero_carte<<" Registered"<<endl;
			cout<<"*********************************************"<<endl;
			tarjeta.insert(tarjeta.end(),1,numero_carte);
			
			//ecrire au fichier
ofstream ofile(filename);
for(unsigned i=0; i<clients.size(); i++)
	{
	ofile<<clients[i]<<"	"<<tarjeta[i]<<endl;
	}
	ofile.close();
	
			}
			
				

			
	}
	
//POUR ENLEVER UN CLIENT
        if(opcion=="2")
       { 
       
		while(1)
			{
			cout<<endl;
			 cout<<"-------------LISTE DES CLIENTS-------------------"<<endl;
			 cout<<"Num:"<<"		 "<<"client name:"<<endl;
			for(unsigned i=0; i<clients.size();i++)
				{
				cout<<linea++<<"		 "<<clients[i]<<endl;
				}
				 cout<<"-------------------------------------------------"<<endl<<endl;
				linea=0;
				printf("Enter client a enlever ou tapez quit: ");
				while(1)
				{
				
				getline(cin,line);
					if(line=="quit") break;
					
					stringstream ss(line);
					if (ss>>borrar)
					{
					   if( borrar>=0 && borrar < clients.size())
					   {
						if(ss.eof())
						{
							cout<<"***********************************"<<endl;
							cout<<"Removed client: "<<clients[borrar]<<endl;
							cout<<"***********************************"<<endl;
							clients.erase(clients.begin() + borrar);
							tarjeta.erase(tarjeta.begin() + borrar);
							//ecrire au fichier
							ofstream ofile(filename);
							for(unsigned i=0; i<clients.size(); i++)
							{
							ofile<<clients[i]<<"	"<<tarjeta[i]<<endl;
							}
							ofile.close();
							break;
							
						}
					   }	else {cout<<"veuillez entrer un numero entre:  "<<"0"<<" et "<<clients.size()-1<<endl;continue;}
					
					}
					
				
				}
				
			
				
	//ecrire au fichier
	ofstream ofile(filename);
	for(unsigned i=0; i<clients.size(); i++)
		{
		ofile<<clients[i]<<"	"<<tarjeta[i]<<endl;
		}
	ofile.close();
				
				break;
			}
	}
	
}
	
	
	
//ecrire au fichier
ofstream ofile(filename);
for(unsigned i=0; i<clients.size(); i++)
	{
	ofile<<clients[i]<<"	"<<tarjeta[i]<<endl;
	}
	ofile.close();
	
}




bool baseclient::validation_numero(int carta)
{
static const char* filename = "basedesdonnees.txt";
string datos;
cout<<"read the file"<<endl;
ifstream infile(filename);
string result;
	ostringstream convert;
	convert <<carta;
	result = convert.str();
	
	cout<<"RESULTADO "<<result<<endl;

	while(infile.good())
	{
		getline(infile,datos);
		cout<<datos<<endl;
		std::size_t found = datos.find(result);
		if(found != std::string::npos)
		{cout<<"encontre cliente"<<endl;
		return true;}		
	}
	return false;
	
	/*
	initialisations_ports();
	attente_insertion_carte();
	int numero_carte=lecture_numero_carte();
	*/
}
