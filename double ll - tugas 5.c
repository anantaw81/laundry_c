//Creted by Ananta.
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
static int hello= 1;

struct data_cucian{
	char pemilik[50+1];
	int berat;
	int jenis_member;
	};

struct node{
	//struct data_cucian data_cuci;
	struct data_cucian laundry;
	struct node *sebelum;
	struct node *selanjutnya;
	};

struct node *kepala;
struct node *ekor;
struct node *cari;

void init(){
	kepala = NULL;
	ekor = NULL;
	}
int data_kosong(){
	if(ekor == NULL) return 1;
	else return 0;
	}
int cek_no_ekor(int nomor){
	struct node *bantuan;
	int i = 1, no_ekor = 0;
	bantuan = kepala;
	if(data_kosong()==0){
		while(bantuan != ekor -> selanjutnya){
			bantuan = bantuan -> selanjutnya;
			i ++;
			}
			no_ekor = i-1;
		}
	if(no_ekor == nomor)return 1;
	else return 0;
	}
int cek_kepala_ekor(){
	if(kepala == ekor){
		return 1;
		}
	else return 0;
	}
void perulangan(int nomor){
	int i = 1;
	cari = kepala;
	while (i < nomor){
		cari = cari -> selanjutnya;
		i++;
		}
	}
void tambah_data(int nomor){ //1 kalo nambah di ekor, ~1 untuk kepala
	struct node *baru;
	baru = (struct node *) malloc(sizeof(struct node));
	if(baru == NULL){
		printf("Error : Memori penuh, tidak bisa menambah data");
		}
	baru->selanjutnya=NULL;
	baru->sebelum=NULL;
	fflush(stdin);
	printf("Masukkan nama pelanggan : ");
	gets(baru->laundry.pemilik);
	fflush(stdin);
	printf("Masukkan berat cucian (kg) : ");
	scanf("%d", &baru->laundry.berat);
	printf("Masukkan level cucian (1 = Cepat, 2 = Sedang , 3= Lama) : ");
	scanf("%d", &baru->laundry.jenis_member);
	hello ++;
	//tambah datanya disini ya minta data.
	if(data_kosong()==1){
		kepala = baru;
		ekor = baru;
		kepala->sebelum=NULL;
		kepala->selanjutnya=NULL;
		printf("Karena Data Kosong, Tambah Data Awal Berhasil");
		}
	else{
		if(nomor == 1){//ekor ya
			baru->sebelum=ekor;
			ekor->selanjutnya=baru;
			ekor=baru;
			printf("Tambah Data Paling Belakang Berhasil");			
			}
		else if (nomor == 2){ //kepala
			baru->selanjutnya = kepala;
			kepala -> sebelum=baru;
			kepala=baru;
			printf("Tambah Data Paling Depan Berhasil");
			}
		else if (nomor == 3){
			struct node *bantu;
			bantu = cari->selanjutnya;
			cari->selanjutnya = baru;
			bantu -> sebelum = baru;
			baru -> sebelum = cari;
			baru -> selanjutnya = bantu;
			printf("Tambah Data Sesuai Nomor Berhasil");
			} //untuk data yang di tengah.
		}	
	 
	}

void tampil_data(){  //balik juga bisa si ini 
	int i =1;
	struct node *bantu;
	bantu = kepala;
	if(data_kosong()==0){
		printf("No Nama  \t Berat(kg)\t Level\n");
		while(bantu != ekor->selanjutnya){
			printf("%d. ", i);
			printf("%s \t %d \t\t %d", bantu->laundry.pemilik , bantu->laundry.berat, bantu->laundry.jenis_member );
			printf("\n");
			bantu = bantu->selanjutnya;
			i++;
			}
		}
	else {
		printf("Data Masih Kosong !");
		}
	}
void tampil_data_kepala(){
	printf("%s \t %d \t %d", kepala->laundry.pemilik , kepala->laundry.berat, kepala->laundry.jenis_member );
	}
void tampil_data_ekor(){
	printf("%s \t %d \t %d", ekor->laundry.pemilik , ekor->laundry.berat, ekor->laundry.jenis_member );
	}
void hapus_data_kepala(int nomor){
	if(data_kosong()==1){
		printf("Memang tidak ada data !");
		}
	else{
		struct node *hapus;
		if(nomor == 1){ //hapus data kepala
			hapus = kepala;
			kepala = kepala->selanjutnya;
			kepala-> sebelum = NULL;
			free(hapus);
			printf("Hapus data paling depan berhasil !");
			}
		else if(nomor == 2){ //hapus data ekor
			hapus = ekor;
			ekor = ekor->sebelum;
			ekor->selanjutnya=NULL;
			free(hapus);
			printf("Hapus data paling belakang berhasil !");
			}
		else if(nomor == 3){ //hapus data tertentu
			struct node *seb_cari, *ses_cari ;
			hapus = cari;
			ses_cari = cari->selanjutnya;
			seb_cari = cari -> sebelum; 
			seb_cari->selanjutnya = ses_cari;
			ses_cari->sebelum = seb_cari; 
			free (hapus);
			printf("Hapus data sesuai nomor berhasil !");
			}
		else if(nomor == 4){ //hapus semua data
			struct node *bantu;
			bantu = kepala;
			while(bantu != NULL){
				hapus = bantu;
				bantu = bantu->selanjutnya;
				free(hapus);
				}
			kepala = NULL;
			ekor = NULL;
			hello = 1;
			printf("Hapus semua data berhasil !");
			}
		}
	}
void masukkan_string(char *keterangan, char *masukan, int panjang_maks){
	char st[256];
	do{
		printf(keterangan);
		fflush(stdin);
		gets(st);
		if(strlen(st)>panjang_maks){
			printf("Terlalu panjang. Maksimum %d karakter \n", panjang_maks);
			}
		}
	while(strlen(st) > panjang_maks);
	strcpy(masukan, st);
	}
	
void cari_data(int nomor_data){
	struct node *data; 
	//pendahulu = NULL;
	data = kepala;
	char pilihan1;
	char nama[51];
	masukkan_string("Masukkan nama yang akan dicari : ", nama, 50);
	while (data){
		if(strcmp(nama, data->laundry.pemilik) != 0){ //ganti jangan pake nomor
			//pendahulu = data;
			data = data->selanjutnya; 
			}
		else{
			cari = data;
			puts("Data ketemu !");
			printf("%s \t %d \t %d\n", data->laundry.pemilik , data->laundry.berat, data->laundry.jenis_member );
			printf("Ingin mengahapusnya ? (Y/N) ");
			scanf("%c", &pilihan1);
			if(pilihan1 == 'y' || pilihan1 == 'Y'){
				if(cek_kepala_ekor()==1){
					hapus_data_kepala(4);
					}
				else{
					hapus_data_kepala(3);
				}
				}
			break; //data ketemu.
			}
		}
	if(data == NULL){
		printf("Data tidak ditemukan !\n");
		}
	}

void tentang_program(){
	puts("");
	puts("Program ini bertujuan untuk membantu pegawai laundry.");
	puts("-Menyusun list cucian yang harus dicuci sesuai urutan.");
	puts("-Karena pelanggan mempunyai level pengerjaan."); 
	puts("-Misal harus selesai 2 jam (level premium), maka"); 
	puts("harus ditaruh di urutan paling depan.");
	puts("");
	}


void menu_utama(){
	int pil, pil_tiga, pil_enam;
	while (1){
	puts("");
	puts("__________________________________________");
	puts("| Selamat Datang Karyawan Pusaka Laundry |");
	puts("| Menu :                                 |");
	puts("| 1. Tambah Data Cucian Paling Depan     |");
	puts("| 2. Tambah Data Cucian Paling Belakang  |");
	puts("| 3. Tambah Data Cucian Pada Nomor       |");
	puts("| 4. Hapus Data Cucian Paling Depan      |");
	puts("| 5. Hapus Data Cucian Paling Belakang   |");
	puts("| 6. Hapus Data Cucian Pada Nomor        |");
	puts("| 7. Hapus Semua Data Cucian             |");
	puts("| 8. Lihat Data Semua Cucian             |");
	puts("| 9. Lihat Data Cucian Paling Depan      |");
	puts("| 10. Lihat Data Cucian Paling Belakang  |");
	puts("| 11. Cari Data Cucian                   |");
	puts("| 12. Tetang Program                     |");
	puts("| 13. Keluar                             |");
	puts("|________________________________________|");
	printf("Pilihan yang ingin Anda masukkan ? ");
	scanf("%d", &pil);
	if(pil == 1){
			tambah_data(2);
		}
		else if (pil == 2){
			tambah_data(1);
			}
			else if(pil == 3){
				tampil_data();
				printf("Tambah data setelah nomor : ");
				scanf("%d", &pil_tiga);
				if(cek_no_ekor(pil_tiga)==1){
					tambah_data(1);
					}
				else{
				perulangan(pil_tiga);
				tambah_data(3);}
				}
				else if(pil == 4){
					if(cek_kepala_ekor() == 1){
						hapus_data_kepala(4);
						}
					else{
					hapus_data_kepala(1); }
					}
					else if(pil == 5){
						if(cek_kepala_ekor()==1){
							hapus_data_kepala(4);
							}
						else{
						hapus_data_kepala(2);}
						}
						else if(pil == 6){
							tampil_data();
							printf("Hapus data nomor : ");
							scanf("%d", &pil_enam);
							if(cek_no_ekor(pil_enam)==1 || pil_enam==1){
								hapus_data_kepala(2);
								}
							else{
							perulangan(pil_enam);
							hapus_data_kepala(3);
							}
							}
							else if(pil == 7){
								hapus_data_kepala(4);
								}
								else if(pil == 8){
									tampil_data();
									}
									else if(pil == 9){
										tampil_data_kepala();
										}
										else if(pil == 10){
											tampil_data_ekor();
											}
											else if(pil == 11){
												cari_data(1);
												}
												else if(pil == 12){
													tentang_program();
													}
													else if(pil == 13){
														break;
														}
													else{
														puts("Pilihan Salah !");
													}
											}
	}
int main(int argc, char **argv)
{	
	init(); //inisialisasi kepala dan ekor dari link list
	menu_utama();
	return 0;
}

