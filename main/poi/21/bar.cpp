//sobskdrbhvk
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

const int maxn = 1e6 + 85 - 69,
	  maxl = 21;
int sum[maxn],
	lst[maxn],
	nxt[maxn],
	pps[maxn],
	spt[maxn][maxl],
	n, ans;
string s;
int stc[maxn], sz;
char str[maxn];

int get_min(int st, int en){
	int f = pps[en - st + 1];
	return min(spt[st][f], spt[en - (1 << f) + 1][f]);
}

int main(){
	scanf("%d%s", &n, str);
	for(int i = 0; i < n; i++)
		s += str[i];
	for(int i = 0; i < n; i++)
		sum[i + 1] = sum[i] + (s[i] == 'p' ? +1 : -1);
	for(int i = n; i >= 0; i--){
		while(sz and sum[stc[sz - 1]] >= sum[i])
			sz--;
		if(sz) nxt[i] = stc[sz - 1] - 1;
		else nxt[i] = n;
		stc[sz++] = i;
	}
	sum[n] = 0;
	for(int i = n - 1; i >= 0; i--)
		sum[i] = sum[i + 1] + (s[i] == 'p' ? +1 : -1);
	for(int i = 0; i <= n; i++){
		while(sz and sum[stc[sz - 1]] >= sum[i])
			sz--;
		if(i){
			if(sz) lst[i - 1] = stc[sz - 1];
			else lst[i - 1] = -1;
			vec[lst[i - 1]].PB(i - 1);
		}
		stc[sz++] = i;
	}/*
	pps[0] = -1;
	for(int i = 1; i < maxn; i++)
		pps[i] = pps[i>>1]+1;
	for(int i = 0; i < n; i++)
		spt[i][0] = lst[i];
	for(int j = 1; j < maxl; j++)
		for(int i = 0; i + (1 << j) <= n; i++)
			spt[i][j] = min(spt[i][j - 1], spt[i + (1 << (j - 1))][j - 1]);
	for(int i = 0; i < n; i++){
		if(s[i] == 'j') continue;
		int lo = i,
			hi = nxt[i];
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if(get_min(mid, nxt[i] - 1) < i)
				lo = mid;
			else
				hi = mid;
		}
		smax(ans, lo - i + 1);
	}*/
	for(int i = 0; i < n; i++){
		
	}
	printf("%d", ans);
	return 0;
}
