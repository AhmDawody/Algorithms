#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int min3(int, int, int);
int moneychange(int);


int main(){
    int coins, money;
    scanf("%d", &money);
    coins = moneychange(money);
    printf("%d", coins);
    return 0;
}

int min3(int a, int b, int c){
    if((a<=b) && (a<=c)){
        return a;
    }else if((b<=a) && (b<=c)){
        return b;
    }else{
        return c;
    }
}

int moneychange(int money){
    int i, coins[money+1];

    coins[3] =1;
    coins[4] =1;
    for(i=0; i<=money; i++){
        if(i<3){
            coins[i] =i;
        }
        if(i>4){
            coins[i] = min3(coins[i-1]+1, coins[i-3]+1, coins[i-4]+1);
        }
    }
    return coins[money];
} 


