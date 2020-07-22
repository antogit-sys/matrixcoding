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
Date:21/07/2020
School:ITT Giorgi

Open Source Project

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
		#if __linux__ || __GNUC__ || __LINUX__ || _linux || __APPLE__
				system("clear");
				system("figlet -l ""Matrix  Coding""");
		#elif __WIN32__ || _WIN64 || __CYGWIN__ || __CYGWIN32__
				system("cls");
				printf("=============\n");
				printf("Matrix Coding");
				printf("\n=============\n");
		#endif
		printf("inserisci parola: ");
		//scanf("%s",parola);
		fgets(parola,99,stdin);
	}while(strcmp(parola,"\n")==0);			
	
	printf("ascii: ");
	fascii(ascii,parola);
	intbin(bintmp,binv,ascii,parola); //convrt int/bin

	printf("\n");
	verifica(arrbp,arrcheck,binv,parola); //cs & bp
	printf("corrected:\n");
	stampa(arrbp,arrcheck,binv,parola,xr,0); //out stream (0=stampo senza freccia|1=stampo con freccia)
	printf("\n+--------------------------------------+\n");
	durtybit(binv,parola); 	//Sporco un bit a caso nella matrice

	rilevazione(binv,parola,arrbp,arrcheck,&xr,&yc); //passaggio per riferimento in C
 	stampa(arrbp,arrcheck,binv,parola,xr,1);
 	setw(yc);
 	
return 0;
}
