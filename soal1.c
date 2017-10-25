#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void tambah_senjata();
int main()
{
	key_t key = 1234;
	int shmid = shmget ( key, 6*sizeof (int), IPC_CREATE | 6666 );
	int *jumlah_senjata = (int*) shmat(shmid, NULL, 0);

	int pilih_senjata=0;
	printf("PILIH MENU SENJATA:\n 1. Lihat Senjata \n 2. Tambah Senjata \n 3. EXIT \n");

	char nama_senjata[5][10]={"PM2-V1","MP4A1","SPR-3","SS2-V5","SPG1-V3","MINE"};

	while (pilih_senjata!=3){
		scanf("%d", &pilih_senjata);
		if (pilih_senjata){
			if(jumlah_senjata[0]>0)
				printf("PM2-V1 %d\n", jumlah_senjata[0] );
			if(jumlah_senjata[1]>0)
				printf("MP4A1 %d\n", jumlah_senjata[1] );
			if(jumlah_senjata[2]>0)
				printf("SPR-3 %d\n", jumlah_senjata[2] );
			if(jumlah_senjata[3]>0)
				printf("SS2-V5 %d\n", jumlah_senjata[3] );
			if(jumlah_senjata[4]>0)
				printf("SPG1-V3 %d\n", jumlah_senjata[4] );
			if(jumlah_senjata[5]>0)
				printf("MINE %d\n", jumlah_senjata[5] );
		}
		else if (pilih_senjata==2)
		{
			int x; int tambahan_senjata;
			char senjata_fix[10];
			scanf("%s", &senjata_fix[10]);
			scanf("%s", &tambahan_senjata);
			if (strcmp(senjata_fix, "PM2-V1"))
				jumlah_senjata[0]+= tambahan_senjata;
			else if (strcmp(senjata_fix, "MP4A1"))
				jumlah_senjata[0]+= tambahan_senjata;
			else if (strcmp(senjata_fix, "SPR-3"))
				jumlah_senjata[0]+= tambahan_senjata;
			else if (strcmp(senjata_fix, "SS2-V5"))
				jumlah_senjata[0]+= tambahan_senjata;
			else if (strcmp(senjata_fix, "SPG1-V3"))
				jumlah_senjata[0]+= tambahan_senjata;
			else if (strcmp(senjata_fix, "MINE"))
				jumlah_senjata[0]+= tambahan_senjata;
	}
	else printf("Error!!!\n");
}
	shmdt(jumlah_senjata);
	shmctl(shmid, IPC_CREATE, NULL);
}
