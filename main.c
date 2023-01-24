#include "function.c" // calling file function

int main() {
	int menu;

	// clear
	system("cls");
	// Loading effect
	printf("Please Wait ");
	sleep(1);
	printf(". ");
	sleep(1);
	printf(". ");
		sleep(1);
		printf(". ");
		sleep(1);
		printf(". ");
		system("cls");

    while (1){
			system("cls");
    	printf("==================================================================\n");
			printf("::\t\t\tSISTEM DATA DOSEN ITTS\t\t\t::\n");
    	printf("==================================================================\n");
    	printf("[1]. Lihat Data Dosen\n");
    	printf("[2]. Input Data Dosen\n");
    	printf("[3]. Edit Data Dosen\n");
    	printf("[4]. Hapus Data Dosen\n");
    	printf("[5]. Cari Data Dosen\n");
    	printf("[9]. Keluar\n");
    	printf("Pilih Menu : ");
    	scanf("%d", &menu);
    	switch (menu){
    	case 1:
					system("cls");
    	  	lihatDataDosen();
    	  	break;
    	case 2:
					system("cls");
    	  	inputDataDosen();
    	  	break;
    	case 3:
					system("cls");
    	  	editDataDosen();
    	  	break;
    	case 4:
					system("cls");
    	  	hapusDataDosen();
    	  	break;
    	case 5:
					system("cls");
    	  	cariDataDosen();
    	  	break;
    	case 9:
					system("cls");
					printf("TERIMAKASIH\n");
					sleep(2);
					system("cls");
					return 0;
    	  	break;
    	default:
					printf("\n=============== ERROR MESSAGE ===============\n");
					printf("Pilihan anda tidak tersedia!\n");
					sleep(2);
					system("cls");
    	  	break;
    	}
		}

	return 0;

}
