/*
NIM				: 13515028
Nama			: Taufan Mahaputra
Tanggal			: 29 September 2016
Topik praktikum	: ADT Stack
Deskripsi			: Implementasi ADT Stack
*/

#include <stdio.h>
#include "stackt.h"
	
	void BacaString(char K[100]);
	int CharToInt(char K);
	void IsiStack(Stack *S, char K[100]);
	Stack JumlahStack(Stack s1, Stack s2);
	void CopyStack (Stack sin, Stack *sout);
	void TulisStack(Stack sin);
	
int main() {
	char enter;
	char X[100]; /*deklarasi string*/
	char Y[100]; /*deklarasi string*/
	
	BacaString(X);
	scanf("%c", &enter); 
	BacaString(Y); /*Baca string dari input user*/
		
	
	Stack S1,S2,SPlus; /*deklarasi stack of integer*/
	
	CreateEmpty(&S1);CreateEmpty(&S2);CreateEmpty(&SPlus); /*Inisiasi stack kosong*/
	
	IsiStack(&S1, X); IsiStack(&S2,Y);
	
	SPlus = JumlahStack(S1,S2); /*Menjumlahkan stack*/
	
	TulisStack(SPlus);
	printf("\n");
	 /*Print ke layar hasil stack penjumlahan*/
	
	
	return 0;
}



//
//
void BacaString(char K[100])
{
	int i=1;
	do
	{
		scanf("%c", &K[i]);
		i++;
	}
	while(K[i-1] != '#');
}
//
//
//
int CharToInt(char K)
{
	int x;
			switch (K){
					case '0' : x = 0; break;
					case '1' : x = 1; break;
					case '2' : x = 2; break;
					case '3' : x = 3; break;
					case '4' : x = 4; break;
					case '5' : x = 5; break;
					case '6' : x = 6; break;
					case '7' : x = 7; break;
					case '8' : x = 8; break;
					case '9' : x = 9; break;
				};
		return x;
}
//
//
void IsiStack(Stack *S,char K[100])
{
	int i=1;
	while(K[i] != '#')
	{
		Push(S, CharToInt(K[i]));
		i++;
	}
}
//
//
//
Stack JumlahStack(Stack s1, Stack s2)
{
	Stack sout;
	CreateEmpty(&sout);
	int x,y;
	int sisa = 0;
	while(!IsEmpty(s1) || !IsEmpty(s2))
	{
			
			if(!IsEmpty(s1) && !IsEmpty(s2)){
					Pop(&s1,&x); Pop(&s2,&y);
								
					Push(&sout,(((x+y)%10)+sisa)%10);
					if( x+y+sisa >=10) {
						sisa = ((x+y+sisa)/10);
					} else{
						sisa = 0;
					}
			} else if(IsEmpty(s1)){
				Pop(&s2,&y);
				Push(&sout,y+sisa);
				sisa = 0;
			} else if(IsEmpty(s2)){
				Pop(&s1,&x);
				Push(&sout,x+sisa);
				sisa = 0;
			}
	}
	
	if(sisa !=0)
	{
	 Push(&sout, sisa);	
	}
	
	return sout;
	
}
//
//
//
void CopyStack (Stack sin, Stack *sout)
					{
						Stack temp;
						CreateEmpty(&temp);
						CreateEmpty(sout);
						int x;
						
						while(!IsEmpty(sin)){
							Pop(&sin, &x);
							Push(&temp, x);
						}
						
						int y;
						while(!IsEmpty(temp)){
							Pop(&temp, &y);
							Push(sout, y);
						}
					}
//			
//
//
void TulisStack(Stack sin)
	{
		Stack sout;
		CopyStack(sin,&sout);
		while(!IsEmpty(sout)){
			int x;
			Pop(&sout,&x);
			printf("%d", x);
		}
	}
