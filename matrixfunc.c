#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "matrixlib.h"

void fascii(int ascii[],char parola[])
{
	//#converte char in decimal e stampa
	int l = strlen(parola)-1; 
	for(int i=0;i<l;i++){
		ascii[i]=(int)parola[i];
		printf("%d ",ascii[i]);
	}

}
void intbin(int b[][C],int binv[][C],int n[],char parola[]) //n=numero ascii
{
	//#da decimal a bin
	printf("\n");
	int l = strlen(parola)-1;
	for(int i=0;i<l;i++){
		for(int j=0;j<C;j++){
			if(n[i]%2==0){//resto 0
				b[i][j]=0;
			}else{// resto 1
				b[i][j]=1;
			}
			n[i]=n[i]/2;
		}
	}

	binReverse(b,binv,parola); //reverse della stringa binaria

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
	printf("\t        bp");
	for(int i=0;i<l;i++){
		//stampa parola
		if( n==0 || (xr!=i && n==1) ){ 
			printf("\n%c:\t",parola[i]);
		}else if(xr==i && n==1){
			int cascii=binint(pbi,xr,parola);
			if(cascii<32 || cascii==127){
				printf("%s",casciicontroll(cascii));
			}else{
				printf("%c:      ",cascii);
			}
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
	printf("\n\t"); //"     "
	for(int i=0;i<7;i++)
		printf("-");
	printf("+");

	/*stampa cs*/
	printf("\ncs\t"); //"     "
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
			*xr=x; //prendo la cordinata(righe)
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
			*yc=y;//prendo la cordinata(colonna)
		}
		contcs=0;
	}

}
int controllo(char p[],int arrbp[],int cbp,int arrcs[],int ccs,int z,int n)
{
	/*
	 * n=0 --> bit di parità
	 * n=1 --> checksum
	*/ 
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
	printf("\n\t");
	for(int i=0;i<yc;i++){
		printf(" "); 
	}
	printf(FRECCIAVERTICALE);

	for(int i=0;i<yc;i++){
		printf(" "); 
	}
	printf("        |\n\n");
	
}
int binint(int m[][C],int xr,char parola[])
{
	//salvo in v[C] la stringa binaria della matrice "sporcata"
	int v[C],n=0;
	printf("\n");
	for(int i=0;i<strlen(parola)-1;i++){
		if(xr==i){ //controllo
			for(int j=0;j<C;j++){
					v[j]=m[xr][j];
			}
		}
			
	}

	//da binario a decimal
	for(int i=C-1,j=0; i>=0; i--,j++){
		if(v[j]==1){
			n=n+pow(2,i); //n=n+2^i
		}
	}
	
return n;
}
const char *casciicontroll(int cascii)
{
	/* CARATTERI DI CONTROLLO */
	
	switch(cascii){
		case 0:
			return "NUL:\t"; //null '\0' *
		case 1:
			return "SOH:\t"; //start of heading (inizio dell'intestazione) *
		case 2:
			return "STX:\t"; //start of text (inizio del testo) *
		case 3:
			return "ETX:\t"; //end of text (fine del testo) *
		case 4:
			return "EOT:\t"; //end of trasmission (fine della trasmissione) *
		case 5:
			return "ENQ:\t"; //enquiry (richiesta) *
		case 6:
			return "ACK:\t"; //Acknowledge (riconoscimento) *
		case 7:
			return "BEL:\t"; //bell (Viene utilizzato quando è necessario richiamare l'attenzione umana. Può controllare i dispositivi di allarme ) "\a" *
		case 8:
			return "BS:\t"; //Backspace "\b" *
		case 9:
			return "TAB:\t";//HB (Horizontal Tab) "\t" *
		case 10:
			return "LF:\t"; //Leen Feed (avanzamento di riga) "\n" *
		case 11:
			return "VT:\t"; //Vertical Tab "\v" *
		case 12:
			return "FF:\t"; //Form Feed "\f" *
		case 13:
			return "CR:\t"; //Carriage return ritorna a inizio riga"\r" * 
		case 14:
			return "SO:\t"; //Shift Out
		case 15:
			return "SI:\t"; //Shift In
		case 16:
			return "DLE:\t"; //Data Link Escape
		case 17:
			return "DC1:\t"; //Device Control 1
		case 18:
			return "DC2:\t"; //Device Control 2
		case 19:
			return "DC3:\t"; //Device Control 3
		case 20:
			return "DC4:\t"; //Device Control 4
		case 21:
			return "NAK:\t"; //Negative Acknowledgement *
		case 22:
			return "SYN:\t"; //Synchronous Idle *
		case 23:
			return "ETB:\t"; //End of Transmission Block
		case 24:
			return "CAN:\t"; //Cancel *
		case 25:
			return "EM:\t"; //End of Medium
		case 26:
			return "SUB:\t"; //Substitute (CTRL ^Z)
		case 27:
			return "ESC:\t"; //Escape "\e" 
		case 28:
			return "FS:\t"; //File Separator
		case 29:
			return "GS:\t"; //Group Separator
		case 30:
			return "RS:\t"; //Record Separator
		case 31:
			return "US:\t"; //Unit Separator
		
	}

return "DEL:\t"; //0x127 - 1111111
}
