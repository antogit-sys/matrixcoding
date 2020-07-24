#if __linux__ || __GNUC__ || __LINUX__ || _linux || __APPLE__
#	define FRECCIAORIZZONTALE " ◄---"
#	define FRECCIAVERTICALE "▲\n"
#	define PULISCI "clear"
#elif __WIN32__ || _WIN64 || __CYGWIN__ || __CYGWIN32__
#	define FRECCIAORIZZONTALE " <---"
#	define FRECCIAVERTICALE "^\n"
#	define PULISCI "cls"
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
