#include <stdio.h>
#include <stdlib.h>

int fib(int);

int main(){
    int x;
    x = fib(15);
    printf("%d", x);
    return 0;
}
int fib(int n){
    int arr[n+1], i;
    arr[0] =0;
    arr[1] =1;
    for(i=2; i<=n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}