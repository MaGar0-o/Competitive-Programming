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

LL coont(int len, char st, char en, int cnt){

}

LL count(int pos){
	LL ret = 0;
	int cnt = 0;
	for(int i = 0; i < pos; i++)
		cnt += str[i] != str[i + 1];
	for(int i = N - 1; i >= N - 1 - pos and i >= (N+1) / 2; i--){
		if(i > pos and i + 1 < N) cnt += str[N - 1 - i] != str[N - i - 2];
		if((i > pos and str[N - 1 - i] == 'I') or (str[i] == 'X' and str[N - 1 - i] == 'I'))
			ret += coont(i - pos - 1, str[pos], 'I', K - cnt);
		smin(ret, Inf);
		if(i <= pos and (str[i] != str[N - 1 - i]))
			return ret;
	}
	return min(Inf, ret + strcnt(N - 2 * (pos + 1)));
}

void build(int pos = 0){
	if(pos == N){
		cout << str << '\n';
		return;
	}
	str[pos] = 'I';
	if(count(pos) < I)
		str[pos] = 'X';
	return build(pos + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K >> I;
	build();
	return 0;
}
