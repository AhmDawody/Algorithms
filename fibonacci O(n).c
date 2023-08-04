#include <stdio.h>
#include <stdlib.h>


long long fib(long long n);

int main(){
    long long y, n;
    scanf("%lld",&n);
    y = fib(n);
    printf("%lld", y);
    return 0;
}
long long fib(long long n){
    long long i;
    if (n <= 1) {
        return n;
    }

    long long prev = 0;
    long long curr = 1;
    long long next;

    for (i = 2; i <= n; i++) {
        next = (prev + curr);
        prev = curr;
        curr = next;
    }

    return curr;
}