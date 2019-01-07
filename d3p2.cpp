#include <fstream>

using namespace std;

ifstream fin  ("date.in");
ofstream fout ("date.out");

int n, a, b, c, d, i, j, sol, nr, k, ok;
int mat[10005][10005];

char c1, c2, c3, c4, c5;

struct data {
    int id, x1, y1, x2, y2;
}v[10005];

int main(){
    while (fin >> c1){
        fin >> n >> c2 >> a >> c3 >> b >> c4 >> c >> c5 >> d;
        v[++nr] = {n, b+1, a+1, b+d, a+c};
        for (i=b+1; i<=b+d; i++){
            for (j=a+1; j<=a+c; j++){
                if (mat[i][j] == 0){
                    mat[i][j] = n;
                }
                else{
                    mat[i][j] = -1;
                }
            }
        }
    }
    for (k=1; k<=nr; k++){
        ok = 1;
        for (i=v[k].x1; i<=v[k].x2; i++){
            for (j=v[k].y1; j<=v[k].y2; j++){
                if (mat[i][j] != v[k].id){
                    ok = 0;
                    break;
                }
            }
            if (ok == 0)
                break;
        }
        if (ok == 1)
            sol = v[k].id;
    }
    fout << sol;
    return 0;
}

