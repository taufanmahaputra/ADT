/*
NIM				: 13515028
Nama			: Taufan Mahaputra
Tanggal			: 6 Oktober 2016
Topik praktikum	: Queue
Deskripsi			: Implementasi queue
*/

#include <stdio.h>
#include "boolean.h"
#include "queue.h"


float AvgElmt (Queue Q);
/* Menghasilkan rata-rata elemen dalam queue Q yang tidak kosong */

int main() {

	Queue Q;
	int N;
	scanf("%d", &N);
	CreateEmpty(&Q, N);
	
	
	boolean stop= false; 
	int code,time;
	int count = 0;
	while(!stop) 
	{
		scanf("%d", &code);
		
		if(code == 1)
		{
			scanf("%d", &time);
			if(count<N)
			{
				Add(&Q,time);
				count++;
			} else
			{
				printf("Queue penuh\n");
			}
		} else if(code == 2)
		{
			if(!IsEmpty(Q))
			{
				int x;
				Del(&Q, &x);
				count--;
			} else
			{
				printf("Queue kosong\n");
			}
		} else if(code == 0) 
		{
			stop = true;
		}
		
	}
	 printf("%d\n", count);
	 if(count==0)
	 {
		 printf("Tidak bisa dihitung\n");
	 } else 
	 {
		 printf("%.2f\n", AvgElmt(Q));
	 }
	
	
	return 0;
}


float AvgElmt (Queue Q)
{
		int count,sum=0;
		int x;
		while(!IsEmpty(Q))
		{
			Del(&Q,&x);
			sum += x;
			count++;
		}
		
	float z,y;
	z = sum;
	y = count;
	return (z/y);
}
