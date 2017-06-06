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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s,
		   ans[2];
	ans[0].resize(13);
	ans[1].resize(13);
	cin >> s;
	for(int i = 0; i < 27; i++)
		if(s[i] == s[(i + 1) % 27]){
			cout << "Impossible\n";
			return 0;
		}
	char ch;
	for(int i = 0; i < 26; i++)
		if(count(all(s), 'A' + i) == 2)
			ch = 'A' + i;
	int p1 = -1, p2 = -1;
	for(int i = 0; i < 27; i++)
		if(s[i] == ch)
			(p1 == -1) ? p1 = i : p2 = i;
	int cnt = p2 - p1 - 1;
	int cnt2 = cnt / 2;
	for(int i = 0; i < cnt2; i++)
		ans[0][cnt2 - i - 1] = s[p1 + i + 1];
	for(int i = 0; i < cnt - cnt2; i++)
		ans[1][i] = s[p1 + cnt2 + i + 1];
	ans[0][cnt2] = ch;
	int ptr = cnt2 + 1;
	int n = 13;
	for(int i = p2 + 1; i < sz(s); i++){
		ans[ptr/n][ptr%n] = s[i];
		if(ptr == n - 1) ptr += n;
		else if(ptr < n) ptr++;
		else
			ptr--;
	}
	ptr = n + cnt - cnt2;
	for(int i = p1 - 1; i >= 0; i--){
		ans[ptr/n][ptr%n] = s[i];
		if(ptr == 2*n - 1) ptr -= n;
		else if(ptr < n) ptr--;
		else ptr++;
	}
	cout << ans[0] << '\n' << ans[1] << endl;
	return 0;
}
