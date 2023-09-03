#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int min3(int, int, int);
int min2(int, int);
int Knapsack(int, int*, int*, int);

int main(){
    int vals[4] = {9, 14, 16, 30};
    int weights[4] = {2, 3, 4, 6};
    int max = Knapsack(10, weights, vals, 4);
    printf("%d", max);
    return 0;
}

int Knapsack(int W, int* weights, int* vals, int n){
    int i, j, maxval;
    int arr[W+1];
    arr[0] = 0;
    for(i=1; i<=W; i++){
        maxval = 0;
        for(j=0; j<n; j++){
            if(weights[j] <= i){
                arr[i] = arr[i-weights[j]] + vals[j];
                if(arr[i] > maxval){
                    maxval = arr[i];
                }
            }
        }
        arr[i] = maxval;
    }
    return arr[W];
}

int min2(int a, int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

int min3(int a, int b, int c){
    if (a<=b && a<=c){
        return a;
    }else if(b<=c && b<=a){
        return b;
    }else{
        return c;
    }
}
