#include <iostream>
#include <cstdlib>
#include <ctime>

//--JEUX DE NOMBRES ALEATOIRES--//
//--VERSION: 0.0.1

//FONCTION DE COMPARAISON
int sup_inf(int val_alea, int val_choix){
	
	if (val_alea == val_choix)
	{
	std::cout<<"BINGO !\n";
	}	
	if (val_alea < val_choix)
	{
	std::cout <<"VOTRE NOMBRE EST PLUS GRAND !"<<std::endl;
	}
	if (val_alea > val_choix)
	{
	std::cout<<"VOTRE NOMBRE EST PLUS PETIT !"<<std::endl;
	}

	return 0; }


//FONCTION DE GENERATION D'UN NOMBRE ALEATOIRE
int alea_number_gen(int mini, int maxi)
{

	srand(static_cast <unsigned int>(time(NULL)));
	int alea_number = (rand() % (maxi - mini + 1)) + mini ;
	
	return alea_number ; }

//FONCTION MAIN DU PROGRAMME PRINCIPAL
int main(){
	int choix;
	int number_gen;
	int rest_vie ;
	int valeur_min ;
	int valeur_max ;
	int tentatives ;
	int arret = 0 ;
	
	do
	{
		std::cout<<"\nCHOISISSEZ UNE VALEUR MINIMALE : ";
		std::cin>> valeur_min;
		std::cout<<"CHOISISSEZ UNE VALEUR MAXIMALE : ";
		std::cin>> valeur_max;
		std::cout<<"CHOISISSEZ LE NOMBRE DE TENTATIVES : ";
		std::cin>> tentatives;
		
		//GENERATION DU NOMBRE ALEATOIRE
		number_gen = alea_number_gen(valeur_min,valeur_max);
		
		std::cout<<"VOUS AVEZ "<<tentatives<<" TENTATIVES POUR TROUVER LE NOMBRE MYSTERE !\n"<<std::endl;
		
		/*Boucle sur le nombre de tentatives*/
		for (int i = 1; i <= tentatives ; i++) 
			{
						
				std::cout<< "DONNER UN NOMBRE COMPRIS ENTRE: " <<valeur_min<< " ET " <<valeur_max<<": ";
				std::cin >> choix;
				rest_vie = tentatives - i;
				
				/*Arreter le programme s'il n y a plus de vie*/
				if (rest_vie==0 && choix != number_gen) 
				{
				break;
				}
				else /*Sinon afficher les tentatives restantes*/
				{
				/*AFFICHAGE DU MESSAGE PLUS GRAND OU PLUS PETIT*/
				sup_inf(number_gen,choix);
					if (rest_vie != 0 && choix != number_gen)
					{
					std::cout<< "IL VOUS RESTE "<< rest_vie <<" TENTATIVE(S) !\n"<<std::endl;
					}
				}
				
			if (choix == number_gen) /*Si le nombre est trouve, on felicite et on arrete le programme */
				{
					std::cout<<"FELICITATIONS ! VOUS AVEZ TROUVE LE NOMBRE CHERCHE "
					<<choix<<".\nEN "<<i<<" TENTATIVE(S)\n"<<std::endl;
					break;
				}
				
		
			}

			/*Si le nombre n'est pas trouve et il n'y a plus de vie, on arrete*/
			if (rest_vie == 0 && choix != number_gen)
				{
				std::cout<<"DESOLE ! LE NOMBRE CHERCHE ETAIT: "<<number_gen<<"\n"<<std::endl;
				}
			std::cout<<"CLIQUER SUR 1 POUR RE-JOUER OU UN AUTRE POUR ARRETER : ";
			std::cin >> arret ;
			}
			while ( arret == 1);
			std::cout <<"VOUS AVEZ MIS FIN AU JEUX !\n"<<std::endl;
	}

