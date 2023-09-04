#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long long* MinMax(char*, long long i, long long j, long long**, long long**);
long long parentheses(long long*, long long n_d, char*);
long long calc(long long x, long long y, char);
long long maximum(long long a,long long b,long long c,long long d);
long long minimum(long long a,long long b,long long c,long long d);

int main(){
    long long i, n=0, j=0, k=0, max;
    char sub[29];
    scanf("%s", sub);
    for(i=0; sub[i]!= NULL; i++){
        n++;
    }
    long long n_d = (n+1)/2;
    long long n_op = (n-1)/2;
    char op[n_op];
    long long d[n_d];
    for(i=0; i<n; i++){
        if(i%2 == 0){
            d[j] = sub[i] - 0x30;
            j++;
        }else{
            op[k] = sub[i];
            k++;
        }
    }
    max = parentheses(d, n_d, op);
    printf("%lld", max);
    return 0;
}

long long parentheses(long long* d, long long n_d, char* op){
    long long i, j, s;
    long long** M = (long long**)malloc(n_d * sizeof(long long*));
    long long** m = (long long**)malloc(n_d * sizeof(long long*));
    for(i=0; i<n_d; i++){
        M[i] = (long long*)malloc(n_d * sizeof(long long));
        m[i] = (long long*)malloc(n_d * sizeof(long long));
    }
    long long* arr = malloc(2 * sizeof(long long));
    for(i=0; i<n_d; i++){
        M[i][i] = d[i];
        m[i][i] = d[i];
    }
    for(s=0; s<n_d-1; s++){
        for(i=0; i<(n_d-s)-1; i++){
            j = i+s+1;
            arr = MinMax(op, i, j, M, m);
            m[i][j] = arr[0];
            M[i][j] = arr[1];
        }
    }
    return M[0][n_d-1];
}

long long* MinMax(char* op, long long i, long long j, long long** M, long long** m){
    long long min = INFINITY, max = -INFINITY, k, a, b, c, d;
    long long x, y;
    long long* arr = malloc(2 * sizeof(long long));
    for(k=i; k<j; k++){
        a = calc(M[i][k], M[k+1][j], op[k]);
        b = calc(M[i][k], m[k+1][j], op[k]);
        c = calc(m[i][k], M[k+1][j], op[k]);
        d = calc(m[i][k], m[k+1][j], op[k]);
        x = minimum(a, b, c, d);
        y = maximum(a, b, c, d);
        if(x<min)   min = x;
        if(y>max)   max = y;
    }
    arr[0] = min;
    arr[1] = max;
    return arr;
}

long long calc(long long x, long long y, char c){
    if(c == '-'){
        return x-y;
    }else if(c == '+'){
        return x+y;
    }else{
        return x*y;
    }
}

long long maximum(long long a,long long b,long long c,long long d)
{
    long long a1 = a>b?a:b;
    long long a2 = c>d?c:d;
    return a1>a2?a1:a2;
}

long long minimum(long long a,long long b,long long c,long long d)
{
    long long a1 = a<b?a:b;
    long long a2 = c<d?c:d;
    return a1<a2?a1:a2;
}