#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* hilo_funcion(void* arg) {
    int thread_id = *(int*)arg;
    printf("Hello from thread %d\n", thread_id);
    free(arg);
    return NULL;
}

int main() {
    int n_threads = 2;
    pthread_t threads[n_threads];
    
    for (int i = 0; i < n_threads; i++) {
        int* thread_id = (int*)malloc(sizeof(int));
        *thread_id = i + 1;
        pthread_create(&threads[i], NULL, hilo_funcion, (void*)thread_id);
    }

    for (int i = 0; i < n_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Hello from the main thread\n");

    return 0;
}

