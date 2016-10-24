/*
NIM				: 13515028
Nama			: Taufan Mahaputra
Tanggal			: 15 September 2016
Topik praktikum	: Implementasi Matriks
Deskripsi		: Program mengeluarkan hasil data-data dari matriks
*/

#include <stdio.h>
#include "matriks.h"

int main (){ 
	
void TulisNilaiX (MATRIKS M, indeks j, ElType X){
	
	int i;
	int count = 0;
	
	printf("[");
	for(i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++) {

			if(Elmt(M,i,j) == X ) {
				count++;
				printf("%d", i);
				if(count < CountXKol(M,j,X)){
					printf(",");
				}
			}
	}
	printf("]");
	
}


void TulisStatistikMhs (MATRIKS M, indeks i){
	int max,min;
	
	MaxMinBrs(M,i,&max,&min);
	
	printf("[%d] %.2f %d %d",i,RataBrs(M,i),max,min);

	
}



void TulisStatistikMK (MATRIKS M,indeks j){
	
	int max,min;
	
	MaxMinKol(M,j,&max,&min);
	
	printf("[%d] %.2f [%d %d ",j,RataKol(M,j),max,CountXKol(M,j,max));TulisNilaiX(M,j,max);printf("] [%d %d ",min,CountXKol(M,j,min));TulisNilaiX(M,j,min);printf("]");
	

}



	MATRIKS M;
	int X,Y,i,j;
	scanf("%d", &X);
	scanf("%d", &Y);
	BacaMATRIKS(&M,X,Y);
	printf("STATISTIK PER MAHASISWA\n");
	for(i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
		TulisStatistikMhs(M,i);
			printf("\n");
		
	}
	printf("STATISTIK PER MATA KULIAH\n");
	for(j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
		TulisStatistikMK(M,j);
			printf("\n");
	}
	
	return 0;
}
	
