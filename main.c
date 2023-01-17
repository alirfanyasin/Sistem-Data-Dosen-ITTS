// Include file header
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct dosen{
  char  nip[50];
  char  nama[50];
  char  matkul[50];
  char  alamat[50];
  char  kontak[50];
};char clear[1];



/*Function Lihat Data------------------------------------------------------*/
void lihatDataDosen(){
  int loop = 0;
  char dataDosen[500];
  struct dosen lihatDosen[100];
  char *hasil;
  FILE *fptr;
  fptr = fopen("dataDosen.txt", "r"); /*Buka File DataDosen.txt*/

  /*Hapus Data Pada lihatDosen*/
  for (int i = 0; i < 100; i++){
    for (int j = 0; j < 50; j++){
      lihatDosen[i].nip[j] = clear[0];
      lihatDosen[i].nama[j] = clear[0];
      lihatDosen[i].matkul[j] = clear[0];
      lihatDosen[i].kontak[j] = clear[0];
      lihatDosen[i].alamat[j] = clear[0];
    }
  }
  /*End Hapus Data Pada lihatDosen*/

  while (fgets(dataDosen, sizeof(dataDosen), fptr)){  /*Untuk Setiap Baris Data Pada dataDosen.txt*/
    int loop2 = 0;
    int index[4];

    /*Mencari Index Dari Char '|'*/
    hasil = strchr(dataDosen, '|');
    while(hasil != NULL){
      index[loop2] = hasil - dataDosen;
      hasil = strchr(hasil+1, '|');
      loop2++;
    }
    /*Mencari Index Dari Char '|'*/

    /*Memasukkan Data Pada File txt Ke lihatDosen*/
    for (int j = 0; j < index[0]; j++){
      lihatDosen[loop].nip[j] = dataDosen[j];
    }
    for (int j = 0; j < index[1]-index[0]-1; j++){
      lihatDosen[loop].nama[j] = dataDosen[j+index[0]+1];
    }
    for (int j = 0; j < index[2]-index[1]-1; j++){
      lihatDosen[loop].matkul[j] = dataDosen[j+index[1]+1];
    }
    for (int j = 0; j < index[3]-index[2]-1; j++){
      lihatDosen[loop].alamat[j] = dataDosen[j+index[2]+1];
    }
    for (int j = 0; j < strlen(dataDosen)-index[3]-1; j++){
      lihatDosen[loop].kontak[j] = dataDosen[j+index[3]+1];
    }
    /*End Memasukkan Data Pada File txt Ke lihatDosen*/

    /*Menampilkan Data Pada lihatDosen*/
    printf("\n");  
    printf("NIP = %s", lihatDosen[loop].nip);
    printf("\n");
    printf("Nama = %s", lihatDosen[loop].nama);
    printf("\n");
    printf("Matkul = %s", lihatDosen[loop].matkul);
    printf("\n");
    printf("Alamat = %s", lihatDosen[loop].alamat);
    printf("\n");
    printf("Kontak = %s", lihatDosen[loop].kontak);
    printf("\n");
    /*Menampilkan Data Pada lihatDosen*/

    loop++;
  }
  fclose(fptr); /*Tutup File datadosen.txt*/

  printf("\nTekan enter untuk keluar..\n");
  getchar();
  getchar();

}



/*Function Input Data Dosen------------------------------------------------------*/
void inputDataDosen(){
struct dosen inputDosen[100];
int jmlInput;

/*Hapus Data Pada inputDosen*/
for (int i = 0; i < 100; i++){
  for (int j = 0; j < 50; j++){
    inputDosen[i].nama[j] = clear[0];
    inputDosen[i].nama[j] = clear[0];
    inputDosen[i].matkul[j] = clear[0];
    inputDosen[i].kontak[j] = clear[0];
    inputDosen[i].alamat[j] = clear[0];
  }
}
/*End Hapus Data Pada inputDosen*/

printf("Masukkan Jumlah Input :  ");
scanf("%d", &jmlInput); /*Masukkan Jumlah Input Data Yang Diinginkan*/

for (int i = 0; i < jmlInput; i++)
{
  /*Ambil Input Data Dosen Dari User*/
  printf("\nNIP : ");
  scanf(" %[^\n]s", inputDosen[i].nip);
  printf("Nama : ");
  scanf(" %[^\n]s", inputDosen[i].nama);
  printf("Matkul : ");
  scanf(" %[^\n]s", inputDosen[i].matkul);
  printf("Alamat : ");
  scanf(" %[^\n]s", inputDosen[i].alamat);
  printf("Kontak : ");
  scanf(" %[^\n]s", inputDosen[i].kontak);
  /*End Ambil Input Data Dosen Dari User*/

  /*Menggabungkan Input User Menjadi Satu String*/
  char str[500] = {""};
  strcat(str, inputDosen[i].nip);
  strcat(str, "|");
  strcat(str, inputDosen[i].nama);
  strcat(str, "|");
  strcat(str, inputDosen[i].matkul);
  strcat(str, "|");
  strcat(str, inputDosen[i].alamat);
  strcat(str, "|");
  strcat(str, inputDosen[i].kontak);
  strcat(str, "\n");
  /*End Menggabungkan Input User Menjadi Satu String*/

  /*Simpan String Hasil Penggabungan Ke dataDosen.txt*/
  FILE *fptr;
  fptr = fopen("dataDosen.txt", "a");
  fprintf(fptr,"%s", str);
  fclose(fptr);
  /*End Simpan String Hasil Penggabungan Ke dataDosen.txt*/
}
}



/*Function Edit Data Dosen------------------------------------------------------*/
void editDataDosen(){

}



/*Function Hapus Data Dosen------------------------------------------------------*/
void hapusDataDosen(){
  int loop = 0;
  int loop6 = 0;
  char dataDosen[500];
  struct dosen hapusDosen[100];
  char *hasil;
  FILE *fptr;
  fptr = fopen("dataDosen.txt", "r"); /*Buka File DataDosen.txt*/
  char hapusData[50];
  printf("Masukkan NIP Yang Ingin Dihapus : ");
  scanf("%s", hapusData);

  /*Hapus Data Pada hapusDosen*/
  for (int i = 0; i < 100; i++){
    for (int j = 0; j < 50; j++){
      hapusDosen[i].nip[j] = clear[0];
      hapusDosen[i].nama[j] = clear[0];
      hapusDosen[i].matkul[j] = clear[0];
      hapusDosen[i].kontak[j] = clear[0];
      hapusDosen[i].alamat[j] = clear[0];
    }
  }
  /*End Hapus Data Pada hapusDosen*/

  while (fgets(dataDosen, sizeof(dataDosen), fptr)){  /*Untuk Setiap Baris Data Pada dataDosen.txt*/
    int loop4 = 0;
    int loop5 = 0;
    int index3[4];
    /*Mencari Index Dari Char '|'*/
    hasil = strchr(dataDosen, '|');
    while(hasil != NULL){
      index3[loop4] = hasil - dataDosen;
      hasil = strchr(hasil+1, '|');
      loop4++;
    }
    /*Mencari Index Dari Char '|'*/

    for (int j = 0; j < index3[0]; j++){
      if (dataDosen[j] == hapusData[j]){
        loop5++;
      }
    }

    if (loop5 != index3[0]){
      char str[500] = {""};
      strcat(str, dataDosen);

    if (loop6 > 0)
    {
      /*Simpan String Hasil Penggabungan Ke dataDosen.txt*/
      FILE *fptr;
      fptr = fopen("dataDosen.txt", "a");
      fprintf(fptr,"%s", str);
      fclose(fptr);
      /*End Simpan String Hasil Penggabungan Ke dataDosen.txt*/
    }
    if (loop6 == 0)
    {
      /*Simpan String Hasil Penggabungan Ke dataDosen.txt*/
      FILE *fptr;
      fptr = fopen("dataDosen.txt", "w");
      fprintf(fptr,"%s", str);
      fclose(fptr);
      /*End Simpan String Hasil Penggabungan Ke dataDosen.txt*/
      loop6++;
    }
    }else{
      
    }
    loop++;
  }
  fclose(fptr); /*Tutup File datadosen.txt*/
}



/*Function Cari Data Dosen------------------------------------------------------*/
void cariDataDosen(){
  int search = 0;
  int loop = 0;
  char *hasil;
  char searchData[50];
  char dataDosen[500];
  struct dosen cariData[100];
  FILE *fptr;
  fptr = fopen("dataDosen.txt", "r"); /*Buka File dataDosen.txt*/

  /*Hapus Data Pada cariData*/
  for (int i = 0; i < 100; i++){
    for (int j = 0; j < 50; j++){
      cariData[i].nip[j] = clear[0];
      cariData[i].nama[j] = clear[0];
      cariData[i].matkul[j] = clear[0];
      cariData[i].kontak[j] = clear[0];
      cariData[i].alamat[j] = clear[0];
    }
  }
  /*End Hapus Data Pada cariData*/

  /*Menu Cari Data*/
  printf("1.Nip\n2.Nama\n3.Matkul\nCari Berdasarkan : ");
  scanf("%d", &search);
  if (search == 1){ printf("Masukkan Nip : "); };
  if (search == 2){ printf("Masukkan Nama : "); };
  if (search == 3){ printf("Masukkan Matkul : "); };
  scanf(" %[^\n]s", &searchData);
  /*End Menu Cari Data*/

  while (fgets(dataDosen, sizeof(dataDosen), fptr)){  /*Untuk Setiap Baris Data Pada dataDosen.txt*/
    int loop2 = 0;
    int loop3 = 0;
    int index2[4];

    /*Mencari Index Dari Char '|'*/
    hasil = strchr(dataDosen, '|');
    while(hasil != NULL){
      index2[loop2] = hasil - dataDosen;
      hasil = strchr(hasil+1, '|');
      loop2++;
    }
    /*End Mencari Index Dari Char '|'*/

    /*Seleksi Search Menggunakan NIP*/
    if (search == 1){
      for (int j = 0; j < index2[0]; j++){
        if (dataDosen[j] == searchData[j]){
          loop3++;
        }
      }
    }
    /*End Seleksi Search Menggunakan NIP*/

    /*Seleksi Search Menggunakan Nama*/
    if (search == 2){

      for (int i = 0; i < 50; i++){
        int loop4 = 0;
        for (int j = 0; j < index2[1]-index2[0]-1; j++){
        if (tolower(dataDosen[i+j+index2[0]+1]) == tolower(searchData[j])){
          loop4++;
        }
        if (loop4 == strlen(searchData)){
          loop3 = index2[0];
        }
      }
      }
    }
    /*End Seleksi Search Menggunakan Nama*/
    
    if (loop3 == index2[0]){  /*Jika Data Sesuai Dengan Yang Dicari User*/

      /*Memasukkan Data Yang Telah Di Seleksi Ke cariData*/
      for (int j = 0; j < index2[0]; j++){
        cariData[loop].nip[j] = dataDosen[j];
      }
      for (int j = 0; j < index2[1]-index2[0]-1; j++){
        cariData[loop].nama[j] = dataDosen[j+index2[0]+1];
      }
      for (int j = 0; j < index2[2]-index2[1]-1; j++){
        cariData[loop].matkul[j] = dataDosen[j+index2[1]+1];
      }
      for (int j = 0; j < index2[3]-index2[2]-1; j++){
        cariData[loop].alamat[j] = dataDosen[j+index2[2]+1];
      }
      for (int j = 0; j < strlen(dataDosen)-index2[3]-1; j++){
        cariData[loop].kontak[j] = dataDosen[j+index2[3]+1];
      }
      /*End Memasukkan Data Yang Telah Di Seleksi Ke cariData*/

      /*Tampilkan Data Yang Lolos Seleksi*/
      printf("\n");  
      printf("NIP = %s", cariData[loop].nip);
      printf("\n");
      printf("Nama = %s", cariData[loop].nama);
      printf("\n");
      printf("Matkul = %s", cariData[loop].matkul);
      printf("\n");
      printf("Alamat = %s", cariData[loop].alamat);
      printf("\n");
      printf("Kontak = %s", cariData[loop].kontak);
      printf("\n");
      /*End Tampilkan Data Yang Lolos Seleksi*/

      loop++;
    }
  }

  if (loop == 0){ /*Jika Data Tidak Ditemukan*/
    printf("Hasil Tidak Ditemukan..");
  }
    
  fclose(fptr);
  printf("\nTekan enter untuk keluar..\n");
  getchar();
  getchar();
}

int main() {
  int menu;
    while (1){
      printf("===Data Dosen=== :\n");
      printf("1. Lihat Data Dosen\n");
      printf("2. Input Data Dosen\n");
      printf("3. Edit Data Dosen\n");
      printf("4. Hapus Data Dosen\n");
      printf("5. Cari Data Dosen\n");
      printf("Pilih Menu :");
      scanf("%d", &menu);

      switch (menu){
      case 1:
        lihatDataDosen();
        break;
      case 2:
        inputDataDosen();
        break;
      case 4:
        hapusDataDosen();
        break;
      case 5:
        cariDataDosen();
        break;
      default:

        break;
      }
      
    }
    
  return 0;
}