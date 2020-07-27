#if __linux__	//se è un sistema linux dichiara
#	define FRECCIAORIZZONTALE " ◄---"
#	define FRECCIAVERTICALE "▲\n"
#	define PULISCI "clear"
#	define OSINTRO() system("figlet -l ""Matrix  Coding"" ")
#elif __APPLE__ //altrimenti se è un sistema apple dichiara
#	define FRECCIAORIZZONTALE " ◄---"
#	define FRECCIAVERTICALE "▲\n"
#	define PULISCI "clear"
#	define OSINTRO() printf("=============\nMatrix Coding\n=============\n")
#elif __WIN32__ || _WIN64 || __CYGWIN__ || __CYGWIN32__ //altrimenti se è un sistema winzzoz dichiara
#	define FRECCIAORIZZONTALE " <---"
#	define FRECCIAVERTICALE "^\n"
#	define PULISCI "cls"
#	define OSINTRO() printf("=============\nMatrix Coding\n=============\n")
#endif

#define C 7
#define R 100
/* 
	¯\_(ツ)_/¯ 
*/

void fascii(int[],char[]);
void convert(char[],int[]);
void intbin(int[][C],int[][C],int[],char[]);
void binReverse(int[][C],int[][C],char[]);
void stampa(int[],int[],int[][C],char[],int,int);
void verifica(int[],int[],int[][C],char[]);
void durtybit(int[][C],char[]);
void rilevazione(int[][C],char[],int[],int[],int*,int*);
int controllo(char[],int[],int,int[],int,int,int);
void setw(int);
int binint(int[][C],int,char[]);
const char* casciicontroll(int);

