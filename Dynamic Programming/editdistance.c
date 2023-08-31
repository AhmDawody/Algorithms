#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int min3(int, int, int);
int EditDistance(char*, char*);

int main(){
    char str1[100], str2[100];
    int editdistance;
    scanf("%s", str1);
    scanf("%s", str2);
    editdistance = EditDistance(str1, str2);
    printf("%d", editdistance);
    return 0;
}

int EditDistance(char* str1, char* str2){
    int len1, len2, i, j;
    int insert, delete, match, mismatch;
    len1 = strlen(str1);
    len2 = strlen(str2);
    int D[len1+1][len2+1];          //rows,,columns
    for(i=0; i<=len2; i++){
        D[0][i] = i;
    }
    for(i=0; i<=len1; i++){
        D[i][0] = i;
    }
    for(j=1; j<=len2; j++){
        for(i=1; i<=len1; i++){
            insert = D[i][j-1]+1;
            delete = D[i-1][j]+1;
            match = D[i-1][j-1];
            mismatch = D[i-1][j-1]+1;
            if(str1[i-1] == str2[j-1]){
                D[i][j] = min3(insert, delete, match);
            }
            else{
                D[i][j] = min3(insert, delete, mismatch);
            }
        }
    }
    return D[len1][len2];
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
