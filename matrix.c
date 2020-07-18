#include <stdio.h>
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
	
	printf("inserisci parola: ");
	//scanf("%s",parola);
	fgets(parola,99,stdin);							
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
