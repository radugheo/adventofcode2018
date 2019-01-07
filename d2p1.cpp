#include <fstream>
#include <cstring>

using namespace std;

ifstream fin  ("date.in");
ofstream fout ("date.out");

int n, i, j, l, nr1, nr2, ok1, ok2, f[100];
char s[300][300];

int main(){
    while (fin >> s[n]){
        l = strlen(s[n]);
        n++;
    }
    for (i=0; i<n; i++){
        ok1 = 0;
        ok2 = 0;
        for (j=0; j<=30; j++)
            f[j] = 0;
        for (j=0; j<l; j++){
            f[s[i][j] - 'a']++;
        }
        for (j=0; j<=30; j++){
            if (f[j] == 2 && ok1 == 0){
                nr1++;
                ok1 = 1;
            }
            if (f[j] == 3 && ok2 == 0){
                nr2++;
                ok2 = 1;
            }
        }
    }
    fout << nr1*nr2;
    return 0;
}
