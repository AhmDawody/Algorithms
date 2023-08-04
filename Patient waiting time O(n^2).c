#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int MinTotalWaitingTime(int*, int);


int main(){
    int t[5] = {2, 1, 5, 4, 3};
    int n = 5, res;
    res = MinTotalWaitingTime(t, n);
    printf("%d", res);
    return 0;
}

int MinTotalWaitingTime(int* t, int n){
    int Waitingtime = 0, i, j;
    int count = n-1;
    int treated[n];

    for(i=0; i<n; i++){
        treated[i] = 0;
    }

    for(i=0; i<n; i++){
        int tmin = INFINITY;
        int minindex = 0;
        for(j=0; j<n; j++){
            if(treated[j]==0 && t[j]<tmin){
                tmin = t[j];
                minindex = j;
            }
        }
        Waitingtime += (count--)*tmin;
        treated[minindex] = 1;
    }
    return Waitingtime;
}