#include <stdio.h>
int fib(int n1){
    if(n1==0){
        return 0;
    }
    else if(n1==1){
        return 1;
    } else{
        return fib(n1-2)+fib(n1-1);
    }
}
int main(void) {
    int a = fib(4);
    printf("%d",a);
    return 0;
}
