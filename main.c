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

void lihatDataDosen(){
    char dataDosen[500];
    struct dosen lihatData;
    FILE *fptr;
    char *hasil;
    int index[4];

  fptr = fopen("dataDosen.txt", "r");
  while (fgets(dataDosen, sizeof(dataDosen), fptr)){
        hasil = strchr(dataDosen, '|');
        int loop = 0;
        while(hasil != NULL){
            index[loop] = hasil - dataDosen;
            printf("Ditemukan pada huruf ke-%d\n", hasil - dataDosen);
            hasil = strchr(hasil+1, '|');
            loop++;
            printf("%d", index[loop]);
        }
        printf("\n");
    }
  fclose(fptr);
}

void inputDataDosen(){
  struct dosen dosen01;
  printf("\nNIP : ");
  scanf(" %[^\n]s", dosen01.nip);
  printf("Nama : ");
  scanf(" %[^\n]s", dosen01.nama);
  printf("Matkul : ");
  scanf(" %[^\n]s", dosen01.matkul);
  printf("Alamat : ");
  scanf(" %[^\n]s", dosen01.alamat);
  printf("Kontak : ");
  scanf(" %[^\n]s", dosen01.kontak);

  char str[500];
  strcat(str, dosen01.nip);
  strcat(str, "|");
  strcat(str, dosen01.nama);
  strcat(str, "|");
  strcat(str, dosen01.matkul);
  strcat(str, "|");
  strcat(str, dosen01.alamat);
  strcat(str, "|");
  strcat(str, dosen01.kontak);
  strcat(str, "\n");

  FILE *fptr;
  fptr = fopen("dataDosen.txt", "a");
  fprintf(fptr,"%s", str);
  fclose(fptr);
}


int main() {
  int menu;
    while (1)
    {
      printf("===Data Dosen=== :\n");
      printf("1. Lihat Data Dosen\n");
      printf("2. Input Data Dosen\n");
      printf("3. Edit Data Dosen\n");
      printf("4. Hapus Data Dosen\n");
      printf("Pilih Menu :");
      scanf("%d", &menu);

      switch (menu)
      {

      case 1:
        lihatDataDosen();
        break;

      case 2:
        inputDataDosen();
        break;
      
      default:
        break;
      }
      
    }
    
  return 0;
}