/* File : prioqueue.h */
/* Definisi ADT Priority Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut mengecil berdasarkan elemen prio */


/*
NIM				: 13515028
Nama			: Taufan Mahaputra
Tanggal			: 6 Oktober 2016
Topik praktikum	: Queue
Deskripsi			: Implementasi queue
*/

#include <stdio.h>
#include "boolean.h"
#include "prioqueue.h"
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
{
	return ( Head(Q) == Nil && Tail(Q) == Nil ); 
}
boolean IsFull (Queue Q)
{
	return ( NBElmt(Q) > MaxEl(Q) );
}

int NBElmt (Queue Q)
{
	if(!IsEmpty(Q) && (Tail(Q) > Head(Q)))
	{
		return Tail(Q)-Head(Q)+1;
	} else if (!IsEmpty(Q))
	{
		return (MaxEl(Q) - Head(Q) + 1 + Tail(Q));
	}
	 else
	{
		return 0;
	}
}


/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
{
	(*Q).T = (address *) malloc ((Max+1) * sizeof(address));
		if ((*Q).T != NULL) {
		MaxEl(*Q) = Max;
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
		} else /* alokasi gagal */ {
		MaxEl(*Q) = Nil;
		}
}

/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
{
	MaxEl(*Q) = Nil;
	free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X)
{
	
		/* Algoritma */
		if (IsEmpty(*Q)) {
		Head(*Q)=1;
		Tail(*Q)++;
		Prio(InfoTail(*Q))=Prio(X);
		Info(InfoTail(*Q))=Info(X);
		} else /* Q tidak kosong */ {
			if (Tail(*Q)==MaxEl(*Q)) { /* Geser elemen Tail(*Q)  ke indeks 1 */
				Tail(*Q) = 1;
			} else {
				Tail(*Q)++;
			}
			
			int mark = Head(*Q);
			while ( (Prio(Elmt(*Q,mark)) >= Prio(X)) && (mark < Tail(*Q))) 
			{
				mark++;
			} 
			if (mark == Tail(*Q))
			{
				Prio(InfoTail(*Q))=Prio(X);
				Info(InfoTail(*Q))=Info(X);
			} else
			{
				int i = Tail(*Q);
				while(i > mark)
				{
					Prio(Elmt(*Q,i)) = Prio(Elmt(*Q,i-1));
					Info(Elmt(*Q,i)) = Info(Elmt(*Q,i-1));
					i--;
				}
				Prio(Elmt(*Q,mark))=Prio(X);
				Info(Elmt(*Q,mark))=Info(X);
			}
		}
}


void Del (Queue * Q, infotype * X)
{
		*X = InfoHead(*Q);
		if (Head(*Q)==Tail(*Q)) { /* Set mjd queue kosong */
		Head(*Q)=Nil; Tail(*Q)=Nil;
		}
		else {
		if (Head(*Q)==MaxEl(*Q)) { /* Geser elemen Head(*Q) maju  */
				Head(*Q) = 1;
			} else {
				Head(*Q)++;
			}
		}
}

/* Operasi Tambahan */
void PrintQueue (Queue Q)
{
	if(IsEmpty(Q))
	{
		printf("#\n");
	} else
	{
		infotype X;
		while(!IsEmpty(Q))
		{
			
			Del(&Q, &X);
			printf("%d %d\n", Prio(X), Info(X));
		}
		if(IsEmpty(Q))
		{
			printf("#\n");
		}
	}
}


