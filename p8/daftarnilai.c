/*
NIM				: 13515028
Nama			: Taufan Mahaputra
Tanggal			: 20 Oktober 2016
Topik praktikum	: List Linier
Deskripsi		: Implementasi list linier
*/

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "boolean.h"

int main() {

	List L;
	CreateEmpty(&L);
	
	int X,count;
	
	count = 0;
	
	do
	{
		scanf("%d", &X);
			if(X>=0 && X<=100)
			{
				InsVFirst(&L,X);
				count++;
			}
	} while(X>=0 && X<=100);
	
	if(count == 0)
	{
		printf("Daftar nilai kosong\n");
	}
	else
	{
		printf("%d\n", count);
		printf("%d\n", Max(L));
		printf("%d\n", Min(L));
		printf("%.2f\n", Average(L));
		
		List L2; CreateEmpty(&L2);
		L2 = FInversList(L);
		PrintInfo(L2);
		printf("\n");
		PrintInfo(L);
		printf("\n");
	}
	
	
	return 0;
}
