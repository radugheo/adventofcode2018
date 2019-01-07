
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin  ("date.in");
ofstream fout ("date.out");

int n, i, j, l, nr, t;

char mat[250][250];

int main(){
    while (fin >> mat[n]){
        l = strlen(mat[n]);
        n++;
    }
    for (i=1; i<n; i++){
        for (j=i+1; j<=n; j++){
            nr = 0;
            for (t=0; t<l; t++){
                if (mat[i][t] == mat[j][t]){
                    nr++;
                }
                else{
                    continue;
                }
            }
            if (nr == l - 1){
                for (t=0; t<=nr; t++){
                    if (mat[i][t] == mat[j][t]){
                        fout << mat[i][t];
                    }
                    else{
                        continue;
                    }
                }
                fout << "\n";
            }
        }
    }
    return 0;
}
