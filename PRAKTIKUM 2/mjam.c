/*
NIM             : 13515028
Nama            : Taufan Mahaputra
Tanggal         : 1 September 2016
Topik praktikum : ADT
Deskripsi       : Dengan memanfaatkan ADT Jam yang telah Anda buat pada praktikum sebelumnya, buatlah sebuah program yang digunakan untuk membaca beberapa pasangan JAM yang merepresentasikan waktu mulai dan waktu selesai pembicaraan telepon di suatu perusahaan penyedia layanan telepon, misalnya <J1, J2>. Selanjutnya untuk masing-masing pasangan, dituliskan durasi pembicaraan telepon dalam detik. Durasi pembicaraan telepon harus positif, sehingga harus diperiksa dulu manakah di antara J1 dan J2 yang lebih awal. Jam yang lebih awal adalah jam mulai sedangkan jam yang lebih akhir adalah jam selesai.
*/

#include "boolean.h"
#include <stdio.h>
#include "jam.h"

int main() {
    
    int N,i;
    long x,y,JMin,JMax;
    JAM J1,J2;
    
    scanf("%d",&N);
    printf("[1]\n");
    BacaJAM(&J1);
    BacaJAM(&J2);
    
    
    x = JAMToDetik(J1);
    y = JAMToDetik(J2);
    
    if(x<=y) {
            printf("%ld\n", Durasi(J1,J2));
        } else{ printf("%ld\n", Durasi(J2,J1)); }
    
    if(x<=y){ JMin = x; JMax = y;} else { JMin = y; JMax = x;}
    
    
    for(i=2;i<=N;i++) {
        printf("[%d]\n",i);
        BacaJAM(&J1);
        BacaJAM(&J2);
       
         x = JAMToDetik(J1);
        y = JAMToDetik(J2);
    
        if(x<=y) {
            printf("%ld\n", Durasi(J1,J2));
        } else{ printf("%ld\n", Durasi(J2,J1)); }
        

         
         
         if(JAMToDetik(J1)>= JMax) { JMax = JAMToDetik(J1);} 
         else if ((JAMToDetik(J2)>=JMax)) { JMax = JAMToDetik(J2); }
        
        
    }
    
    TulisJAM(DetikToJAM(JMin));
    printf("\n");
    TulisJAM(DetikToJAM(JMax));
    printf("\n");
    return 0;
}