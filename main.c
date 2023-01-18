#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
void menu();
void tambah_mhs();
void tampil_mhs();
void edit_mhs();
void hapus_mhs();
void cari_mhs();
void close();
// void tampil_sort();
struct DATA {
	char nama[30], alamat[50], email[50], kontak[15], matkul[30];
	int id, tanggal_lahir, bulan_lahir, tahun_lahir;
	
}tambah,cek,hapus,sort[100],temp;

// char index[2];
// struct date{
// 	int tgl;
// 	int bln;
// 	int thn;
// };
int main()
{
	system("cls");
		printf("Now Loading");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
	menu();
	return 0;
}
void menu(){
	int pilih;
	menu:
		system("cls");
		printf("MAIN MENU ::");
		printf("\n[1]. Tambah Mahasiswa Dan Nilai Mahasiswa");
		printf("\n[2]. Tampil Data Mahasiswa");
		printf("\n[3]. Cari Data Lengkap Mahasiswa");
		printf("\n[4]. Hapus Data Mahasiswa");
		printf("\n[5]. Edit Data Mahasiswa");
		printf("\n[6]. Menampilkan Total Nilai ASCENDING Dan DESCENDING");	
		printf("\n[7]. Keluar");
		printf("\n\nInput Pilihan Nomor Menu : ");
		scanf("%d", &pilih);
		switch(pilih){
			case 1:tambah_mhs();
				break;
			case 2:tampil_mhs();
				break;
			case 3: 
			cari_mhs();
				break;	
			case 4:
			hapus_mhs();
				break;
			case 5:
			edit_mhs();
				break;
				break;
			case 6:
			// tampil_sort();
				break;
			case 7:close();
				break;
			default:printf("\nMohon Maaf Pilihan Anda Salah !");
				getche();
				goto menu;
		}
}
void tambah_mhs(){
	FILE *ptr,*ptr1;
	int count=0;
	
	ptr =fopen("DATA_DOSEN.txt","a");
		system("cls");
		ptr1 =fopen("DATA_DOSEN.txt","r");
		while (fscanf (ptr1,"%d;%[^;];%[^;];%d;%d;%d;%s;%s;%s\n",&tambah.id,tambah.nama,tambah.email,&tambah.tanggal_lahir,&tambah.bulan_lahir,&tambah.tahun_lahir,tambah.alamat,tambah.kontak,tambah.matkul)!=EOF)
		{
			tambah.id++;	
		}
		cek.id = tambah.id;
		fclose(ptr1);
		printf ("masukan nama dosen\t\t\t : ");fflush(stdin);
		scanf ("%[^\n]",tambah.nama);
		printf ("masukan email dosen\t\t\t : ");fflush(stdin);
		scanf ("%[^\n]",tambah.email);
		printf ("masukan tanggal lahir dosen\t : ");fflush(stdin);
		scanf ("%d",&tambah.tanggal_lahir); 
		printf("Masukkan bulan lahir dosen\t\t : ");
		scanf("%d",&tambah.bulan_lahir);
		printf("Masukkan tahun lahir dosen\t\t : ");
		scanf("%d",&tambah.tahun_lahir);
		printf("Masukkan alamat dosen\t\t\t : ");
		scanf("%[^\n]",tambah.alamat);
		printf("Masukkan kontak dosen\t\t\t : ");
		scanf("%[^\n]",tambah.kontak);
		printf("Masukkan matkul dosen\t\t\t : ");
		scanf("%[^\n]",tambah.matkul);


		fprintf(ptr,"%d;%s;%s;%d;%d;%d;%s;%s;%s\n",tambah.id,tambah.nama,tambah.email,tambah.tanggal_lahir,tambah.bulan_lahir,tambah.tahun_lahir,tambah.alamat,tambah.kontak,tambah.matkul);
		fclose(ptr);
	
		printf("\n\nData Mahasiswa Sudah Disimpan !");
		add_invalid:
		printf("\n\n\tEnter 1 untuk menu utama dan 0 untuk keluar : ");
		switch(getch()){
    		case '1': menu();
        		break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto add_invalid;
 		}
}

void close(){
}

void tampil_mhs()
{
	FILE *view;
	view = fopen("DATA_DOSEN.txt","r");
	int test=0;
	system ("cls");
	printf ("ID\t\tNAMA\t\tJK\t\tUMUR\t\tUTS\t\tTUGAS\t\tKUIS\t\tUAS\t\tRata-Rata\n");
	while (fscanf (view,"%d;%[^;];%[^;];%d;%d;%d;%s;%s;%s\n",&tambah.id,tambah.nama,tambah.email,&tambah.tanggal_lahir,&tambah.bulan_lahir,&tambah.tahun_lahir,tambah.alamat,tambah.kontak,tambah.matkul)!=EOF)
	{
		printf("%d\t\t%s\t%s\t\t%d\t\t%d\t\t%d\t\t%s\t\t%s\t\t%s\n",tambah.id,tambah.nama,tambah.email,tambah.tanggal_lahir,tambah.bulan_lahir,tambah.tahun_lahir,tambah.alamat,tambah.kontak,tambah.matkul);
		test++;
	}
	printf ("\nJumlah Data Mahasiswa : %d",test);
	fclose(view);
	
	if(test==0)
	{
		system("cls");
		printf ("\nData Kosong ! \n");
	}
	list_invalid:
    printf("\n\nEnter 1 untuk menu utama dan 0 untuk keluar : ");
    switch(getch()){
    	case '1': menu();
        	break;
        case '0': close();
        	break;
        default:printf("\nMaaf Kesalahan Input !");
        	getche();
        	goto list_invalid;
 	}
}
void cari_mhs()
{
	FILE *ptr;
	int test=0;
	system("cls");
	ptr=fopen("DATA_DOSEN.txt","r");
	system("cls");
	printf("Input ID Mahasiswa : ");
	scanf("%d", &cek.id);
	while(fscanf (ptr,"%d;%[^;];%[^;];%d;%d;%d;%s;%s;%s\n",&tambah.id,tambah.nama,tambah.email,&tambah.tanggal_lahir,&tambah.bulan_lahir,&tambah.tahun_lahir,tambah.alamat,tambah.kontak,tambah.matkul)!=EOF){
		if(tambah.id==cek.id){
			test=1;
			printf ("\nID [%d]",tambah.id);
			printf("\nNama Mahasiswa\t: %s",tambah.nama);
			printf("\nEmail Dosen\t: %s",tambah.email);
			printf("\nTanggal Lahir\t\t: %d",tambah.tanggal_lahir);
			printf("\nBulan Lahir\t: %d",tambah.bulan_lahir);
			printf("\nTahun Lahir\t: %d",tambah.tahun_lahir);
			printf("\nAlamat Dosen\t: %s",tambah.alamat);
			printf("\nKontak Dosen\t: %s",tambah.kontak);
			printf("\nMatkul Pengampuh\t: %s",tambah.matkul);
		}
	}
	fclose(ptr);
	if(test!=1){
		system("cls");
		detail_print:
		printf("\nData tidak ditemukan !\a\a\a");
		detail_invalid:
		printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama dan 2 untuk keluar :");
        switch(getch()){
            case '0': cari_mhs();
            	break;
            case '1': menu();
            	break;
            case '2': close();
            	break;
            default:printf("\nMaff Kesalahan Input !");
            	getche();
            	goto detail_invalid;
        }
	}else{
		detail_valid:
		printf("\n\n\nInput 1 untuk ke menu utama dan 0 untuk keluar :");
        switch(getch()){
        	case '1': menu();
       			break;
       		case '0': close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto detail_valid;
       	}	
    }	
	
}




void hapus_mhs()
{
	FILE *lama, *baru;
	int test=0;
	lama = fopen("DATA_DOSEN.txt","r");
	baru = fopen("baru.txt","w");
	system("cls");
	printf("Input No. ID Mahasiswa yang akan di hapus : ");
	scanf("%d", &hapus.id);
	while(fscanf (lama,"%d;%[^;];%[^;];%d;%d;%d;%s;%s;%s\n",&tambah.id,tambah.nama,tambah.email,&tambah.tanggal_lahir,&tambah.bulan_lahir,&tambah.tahun_lahir,tambah.alamat,tambah.kontak,tambah.matkul)!=EOF)
	{
		if(tambah.id != hapus.id)
		{
			fprintf(baru,"%d;%s;%s;%d;%d;%d;%s;%s;%s\n",tambah.id,tambah.nama,tambah.email,tambah.tanggal_lahir,tambah.bulan_lahir,tambah.tahun_lahir,tambah.alamat,tambah.kontak,tambah.matkul);	
		}
		else{
			test++;
			printf("\nData Mahasiswa No ID : %d dengan Nama : %s\n",tambah.id,tambah.nama);
			printf("\nBerhasil dihapus dari Daftar !");
		}
	}
	fclose(lama);
	fclose(baru);
	remove("DATA_DOSEN.txt");
	rename("baru.txt","DATA_DOSEN.txt");
		if(test==0){
            printf("\nData tidak ditemukan !\a\a\a");
            erase_invalid:
            printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :");
			switch(getch()){
            	case '0': hapus_mhs();
            		break;
            	case '1': menu();
            		break;
            	case '2': close();
            		break;
            	default:printf("\nMaaf Kesalahan Input !");
            		getche();
            		goto erase_invalid;
			}
    }
    else{
    	erase_valid:
		printf("\nInput 1 untuk ke menu utama and 0 untuk keluar :");
        switch(getch()){
       		case '1': menu();
       			break;
       		case '0': close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto erase_valid;
        }
    }
	
}
void edit_mhs()
{
	int pilih,test=0;
	FILE *lama,*baru;
	lama = fopen("DATA_DOSEN.txt","r");
	baru = fopen ("baru.txt","w");
	system("cls");
	
	printf ("Masukan ID Mahasiswa : ");
	scanf ("%d",&cek.id);
	while(fscanf (lama,"%d;%[^;];%[^;];%d;%d;%d;%s;%s;%s\n",&tambah.id,tambah.nama,tambah.email,&tambah.tanggal_lahir,&tambah.bulan_lahir,&tambah.tahun_lahir,tambah.alamat,tambah.kontak,tambah.matkul)!=EOF)
	{
		if(tambah.id == cek.id)
		{
			test=1;
			ganti:
				printf("\nNo. ID : %d dimiliki Mahasiswa dengan Nama : %s",tambah.id,tambah.nama);
				printf("\n\nData yang akan diganti : ");
				printf("\n[1]. Nama");
				printf("\n[2]. Email");
				printf("\n[3]. Matkul");
				printf("\nInput Pilihan : ");
				scanf("%d",&pilih);
				
				if(pilih == 1)
				{
					printf ("\nMasukan Data Nama Baru : ");fflush(stdin);
					scanf ("%[^\n]",cek.nama);
					strcpy(tambah.nama,cek.nama);
						fprintf(baru,"%d;%s;%s;%d;%d;%d;%s;%s;%s\n",tambah.id,tambah.nama,tambah.email,tambah.tanggal_lahir,tambah.bulan_lahir,tambah.tahun_lahir,tambah.alamat,tambah.kontak,tambah.matkul);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 2)
				{
					printf("\nMasukan Data Email : ");fflush(stdin);
					scanf ("%[^\n]",cek.email);
					strcpy(tambah.email,cek.email);
						fprintf(baru,"%d;%s;%s;%d;%d;%d;%s;%s;%s\n",tambah.id,tambah.nama,tambah.email,tambah.tanggal_lahir,tambah.bulan_lahir,tambah.tahun_lahir,tambah.alamat,tambah.kontak,tambah.matkul);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 3)
				{
					printf ("\nMasukan Data Matkul Baru : ");
					scanf ("%[^\n]",cek.matkul);
					strcpy(tambah.matkul, cek.matkul);
					fprintf(baru,"%d;%s;%s;%d;%d;%d;%s;%s;%s\n",tambah.id,tambah.nama,tambah.email,tambah.tanggal_lahir,tambah.bulan_lahir,tambah.tahun_lahir,tambah.alamat,tambah.kontak,tambah.matkul);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else{
					printf("\n\nInput Anda Salah !");
					getche();
					goto ganti;
				}
		}
		else
		{
			fprintf(baru,"%d;%s;%s;%d;%d;%d;%s;%s;%s\n",tambah.id,tambah.nama,tambah.email,tambah.tanggal_lahir,tambah.bulan_lahir,tambah.tahun_lahir,tambah.alamat,tambah.kontak,tambah.matkul);
		}
	}

	fclose(lama);
	fclose(baru);
	remove("DATA_DOSEN.txt");
	rename("baru.txt","DATA_DOSEN.txt");
	if(test!=1){   
		system("cls");
        printf("\nData tidak ditemukan !\a\a\a");
        edit_invalid:
        printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama dan 2 untuk keluar :");
        switch(getch()){
            case '0': edit_mhs();
            	break;
            case '1': menu();
            	break;
            case '2': close();
            	break;
            default:printf("\nMaaf Kesalahan Input !");
            	getche();
            	goto edit_invalid;
        }
    }
    else{
    	edit_valid:
		printf("\n\n\nInput 1 untuk ke menu utama dan 0 untuk keluar :");
        switch(getch()){
        	case '1': menu();
        		break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto edit_valid;
        }
    }
}



// FUNCTION TAMPIL SORT
void tampil_sot() {}


	
