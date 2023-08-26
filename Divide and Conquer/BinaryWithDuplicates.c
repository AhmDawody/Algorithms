#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int BinarySearch(int, int, int, int*);

int main(){
    int n, m, i;

    scanf("%d", &n);
    int k[n];
    for(i=0; i<n; i++){
        scanf("%d",&k[i]);
    }

    scanf("%d", &m);
    int q[m];
    for(i=0; i<m; i++){
        scanf("%d",&q[i]);
    }
    int result[m];

    for(i=0; i<m; i++){
        result[i] = BinarySearch(q[i], 0, n, k);
    }

    for(i=0; i<m; i++){
        printf("%d ", result[i]);
    }
    return 0;
}

int BinarySearch(int q, int l, int r, int*k){
    int m;
    if(l<=r){
        m = (l+r)/2;
        if(q == k[m]){
            while(m>= 0 && q == k[m]){
                m--;
            }
            return m+1;
        }
        else if(q < k[m])   return BinarySearch(q, l, m-1, k);
        else return BinarySearch(q, m+1, r, k);
    }
    return -1;
}