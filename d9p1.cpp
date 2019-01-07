#include <bits/stdc++.h>

using namespace std;

FILE * fin  = freopen ("day9.in" , "r", stdin);
FILE * fout = freopen ("day9.out", "w", stdout);

long long n, m, i, sol, p, j, k, s[1040013];

deque <int> d;

int main() {
    fscanf(fin, "%d players; last marble is worth %d points", &n, &m);
    /// m = m * 100; - part 2
    d.push_back(0);
    for (i=1; i<=m; i++){
        if (!(i % 23)){
            s[i%n] += (long long)i;
            for (j=0; j<7; j++){
                k = d.back();
                d.pop_back();
                d.push_front (k);
            }
            s[i%n] += (long long)(d.front());
            d.pop_front();
        }
        else{
            for (j=0; j<2; j++){
                k = d.front();
                d.pop_front();
                d.push_back (k);
            }
            d.push_front (i);
        }
    }
    for (i=1; i<=n; i++){
        sol = (long long)max ((long long)sol, (long long)s[i]);
    }
    fprintf (fout, "%lld", sol);
}
