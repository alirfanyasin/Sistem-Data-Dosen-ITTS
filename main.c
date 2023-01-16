// Include file header
#include <stdio.h>
#include <string.h>

struct dosen{
  char  nip[50];
  char  nama[50];
  char  matkul[50];
  char  alamat[50];
  char  kontak[50];
};

/*Function Lihat Data------------------------------------------------------*/
void lihatDataDosen(){
  char dataDosen[500];
  struct dosen lihatData[100];
  FILE *fptr;
  char *hasil;
    
  fptr = fopen("dataDosen.txt", "r");
    int loop = 0;
    while (fgets(dataDosen, sizeof(dataDosen), fptr)){
      hasil = strchr(dataDosen, '|');
      int loop2 = 0;
      int index[4];

      while(hasil != NULL){
        index[loop2] = hasil - dataDosen;
        hasil = strchr(hasil+1, '|');
        loop2++;
      }

      for (int j = 0; j < index[0]; j++){
        lihatData[loop].nip[j] = dataDosen[j];
      }
      for (int j = 0; j < index[1]-index[0]-1; j++){
        lihatData[loop].nama[j] = dataDosen[j+index[0]+1];
      }
      for (int j = 0; j < index[2]-index[1]-1; j++){
        lihatData[loop].matkul[j] = dataDosen[j+index[1]+1];
      }
      for (int j = 0; j < index[3]-index[2]-1; j++){
        lihatData[loop].alamat[j] = dataDosen[j+index[2]+1];
      }
      for (int j = 0; j < strlen(dataDosen)-index[3]-1; j++){
        lihatData[loop].kontak[j] = dataDosen[j+index[3]+1];
      }

      printf("\n");  
      printf("NIP = %s", lihatData[loop].nip);
      printf("\n");
      printf("Nama = %s", lihatData[loop].nama);
      printf("\n");
      printf("Matkul = %s", lihatData[loop].matkul);
      printf("\n");
      printf("Alamat = %s", lihatData[loop].alamat);
      printf("\n");
      printf("Kontak = %s", lihatData[loop].kontak);
      printf("\n");
      loop++;
    }
  fclose(fptr);
  printf("\nTekan enter untuk keluar..\n");
  getchar();
  getchar();
}


/*Function Input Data Dosen------------------------------------------------------*/
void inputDataDosen(){
  struct dosen inputDosen;

  printf("\nNIP : ");
  scanf(" %[^\n]s", inputDosen.nip);
  printf("Nama : ");
  scanf(" %[^\n]s", inputDosen.nama);
  printf("Matkul : ");
  scanf(" %[^\n]s", inputDosen.matkul);
  printf("Alamat : ");
  scanf(" %[^\n]s", inputDosen.alamat);
  printf("Kontak : ");
  scanf(" %[^\n]s", inputDosen.kontak);

  char str[500];
  strcat(str, inputDosen.nip);
  strcat(str, "|");
  strcat(str, inputDosen.nama);
  strcat(str, "|");
  strcat(str, inputDosen.matkul);
  strcat(str, "|");
  strcat(str, inputDosen.alamat);
  strcat(str, "|");
  strcat(str, inputDosen.kontak);
  strcat(str, "\n");

  FILE *fptr;
  fptr = fopen("dataDosen.txt", "a");
  fprintf(fptr,"%s", str);
  fclose(fptr);
}

/*Function Cari Data Dosen------------------------------------------------------*/
void cariDataDosen(){
  int search = 0;
  char searchData[50];
  printf("Cari Berdasarkan 1(nip) 2(nama) 3(matkul) : ");
  scanf("%d", &search);
  if (search == 1){ printf("Masukkan Nip : "); };
  if (search == 2){ printf("Masukkan Nama : "); };
  if (search == 3){ printf("Masukkan Matkul : "); };
  scanf(" %[^\n]s", &searchData);

  char dataDosen[500];
  struct dosen cariData[100];
  FILE *fptr;
  char *hasil;
    
  fptr = fopen("dataDosen.txt", "r");
    int loop = 0;
    while (fgets(dataDosen, sizeof(dataDosen), fptr)){
      hasil = strchr(dataDosen, '|');
      int loop2 = 0;
      int index2[4];
      int loop3 = 0;
      while(hasil != NULL){
        index2[loop2] = hasil - dataDosen;
        hasil = strchr(hasil+1, '|');
        loop2++;
      }

      if (search == 1){
        for (int j = 0; j < index2[0]; j++){
          if (dataDosen[j] == searchData[j]){
          // cariData[loop].nip[j] = dataDosen[j];
          loop3++;
          }
        }
      }
      if (search == 2){
        int loop4 = 0;
        for (int j = 0; j < index2[1]-index2[0]-1; j++){
          if (dataDosen[j+index2[0]+1] == searchData[j]){
          // cariData[loop].nip[j] = dataDosen[j];
          loop4++;
          }
          if (loop4 == strlen(searchData)){
            loop3 = index2[0];
          }
          printf("%d", loop4);
        }
        printf("%d\n", strlen(searchData));
        
      }
      // printf("%d",index2[0]);

      if (loop3 == index2[0]){
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
        loop++;
      }
    }
    if (loop == 0){
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
      case 5:
        cariDataDosen();
        break;
      default:

        break;
      }
      
    }
    
  return 0;
}