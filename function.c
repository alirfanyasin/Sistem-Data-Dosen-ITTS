// Include File Header
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>


// Declaration value
#define pjg 100
#define pjg2 50
#define pjg3 500


struct dosen{
	char  nip[pjg2];
	char  jenis_kelamin[pjg2];
    char  nama[pjg2];
    char  matkul[pjg2];
    char  alamat[pjg2];
    char  kontak[pjg2];
};

// Function Lihat Dosen
void lihatDataDosen(){
  	int loop = 0;
  	char dataDosen[pjg3];
  	struct dosen lihatDosen[pjg];
  	char *hasil;
  	FILE *fptr;
  	fptr = fopen("dataDosen.txt", "r");/*Buka File DataDosen.txt*/

  	memset(lihatDosen, 0, sizeof(lihatDosen)); /*Hapus Data Pada lihatDosen*/
        system("cls");
		printf("===================== LIHAT DATA DOSEN =====================\n");
  	while (fgets(dataDosen, sizeof(dataDosen), fptr)){/*Untuk Setiap Baris Data Pada dataDosen.txt*/
    	int loop2 = 0;
    	int index[5];

    	/*Mencari Index Dari Char '|'*/
    	hasil = strchr(dataDosen, '|');
    	while(hasil != NULL){
    	  	index[loop2] = hasil - dataDosen;
    	  	hasil = strchr(hasil+1, '|');
    	  	loop2++;
    	}
    	/*End Mencari Index Dari Char '|'*/

    	/*Memasukkan Data Pada File txt Ke lihatDosen*/
    	for (int j = 0; j < index[0]; j++){
    	  	lihatDosen[loop].nip[j] = dataDosen[j];
    	}
    	for (int j = 0; j < index[1]-index[0]-1; j++){
    	  	lihatDosen[loop].nama[j] = dataDosen[j+index[0]+1];
    	}
    	for (int j = 0; j < index[2]-index[1]-1; j++){
    	  	lihatDosen[loop].jenis_kelamin[j] = dataDosen[j+index[1]+1];
    	}
    	for (int j = 0; j < index[3]-index[2]-1; j++){
    	  	lihatDosen[loop].matkul[j] = dataDosen[j+index[2]+1];
    	}
    	for (int j = 0; j < index[4]-index[3]-1; j++){
    	  	lihatDosen[loop].alamat[j] = dataDosen[j+index[3]+1];
    	}
    	for (int j = 0; j < strlen(dataDosen)-index[4]-1; j++){
    	  	lihatDosen[loop].kontak[j] = dataDosen[j+index[4]+1];
    	}
    	/*End Memasukkan Data Pada File txt Ke lihatDosen*/

    	/*Menampilkan Data Pada lihatDosen*/
    	printf("\n");  
    	printf("NIP\t\t\t: %s\n", lihatDosen[loop].nip);
    	printf("Nama\t\t\t: %s\n", lihatDosen[loop].nama);
    	printf("Jenis Kelamin\t\t: %s\n", lihatDosen[loop].jenis_kelamin);
    	printf("Matkul\t\t\t: %s\n", lihatDosen[loop].matkul);
    	printf("Alamat\t\t\t: %s\n", lihatDosen[loop].alamat);
    	printf("Kontak\t\t\t: %s\n", lihatDosen[loop].kontak);
			printf("====================================\n");
    	/*Menampilkan Data Pada lihatDosen*/

    	loop++;
  	}

		printf("\nJumlah Data Dosen : %d\n\n", loop);

  	fclose(fptr);/*Tutup File datadosen.txt*/
	while (1)
	{
		int loop7 = 0;
		int sort = 0;
		while (strlen(lihatDosen[loop7].nip) != 0){
			loop7++;
		}
		/*Menu Sort*/
		printf("[1]. Urutkan Ascending Berdasarkan Nama\n");
		printf("[2]. Urutkan Descending Berdasarkan Nama\n");
		printf("[3]. Urutkan Ascending Berdasarkan NIP\n");
		printf("[4]. Urutkan Descending Berdasarkan NIP\n");
		printf("[9]. Kembali\n");
		printf("Pilih opsi menu : ");
		scanf("%d", &sort);
		/*End Menu Sort*/

		/*Jika User Memilih Sorting Berdasarkan Nama*/
		if (sort == 1 || sort == 2){
			int ind[loop7]; /*Untuk Menyimpan Index Sesuai Urutan Nama, Yang Akan Digunakan Untuk Print*/
			int loop8;

			/*Sort Nama Dari Yang Terkecil Dan Masukkan Index ke Ind*/
			for (int a = 0; a < loop7; a++)/*Untuk Setiap Data Yang Ada*/
			{
				loop8 = 0;
				for (int i = 0; i < loop7; i++)/*Bandingkan Dengan Semua Data Yang Ada*/
				{
					for (int j = 0; j < sizeof(lihatDosen[i].nama); j++)/*Bandingkan Setiap Huruf Pada Nama Dengan Data Lain*/
					{
						if (tolower(lihatDosen[a].nama[j]) > tolower(lihatDosen[i].nama[j]))
						{
							loop8++;/*Tambahkan Index Dan Kemudian Break Jika Nama Lebih Besar*/
							break;
						}else if(tolower(lihatDosen[a].nama[j]) < tolower(lihatDosen[i].nama[j])){
							break;/*Break Jika Nama Lebih Kecil*/
						}
					}

				}
				ind[loop8] = a;/*Masukkan Index Sekarang Kedalam Ind Yang Berindex Total Dari loop8*/
			}
			/*End Sort Nama Dari Yang Terkecil Dan Masukkan Index ke Ind*/
			
			system("cls");
			printf("===================== LIHAT DATA DOSEN =====================\n");


			if (sort == 1)/*Jika User Memilih Ascending*/
			{
				/*Print lihatDosen Berdasarkan Urutan ind dari Depan Kebelakang*/
				for (int i = 0; i < loop7; i++)
				{
					printf("\n");  
					printf("NIP\t\t\t: %s\n", lihatDosen[ind[i]].nip);
					printf("Nama\t\t\t: %s\n", lihatDosen[ind[i]].nama);
					printf("Jenis Kelamin\t\t: %s\n", lihatDosen[ind[i]].jenis_kelamin);
					printf("Matkul\t\t\t: %s\n", lihatDosen[ind[i]].matkul);
					printf("Alamat\t\t\t: %s\n", lihatDosen[ind[i]].alamat);
					printf("Kontak\t\t\t: %s\n", lihatDosen[ind[i]].kontak);
					printf("====================================\n");

				}
				/*End Print lihatDosen Berdasarkan Urutan ind dari Depan Kebelakang*/
			}

			if (sort == 2)/*Jika User Memilih Descending*/
			{
				/*Print lihatDosen Berdasarkan Urutan ind dari Belakang Kedepan*/
				for (int i = loop7-1; i >= 0; i--)
				{
					printf("\n");  
					printf("NIP\t\t\t: %s\n", lihatDosen[ind[i]].nip);
					printf("Nama\t\t\t: %s\n", lihatDosen[ind[i]].nama);
                    printf("Jenis Kelamin\t\t: %s\n", lihatDosen[ind[i]].jenis_kelamin);
					printf("Matkul\t\t\t: %s\n", lihatDosen[ind[i]].matkul);
					printf("Alamat\t\t\t: %s\n", lihatDosen[ind[i]].alamat);
					printf("Kontak\t\t\t: %s\n", lihatDosen[ind[i]].kontak);
					printf("====================================\n");

				}
				/*End Print lihatDosen Berdasarkan Urutan ind dari Belakang Kedepan*/
			}

		}
		/*End Jika User Memilih Sorting Berdasarkan Nama*/

		/*Jika User Memilih Sorting Berdasarkan NIP*/
		else if(sort == 3 || sort == 4){
			int ind[loop7]; /*Untuk Menyimpan Index Sesuai Urutan NIP, Yang Akan Digunakan Untuk Print*/
			int loop8;

			/*Sort NIP Dari Yang Terkecil Dan Masukkan Index ke Ind*/
			for (int a = 0; a < loop7; a++)/*Untuk Setiap Data Yang Ada*/
			{
				loop8 = 0;
				for (int i = 0; i < loop7; i++)/*Bandingkan Dengan Semua Data Yang Ada*/
				{
					if (strlen(lihatDosen[a].nip) > strlen(lihatDosen[i].nip))/*Jika Jumlah Digit Lebih Besar*/
					{
						loop8++;
					}else if(strlen(lihatDosen[a].nip) < strlen(lihatDosen[i].nip)){/*Jika Jumlah Digit Lebih Kecil*/

					}else{
						for (int j = 0; j < sizeof(lihatDosen[i].nip); j++)/*Bandingkan Setiap Huruf Pada NIP Dengan Data Lain*/
						{
							if (tolower(lihatDosen[a].nip[j]) > tolower(lihatDosen[i].nip[j]))
							{
								loop8++;/*Tambahkan Index Dan Kemudian Break Jika NIP Lebih Besar*/
								break;
							}else if(tolower(lihatDosen[a].nip[j]) < tolower(lihatDosen[i].nip[j])){
								break;/*Break Jika NIP Lebih Kecil*/
							}
						}
					}

				}
				ind[loop8] = a;/*Masukkan Index Sekarang Kedalam Ind Yang Berindex Total Dari loop8*/
			}
			/*End Sort NIP Dari Yang Terkecil Dan Masukkan Index ke Ind*/

			system("cls");
			printf("===================== LIHAT DATA DOSEN =====================\n");


			if (sort == 3)/*Jika User Memilih Ascending*/
			{
				/*Print lihatDosen Berdasarkan Urutan ind dari Depan Kebelakang*/
				for (int i = 0; i < loop7; i++)
				{
					printf("\n");  
					printf("NIP\t\t\t: %s\n", lihatDosen[ind[i]].nip);
					printf("Nama\t\t\t: %s\n", lihatDosen[ind[i]].nama);
                    printf("Jenis Kelamin\t\t: %s\n", lihatDosen[ind[i]].jenis_kelamin);
					printf("Matkul\t\t\t: %s\n", lihatDosen[ind[i]].matkul);
					printf("Alamat\t\t\t: %s\n", lihatDosen[ind[i]].alamat);
					printf("Kontak\t\t\t: %s\n", lihatDosen[ind[i]].kontak);
					printf("====================================\n");

				}
				/*End Print lihatDosen Berdasarkan Urutan ind dari Depan Kebelakang*/
			}

			if (sort == 4)/*Jika User Memilih Descending*/
			{
				/*Print lihatDosen Berdasarkan Urutan ind dari Belakang Kedepan*/
				for (int i = loop7-1; i >= 0; i--)
				{
					printf("\n");  
					printf("NIP\t\t\t: %s\n", lihatDosen[ind[i]].nip);
					printf("Nama\t\t\t: %s\n", lihatDosen[ind[i]].nama);
                    printf("Jenis Kelamin\t\t: %s\n", lihatDosen[ind[i]].jenis_kelamin);
					printf("Matkul\t\t\t: %s\n", lihatDosen[ind[i]].matkul);
					printf("Alamat\t\t\t: %s\n", lihatDosen[ind[i]].alamat);
					printf("Kontak\t\t\t: %s\n", lihatDosen[ind[i]].kontak);
					printf("====================================\n");
				}
				/*End Print lihatDosen Berdasarkan Urutan ind dari Belakang Kedepan*/
			}
		}
		/*End Jika User Memilih Sorting Berdasarkan NIP*/

		/*Jikas User Memilih Untuk Kembali*/
		else if(sort == 9){
			system("cls");
			break;
		}
		/*End Jikas User Memilih Untuk Kembali*/
	}
}



// Function Tambah Dosen
void inputDataDosen(){
	struct dosen inputDosen[pjg];
	int jmlInput;

	memset(inputDosen, 0, sizeof(inputDosen));/*Hapus Data Pada inputDosen*/
	printf("===================== INPUT DATA DOSEN =====================\n");
	printf("Masukkan Jumlah Input\t: ");
	scanf("%d", &jmlInput);/*Masukkan Jumlah Input Data Yang Diinginkan*/

	for (int i = 0; i < jmlInput; i++)
	{
		/*Ambil Input Data Dosen Dari User*/
		printf("\nNIP\t\t\t: ");
		scanf(" %[^\n]s", inputDosen[i].nip);
		printf("Nama\t\t\t: ");
		scanf(" %[^\n]s", inputDosen[i].nama);
		printf("Jenis Kelamin\t\t: ");
		scanf(" %[^\n]s", inputDosen[i].jenis_kelamin);
		printf("Matkul\t\t\t: ");
		scanf(" %[^\n]s", inputDosen[i].matkul);
		printf("Alamat\t\t\t: ");
		scanf(" %[^\n]s", inputDosen[i].alamat);
		printf("Kontak\t\t\t: ");
		scanf(" %[^\n]s", inputDosen[i].kontak);
		
		/*End Ambil Input Data Dosen Dari User*/

		/*Menggabungkan Input User Menjadi Satu String*/
		char str[pjg3] = {""};
		strcat(str, inputDosen[i].nip);
		strcat(str, "|");
		strcat(str, inputDosen[i].nama);
		strcat(str, "|");
		strcat(str, inputDosen[i].jenis_kelamin);
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
	printf("\nData berhasil di inputkan\n");
	printf("Loading ");
	sleep(1);
	printf(". ");
	sleep(1);
	printf(". ");
	sleep(1);
	printf(". ");
	sleep(1);
	printf(". ");
	system("cls");
}




// Function Edit Dosen
void editDataDosen(){
	int loop = 0;
  int loop6 = 0;
  char dataDosen[pjg3];
  char editData[pjg2];
  char jenis_kelamin[pjg2];
  char *hasil;
	char tmpNama[pjg2],tmpJenisKelamin[pjg2], tmpMatkul[pjg2], tmpAlamat[pjg2], tmpKontak[pjg2];
	struct dosen editDosen[pjg];
	FILE *fptr;
	fptr = fopen("dataDosen.txt", "r"); /*Buka File DataDosen.txt*/
	printf("===================== EDIT DATA DOSEN =====================\n");
	printf("Masukkan NIP Yang Ingin Diedit : ");
	scanf("%s", editData);
	printf("\nNama\t\t\t: ");
	scanf(" %[^\n]s", tmpNama);
	printf("Jenis Kelamin\t\t: ");
	scanf(" %[^\n]s", tmpJenisKelamin);
	printf("Matkul\t\t\t: ");
	scanf(" %[^\n]s", tmpMatkul);
	printf("Alamat\t\t\t: ");
	scanf(" %[^\n]s", tmpAlamat);
	printf("Kontak\t\t\t: ");
	scanf(" %[^\n]s", tmpKontak);

  	memset(editDosen, 0, sizeof(editDosen));  /*Hapus Data Pada editDosen*/

  	while (fgets(dataDosen, sizeof(dataDosen), fptr)){  /*Untuk Setiap Baris Data Pada dataDosen.txt*/
  	  	int loop4 = 0;
  	  	int loop5 = 0;
  	  	int index3[5];

  	  	/*Mencari Index Dari Char '|'*/
  	  	hasil = strchr(dataDosen, '|');
  	  	while(hasil != NULL){
  	  	  	index3[loop4] = hasil - dataDosen;
  	  	  	hasil = strchr(hasil+1, '|');
  	  	  	loop4++;
  	  	}
  	  	/*End Mencari Index Dari Char '|'*/

  	  	/*Seleksi NIP Dengan Input User*/
  	  	for (int j = 0; j < index3[0]; j++){
  	  	  	if (dataDosen[j] == editData[j] && strlen(editData) == index3[0]){
  	  	    	loop5++;
  	  	  	}
  	  	}
  	  	/*End Seleksi NIP Dengan Input User*/

  	  	if (loop5 != index3[0]){  /*Jika NIP Tidak Sama Dengan Input User*/
  	  	  	char str[pjg3] = {""};
  	  	  	strcat(str, dataDosen);

  	  	  	if (loop6 > 0){
  	  	  	  	/*Simpan String Hasil Penggabungan Ke dataDosen.txt*/
  	  	  	  	FILE *fptr;
  	  	  	  	fptr = fopen("dataDosen.txt", "a");
  	  	  	  	fprintf(fptr,"%s", str);
  	  	  	  	fclose(fptr);
  	  	  	  	/*End Simpan String Hasil Penggabungan Ke dataDosen.txt*/
  	  	  	}
  	  	  	if (loop6 == 0) /*Hapus Data Sebelumnya*/{
  	  	  	  	/*Simpan String Hasil Penggabungan Ke dataDosen.txt*/
  	  	  	  	FILE *fptr;
  	  	  	  	fptr = fopen("dataDosen.txt", "w");
  	  	  	  	fprintf(fptr,"%s", str);
  	  	  	  	fclose(fptr);
  	  	  	  	/*End Simpan String Hasil Penggabungan Ke dataDosen.txt*/
  	  	  	  	loop6++;
  	  	  	}
  	  	}else if(loop5 == index3[0]){  /*Jika NIP Sama Dengan Input User Simpan Edit User*/
			char str[pjg3] = {""};
  	  	  	strcat(str, editData);
  	  	  	strcat(str, "|");
  	  	  	strcat(str, tmpNama);
  	  	  	strcat(str, "|");
  	  	  	strcat(str, tmpJenisKelamin);
  	  	  	strcat(str, "|");
  	  	  	strcat(str, tmpMatkul);
  	  	  	strcat(str, "|");
  	  	  	strcat(str, tmpAlamat);
  	  	  	strcat(str, "|");
  	  	  	strcat(str, tmpKontak);
  	  	  	strcat(str, "\n");

  	  	  	if (loop6 > 0){
  	  	  	  	/*Simpan String Hasil Penggabungan Ke dataDosen.txt*/
  	  	  	  	FILE *fptr;
  	  	  	  	fptr = fopen("dataDosen.txt", "a");
  	  	  	  	fprintf(fptr,"%s", str);
  	  	  	  	fclose(fptr);
  	  	  	  	/*End Simpan String Hasil Penggabungan Ke dataDosen.txt*/
  	  	  	}
  	  	  	if (loop6 == 0) /*Hapus Data Sebelumnya*/{
  	  	  	  	/*Simpan String Hasil Penggabungan Ke dataDosen.txt*/
  	  	  	  	FILE *fptr;
  	  	  	  	fptr = fopen("dataDosen.txt", "w");
  	  	  	  	fprintf(fptr,"%s", str);
  	  	  	  	fclose(fptr);
  	  	  	  	/*End Simpan String Hasil Penggabungan Ke dataDosen.txt*/
  	  	  	  	loop6++;
  	  	  	}
  	  	}
  	  	loop++;
  	}
  	fclose(fptr); /*Tutup File datadosen.txt*/
}




// Function Hapus Dosen
void hapusDataDosen(){
  int loop = 0;
  int loop6 = 0;
  char dataDosen[pjg3];
  char hapusData[pjg2];
  char *hasil;
  struct dosen hapusDosen[pjg];
  FILE *fptr;
  fptr = fopen("dataDosen.txt", "r"); /*Buka File DataDosen.txt*/
	printf("===================== HAPUS DATA DOSEN =====================\n");
  printf("Masukkan NIP Yang Ingin Dihapus : ");
  scanf("%s", hapusData);

  memset(hapusDosen, 0, sizeof(hapusDosen));  /*Hapus Data Pada hapusDosen*/
  
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
    /*End Mencari Index Dari Char '|'*/
    /*Seleksi NIP Dengan Input User*/
    for (int j = 0; j < index3[0]; j++){
  	  if (dataDosen[j] == hapusData[j] && strlen(hapusData) == index3[0]){
	    	loop5++;
	  	} 
  	}
  	/*End Seleksi NIP Dengan Input User*/

  if (loop5 != index3[0]){  /*Jika NIP Tidak Sama Dengan Input User*/
    	char str[pjg3] = {""};
    	strcat(str, dataDosen);
  
  	if (loop6 > 0){
  	  /*Simpan String Hasil Penggabungan Ke dataDosen.txt*/
  	  FILE *fptr;
  	  fptr = fopen("dataDosen.txt", "a");
  	  fprintf(fptr,"%s", str);
  	  fclose(fptr);
  	  /*End Simpan String Hasil Penggabungan Ke dataDosen.txt*/
  	}
  	if (loop6 == 0) /*Hapus Data Sebelumnya*/{
  	  /*Simpan String Hasil Penggabungan Ke dataDosen.txt*/
  	  FILE *fptr;
  	  fptr = fopen("dataDosen.txt", "w");
  	  fprintf(fptr,"%s", str);
  	  fclose(fptr);
  	  /*End Simpan String Hasil Penggabungan Ke dataDosen.txt*/
  	  loop6++;
  	}
  }else{  /*Jika NIP Sama Dengan Input User (Kosongkan File)*/
  	  }
  	  loop++;
  	}
  	fclose(fptr); /*Tutup File datadosen.txt*/
		printf("Data berhasil di hapus\n");
		printf("Loading ");
		sleep(1);
		printf(". ");
		sleep(1);
		printf(". ");
		sleep(1);
		printf(". ");
		sleep(1);
		printf(". ");
		system("cls");
}




// Function Cari Dosen
void cariDataDosen(){
  int search = 0;
  int loop = 0;
  char *hasil;
  char searchData[pjg2];
  char dataDosen[pjg3];
  struct dosen cariData[pjg];
  FILE *fptr;
  fptr = fopen("dataDosen.txt", "r");/*Buka File dataDosen.txt*/
  memset(cariData, 0, sizeof(cariData));/*Hapus Data Pada cariData*/

  /*Menu Cari Data*/
	printf("===================== CARI DATA DOSEN =====================\n");
  printf("1.Nip\n2.Nama\n3.Matkul\nCari Berdasarkan : ");
  scanf("%d", &search);
  if (search == 1){ printf("Masukkan Nip : "); };
  if (search == 2){ printf("Masukkan Nama : "); };
  if (search == 3){ printf("Masukkan Matkul : "); };
  scanf(" %[^\n]s", &searchData);
  /*End Menu Cari Data*/

  	while (fgets(dataDosen, sizeof(dataDosen), fptr)){/*Untuk Setiap Baris Data Pada dataDosen.txt*/
  	  int loop2 = 0;
  	  int loop3 = 0;
  	  int loop4 = 0;
  	  int index2[5];

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
  	  	    	if (dataDosen[j] == searchData[j] && strlen(searchData) == index2[0]){
  	  	      	loop3++;
  	  	    	}
  	  	  	}
  	  	}
  	  	/*End Seleksi Search Menggunakan NIP*/

  	  	/*Seleksi Search Menggunakan Nama*/
  	  	if (search == 2){

  	  	  	for (int i = 0; i < index2[1] - index2[0] - 1; i++){
  	  	  	  	loop4 = 0;
  	  	  	  	for (int j = 0; j < strlen(searchData); j++){
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

  	  	/*Seleksi Search Menggunakan Matkul*/
  	  	if (search == 3){
  	  	  	  	loop4 = 0;
  	  	  	  	for (int j = 0; j < strlen(searchData); j++){
  	  	  	  	  	if (tolower(dataDosen[j+index2[2]+1]) == tolower(searchData[j])){
  	  	  	  	  	  	loop4++;
  	  	  	  	  	}
  	  	  	  	  	if (loop4 == index2[3] - index2[2] - 1){
  	  	  	  	  	  	loop3 = index2[0];
  	  	  	  	  	}
  	  	  	  	}
  	  	}
  	  	/*End Seleksi Search Menggunakan Matkul*/

  	  	if (loop3 == index2[0]){/*Jika Data Sesuai Dengan Yang Dicari User*/

  	  	  	/*Memasukkan Data Yang Telah Di Seleksi Ke cariData*/
  	  	  	for (int j = 0; j < index2[0]; j++){
  	  	  	  	cariData[loop].nip[j] = dataDosen[j];
  	  	  	}
  	  	  	for (int j = 0; j < index2[1]-index2[0]-1; j++){
  	  	  	  	cariData[loop].nama[j] = dataDosen[j+index2[0]+1];
  	  	  	}
  	  	  	for (int j = 0; j < index2[2]-index2[1]-1; j++){
  	  	  	  	cariData[loop].jenis_kelamin[j] = dataDosen[j+index2[1]+1];
  	  	  	}
  	  	  	for (int j = 0; j < index2[3]-index2[2]-1; j++){
  	  	  	  	cariData[loop].matkul[j] = dataDosen[j+index2[2]+1];
  	  	  	}
  	  	  	for (int j = 0; j < index2[4]-index2[3]-1; j++){
  	  	  	  	cariData[loop].alamat[j] = dataDosen[j+index2[3]+1];
  	  	  	}
  	  	  	for (int j = 0; j < strlen(dataDosen)-index2[4]-1; j++){
  	  	  	  	cariData[loop].kontak[j] = dataDosen[j+index2[4]+1];
  	  	  	}
  	  	  	/*End Memasukkan Data Yang Telah Di Seleksi Ke cariData*/

  	  	  	/*Tampilkan Data Yang Lolos Seleksi*/
  	  	  	printf("\n");  
  	  	  	printf("NIP\t\t\t: %s\n", cariData[loop].nip);
  	  	  	printf("Nama\t\t\t: %s\n", cariData[loop].nama);
  	  	  	printf("Jenis Kelamin\t\t: %s\n", cariData[loop].jenis_kelamin);
  	  	  	printf("Matkul\t\t\t: %s\n", cariData[loop].matkul);
  	  	  	printf("Alamat\t\t\t: %s\n", cariData[loop].alamat);
  	  	  	printf("Kontak\t\t\t: %s", cariData[loop].kontak);
  	  	  	/*End Tampilkan Data Yang Lolos Seleksi*/

  	  	  	loop++;
  	  }
  	}

  	if (loop == 0){ /*Jika Data Tidak Ditemukan*/
  	  	printf("Hasil Tidak Ditemukan...");
  	}
	
  	fclose(fptr);
  	printf("\nTekan enter untuk keluar...\n");
  	getchar();
  	getchar();
}
