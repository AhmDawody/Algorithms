#include <stdio.h>
#include <stdlib.h>


int main()
{
    long long max1 =0, max2 =0;
    int n, i;
    scanf("%d", &n);
    long long arr[n];

    for(i=0; i<n; i++){
        scanf("%lld", &arr[i]);
        if(arr[i] > max1){
            max2 = max1;
            max1 = arr[i];
        }
        else if(arr[i] > max2){
            max2 = arr[i];
        }
    }
    printf("%lld", max1 * max2);
    return 0;
}