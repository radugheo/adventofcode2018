#include <bits/stdc++.h>
#define MOD 20183

using namespace std;

FILE *fin  = fopen ("date.in" , "r");
FILE *fout = fopen ("date.out", "w");

long long depth, n, m, i, j, sum;
long long a[1000][1000];

char b[1000][1000];

int main(){
    fscanf (fin, "depth: %d\ntarget: %d,%d", &depth, &m, &n);
    a[0][0] = depth%MOD;
    b[0][0] = 'M', b[n][m] = 'T';
    for (j=1; j<=m; j++){
        a[0][j] = (j*16807+depth)%MOD;
        if (a[0][j]%3 == 0){
            b[0][j] = '.';
        }
        if (a[0][j]%3 == 1){
            b[0][j] = '=';
        }
        if (a[0][j]%3 == 2){
            b[0][j] = '|';
        }
    }
    for (i=1; i<=n; i++){
        a[i][0] = (i*48271+depth)%MOD;
        if (a[i][0]%3 == 0){
            b[i][0] = '.';
        }
        if (a[i][0]%3 == 1){
            b[i][0] = '=';
        }
        if (a[i][0]%3 == 2){
            b[i][0] = '|';
        }
    }
    for (i=1; i<=n; i++){
        for (j=1; j<=m; j++){
            a[i][j] = (a[i-1][j]*a[i][j-1] + depth)%MOD;
            if (a[i][j]%3 == 0){
                b[i][j] = '.';
            }
            if (a[i][j]%3 == 1){
                b[i][j] = '=';
            }
            if (a[i][j]%3 == 2){
                b[i][j] = '|';
            }
        }
    }
    a[n][m] = depth%MOD;
    for (i=0; i<=n; i++){
        for (j=0; j<=m; j++){
            //fprintf (fout, "%d ", a[i][j]);
            sum += a[i][j]%3;
        }
        //fprintf (fout, "\n");
    }
    fprintf (fout, "%d", sum);
    return 0;
}
