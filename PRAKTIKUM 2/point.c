/* File: point.h */
/* Tanggal: 28 Agustus 2016 */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

/*
NIM             : 13515028
Nama            : Taufan Mahaputra
Tanggal         : 1 September 2016
Topik praktikum : ADT
Deskripsi       : Membuat file-file ADT Point
*/

#include "boolean.h"
#include "point.h"
#include <stdio.h>
#include <math.h>


/* *** DEFINISI PROTOTIPE PRIMITIF *** */

/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float x, float y){
/* Membentuk sebuah POINT dari komponen-komponennya */
	POINT p;
	Absis(p) = x;
	Ordinat(p) = y;
	return (p);

}


/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P){
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
	float x, y;
	char spc;

	scanf("%f", &x); scanf("%c", &spc); scanf("%f", &y);
	Absis(*P) = x;
	Ordinat(*P) = y;

}
void TulisPOINT (POINT P){
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */

	printf("(%.2f,%.2f)", Absis(P), Ordinat(P));

}
/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
	return (((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)))) ;
}
boolean NEQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 tidak sama dengan P2 */
	return (((Absis(P1) != Absis(P2)) && (Ordinat(P1) != Ordinat(P2))));
}
/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
/* Menghasilkan true jika P adalah titik origin */
	return ((Absis(P) == 0) && (Ordinat(P) == 0)) ;
}
boolean IsOnSbX (POINT P){
/* Menghasilkan true jika P terletak Pada sumbu X */
	return (Ordinat(P) == 0);
}
boolean IsOnSbY (POINT P){
/* Menghasilkan true jika P terletak pada sumbu Y */
	return (Absis(P) == 0);
}
int Kuadran (POINT P){
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */

	if ( (Absis(P) > 0) && (Ordinat(P) > 0)) {
		return (1);
	} else if ( (Absis(P) > 0) && (Ordinat(P) < 0)) {
		return (2);
	} else if ( (Absis(P) < 0) && (Ordinat(P) > 0)) {
		return (3);
	} else if ( (Absis(P) < 0) && (Ordinat(P) < 0)) {
		return (4);
	}

}
/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P){
/* Mengirim salinan P dengan absis ditambah satu */
	return ( MakePOINT((Absis(P) +1), (Ordinat(P))));
}
POINT NextY (POINT P){
/* Mengirim salinan P dengan ordinat ditambah satu */
	return ( MakePOINT((Absis(P)), (Ordinat(P) + 1)));
}
POINT PlusDelta (POINT P, float deltaX, float deltaY){
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
	return ( MakePOINT((Absis(P) + deltaX), (Ordinat(P) + deltaY)));
}
POINT MirrorOf (POINT P, boolean SbX){
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
	if(SbX) {
		return MakePOINT (Absis(P), (Ordinat(P) * (-1)));
	} else { return MakePOINT ((Absis(P) * (-1)), (Ordinat(P))); }
}
float Jarak0 (POINT P){
/* Menghitung jarak P ke (0,0) */
	return (sqrt (((Absis(P))* (Absis(P))) + ((Ordinat(P)) * (Ordinat(P))) ));
}
float Panjang (POINT P1, POINT P2){
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
    float a,b;
    a = Absis(P1) - Absis(P2);
    b = Ordinat(P1) - Ordinat(P2);
    return (sqrt((a*a) + (b*b)));
}
void Geser (POINT *P, float deltaX, float deltaY){
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
    POINT T = *P;
	*P = PlusDelta(T, deltaX, deltaY);

}
void GeserKeSbX (POINT *P){
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
	POINT T = *P;
	*P = MakePOINT(Absis(T), 0);
}
void GeserKeSbY (POINT *P){
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
    POINT T = *P;
	*P = MakePOINT(0, Ordinat(T));
}
void Mirror (POINT *P, boolean SbX){
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
    POINT T = *P;

	if(SbX) {
		 *P = MakePOINT (Absis(T), (Ordinat(T) * (-1)));
	} else { *P =MakePOINT ((Absis(T) * (-1)), (Ordinat(T))); }
}
void Putar (POINT *P, float Sudut){
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
    float rad,x,y;
    POINT T = *P;
    rad = (0.01745) * Sudut;
    x = (Absis(T)*(cos(rad)) - (Ordinat(T)*(sin(rad))));
    y = (Absis(T)*(sin(rad)) + (Ordinat(T)*(cos(rad))));
    *P = MakePOINT(x,y);
}

