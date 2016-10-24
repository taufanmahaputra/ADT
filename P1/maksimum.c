/* NIM 			: 13515028
Nama 			: Taufan Mahaputra
Tanggal			: 25 Agustus 2016
Topik praktikum	: Pengenalan bahasa C
Deskripsi		: Program mencari bilangan maksimum dari 3 bilangan dari inputan */

#include <stdio.h>

int main() {
	
	/* KAMUS */
	int a,b,c,max;
	
	/* ALGORITMA */
	
	
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	
	if (a>=b) {
		max = a;
		if(c>=max){
				max = c;
			}
	} else {
			max = b;
			if(c>=max){
				max = c;
			}
			
		}
	printf("%d\n",max);
	
	
	return 0;
}
