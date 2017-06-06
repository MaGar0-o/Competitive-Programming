//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

int main(){
	LL x, k, id;
	cin >> x >> k >> id;
	while(id > x)
		id = (id - (x + 1 - k)) / k;
	cout << id << '\n';
	return 0;
}
