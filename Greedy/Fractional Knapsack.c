#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float Max_Loot(int, int, int*, int*);
int BestItem(int, int*, int*);

int main(){
    int n, W, i;
    float max;
    scanf("%d %d",&n, &W);

    int c[n], w[n];
    for(i=0; i<n; i++){
        scanf("%d %d",&c[i], &w[i]);
    }

    max = Max_Loot(n, W, c, w);
    printf("%.4f", max);
    return 0;
}

int BestItem(int n, int* c, int* w){
    float max = 0;
    int index = 0, i;
    for(i=0; i<n; i++){
        float value_per_weight = (float)c[i] / w[i];
        if(value_per_weight > max){
            max = value_per_weight;
            index = i;
        }
    }
    return index;
}

float Max_Loot(int n, int W, int* c, int* w){
    float total = 0;
    int i, index, weight;
    for(i=0; i<n; i++){
        if(W == 0){
            return total;
        }
        index = BestItem(n, c, w);

        if(w[index]<=W){
            weight = w[index];
        }else{weight = W;}

        total += ((float)c[index]/w[index]) * weight;
        w[index] -= weight;
        W -= weight;

    }
    return total;
}
