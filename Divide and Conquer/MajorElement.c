#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int majorityelement(int, int,  int*);
int elementcount(int, int, int*, int);

int main(){
    int n,i, result;

    scanf("%d", &n);
    int a[n];

    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    result = majorityelement(0, n-1, a);
    if(result == -1)   result =0;
    else   result = 1;
    printf("%d", result);

    return 0;
}

int majorityelement(int l, int r, int* a){
    int xcount =0, ycount =0;
    int x, y;
    int mid;
    if(l<r){
        mid = (l + r)/2;
        x = majorityelement(l, mid, a);
        y = majorityelement(mid+1, r, a);

        if(x==y)    return x;

        xcount = elementcount(l, r, a, x);
        ycount = elementcount(l, r, a, y);

        if((xcount > ycount) && xcount > (r-l+1)/2)     return x;
        if((xcount < ycount) && ycount > (r-l+1)/2)     return y;
        else return -1;
    }
    return a[l];
}

int elementcount(int l, int r, int* a, int e){
    int count =0, i;
    for(i=l; i<=r; i++){
        if(e == a[i]){
            count ++;
        }
    }
    return count;
}