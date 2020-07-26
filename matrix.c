/*


 ███▄ ▄███▓ ▄▄▄     ▄▄▄█████▓ ██▀███   ██▓▒██   ██▒    ▄████▄   ▒█████  ▓█████▄  ██▓ ███▄    █   ▄████
▓██▒▀█▀ ██▒▒████▄   ▓  ██▒ ▓▒▓██ ▒ ██▒▓██▒▒▒ █ █ ▒░   ▒██▀ ▀█  ▒██▒  ██▒▒██▀ ██▌▓██▒ ██ ▀█   █  ██▒ ▀█▒
▓██    ▓██░▒██  ▀█▄ ▒ ▓██░ ▒░▓██ ░▄█ ▒▒██▒░░  █   ░   ▒▓█    ▄ ▒██░  ██▒░██   █▌▒██▒▓██  ▀█ ██▒▒██░▄▄▄░
▒██    ▒██ ░██▄▄▄▄██░ ▓██▓ ░ ▒██▀▀█▄  ░██░ ░ █ █ ▒    ▒▓▓▄ ▄██▒▒██   ██░░▓█▄   ▌░██░▓██▒  ▐▌██▒░▓█  ██▓
▒██▒   ░██▒ ▓█   ▓██▒ ▒██▒ ░ ░██▓ ▒██▒░██░▒██▒ ▒██▒   ▒ ▓███▀ ░░ ████▓▒░░▒████▓ ░██░▒██░   ▓██░░▒▓███▀▒
░ ▒░   ░  ░ ▒▒   ▓▒█░ ▒ ░░   ░ ▒▓ ░▒▓░░▓  ▒▒ ░ ░▓ ░   ░ ░▒ ▒  ░░ ▒░▒░▒░  ▒▒▓  ▒ ░▓  ░ ▒░   ▒ ▒  ░▒   ▒
░  ░      ░  ▒   ▒▒ ░   ░      ░▒ ░ ▒░ ▒ ░░░   ░▒ ░     ░  ▒     ░ ▒ ▒░  ░ ▒  ▒  ▒ ░░ ░░   ░ ▒░  ░   ░
░      ░     ░   ▒    ░        ░░   ░  ▒ ░ ░    ░     ░        ░ ░ ░ ▒   ░ ░  ░  ▒ ░   ░   ░ ░ ░ ░   ░
       ░         ░  ░           ░      ░   ░    ░     ░ ░          ░ ░     ░     ░           ░       ░
                                                      ░                  ░

Original Author: antogit-sys
Date:24/07/2020
School:ITT Giorgi

▄︻̷̿┻̿═━一 - - - - Open Source Project

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrixlib.h"

int main()
{
	int bintmp[R][C];
	int binv[R][C];
	int ascii[R];
	char parola[R];
	
	int arrbp[R];
	int arrcheck[C];
	
	int xr,yc;
	                                                                                   
	do{
		system(PULISCI); //pulizia dello schermo funzionante sia in winzzoz che in linux
		OSINTRO(); //macro definita in matrixlib.h
		printf("inserisci parola: ");
		//scanf("%s",parola);
		fgets(parola,99,stdin); //mi tiene conto del carattere 32 (lo spazio)
	}while(strcmp(parola,"\n")==0);			
	
	printf("ascii: ");
	fascii(ascii,parola); //convert char in deciaml
	intbin(bintmp,binv,ascii,parola); //convrt int/bin

	printf("\n");
	verifica(arrbp,arrcheck,binv,parola); //cs & bp
	printf("corrected:\n");
	stampa(arrbp,arrcheck,binv,parola,xr,0); //out stream (0=stampo senza freccia|1=stampo con freccia)
	printf("\n+--------------------------------------+\n");
	durtybit(binv,parola); 	//Sporco un bit a caso nella matrice

	rilevazione(binv,parola,arrbp,arrcheck,&xr,&yc); //passaggio per riferimento in C
 	stampa(arrbp,arrcheck,binv,parola,xr,1);
 	setw(yc); //con i dovuti spazi stampo su schermo la freccia verticale
 	printf("\n\n");
 

 	
return 0;
}
