//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
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

const int maxn = 2e5;
int a[maxn];
int n;

int main(){
	while(scanf("%d", a+n) and a[n]){
		++n;
		if(n == 60) break;
	}
	sort(a, a + n);
	for(int i = n - 2; i--;)
		if(a[i] + a[i + 1] > a[i + 2]){
			printf("%d %d %d\n", a[i], a[i + 1], a[i + 2]);
			return 0;
		}
	printf("NIE\n");
	return 0;
}
