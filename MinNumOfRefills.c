#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int MinNumOfRefils(int, int, int, int*);

int main(){
    int d, m, n, i, refills;
    scanf("%d", &d);
    scanf("%d", &m);
    scanf("%d", &n);
    int s[n];
    for(i=0; i<n; i++){
        scanf("%d", &s[i]);
    }
    refills = MinNumOfRefils(d, m, n, s);
    printf("%d", refills);
    return 0;
}

int MinNumOfRefils(int d, int m, int n, int* s){
    int i = 0, start = 0, end = m, refills = 0;
    while((d-start)>m){
        if(s[i] > end || i == n){
            return -1;
        }
        for(; i<n; i++){
            if(s[i]>end){
                break;
            }
        }
        start = s[i-1];
        end = s[i-1] + m;
        refills++;
    }
    return refills;
}
