#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

ifstream fin  ("date.in");
ofstream fout ("date.out");

char c;

int y, k, i, j, t, s, x, m, imin, imax, jmin, jmax, a[500][500], sol[70000], b[500][500];

pair <int, int> v[250000];

int distMNH (int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

bool verif (int x){
	int i, j;
	for (i=imin; i<=imax; i++){
		if (b[i][jmin] == x || x == b[i][jmax])
			return false;
	}
	for (j=jmin; j<=jmax; j++){
		if (b[imin][j] == x || x == b[imax][j])
			return false;
	}
	return true;
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
            a[i][j] = 10000000;
        }
    }
    for (t=1; t<=k; t++){
        x = v[t].first, y = v[t].second;
        for (i=0; i<=imax; i++){
            for (j=0; j<=jmax; j++){
                s = distMNH(x, y, i, j);
                if (s < a[i][j]){
                    a[i][j] = s;
                    b[i][j] = t;
                }
                else if (s == a[i][j]){
                    b[i][j] = -1;
                }
            }
        }
    }
    for (i=0; i<=imax; i++){
        for (j=0; j<=jmax; j++){
            if (b[i][j] > 0){
                sol[b[i][j]]++;
            }
        }
    }
    for (i=1; i<=k; i++){
        if (verif(i))
        	m = max (m, sol[i]);
    }
    fout << m;
    return 0;
}


