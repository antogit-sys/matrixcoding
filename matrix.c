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
	
	int r=0,c=0;
	int xr,yc;
	
	printf("inserisci parola: ");
	//scanf("%s",parola);
	fgets(parola,99,stdin);							
	printf("ascii: ");
	fascii(ascii,parola);
	intbin(bintmp,binv,ascii,parola); //convrt int/bin

	printf("\n");
	verifica(arrbp,arrcheck,binv,parola); //cs & bp
	//stampa(arrbp,arrcheck,binv,parola,xr); //out stream
	durtybit(binv,parola,&r,&c); 	//Sporco un bit a caso della matrice

	rilevazione(binv,parola,arrbp,arrcheck,r,c,&xr,&yc);
 	stampa(arrbp,arrcheck,binv,parola,xr);
 	setw(yc);
 	
return 0;
}
