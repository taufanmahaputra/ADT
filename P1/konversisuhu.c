/* NIM 			: 13515028
Nama 			: Taufan Mahaputra
Tanggal			: 25 Agustus 2016
Topik praktikum	: Pengenalan bahasa C
Deskripsi		: Program mengkonversi suhu dari satuan celcius ke satuan suhu yang lain */

#include <stdio.h>

int main() {
	
	/* KAMUS */
	float x,hasil;
	char p,enter;
	
	/* ALGORITMA */
	
	
	scanf("%f",&x);
	scanf("%c",&enter); //membaca enter
	scanf("%c",&p);
	
	
	if (p == 'R') {
		hasil = (4*x)/5;
	} 
	else if (p == 'F') {
		hasil = (((9*x)/5) + 32);	
	}
	else{
		hasil = x + 273.15;
	} 
		
	printf("%.2f\n",hasil);
	
	
	return 0;
}
