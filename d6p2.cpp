#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

ifstream fin  ("date.in");
ofstream fout ("date.out");

char c;

int y, k, i, j, t, s, x, imin, imax, jmin, jmax, cnt;

pair <int, int> v[250000];

int distMNH (int x1, int y1, int x2, int y2){

    return abs(x1 - x2) + abs(y1 - y2);

}

int main(){

    imin = jmin = 1000000;
    while (fin >> x){
        fin >> c >> y;
        v[++k] = {y, x};
        if (y < imin){ imin = y; } if (x < jmin){ jmin = x; }
        if (y > imax){ imax = y; } if (x > jmax){ jmax = x; }
    }
    for (i=0; i<=imax; i++){
        for (j=0; j<=jmax; j++){
            s = 0;
            for (t=1; t<=k; t++){
                x = v[t].first, y = v[t].second;
                s += distMNH(i, j, x, y);
            }
            if (s < 10000){
                cnt++;
            }
        }
    }
    fout << cnt;
    return 0;
}




