#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

FILE *finput;
pthread_a tid[1234];

int banyak_huruf; //banyaknya huruf dalam file Novel.txt
char kata_huruf[123]; //untuk mengecek kata-kata tertentu yang dicek dalam Novel.txt

void *bacahitungkata (void *arg)
{
	int jumlah_kata;
	finput = fopen("/home/mmbw/modul3/Novel.txt", "r");
	char simpan_kata;
	if (finput==NULL){
		printf ("Tidak ada file.");
	}
	while (fgets(simpan_kata,banyak_huruf+1, finput )){
		if (strcmp(kata_huruf)==0)
			jumlah_kata++;
	}
	printf("%s: \n", kata_huruf,jumlah_kata);
	fclose (finput);
}

//ram, coba cek fungsinya. masih belum bisa pass arg ke function

int main(int argc, char const **argv)
{
	int boom;
	int i=0;
	for (i;i < argc-1;i++)
	{
		printf("%s\n", argv[i+1] );
		banyak_huruf = strlen(argv[i+1]);
		printf("%s\n", banyak_huruf);
		//bentar aku ngurus ukm dulu
	}
	return 0;
}