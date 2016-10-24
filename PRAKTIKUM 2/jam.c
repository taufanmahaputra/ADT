/* File: jam.h */
/* Tanggal: 28 Agustus 2016 */
/* Definisi ADT JAM */

/*
NIM             : 13515028
Nama            : Taufan Mahaputra
Tanggal         : 1 September 2016
Topik praktikum : ADT
Deskripsi       : Membuat file-file ADT Point
*/

#include "jam.h"
#include "boolean.h"
#include <stdio.h>


/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid (int H, int M, int S){
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
	return ( (H>=0) && (H<24) && (M>=0) && (M<60) && (S>=0) && (S<60) );
}


/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int hh, int mm, int ss){
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
	JAM j;
	Hour(j) = hh;
	Minute(j) = mm;
	Second(j) = ss;
	return j;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J){
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh:
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */

	int h,m,s;
	char spc;

	do {
		scanf("%d %d %d", &h,&m,&s);
		if (IsJAMValid(h,m,s)) {
			*J = MakeJAM(h,m,s);
		} else { printf("Jam tidak valid"); }
	}
	while (!(IsJAMValid(h,m,s)));

}
void TulisJAM (JAM J){
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
	printf("%d:%d:%d", Hour(J), Minute(J), Second(J));

}
/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToDetik (JAM J){
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
	 long detik;
	 detik = (3600*Hour(J)) + (60*Minute(J)) + Second(J);

	 return detik;
}

JAM DetikToJAM (long N){
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
	JAM J;

	if(N >=86400) { N = N%86400; }

	Hour(J) = N / 3600;
	Minute(J) = (N%3600)/ 60;
	Second(J) = (N%3600)% 60;

	return J;

}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2){
/* Mengirimkan true jika J1=J2, false jika tidak */
	return ((Hour(J1) == Hour (J2)) && (Minute(J1) == Minute(J2)) && (Second(J1) == Second(J2)));
}
boolean JNEQ (JAM J1, JAM J2){
/* Mengirimkan true jika J1 tidak sama dengan J2 */
	return ((Hour(J1) != Hour (J2)) && (Minute(J1) != Minute(J2)) && (Second(J1) != Second(J2)));
}
boolean JLT (JAM J1, JAM J2){
/* Mengirimkan true jika J1<J2, false jika tidak */
	return ((Hour(J1) < Hour (J2)) && (Minute(J1) < Minute(J2)) && (Second(J1) < Second(J2)));
}
boolean JGT (JAM J1, JAM J2){
/* Mengirimkan true jika J1>J2, false jika tidak */
	return ((Hour(J1) > Hour (J2)) && (Minute(J1) > Minute(J2)) && (Second(J1) > Second(J2)));
}
/* *** Operator aritmatika JAM *** */
JAM NextDetik (JAM J){
/* Mengirim 1 detik setelah J dalam bentuk JAM */
	long temp = JAMToDetik(J)+1;
        if (temp>=0) {
            return DetikToJAM(temp);
        } else {
            return DetikToJAM(temp+86400);;
        }
}
JAM NextNDetik (JAM J, int N){
/* Mengirim N detik setelah J dalam bentuk JAM */
	long temp1,temp2,temp3;
	 temp1 = abs(N) % 86400;
	 temp2 = JAMToDetik(J);
	 temp3 = temp2 + temp1;
	 return DetikToJAM(temp3);

}
JAM PrevDetik (JAM J){
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
    long temp = JAMToDetik(J)-1;
        if (temp>=0) {
            return DetikToJAM(temp);
        } else {
            return DetikToJAM(temp+86400);;
        }

}
JAM PrevNDetik (JAM J, int N){
/* Mengirim N detik sebelum J dalam bentuk JAM */
	  long temp = JAMToDetik(J)-N;
        if (temp>=0) {
            return DetikToJAM(temp);
        } else {
            return DetikToJAM(temp+8640000);;
        }

}
/* *** Kelompok Operator Aritmetika *** */
long Durasi (JAM JAw, JAM JAkh){
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
	if(JGT(JAw, JAkh)) {
		return (  JAMToDetik(JAw) - JAMToDetik(JAkh) + 86400 );
	} else { return ( JAMToDetik(JAkh) - JAMToDetik(JAw)); }
}

