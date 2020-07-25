#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "matrixlib.h"

void fascii(int ascii[],char parola[])
{
	//#converte char in ascii e stampa
	int l = strlen(parola)-1;
	for(int i=0;i<l;i++){
		ascii[i]=(int)parola[i];
		printf("%d ",ascii[i]);
	}

}
void intbin(int b[][C],int binv[][C],int n[],char parola[]) //n=numero ascii
{
	//#da ascii a bin
	printf("\n");
	int l = strlen(parola)-1;
	for(int i=0;i<l;i++){
		for(int j=0;j<C;j++){
			if(n[i]%2==0){
				b[i][j]=0;
			}else{
				b[i][j]=1;
			}
			n[i]=n[i]/2;
		}
	}

	binReverse(b,binv,parola);

}
void binReverse(int bintmp[][C],int pbin[][C],char parola[])
{
	
	int z,j=0,i=0;
	int l = strlen(parola)-1;
	
	for(i=0;i<l;i++){	
		for(j=C-1,z=0; j>=0; z++,j--){
			pbin[i][z]=bintmp[i][j];
		}
	}
	
	
	/*for(i=0;i<l;i++){
		z=0;
		for(j=C-1;j>=0;j--){
			pbin[i][z++]=bintmp[i][j];
		}
	}*/


}

void stampa(int arrbp[],int arrcs[],int pbi[][C],char parola[],int xr,int n)
{
	int l = strlen(parola)-1;
	printf("\t    bp");
	for(int i=0;i<l;i++){
		//stampa parola
		if( n==0 || (xr!=i && n==1) ){
			printf("\n%c: ",parola[i]);
		}else if(xr==i && n==1){
			printf("\nP: ");
		}
		for(int j=0;j<C;j++){
			//stampa stringa binaria
			printf("%d",pbi[i][j]);
		}
		/*stampa bp*/
		printf("| %d",arrbp[i]);
		
		if(xr==i && n==1){
			printf(FRECCIAORIZZONTALE);
		}
		
	}
	
	//stampa separatore
	printf("\n");
	for(int i=0;i<11;i++)
		printf("-");

	/*stampa cs*/
	printf("\ncs ");
	for(int j=0;j<C;j++){
		printf("%d",arrcs[j]);
	}
}
void verifica(int arraybp[],int arraycs[],int m[][C],char parola[])
{
	int i=0,j=0,r=strlen(parola)-1,contbp=0,contcs=0;
	/*Bit di parità*/
	for(i=0;i<r;i++){
		for(j=0;j<C;j++){
			if(m[i][j]==1){
				contbp++;
			}
		}
		if(contbp%2==0){
			arraybp[i]=0;
		}else if(contbp%2==1){
			arraybp[i]=1;
		}
		contbp=0;
	}


	/*Checksum*/
	for(j=0;j<C;j++){
		for(i=0;i<r;i++){
			if(m[i][j]==1){
				contcs++;
			}
		}
		if(contcs%2==0){
			arraycs[j]=0;//pari
		}else if(contcs%2==1){
			arraycs[j]=1;//dispari
		}
		contcs=0;
	}
	
}
void durtybit(int m[][C],char p[])
{
	srand(time(NULL));

	int r=rand()%strlen(p)-1; //0-strlen(parola)-1 |escludo LF
	int c=rand()%7; //0-7
	if(r==-1){ //controllo,la matrice non può avere cordinate negative
		r=r+1;
	}
	m[r][c]=!m[r][c];
	printf("\nDurtyBit(random) ---> conto anche lo 0"); 
	printf("\nr: %d",r);
	printf("\nc: %d\n",c);
}
void rilevazione(int m[][C],char parola[],int arrbp[],int arraycs[],int *xr,int *yc) //m[][C],parola,arrbp,contbp,arraycs,contcs
{
	int x,y,i,j;
	int contbp=0,contcs=0;
	
	/*Bit di parità*/
	for(i=0;i<strlen(parola)-1;i++){
		for(j=0;j<C;j++){
			if(m[i][j]==1){
				contbp++;
			}
		}
		//righe
		x=controllo(parola,arrbp,contbp,arraycs,contcs,i,0);
		if(x!=0){
			*xr=x;
		}
		//printf("\n");
		contbp=0;
	}

	
	/*checksum*/
	for(j=0;j<C;j++){
		for(i=0;i<strlen(parola)-1;i++){
			if(m[i][j]==1){
				contcs++;
			}
		}
		//colonne
		y=controllo(parola,arrbp,contbp,arraycs,contcs,j,1);
		if(y!=0){
			*yc=y;
		}
		contcs=0;
	}

}
int controllo(char p[],int arrbp[],int cbp,int arrcs[],int ccs,int z,int n)
{
	switch(n){
		case 0:
			if((cbp%2==0 && arrbp[z]==1) || (cbp%2==1 && arrbp[z]==0)){ //se numero cbp-->pari&&arrbp[z]-->1	 oppure	 cbp-->dipari&&arrbp[z]-->0
				return z;
			}
			break;

		case 1:
			if((ccs%2==0 && arrcs[z]==1) || (ccs%2==1 && arrcs[z]==0)){
				return z;
			}
			break;
	}
return 0;
}
void setw(int yc)
{	
	printf("\n   ");
	for(int i=0;i<yc;i++){
		printf(" "); 
	}
	printf(FRECCIAVERTICALE);

	for(int i=0;i<yc;i++){
		printf(" "); 
	}
	printf("   |\n\n");

	
}

