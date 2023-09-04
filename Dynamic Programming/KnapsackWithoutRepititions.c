#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int max2(int, int);
int Knapsack(int, int*, int);

int main(){
    int W, n, i;
    scanf("%d", &W);
    scanf("%d", &n);
    int weights[n];
    for(i=0; i<n; i++){
        scanf("%d", &weights[i]);
    }
    int max = Knapsack(W, weights, n);
    printf("%d", max);
    return 0;
}

int Knapsack(int W, int* weights, int n){
    int b, w, i;
    int** arr = (int**)malloc((n+1) * sizeof(int*));
    for (i = 0; i < (n+1); i++)
        arr[i] = (int*)malloc((W+1) * sizeof(int));

    for(i=0; i<W+1; i++){
        arr[0][i] = 0;
    }
    for(i=0; i<n+1; i++){
        arr[i][0] = 0;
    }

    for(b=1; b<=n; b++){
        for(w=1; w<=W; w++){
            if(weights[b-1]<=w){
                arr[b][w] = max2(arr[b-1][w], arr[b-1][w-weights[b-1]]+weights[b-1]);
            }
            else{
                arr[b][w] = arr[b-1][w];
            }
        }
    }
    return arr[n][W];
}

int max2(int a, int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

