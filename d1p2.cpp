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
            }
            else{
                v[++n] = a;
            }
        }
    }
    f[0] = 1;
    sum = 0;
    while (1){
        for (j=1; j<=n; j++){
            sum += v[j];
            if (sum >= 0){
                f[sum]++;
                if (f[sum] == 2){
                    cout << sum << "\n";
                    return 0;
                }
            }
            else{
                g[-sum]++;
                if (g[-sum] == 2){
                    cout << sum << "\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}
