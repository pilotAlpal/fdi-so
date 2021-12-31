#include <stdio.h> 
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define NO_OF_PHILOSOPHERS 5

pthread_t philosophers[NO_OF_PHILOSOPHERS];
pthread_mutex_t tenedores[NO_OF_PHILOSOPHERS];


void init()
{
    int i;
    for(i=0; i<NO_OF_PHILOSOPHERS; i++)
        pthread_mutex_init(&tenedores[i],NULL);

    
}

void think(int i) {
    printf("philosopher %d thinking... \n" , i);
    sleep(random() % 10);
    printf("philosopher %d stops thinking!!! \n" , i);

}

void eat(int i) {
    printf("philosopher %d eating... \n" , i);
    sleep(random() % 5);
    printf("philosopher %d stops eating!!! \n" , i);

}

void toSleep(int i) {
    printf("philosopher %d sleeping... \n" , i);
    sleep(random() % 10);
    printf("philosopher %d stops sleeping!!! \n" , i);
    
}

void* philosopher(void* i)
{
    int nPhilosopher = (int)i;
    int right = nPhilosopher;
    int left = (nPhilosopher - 1 == -1) ? NO_OF_PHILOSOPHERS - 1 : (nPhilosopher - 1);
    while(1)
    {
        
        think(nPhilosopher);
        
        /// TRY TO TAKE BOTH FORKS (left and right)
        
        eat(nPhilosopher);
        
        // LEAVE BOTH FORKS
        
        toSleep(nPhilosopher);
   }

}

int main()
{
    init();
    unsigned long i;
    for(i=0; i<NO_OF_PHILOSOPHERS; i++)
        pthread_create( &philosophers[i], NULL, philosopher, (void*)i);
    
    for(i=0; i<NO_OF_PHILOSOPHERS; i++)
        pthread_join(philosophers[i],NULL);
    return 0;
} 
