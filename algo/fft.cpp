//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double LD;
typedef complex<LD> base;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()
#define PI 3.1415926

void fft(vector<base> &a, bool invert){
	int n = sz(a);
	if(n == 1){ cout << a[0] << ' ';return;}
	vector<base> a0(n/2), a1(n/2);
	for(int i = 0, j = 0; i < n; i+=2, j++)
		a0[j] = a[i], a1[j] = a[i + 1];
	fft(a0, invert);
	fft(a1, invert);
	LD ang = 2 * PI / n * (invert ? -1 : 1);
	base w(1), wn(cos(ang), sin(ang));
	for(int i = 0; i < n / 2; i++){
		a[i] = a0[i] + w * a1[i];
		a[i + n / 2] = a0[i] - w * a1[i];
		if(invert) a[i] /= 2, a[i + n / 2] /= 2;
		w *= wn;
	}
	return;
}
void multiply (const vector<LL> & a, const vector<LL> & b, vector<LL> & res) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);

	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft (fa, true);

	res.resize (n);
	for (size_t i=0; i<n; ++i)
		res[i] = int (fa[i].real() + 0.5);
}

void solve(){
	int n;
	cin >> n;
	int sz = 1;
	while(sz < n) sz <<= 1;
	vector<base> vec(sz);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		vec[i] = x;
	}
	fft(vec, false);
	cout << endl;
	/*
	n++;
	vector<LL> a(n), b(n), mul;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	multiply(a, b, mul);
	for(int i = 0; i < 2 * n - 1; i++)
		cout << mul[i] << ' ';
	cout << endl;*/
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
