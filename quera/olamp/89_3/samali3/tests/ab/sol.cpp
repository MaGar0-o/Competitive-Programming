// be name khoda

#include <iostream>

using namespace std;

const int MAXN = 1000000 + 100;
int n;
int h[MAXN];
long long int sum;

void input() {
	cin >> n;
	for (int i= 0; i < n; i++)
		cin >> h[i];
}

void solve() {
	int x = h[0] , ind = 0;
	sum = 0;
	long long temp = 0;
	for (int i= 1; i < n; i++)
		if (h[i] <= x)
			temp += (x- h[i]);
		else {
			x = h[i];
			ind = i;
			sum += temp;
			temp = 0;
		}
	x = h[n-1];
	temp = 0;
	for (int i = n-2; i >= ind; i--)
		if (h[i] <= x)
			temp += (x- h[i]);
		else {
			x = h[i];
			sum += temp;
			temp = 0;
		}
}

void output() {
	cout << sum << endl;
}

int main() {
	input();
	solve();
	output();
	return 0;
}
