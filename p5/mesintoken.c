/* File: mesintoken.h */
/* Definisi Mesin Token: Model Akuisisi Versi I */

/*
NIM				: 13515028
Nama			: Taufan Mahaputra
Tanggal			: 22 September 2016
Topik praktikum	: Mesin Token
Deskripsi		: Implementasi mesin kata
*/

#include "boolean.h"
#include "mesinkar.h"
#include "mesintoken.h"



/* State Mesin Kata */
boolean EndToken;
Token CToken;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
	while( (CC == BLANK) && (CC != MARK)) {
		ADV();
	}
}
void STARTTOKEN()
/* I.S. : CC sembarang 
   F.S. : EndToken = true, dan CC = MARK; 
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */
{
		START();
		IgnoreBlank();
		if (CC == MARK) { EndToken = true; }
		else { EndToken = false; SalinToken(); }

}
void ADVTOKEN()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true      
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
		IgnoreBlank();
		if(CC == MARK) { EndToken = true; }
		else { SalinToken(); IgnoreBlank(); }
}
void SalinToken()
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
	int i=1;
	int X[NMax+1];
	for(;;){
		if( (CC == '+') || (CC == '-') || (CC == '*') || (CC == '/') || (CC == '^') ){
			CToken.tkn = CC;
		} else  {
			CToken.tkn = 'b';
			switch (CC){
				case '0' : X[i] = 0; break;
				case '1' : X[i] = 1; break;
				case '2' : X[i] = 2; break;
				case '3' : X[i] = 3; break;
				case '4' : X[i] = 4; break;
				case '5' : X[i] = 5; break;
				case '6' : X[i] = 6; break;
				case '7' : X[i] = 7; break;
				case '8' : X[i] = 8; break;
				case '9' : X[i] = 9; break;
			};
			i++;
		}
		
		ADV();
		
		if((CC == MARK) || (CC == BLANK)){
			break;
		}
	}
	
	if(CToken.tkn == CC) {
			CToken.val = -1;
	} else {
			i--;
			if(i==1) {
				CToken.val = X[i];
			} else if(i==2){
				CToken.val = (X[i-1]*10)+X[i];
			} else if(i==3) {
				CToken.val = (((X[i-2]*10)+X[i-1])*10) + X[i];
			} else if(i==4){
				CToken.val = (((((X[i-3]*10)+X[i-2])*10) + X[i-1])*10) + X[i];
			} else if(i==5){
				CToken.val = (((((((X[i-4]*10)+X[i-3])*10) + X[i-2])*10) + X[i-1])*10)+X[i];
			}
	}
}


