#include <stdio.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    pid_t   pid;
    sem_t   *semaforo;
    int     wstatus;
    int        ret;
    
    sem_unlink("Prueba");
 //   semaforo = sem_open("Prueba",O_CREAT | O_EXCL, 0644, 0);
    semaforo = sem_open("Prueba",O_CREAT, 0644, 0);
    if (semaforo  == SEM_FAILED)
    {
        perror("ERROR");
        exit(EXIT_FAILURE);
    }
    pid = fork();
    if (pid != 0)
    {
        if (pid < 0)
        {
            exit(EXIT_FAILURE);
        }
        printf("Inicio padre pid hijo: %d\n", pid);
        ret = sem_wait(semaforo);
        printf("post -sem_wait %d\n", ret); 
    }
    else
    {
        printf("\tInicio hijo\n");
        sleep(2);
        printf("\tPOST-Sleep 1\n");
        sem_post(semaforo);
        printf("\tPRE-Sleep 2\n");
        sleep(2);
        printf("\tPOST-Sleep 2\n");
        exit(EXIT_SUCCESS);
    }
    wait(&wstatus);
    printf("FIN DE TODO\n");
}