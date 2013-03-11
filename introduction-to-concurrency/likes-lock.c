#include <stdio.h>
#include <pthread.h>

int likes = 0;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void like_post()
{
    pthread_mutex_lock(&lock);
    likes += 1;
    pthread_mutex_unlock(&lock);
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
