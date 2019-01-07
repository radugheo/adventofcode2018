#include <fstream>

using namespace std;

ifstream fin  ("date.in");
ofstream fout ("date.out");

int solve (){
    int c, m, sum, i, k;
    fin >> c >> m;
    sum = 0;
    for (i=1; i<=c; i++){
        sum += solve();
    }
    for (i=1; i<=m; i++){
        fin >> k;
        sum += k;
    }
    return sum;
}

int main(){
    fout << solve ();
    return 0;
}
