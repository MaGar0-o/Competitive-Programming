//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1e5 + 85 - 69;
LD a[maxn][3];
int n;

LD Abs(LD x){
	return x < 0 ? -x : x;
}

bool zero(LD x){
	return Abs(x) <= 1e-9;
}

int main(){
	srand(time(0));
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < 3; j++){
			int x;
			scanf("%d", &x);
			a[i][j] = x;
		}
	int id = rand() % n;
	for(int j = 0; j < 3; j++)
		swap(a[id][j], a[n - 1][j]);
	for(int i = 0; i + 1 < n; i++)
		for(int j = 0; j < 3; j++)
			a[i][j] -= a[n - 1][j];
	n--;
	int fnd = 0;
	for(int j = 0; j < 3 and fnd < n; j++){
		for(int i = fnd + 1; i < n; i++)
			if(!zero(a[i][j])){
				for(int k = 0; k < 3; k++)
					swap(a[fnd][k], a[i][k]);
				break;
			}
		if(zero(a[fnd][j]))
			continue;
		for(int i = 0; i < n; i++)
			if(i != fnd and !zero(a[i][j])){
				LD tmp = a[i][j] / a[fnd][j];
				for(int k = 0; k < 3; k++)
					a[i][k] -= tmp * a[fnd][k];
			}
		fnd++;
	}
	if(fnd == 3)
		printf("NIE");
	else
		printf("TAK");
	return 0;
}
