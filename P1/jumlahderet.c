/* NIM 			: 13515028
Nama 			: Taufan Mahaputra
Tanggal			: 25 Agustus 2016
Topik praktikum	: Pengenalan bahasa C
Deskripsi		: Program membaca sebuah bilangan dan menuliskan hasil penulisan deret 1+2+3+.. */

#include <stdio.h>

int main() {
	
	/* KAMUS */
	int a,i,sum;
	
	/* ALGORITMA */
	
	sum = 0;
	
	scanf("%d",&a);
		
	for (i=1;i<=a;i++) {
			sum += i;
		}
	printf("%d\n",sum);
	
	
	return 0;
}
