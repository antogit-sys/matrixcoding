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
Date:20/07/2020
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
	
	int xr,yc,os;
	
	
	os=winlin();
		
	//tolgo rimanente
	if(os==0){
		system("clear");
	}else if(os==1){
		system("cls");
		
	}
	                                                                                   
	do{
		printf("inserisci parola: ");
		//scanf("%s",parola);
		fgets(parola,99,stdin);
	
		if(strcmp(parola,"\n")==0 && os==1){
			system("clear");	
		}else if(strcmp(parola,"\n")==0 && os==1){
			system("cls");
		}
	}while(strcmp(parola,"\n")==0);			
	
	printf("ascii: ");
	fascii(ascii,parola);
	intbin(bintmp,binv,ascii,parola); //convrt int/bin

	printf("\n");
	verifica(arrbp,arrcheck,binv,parola); //cs & bp
	printf("corrected:\n");
	stampa(arrbp,arrcheck,binv,parola,xr,os,0); //out stream (0=stampo senza freccia|1=stampo con freccia)
	printf("\n+--------------------------------------+\n");
	durtybit(binv,parola); 	//Sporco un bit a caso nella matrice

	rilevazione(binv,parola,arrbp,arrcheck,&xr,&yc); //passaggio per riferimento in C
 	stampa(arrbp,arrcheck,binv,parola,xr,os,1);
 	setw(yc,os);
 	
return 0;
}
