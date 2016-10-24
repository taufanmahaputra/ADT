/*
NIM				: 13515028
Nama			: Taufan Mahaputra
Tanggal			: 15 September 2016
Topik praktikum	: Implementasi Matriks
Deskripsi		: Program berisikan fungsi/prosedur yang dapat dikerjakan pada matriks
*/
#include "matriks.h"
#include <stdio.h>

/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M){
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;  

}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
	return ( (i>=BrsMin) && (i<=BrsMax) && (j>=KolMin) && (j<=KolMax) );
}
/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terkecil M */
	return BrsMin;
}
indeks GetFirstIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terkecil M */
	return KolMin;
}
indeks GetLastIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terbesar M */
	return (NBrsEff(M)+BrsMin-1);
}
indeks GetLastIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terbesar M */
	return (NKolEff(M)+KolMin-1);
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
	return ( (i>=GetFirstIdxBrs(M)) && (i<=GetLastIdxBrs(M)) && (j>=GetFirstIdxKol(M)) && (j<=GetLastIdxKol(M))  );
}
ElType GetElmtDiagonal (MATRIKS M, indeks i){
/* Mengirimkan elemen M(i,i) */
	return Elmt(M,i,i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
/* Melakukan assignment MHsl  MIn */
	int i,j;
	
	MakeMATRIKS(NBrsEff(MIn),NKolEff(MIn),MHsl);
	for (i=GetFirstIdxBrs(MIn);i<=GetLastIdxBrs(MIn);i++) {
		for(j=GetFirstIdxKol(MIn);j<=GetLastIdxKol(MIn);j++){
					Elmt(*MHsl,i,j) = Elmt(MIn,i,j);
		}
	}
}
/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK){
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
	MakeMATRIKS(NB,NK, M);
	int i,j;
	for (i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++) {
		for(j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
			scanf("%d", &Elmt((*M),i,j));
		}
	}


}
void TulisMATRIKS (MATRIKS M){
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
	int i,j;
	for (i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++) {
		for(j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
			printf("%d", Elmt(M,i,j));
				if(j<GetLastIdxKol(M)) {
					printf(" ");
				}
		}
		if(i<GetLastIdxBrs(M)) {
					printf("\n");
		}
	}
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */ 
	MATRIKS M3;
	MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&M3);
	int i,j;
	for (i=GetFirstIdxBrs(M1);i<=GetLastIdxBrs(M1);i++) {
		for(j=GetFirstIdxKol(M1);j<=GetLastIdxKol(M1);j++){
			Elmt(M3,i,j) = Elmt(M1,i,j) + Elmt(M2,i,j);
		}
	}
	
	return M3;
}
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
	MATRIKS M3;
	MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&M3);
	int i,j;
	for (i=GetFirstIdxBrs(M1);i<=GetLastIdxBrs(M1);i++) {
		for(j=GetFirstIdxKol(M1);j<=GetLastIdxKol(M1);j++){
			Elmt(M3,i,j) = Elmt(M1,i,j) - Elmt(M2,i,j);
		}
	}
	
	return M3;
} 
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
	MATRIKS M3;
	MakeMATRIKS(NBrsEff(M1),NKolEff(M2),&M3);
	
	int i,j,k;
	
	for (i=GetFirstIdxBrs(M1);i<=GetLastIdxBrs(M1);i++){
		for(j=GetFirstIdxKol(M2);j<=GetLastIdxKol(M2);j++){
			Elmt(M3,i,j) = 0;
		}
	}
	
	for (i=GetFirstIdxBrs(M1);i<=GetLastIdxBrs(M1);i++) {
		for(j=GetFirstIdxKol(M2);j<=GetLastIdxKol(M2);j++){
			for(k=GetFirstIdxKol(M1);k<=GetLastIdxKol(M1);k++){
					Elmt(M3,i,j) = Elmt(M3,i,j) +  Elmt(M1,i,k) * Elmt(M2,k,j) ;
			}
		}
	}
	
	return M3;
}
MATRIKS KaliKons (MATRIKS M, ElType X){
/* Mengirim hasil perkalian setiap elemen M dengan X */
	MATRIKS M3;
	MakeMATRIKS(NBrsEff(M),NKolEff(M),&M3);
	int i,j;
	for (i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++) {
		for(j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
			Elmt(M3,i,j) = Elmt(M,i,j) * X;
		}
	}
	
	return M3;
}
void PKaliKons (MATRIKS * M, ElType K){
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
	
	int i,j;
	MakeMATRIKS(NBrsEff(*M),NKolEff(*M),M);
	for (i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++) {
		for(j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
			Elmt(*M,i,j) =  Elmt(*M,i,j) * K;
		}
	}
}


/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
   int i,j;
   boolean valid = true;
   if ((NBrsEff(M1)==NBrsEff(M2)) && (NKolEff(M1) == NKolEff(M2))) {
	i = GetFirstIdxBrs(M1);
		while(i<=GetLastIdxBrs(M1) && valid){
			 j = GetFirstIdxKol(M1);
				while(j<=GetLastIdxKol(M1) && valid){
					if(Elmt(M1,i,j) != Elmt(M2,i,j)){
						valid = false;
					}
					j++;		
				}
				i++;
		}
	} else {
		valid = false;
	}
	
	return valid;
}
boolean NEQ (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika M1 tidak sama dengan M2 */
	return (!EQ(M1,M2));
}
boolean EQSize (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
	return ( (NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) == NKolEff(M2))    );
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M){
/* Mengirimkan banyaknya elemen M */
	return ((NBrsEff(M)) * (NKolEff(M)));
}
/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M){
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
	return (NBrsEff(M) == NKolEff(M));
}
boolean IsSimetri (MATRIKS M){
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
	boolean s = true;
	if(IsBujurSangkar(M)){
		int i,j;
		i = GetFirstIdxBrs(M); 
		while(i<=GetLastIdxBrs(M) && s){
			j = GetFirstIdxKol(M);
				while(j<=GetLastIdxKol(M) && s){
					if(Elmt(M,i,j) != Elmt(M,j,i)){
						s = false;
					}
					j++;		
				}
				i++;
		}
	} 
	else {
		s = false;
	}
	 return s;
}
boolean IsSatuan (MATRIKS M){
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
   boolean s = true;
	if(IsBujurSangkar(M)){
		int i,j;
		i = GetFirstIdxBrs(M); 
		while(i<=GetLastIdxBrs(M) && s){
			j = GetFirstIdxKol(M);
				while(j<=GetLastIdxKol(M) && s){
					if(i==j) {
						if(GetElmtDiagonal(M,i) != 1) {
							s = false;
						}
					} else if(Elmt(M,i,j) != 0){
						s = false;
					}
					j++;		
				}
				i++;
		}
	} else {
		s = false;
	}
	
	return  s;
} 
boolean IsSparse (MATRIKS M){
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
  
		int i,j;
		float count = 0;
		for (i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++) {
			for(j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
				if(Elmt(M,i,j) != 0) {
					count++;
				}
			}
		}
			if ( (count > ((NBElmt(M)) * (0.05)))  ) {
				return false;
			} else {
				return true;
			}
	
}
MATRIKS Inverse1 (MATRIKS M){
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
	return KaliKons(M, -1);
}
float Determinan (MATRIKS M){
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
	int i,j,k;
	
	int det1 =1;
	int sumdet1= 0;
	int det2 =1;
	int  sumdet2= 0;
	i =1;
		for(j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
			det1=1;
			for(k=0;k<=NBrsEff(M)-1;k++){
				if((j+k) > 3){
				det1 = det1 * (Elmt(M,(i+k),((j+k)%3)));
				}
				else {
				det1 = det1 * (Elmt(M,(i+k),(j+k)));
				}
			}
			sumdet1 = sumdet1 + det1;
		}
	 i = NBrsEff(M);
	 for(j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
			det2=1;
			for(k=0;k<=NBrsEff(M)-1;k++){
				if((j+k) > 3){
				det2 = det2 * (Elmt(M,(i-k),((j+k)%3)));
				
				}
				else {
				det2 = det2 * (Elmt(M,(i-k),(j+k)));
				
				}
			}
			sumdet2 = sumdet2 + det2;
		}
		
		return (sumdet1-sumdet2);
}
void PInverse1 (MATRIKS * M){
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
	 *M = Inverse1(*M);
}
void Transpose (MATRIKS * M){
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */ 
		int i,j;
		MATRIKS Mout;
		CopyMATRIKS(*M,&Mout);
		for (i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++) {
			for(j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
				Elmt(*M,i,j) = Elmt(Mout,j,i);
			}
		}
}

/* Operasi berbasis baris dan per kolom */

float RataBrs (MATRIKS M, indeks i){
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
	int j;
	float count = 0;
	
	
	for(j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++) {
		count += Elmt(M,i,j);
	}
	
	return (count/(NKolEff(M)));

}

float RataKol (MATRIKS M, indeks j){
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
	
	int i;
	float count = 0;
	
	
	for(i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++) {
		count += Elmt(M,i,j);
	}
	
	return (count/(NBrsEff(M)));
}

void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min){
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
	
	int j;
	int Max = Elmt(M,i,GetFirstIdxKol(M));
	int Min = Elmt(M,i,GetFirstIdxKol(M));
	
	
	for(j=GetFirstIdxKol(M)+1;j<=GetLastIdxKol(M);j++) {
		if(Elmt(M,i,j) >= Max) {
			Max = Elmt(M,i,j);
		}
		if(Elmt(M,i,j) <= Min) {
			Min = Elmt(M,i,j);
		}
	}

	*max = Max;
	*min = Min;
}
void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min){
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */

	int i;
	int Max = Elmt(M,GetFirstIdxBrs(M),j);
	int Min = Elmt(M,GetFirstIdxBrs(M),j);
	
	
	for(i=GetFirstIdxBrs(M)+1;i<=GetLastIdxBrs(M);i++) {
		if(Elmt(M,i,j) >= Max) {
			Max = Elmt(M,i,j);
		}
		if(Elmt(M,i,j) <= Min) {
			Min = Elmt(M,i,j);
		}
	}

	*max = Max;
	*min = Min;
}

int CountXBrs (MATRIKS M, indeks i, ElType X){
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
	int j;
	int count = 0;
	
	
	for(j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++) {
		if(Elmt(M,i,j) == X ) {
			count++;
		}
	}
	
	return (count);

}
int CountXKol (MATRIKS M, indeks j, ElType X){
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
	int i;
	int count = 0;
	
	
	for(i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++) {
		if(Elmt(M,i,j) == X ) {
			count++;
		}
	}
	
	return (count);
}
