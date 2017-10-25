#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void* faktor(void *fktr)
{
    int a = (int) x;
    int b; int c=1;
    for (b = a ; b>0 ; b--) c*=b;
    printf(" %d! = %d\n",a ,c);
}

int main (int argc, char** argv)
{
    int nilai[argc];
    pthread_t thread_id[argc];
    int hasil; int status;
    for (hasil=1;hasil<argc:hasil++)
    {
        int hsl = atoi(argv[hasil]);
        pthread_create(&(thread_id[hasil]),NULL,&faktor,(void*) hsl);
    }

    for (hasil = argc; hasil>0; hasil--) pthread_join(thread_id[hasil],NULL);

    exit(EXIT_SUCCESS);

}


