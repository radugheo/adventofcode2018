#include <fstream>
#include <cstring>

using namespace std;

ifstream cin ("date.in");
ofstream cout ("date.out");

char x;
long long i, j, a, nr, sum, n, m, f[10000005], g[10000005], v[90005];

int main(){
    while (cin >> x){
        if (x != ' '){
            cin >> a;
            if (x == '-'){
                v[++n] = -a;
                sum -= a;
            }
            else{
                v[++n] = a;
                sum += a;
            }
        }
    }
    cout << sum;
    return 0;
}
