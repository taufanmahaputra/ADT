/* File: garis.h */
/* Tanggal: 28 Agustus 2016 */
/* Definisi ADT GARIS, menggunakan ADT point */

/*
NIM             : 13515028
Nama            : Taufan Mahaputra
Tanggal         : 1 September 2016
Topik praktikum : ADT
Deskripsi       : Membuat file-file ADT Point
*/

/* *** ADT LAIN YANG DIPAKAI *** */
#include "boolean.h"
#include "point.h"
#include <stdio.h>
#include "garis.h"
#include <math.h>

        
/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */ 
/* ***************************************************************** */
/* *** Konstruktor membentuk GARIS *** */
void MakeGARIS (POINT P1, POINT P2, GARIS * L){
/* I.S. P1 dan P2 terdefinisi */
/* F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
/* Membentuk sebuah L dari komponen-komponennya */
    GARIS T = *L;
    PAwal(T) = P1;
    PAkhir(T) = P2;
    *L = T;



}

/* ***************************************************************** */
/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS                  */
/* ***************************************************************** */


void BacaGARIS (GARIS * L){
/* I.S. sembarang */
/* F.S. L terdefinisi sebagai GARIS yang valid */
/* Proses : mengulangi membaca dua buah nilai P1 dan P2 sehingga dapat 
   membentuk GARIS yang valid 
   GARIS disebut valid jika titik awal tidak sama dengan titik akhirnya. */
/* Jika pembacaan garis tidak valid, diberikan pesan kesalahan: 
   "Garis tidak valid" */
/* Contoh:
   2 3
   2 3
   Garis tidak valid
   2 3
   3 3 
   --> terbentuk garis L dengan L.PAw = <2,3> dan L.PAkh = <3,3> */
    
    float x1,x2,y1,y2;
    GARIS T = *L;
    
    do {
            scanf("%f %f", &x1,&y1);
            scanf("%f %f", &x2, &y2);
           if((x1==x2) && (y1 == y2)) {
                printf("Garis tidak valid\n");
           } else {
               Absis(PAwal(T)) = x1; Ordinat(PAwal(T)) = y1;
               Absis(PAkhir(T)) = x2; Ordinat(PAkhir(T)) = y2;
               *L = T;
            }
    }
    while( !((x1==x2) && (y1 == y2)) );
    
}

void TulisGARIS (GARIS L){
/* I.S. L terdefinisi */
/* F.S. L tertulis di layar dengan format "((x1,y1),(x2,y2))" 
   tanpa tambahan karakter apa pun di depan, di tengah, atau di belakang,
   termasuk spasi dan enter */

    printf("((%.2f,%.2f),(%.2f,%.2f))",Absis(PAwal(L)),Ordinat(PAwal(L)),Absis(PAkhir(L)),Ordinat(PAkhir(L)));

}

/* *** Kelompok operasi garis *** */
float PanjangGARIS (GARIS L){
/* Menghitung panjang garis L : berikan rumusnya */
    float a,b;
    a = Absis(PAwal(L)) - Absis(PAkhir(L));
    b = Ordinat(PAwal(L)) - Ordinat(PAkhir(L));
    return (sqrt((a*a) + (b*b)));
    
}
float Gradien (GARIS L){
/* Mengembalikan Gradien (m) dari L */
/* Gradien garis yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) */
/* Prekondisi : x1 != x2 */
    return ( (Ordinat(PAkhir(L)) - Ordinat(PAwal(L))) / (Absis(PAkhir(L)) - Absis(PAwal(L)) )  );
}

void GeserGARIS (GARIS * L, float deltaX, float deltaY){
/* I.S. L terdefinisi */
/* F.S. L digeser sebesar deltaX ke arah sumbu X dan sebesar deltaY ke arah sumbu Y */
/* Proses : PAw dan PAkh digeser. */


}
/* *** Kelompok predikat *** */
boolean IsTegakLurus (GARIS L1, GARIS L2){
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */
/* Dua garis saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */
    if( (Gradien(L1) * Gradien(L2)) == (-1) ) { return true; } else { return false; }
}
boolean IsSejajar (GARIS L1, GARIS L2){
/* Menghasilkan true jika L "sejajar" terhadap L1 */
/* Dua garis saling sejajar jika memiliki gradien yang sama */
    if( (Gradien(L1) == Gradien(L2)) ) { return true; } else { return false; }

}
