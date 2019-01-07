#include <fstream>
#include <queue>
#include <algorithm>

using namespace std;

ifstream fin  ("date.in");
ofstream fout ("date.out");

int n, m, i, x, y, k, nod, f1[10000], f2[10000], vecin, sum;

char A, B;
char s1[20], s2[20], s3[20], s4[20], s5[20], s6[20], s7[20], s8[20];

priority_queue <int, vector<int>, greater<int> > q;

vector <int> L[50005];

int main(){
    fin >> n;
    for (i=1; i<=n; i++){
        fin >> s1 >> A >> s2 >> s3 >> s4 >> s5 >> s6 >> B >> s7 >> s8;
        x = A + 1 - 'A';
        y = B + 1 - 'A';
        L[x].push_back(y);
        f1[x]++, f1[y]++;
        f2[y]++;
    }
    for (i=1; i<=26; i++){
        if (f1[i] && !f2[i]){
            q.push(i);
        }
    }
    while (!q.empty()){
        nod = q.top();
        q.pop();
        for (i=0; i<L[nod].size(); i++){
            vecin = L[nod][i];
            f2[vecin]--;
            if (!f2[vecin]){
                q.push(vecin);
            }
        }
        fout << (char)(nod - 1 + 'A');
    }
    return 0;
}
