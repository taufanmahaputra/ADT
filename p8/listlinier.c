/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

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

#define Nil NULL


/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
	return (First(L) == Nil);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
	First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	address P;
	
	/* Algoritma */
    P = (address) malloc (sizeof (ElmtList));
    if (P != Nil) {
      Info(P) = X;
      Next(P) = Nil;
      return P;
    } else {
      return Nil;
	}
}
void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	address P = First(L);
	boolean found = false;
	
		while ((P != Nil) && !found)
		{
			if(Info(P) == X)
			{
				found = true;
			}
			else 
			{
				P = Next(P);
			}
		}
	return P;
}


boolean FSearch (List L, address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
	boolean found = false;
	address X = First(L);
		while ((X != Nil) && !found)
		{
			if(P == X)
			{
				found = true;
			}
			else 
			{
				X = Next(X);
			}
		}
	return found;
}
address SearchPrec (List L, infotype X)
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
	address P = First(L);
	boolean found = false;
	
	if(IsEmpty(L))
	{
		return Nil;
	}
	else
	{
		while( (Next(P) != Nil) && !found)
		{
			if(X == Info(Next(P)))
			{
				found = true;
			}
			else
			{
				P = Next(P);
			}
		}
	}
	if (Next(P) == Nil) {
      return Nil;
    } else {
      return P;
    }
	
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	address P;
	
	P = Alokasi(X);
	if (P != Nil)
	{
		InsertFirst(L,P);
	}
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	address P;
	
	P = Alokasi(X);
	if (P != Nil)
	{
		InsertLast(L,P);
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	address P = First(*L);
	*X = Info(P);
	First(*L) = Next(P);
	Next(P) = Nil;
	Dealokasi(&P);
	
}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	address P;

    /* Algoritma */
    DelLast(L,&P);
    (*X) = Info(P);
	Dealokasi(&P);
}


/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	Next(P) = First(*L);
	First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	address Last;
	
	Last = First(*L);
	if( Last == Nil)
	{
		InsertFirst(L,P);
	}
	else
	{
		while(Next(Last) != Nil)
		{
			Last = Next(Last);
		}
		InsertAfter(L,P,Last);
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P = First(*L);
	First(*L) = Next(First(*L));
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	address P, Prec;
	infotype Y;
	
	P = First(*L);
	if (Info(P) == X)
	{
		DelVFirst(L,&Y);
	} 
	else
	{
		Prec = Nil;
		while(P != Nil)
		{
			if(Info(P) == X)
			{
				DelAfter(L,&P,Prec);
				Dealokasi(&P);
			}
			else
			{
				Prec = P;
				P = Next(P);
			}
		}
	}
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
	address Last, PrecLast;
	
	Last = First(*L);
	PrecLast = Nil;
	while(Next(Last) != Nil)
	{
		PrecLast = Last;
		Last = Next(Last);
	}
	*P = Last;
	if(PrecLast == Nil)
	{
		First(*L) = Nil;
	}
	else
	{
		Next(PrecLast) = Nil;
	}
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel = Next(Prec);
	Next(Prec) = Next(Next(Prec));
	Next(*Pdel) = Nil;
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	if(IsEmpty(L))
	{
		printf("[]");
	}
	else
	{
		address P = First(L);
		
		printf("[");
		while(P!=Nil)
		{
			printf("%d", Info(P));
			if(Next(P) !=Nil)
			{
				printf(",");
			}
			P=Next(P);
		}
		printf("]");
	}
}

int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
	int i=0;
	address P = First(L);
	while(P!=Nil)
	{
		i++;
		P=Next(P);
	}
	
	return i;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai info(P) yang maksimum */
{
	infotype max;
	address P;
	
	P= First(L);
	max = Info(P);
	while(P!=Nil)
	{
		if(Info(P)>=max)
		{
			max = Info(P);
		}
		P= Next(P);
	}
	
	return max;
}

address AdrMax (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
{
	if(IsEmpty(L))
	{
		return Nil;
	}
	else
	{
		infotype X = Max(L);
		address P = Search(L,X);
		return P; 
	}
}
infotype Min (List L)
/* Mengirimkan nilai info(P) yang minimum */
{
	infotype min;
	address P;
	
	P= First(L);
	min = Info(P);
	while(P!=Nil)
	{
		if(Info(P)<=min)
		{
			min = Info(P);
		}
		P= Next(P);
	}
	
	return min;
}
address AdrMin (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
{
	if(IsEmpty(L))
	{
		return Nil;
	}
	else
	{
		infotype X = Min(L);
		address P = Search(L,X);
		return P; 
	}
}
float Average (List L)
/* Mengirimkan nilai rata-rata info(P) */
{
	float sum;
    address P;

    if (NbElmt(L) != 0) 
    {
      P = First(L);
      sum = Info(P);
      P = Next(P);
		while (P != Nil) 
		{
			sum += Info(P);
			P = Next(P);
		}
      return sum/NbElmt(L);
    } else {
      return 0;
    }
	
}

/****************** PROSES TERHADAP LIST ******************/
void DelAll (List *L)
/* Delete semua elemen list dan alamat elemen di-dealokasi */
{
	address P = First(*L);
	infotype x;
	
	while(P!=Nil)
	{
		DelVFirst(L,&x);
		P = First(*L);
	}
}

void InversList (List *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
	address P, Pt;
    int i,N;
    
    i = 1;
    N = NbElmt(*L) -1;
    P = First(*L);
    if (P != Nil) {
      while (i <= N) 
      {
        DelLast(L,&Pt);
        if(i==1)
        {
			InsertFirst(L,Pt);
			P = Pt;
		}
		else
		{
			InsertAfter(L, Pt, P);
			P = Pt;
		}
        i++;
      }
    }
}

List FInversList (List L)
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
	address P, Pt;
	List Lout;
	boolean gagal;
	
	CreateEmpty(&Lout);
	P = First(L);
	gagal = false;
	
		while( (P!=Nil) && (!gagal) )
		{
			Pt = Alokasi(Info(P));
				if(Pt != Nil)
				{
					InsertFirst(&Lout, Pt);
					P = Next(P);
				}
				else
				{
					gagal = true;
					DelAll(&Lout);
				}
		}
		
	return Lout;
}

void CopyList (List *L1, List *L2)
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
{
	First(*L2) = First(*L1);
}
List FCopyList (List L)
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
	address P, Pt;
    List Lout;
    boolean gagal;

    gagal = false;
    CreateEmpty(&Lout);
    P = First(L);
		while ( (P != Nil) && !gagal) 
		{
		  Pt = Alokasi(Info(P));
		  if (Pt != Nil) {
			InsertLast(&Lout,Pt);
			P = Next(P);
		  } else {
			gagal = true;
			DelAll(&Lout);
		  }
		}
    return Lout;
}
void CpAlokList (List Lin, List *Lout)
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */
{
	
	address P, Pt;
    boolean gagal;

    gagal = false;
    CreateEmpty(Lout);
    P = First(Lin);
		while ( (P != Nil) && !gagal) 
		{
		  Pt = Alokasi(Info(P));
		  if (Pt != Nil) {
			InsertLast(Lout,Pt);
			P = Next(P);
		  } else {
			gagal = true;
			DelAll(Lout);
		  }
		}
}

void Konkat (List L1, List L2, List * L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang "baru" */
/* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */
{
	address P, Pt;
    boolean gagal;

    CreateEmpty(L3);
    gagal = false;
    P = First(L1);
		while ((P != Nil)&&(!gagal)) 
		{
		  Pt = Alokasi(Info(P));
			  if (Pt != Nil) {
				InsertLast(L3,Pt);
				P = Next(P);
			  } else {
				gagal = true;
				DelAll(L3);
			  }
		}
		
    if (!gagal) {
      P = First(L2);
		  while ((P != Nil)&&(!gagal)) 
		  {
			Pt = Alokasi(Info(P));
				if (Pt != Nil) {
				  InsertLast(L3,Pt);
				  P = Next(P);
				} else {
				  gagal = true;
				  DelAll(L3);
				}
		  }
    }
	
}
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
	address LastL1;

	CreateEmpty(L3);
	if (IsEmpty(*L1)){
		First(*L3) = First(*L2);
		CreateEmpty(L2);
	} else {
		First(*L3) = First(*L1);
		LastL1 = First(*L1);
		while (Next(LastL1) != Nil){
			LastL1 = Next(LastL1);
		}
		Next(LastL1) = First(*L2);
		CreateEmpty(L1);
		CreateEmpty(L2);
	}	
}
void PecahList (List *L1, List *L2, List L)
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
{
	address P, Pt;
    boolean gagal;
    int i, N;


    CreateEmpty(L1);
    CreateEmpty(L2);
    gagal = false;
    i = 1;
    N = NbElmt(L)/2;
    P = First(L);
		while ((P != Nil) && (!gagal)) 
		{
		  Pt = Alokasi(Info(P));
			 if (i <= N) 
			 {
				if (Pt != Nil) {
				  InsertLast(L1,Pt);
				  P = Next(P);
				  i++;
				} else {
				  gagal = true;
				  DelAll(L1);
				}
			 } 
			  else 
			{
				if (Pt != Nil) {
				  InsertLast(L2,Pt);
				  P = Next(P);
				  i++;
				} else {
				  gagal = true;
				  DelAll(L2);
				}
			}
		}
}
