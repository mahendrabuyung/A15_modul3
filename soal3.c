#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

int threads[2];
void *kepiting () {
 while (1) {

  sleep(20);
  threads[0] -= 10;
  if (threads[0] <= 0 || threads [0] > 100) {
   exit(EXIT_FAILURE);
  }
 }
}
void *lohan () {
 while (1) {

   sleep(20);
   threads[1] -= 10;
   if (threads[1] <= 0 || threads [1] > 100) {
    exit(EXIT_FAILURE);
   }
  }
}
void makan () {
 printf("Hewan yang di berimakan\n1. Kepiting\n2. Lohan\n");
 int a;
 scanf ("%d", &a);
 if (a==1) {
  threads [0]+=10;
  printf("Status kepiting bertambah %d\n", threads[0]);
 }
 else if (a==2) {
  threads [1]+=10;
  printf("Status lohan bertambah %d\n", threads[1]);
 }
 
}
int main ()  {
 threads [0]=100;
 threads [1]=100;
 pthread_t kepiting_t, lohan_t;
 pthread_create (&kepiting_t,NULL,&kepiting,NULL); 
 pthread_create (&lohan_t,NULL,&lohan,NULL);

 while (1) {
  int pilihan;
  if(threads[1] <= 0 || threads[1] > 100 || threads[0] <= 0 || threads[0] > 100) {
   printf("Status Lohan = %d\n", threads[1]);
   printf("Status Kepiting = %d\n", threads[0]);
   printf("GAME OVER\n");
   exit(EXIT_FAILURE);
  }
  else {
   printf("1. Lihat status\n2. Berimakan\n");
   scanf ("%d",&pilihan);

   if (pilihan==1) {
    printf("Status Kepiting: %d\n", threads[0]);
    printf("Status Lohan: %d\n", threads[1]);
   }
   else if (pilihan==2) {
    makan();
   }
  }
 }
}
