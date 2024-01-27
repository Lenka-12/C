#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
void DivByZeroHandler(int signum){
    if(signum==SIGFPE){
        printf("Recieved SIGFPE, Divide by Zero Exception\n");
        exit(0);
    }

    else{
        printf("Received %d signal\n",signum);
    }
}
int main(){
    int result = 0;

    int iNum1 = 123,iNum2 = 0;
    signal(SIGFPE,DivByZeroHandler);

    result = iNum1/iNum2;
    

    printf("Result of Divide by Zero is %d\n",result);

    return EXIT_SUCCESS;

}