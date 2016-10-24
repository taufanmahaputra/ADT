/* NIM 			: 13515028
Nama 			: Taufan Mahaputra
Tanggal			: 25 Agustus 2016
Topik praktikum	: Pengenalan bahasa C
Deskripsi		: Program menjumlahkan 3 bilangan dari inputan */

#include <stdio.h>

int main() {
	
	/* KAMUS */
	int a,b,c,sum;
	
	/* ALGORITMA */
	
	sum = 0;
	
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	
	sum = a+b+c;
	printf("%d\n",sum);
	
	
	return 0;
}
