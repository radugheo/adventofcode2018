#include <fstream>

using namespace std;

ifstream fin  ("date.in");
ofstream fout ("date.out");

int n, a, b, c, d, i, j, sol;
int mat[10005][10005];

char c1, c2, c3, c4, c5;

int main(){
    while (fin >> c1){
        fin >> n >> c2 >> a >> c3 >> b >> c4 >> c >> c5 >> d;
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
    for (i=1; i<=10000; i++){
        for (j=1; j<=10000; j++){
            if (mat[i][j] == -1)
                sol++;
        }
    }
    fout << sol;
    return 0;
}
