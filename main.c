// Include file header
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define pjg 100
#define pjg2 50
#define pjg3 500

struct dosen{
	char  nip[pjg2];
  	char  nama[pjg2];
  	char  matkul[pjg2];
  	char  alamat[pjg2];
  	char  kontak[pjg2];
};


/*Function Lihat Data Dosen------------------------------------------------------*/
void lihatDataDosen(){
  	int loop = 0;
  	char dataDosen[pjg3];
  	struct dosen lihatDosen[pjg];
  	char *hasil;
  	FILE *fptr;
  	fptr = fopen("dataDosen.txt", "r");/*Buka File DataDosen.txt*/

  	memset(lihatDosen, 0, sizeof(lihatDosen)); /*Hapus Data Pada lihatDosen*/

  	while (fgets(dataDosen, sizeof(dataDosen), fptr)){/*Untuk Setiap Baris Data Pada dataDosen.txt*/
    	int loop2 = 0;
    	int index[4];

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
  	fclose(fptr);/*Tutup File datadosen.txt*/
	while (1)
	{
		int loop7 = 0;
		int sort = 0;
		while (strlen(lihatDosen[loop7].nip) != 0){
			loop7++;
		}
		/*Menu Sort*/
		printf("1. Urutkan Ascending Berdasarkan Nama\n");
		printf("2. Urutkan Descending Berdasarkan Nama\n");
		printf("3. Urutkan Ascending Berdasarkan NIP\n");
		printf("4. Urutkan Descending Berdasarkan NIP\n");
		printf("9. Kembali\n");
		printf("Pilih : ");
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

			if (sort == 1)/*Jika User Memilih Ascending*/
			{
				/*Print lihatDosen Berdasarkan Urutan ind dari Depan Kebelakang*/
				for (int i = 0; i < loop7; i++)
				{
					printf("\n");  
					printf("NIP = %s", lihatDosen[ind[i]].nip);
					printf("\n");
					printf("Nama = %s", lihatDosen[ind[i]].nama);
					printf("\n");
					printf("Matkul = %s", lihatDosen[ind[i]].matkul);
					printf("\n");
					printf("Alamat = %s", lihatDosen[ind[i]].alamat);
					printf("\n");
					printf("Kontak = %s", lihatDosen[ind[i]].kontak);
					printf("\n");
				}
				/*End Print lihatDosen Berdasarkan Urutan ind dari Depan Kebelakang*/
			}

			if (sort == 2)/*Jika User Memilih Descending*/
			{
				/*Print lihatDosen Berdasarkan Urutan ind dari Belakang Kedepan*/
				for (int i = loop7-1; i >= 0; i--)
				{
					printf("\n");  
					printf("NIP = %s", lihatDosen[ind[i]].nip);
					printf("\n");
					printf("Nama = %s", lihatDosen[ind[i]].nama);
					printf("\n");
					printf("Matkul = %s", lihatDosen[ind[i]].matkul);
					printf("\n");
					printf("Alamat = %s", lihatDosen[ind[i]].alamat);
					printf("\n");
					printf("Kontak = %s", lihatDosen[ind[i]].kontak);
					printf("\n");
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

			if (sort == 3)/*Jika User Memilih Ascending*/
			{
				/*Print lihatDosen Berdasarkan Urutan ind dari Depan Kebelakang*/
				for (int i = 0; i < loop7; i++)
				{
					printf("\n");  
					printf("NIP = %s", lihatDosen[ind[i]].nip);
					printf("\n");
					printf("Nama = %s", lihatDosen[ind[i]].nama);
					printf("\n");
					printf("Matkul = %s", lihatDosen[ind[i]].matkul);
					printf("\n");
					printf("Alamat = %s", lihatDosen[ind[i]].alamat);
					printf("\n");
					printf("Kontak = %s", lihatDosen[ind[i]].kontak);
					printf("\n");
				}
				/*End Print lihatDosen Berdasarkan Urutan ind dari Depan Kebelakang*/
			}

			if (sort == 4)/*Jika User Memilih Descending*/
			{
				/*Print lihatDosen Berdasarkan Urutan ind dari Belakang Kedepan*/
				for (int i = loop7-1; i >= 0; i--)
				{
					printf("\n");  
					printf("NIP = %s", lihatDosen[ind[i]].nip);
					printf("\n");
					printf("Nama = %s", lihatDosen[ind[i]].nama);
					printf("\n");
					printf("Matkul = %s", lihatDosen[ind[i]].matkul);
					printf("\n");
					printf("Alamat = %s", lihatDosen[ind[i]].alamat);
					printf("\n");
					printf("Kontak = %s", lihatDosen[ind[i]].kontak);
					printf("\n");
				}
				/*End Print lihatDosen Berdasarkan Urutan ind dari Belakang Kedepan*/
			}
		}
		/*End Jika User Memilih Sorting Berdasarkan NIP*/

		/*Jikas User Memilih Untuk Kembali*/
		else if(sort == 9){
			break;
		}
		/*End Jikas User Memilih Untuk Kembali*/
	}
	
	
  	// printf("\nTekan enter untuk keluar..\n");
  	// getchar();
  	// getchar();

}



/*Function Input Data Dosen------------------------------------------------------*/
void inputDataDosen(){
	struct dosen inputDosen[pjg];
	int jmlInput;

	memset(inputDosen, 0, sizeof(inputDosen));/*Hapus Data Pada inputDosen*/

	printf("Masukkan Jumlah Input :  ");
	scanf("%d", &jmlInput);/*Masukkan Jumlah Input Data Yang Diinginkan*/

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
		char str[pjg3] = {""};
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
	int loop = 0;
  	int loop6 = 0;
  	char dataDosen[pjg3];
  	char editData[pjg2];
  	char *hasil;
	char tmpNama[pjg2], tmpMatkul[pjg2], tmpAlamat[pjg2], tmpKontak[50];
  	struct dosen editDosen[pjg];
  	FILE *fptr;
  	fptr = fopen("dataDosen.txt", "r"); /*Buka File DataDosen.txt*/
  	printf("Masukkan NIP Yang Ingin Diedit : ");
  	scanf("%s", editData);
	printf("\nNama : ");
	scanf(" %[^\n]s", tmpNama);
	printf("Matkul : ");
	scanf(" %[^\n]s", tmpMatkul);
	printf("Alamat : ");
	scanf(" %[^\n]s", tmpAlamat);
	printf("Kontak : ");
	scanf(" %[^\n]s", tmpKontak);

  	memset(editDosen, 0, sizeof(editDosen));  /*Hapus Data Pada editDosen*/

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
  	  	  	if (dataDosen[j] == editData[j]){
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
  	  	}else{  /*Jika NIP Sama Dengan Input User Simpan Edit User*/
			char str[pjg3] = {""};
  	  	  	strcat(str, editData);
  	  	  	strcat(str, "|");
  	  	  	strcat(str, tmpNama);
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



/*Function Hapus Data Dosen------------------------------------------------------*/
void hapusDataDosen(){
  	int loop = 0;
  	int loop6 = 0;
  	char dataDosen[pjg3];
  	char hapusData[pjg2];
  	char *hasil;
  	struct dosen hapusDosen[pjg];
  	FILE *fptr;
  	fptr = fopen("dataDosen.txt", "r"); /*Buka File DataDosen.txt*/
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
  	  	  	if (dataDosen[j] == hapusData[j]){
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
}



/*Function Cari Data Dosen------------------------------------------------------*/
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

  	  	if (loop3 == index2[0]){/*Jika Data Sesuai Dengan Yang Dicari User*/

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
    	printf("9. Keluar\n");
    	printf("Pilih Menu :");
    	scanf("%d", &menu);
    	switch (menu){
    	case 1:
    	  	lihatDataDosen();
    	  	break;
    	case 2:
    	  	inputDataDosen();
    	  	break;
    	case 3:
    	  	editDataDosen();
    	  	break;
    	case 4:
    	  	hapusDataDosen();
    	  	break;
    	case 5:
    	  	cariDataDosen();
    	  	break;
    	case 9:
			return 0;
    	  	break;
    	default:
    	  	break;
    	}

	}
}