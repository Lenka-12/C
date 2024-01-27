#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void TestPID(){
    int mypid, myppid;

    printf("Program to know PID and PPID's information\n");

    mypid = getpid();  // Current process ID
    myppid = getppid(); // Current process parent ID

    printf("Current Process ID: %d\n",mypid);
    printf("Current Process Parent ID: %d\n",myppid);

    printf("Cross verification of pid's by executing process commands on a shell\n");

    system("ps -ef");
}

void SIGSTOPTest(){
    printf("Testing SIGSTOP\n");
    raise(SIGSTOP);
}

void alarmTest(){
    alarm(5);

    for (int i=1; i<10; i++){
        printf("%d\n",i);
        sleep(1);
    }
}
int main(){
    // TestPID();
    //SIGSTOPTest();
    //alarmTest();

    int* pInt = (int*) malloc(sizeof(int));
    pInt = NULL;

    if (pInt==NULL){
        printf("Yes\n");
    }

    else{
        printf("No\n");
    }

    return EXIT_SUCCESS;
}