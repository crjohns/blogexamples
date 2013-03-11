#include <stdio.h>
#include <pthread.h>

int likes = 0;

void like_post()
{
    __sync_fetch_and_add(&likes, 1);
}


void *like_test(void *arg)
{
    for(int i=0; i<10000; i++)
        like_post();

    return NULL;
}

int main(int argc, char **argv)
{
    /* Create two threads that each run the function "like_test", and
     * then wait for both of them to finish running before exiting */
    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1, NULL, like_test, NULL);
    pthread_create(&t2, NULL, like_test, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Post was liked %d times\n", likes);

    return 0;
}
