/* NIM 			: 13515028
Nama 			: Taufan Mahaputra
Tanggal			: 25 Agustus 2016
Topik praktikum	: Pengenalan bahasa C
Deskripsi		: Program menampilkan sifat integer dari A, B, C (positif/negatif/nol dan ganjil/genap) 
				  Nilai maksimum, minimum, dan nilai tengah */

#include <stdio.h>

/* PROCEDURE DAN FUNCTION */

void CekInteger (int x){
/* I.S.: x terdefinisi */
/* F.S.: Jika x positif dan genap, maka tertulis di layar: POSITIF-GENAP
         Jika x positif dan ganjil, maka tertulis di layar: POSITIF-GANJIL
         Jika x negatif, maka tertulis di layar: NEGATIF
         Jika x nol, maka tertulis di layar: NOL */
	if ((x>0) && (x%2 ==0)) { printf("POSITIF-GENAP\n"); }
	if ((x>0) && (x%2 !=0)) { printf("POSITIF-GANJIL\n"); }
	if (x<0)  { printf("NEGATIF\n"); }
	if (x==0) { printf("NOL\n"); }
         
         
}
             

int Max (int a, int b, int c) {
/* menghasilkan nilai terbesar di antara a, b, c */
	
	
	if (a>=b) {
		if(c>=a){ return(c);
			} else { return(a); }
	} else {
			if(c>=b){return(c);;
			} else { return(b); }
			}
			
		}
	

 

int Min (int a, int b, int c){
/* menghasilkan nilai terkecil di antara a, b, c */
	if (a<=b) {
		if(c<=a){ return(c);
			} else { return(a); }
	} else {
			if(c<=b){return(c);;
			} else { return(b); }
			}
			
		}



/* PROGRAM UTAMA */

int main () {

       /* KAMUS */

       int A, B, C;

       int nilaitengah;

 

       /* ALGORITMA */

       /* Input */

       scanf("%d", &A);

       scanf("%d", &B);

       scanf("%d", &C);

      

       /* Menuliskan sifat integer */

       CekInteger(A);

       CekInteger(B);

       CekInteger(C);

 

       /* Penulisan maksimum, minimum, dan nilai tengah */

       printf("%d\n", Max(A,B,C));

       printf("%d\n", Min(A,B,C));

       nilaitengah = A + B + C - Max(A,B,C) - Min(A,B,C);

       printf("%d\n", nilaitengah);

      

       return 0;

}
