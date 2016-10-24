/*
NIM				: 13515028
Nama			: Taufan Mahaputra
Tanggal			: 22 September 2016
Topik praktikum	: Mesin Token
Deskripsi		: Implementasi mesin kata
*/

#include <stdio.h>
#include "mesintoken.h"
#include "mesinkar.h"


 
 
int main() {

	
	STARTTOKEN();
	if(EndToken) {
		printf("Ekspresi kosong\n");
	}
	while(!EndToken) {
	
		
		if(CToken.tkn == 'b'){
			printf("%d\n", CToken.val);
		} else { 
			printf("%c\n", CToken.tkn);
		}
		
		ADVTOKEN();
	}
	
	
	
	
	return 0;
}
