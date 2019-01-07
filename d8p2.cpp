#include <fstream>

using namespace std;

ifstream fin  ("date.in");
ofstream fout ("date.out");

int solve (){
    int c, m, sum, i, k;
    fin >> c >> m;
    int v[10000];
    sum = 0;
    for (i=0; i<c; i++){
        v[i] = solve();
    }
    for (i=0; i<m; i++){
        fin >> k;
        if (c == 0){
            sum += k;
        }
        else if (k <= c && k > 0){
            sum += v[k-1];
        }
    }
    return sum;
}

int main(){
    fout << solve();
    return 0;
}
