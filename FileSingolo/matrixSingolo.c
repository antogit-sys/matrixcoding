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

Author:Perrucci Antonio
Date:20/07/2020
School:ITT Giorgi 


Open Source Project
* 
*/  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define C 7
#define R 100

int winlin();
void fascii(int[],char[]);
void convert(char[],int[]);
void intbin(int[][C],int[][C],int[],char[]);
void binReverse(int[][C],int[][C],char[]);
void stampa(int[],int[],int[][C],char[],int,int,int);
void verifica(int[],int[],int[][C],char[]);
void durtybit(int[][C],char[]);
void rilevazione(int[][C],char[],int[],int[],int*,int*);
int controllo(char[],int[],int,int[],int,int,int);
void setw(int,int);

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
int winlin()
{
	if(system("cls")==0){
		//se è un sistema Windows ritorna 1
		return 1;
	}else{
		system("clear");
		//se è un sistema Linux ritorna 0
		return 0;
	}
	
}

void fascii(int ascii[],char parola[])
{
	int l = strlen(parola)-1;
	for(int i=0;i<l;i++){
		ascii[i]=(int)parola[i];
		printf("%d ",ascii[i]);
	}

}
void intbin(int b[][C],int binv[][C],int n[],char parola[]) //n=numero ascii
{
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

void stampa(int arrbp[],int arrcs[],int pbi[][C],char parola[],int xr,int os,int n)
{
	int l = strlen(parola)-1;
	printf("\t    bp");
	for(int i=0;i<l;i++){
		//stampa parola
		printf("\n%c: ",parola[i]);
		for(int j=0;j<C;j++){
			//stampa stringa binaria
			printf("%d",pbi[i][j]);
		}
		/*stampa bp*/
		printf("| %d",arrbp[i]);
		
		if(xr==i && n==1 && os==0){//LINUX
				printf(" ◄---");
		}else if(xr==i && n==1 && os==1){ //WINDOWS
				printf(" <---");
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
void setw(int yc,int os)
{	
	printf("\n   ");
	for(int i=0;i<yc;i++){
		printf(" "); 
	}
	if(os==0){ //LINUX
		printf("▲\n");
	}else if(os==1){//WINDOWS
		printf("^\n");
	}
	for(int i=0;i<yc;i++){
		printf(" "); 
	}
	printf("   |\n\n");
	
	
}
