/*
NIM				: 13515028
Nama			: Taufan Mahaputra
Tanggal			: 4 Oktober 2016
Topik praktikum	: Queue
Deskripsi			: Implementasi queue
*/

#include "boolean.h"
#include "queue.h"
#include <stdlib.h>

#define Nil 0
/* Konstanta untuk mendefinisikan address tak terdefinisi */


/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	return ( Head(Q) == Nil && Tail(Q) == Nil ); 
}
boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
	return ( NBElmt(Q) == MaxEl(Q) );
}
int NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
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
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
	(*Q).T = (infotype *) malloc ((Max+1) * sizeof(infotype));
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
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
	MaxEl(*Q) = Nil;
	free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
		
	address i, j;
		/* Algoritma */
		if (IsEmpty(*Q)) {
		Head(*Q)=1;
		Tail(*Q)++;
		InfoTail(*Q)=X;
		} else /* Q tidak kosong */ {
			if (Tail(*Q)==MaxEl(*Q)) { /* Geser elemen Tail(*Q)  ke indeks 1 */
				Tail(*Q) = 1;
			} else {
				Tail(*Q)++;
			}
			
			InfoTail(*Q)=X;
		}
}
void Del (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
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
