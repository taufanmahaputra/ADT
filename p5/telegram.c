/*
NIM				: 13515028
Nama			: Taufan Mahaputra
Tanggal			: 22 September 2016
Topik praktikum	: Telegram
Deskripsi		: Implementasi mesin kata
*/

#include <stdio.h>
#include "mesinkata.h"

boolean IsKataSama(Kata K1,Kata K2)
{
		if(K1.Length != K2.Length) {
			return false;
		} else {
			int i =1 ;
			while ( (i<K1.Length) && (K1.TabKata[i] == K2.TabKata[i]) ) {
				i++;
			}
			return (K1.TabKata[i] == K2.TabKata[i]);
		}
}


 
 
int main() {

Kata Koma, Titik;


	Koma.TabKata[1] = 'K';
	Koma.TabKata[2] = 'O';
	Koma.TabKata[3] = 'M';
	Koma.TabKata[4] = 'A';
	Koma.Length = 4;
	
	Titik.TabKata[1] = 'T';
	Titik.TabKata[2] = 'I';
	Titik.TabKata[3] = 'T';
	Titik.TabKata[4] = 'I';
	Titik.TabKata[5] = 'K';
	Titik.Length = 5;
	
	STARTKATA();
	
	int nkata,regular,panjang = 0;
	while(!EndKata) {
		nkata++;
		
		
		
		if(IsKataSama(Titik,CKata)) {
			printf(".");
		}
		else if (IsKataSama(Koma,CKata)) {
			printf(",");
		} 
		else {
			if(CKata.Length < 10) {
				regular++;
			} else {
				panjang++;
			}
		
			int i;
			for(i=1; i<= CKata.Length; i++){
				printf("%c", CKata.TabKata[i]);
			}
		}
		
		ADVKATA();
		if((!EndKata) && (!IsKataSama(Titik,CKata)) && (!IsKataSama(Koma,CKata)) ){
			printf(" ");
		}
	}
	
	printf("\n%d\n",regular);
	printf("%d\n",panjang);
	
	int sum;
	if(nkata>10){
		sum = (regular*1000) + (panjang*1500);
		sum = sum - 0.1*(sum);
		
	} else {
		sum = (regular*1000) + (panjang*1500);
	}
	
	printf("%d\n",sum);
	
	return 0;
}
