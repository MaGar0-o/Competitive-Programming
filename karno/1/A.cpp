//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, p;
	cin >> n >> p;
	for(int i = 1; i <= n; i++)
		if(i % p == 0)
			cout << "Pesh ";
		else
			cout << i << ' ';
	cout << '\n';
	return 0;
}
