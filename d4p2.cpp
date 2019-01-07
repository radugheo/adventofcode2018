#include <fstream>
#include <algorithm>
#define data first
#define stare second

using namespace std;

ifstream fin  ("date.in");
ofstream fout ("date.out");

int year, month, day, hour, minute, n, k, i, j, id, s, sol1, S, p, sol2, ok;
int f[70][10005], ids[10005], f1[10005];
pair <long long, long long> v[10005];

char c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c20, c21;

int main (){
	while (fin >> c0){
		fin >> year >> c1 >> month >> c2 >> day >> hour >> c3 >> minute >> c4;
		fin >> c5 >> c6 >> c7 >> c8 >> c9;
		v[++k].data = (((year*100 + month)*100 + day)*100 + hour)*1LL*100 + minute;
		if (c5 == 'G'){
			fin >> c10 >> n >> c11 >> c12 >> c13 >> c14 >> c15 >> c16;
			fin >> c17 >> c18 >> c19 >> c20 >> c21;
            v[k].stare = n;
		}
		if (c5 == 'f'){
			fin >> c10 >> c11 >> c12 >> c13 >> c14 >> c15; ///falls asleep
			v[k].stare = -1;
		}
		if (c5 == 'w'){
			fin >> c10 >> c11; ///wakes up
			v[k].stare = -2;
		}
	}
	sort (v, v + k + 1);
	for (i=1; i<=k; i++){
        if (v[i].stare > 0 && f1[v[i].stare] == 0){
            f1[v[i].stare] = 1;
            ids[++p] = v[i].stare;
        }
	}
	for (i=1; i<=k; i++){
        if (v[i].stare > 0){
            id = v[i].stare;
        }
        if (v[i].stare == -2){
            for (j=v[i-1].data%100; j<=v[i].data%100-1; j++){
                f[j][id]++;
            }
        }
	}
	S = -1;
	for (i=1; i<=60; i++){
        for (j=1; j<=p; j++){
            if (f[i][ids[j]] > S){
                S = f[i][ids[j]];
                sol1 = i;
                sol2 = ids[j];
            }
        }
	}
	fout << sol1*sol2;
	return 0;
}

