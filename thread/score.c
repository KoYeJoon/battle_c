#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>


short int score[30];

//average, sum print
void *s_thread1 (void*arg){
    int i=0;
    int sum = 0;
    double avg = 0;
    //printf("Hi, I'm calculating\n");
    for(i=0;i<(int)arg;i++){
        sum = sum+score[i];
        sleep(1);
    }

    avg = (double)sum / (int)arg ;

    printf("sum : %d, avg : %lf\n", sum, avg);

    //printf("calculating dead\n");
    pthread_exit(arg);
} 

//sorting
void *s_thread2 (void*arg){
    int i=0;
    int j=0;
    short int temp = 0;
    short int arr[30] = {0,};

    for(i=0;i<(int)arg;i++){
        arr[i] = score[i];
    }

    //printf("Hi I'm sorting \n");
    for(i=0;i<(int)arg;i++){
        for(j=0;j<(int)arg-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }

    }

    printf("sorting Score\n");
    for(i=0;i<(int)arg;i++) {
        printf("%hd  ",arr[i]);
        if(i%10 == 9){
            printf("\n");
        }
    }

    //printf("Sorting Dead\n");
    pthread_exit(arg);
}

int main()
{
    int count = 30;
    for(int i=0;i<count;i++){
        scanf("%hd",&score[i]);
    }


    pthread_t tid1, tid2;
    pthread_attr_t attr1, attr2;
    int status1, status2;

    pthread_attr_init(&attr1);
    pthread_attr_setdetachstate(&attr1,PTHREAD_CREATE_DETACHED);

    pthread_attr_init(&attr2);
    pthread_attr_setdetachstate(&attr2,PTHREAD_CREATE_DETACHED);
    

    status1 = pthread_create(&tid1, &attr1, s_thread1, (void *)count);
    status2 = pthread_create(&tid2, &attr2, s_thread2,(void *)count);
    
    if(status1 != 0){
        perror("thread create");
        exit(1);
    }
    if(status2 != 0){
        perror("thread create");
        exit(1);
    }

    pthread_attr_destroy(&attr1);
    pthread_attr_destroy(&attr2);
    pthread_exit(NULL);
    return 0;
}