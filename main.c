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

              for (int j = 0; j < index[0]; j++)
              {
                lihatData[loop].nip[j] = dataDosen[j];
              }
              for (int j = 0; j < index[1]-index[0]-1; j++)
              {
                lihatData[loop].nama[j] = dataDosen[j+index[0]+1];
              }
              for (int j = 0; j < index[2]-index[1]-1; j++)
              {
                lihatData[loop].matkul[j] = dataDosen[j+index[1]+1];
              }
              for (int j = 0; j < index[3]-index[2]-1; j++)
              {
                lihatData[loop].alamat[j] = dataDosen[j+index[2]+1];
              }
              for (int j = 0; j < strlen(dataDosen)-index[3]-1; j++)
              {
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
}

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