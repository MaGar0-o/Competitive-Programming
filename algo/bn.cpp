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

struct Bignum{
	vector<int> d;
	Bignum(int len = 1){
		d.resize(len);
	}
	int &operator[](int i){return d[i];}
	void nlize(void){
		for(int i = 0; i < sz(d); i++){
			if(d[i] / maxdig){
				if(i + 1 == sz(d))
					d.PB(0);
				d[i + 1] += d[i] / maxdig;
				d[i] %= maxdig;
			}
		}
		return;
	}
};

Bingum operator+(Bignum A, Bignum B){
	Bignum ret(sz(A) + 1);
	for(int i = 0; i < sz(A); i++)
		ret[i] += A[i] + B[i];
	ret.nlize();
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}
