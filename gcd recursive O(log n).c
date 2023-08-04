#include <stdio.h>
#include <stdlib.h>

int gcd(int, int);

int main(){
    int x, y, z;
    scanf("%d", &x);
    scanf("%d", &y);
    z = gcd(x,y);
    printf("%d", z);
    return 0;
}
int gcd(int a, int b){
    if (b == 0){
        return a;
    }
    else{
        return gcd(b, (a % b));
    }
}