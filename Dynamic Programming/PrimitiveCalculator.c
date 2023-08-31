#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int PrimitiveCalculator(int*, int);
int min2(int, int);
int min3(int, int, int);
int* backtrack(int*, int);

int main(){
    int i, num, operations;
    int* seq;
    scanf("%d", &num);
    int* arr = malloc((num+1) * sizeof(int));

    operations = PrimitiveCalculator(arr, num);
    seq = backtrack(arr, num);
    
    printf("%d\n", operations);
    for(i=0; i<operations+1; i++){
        printf("%d ",seq[i]);
    }
    return 0;
}

int PrimitiveCalculator(int* arr, int num){   
    int i;
    arr[1] = 0;

    if(num == 1){
        return 0;
    }
    else{
        for(i=2; i<num+1; i++){
            if(i%2 ==0 && i%3 ==0){
                arr[i] = min3(arr[i-1]+1, arr[i/2]+1, arr[i/3]+1);
            }
            else if(i%3 ==0){
                arr[i] = min2(arr[i-1]+1, arr[i/3]+1);
            }
            else if(i%2 ==0){
                arr[i] = min2(arr[i-1]+1, arr[i/2]+1);
            }else{
                arr[i] = arr[i-1] + 1;
            }
        }
    }
    return arr[num];
}

int* backtrack(int* arr, int num){
    int n = arr[num]+1, last;
    int* seq = malloc(n * sizeof(int));
    int i;
    
    for(i=num; i>=0; i--){
        if(i==num){
            seq[arr[i]] = i;
            last = arr[i];
        }
        else{
            if(arr[i] == last-1){
                seq[arr[i]] = i;
                last--;
            }
        }
    }
    return seq;
}

int min2(int a, int b){
    return a<b ? a : b;
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
