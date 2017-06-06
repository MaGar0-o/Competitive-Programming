// be name khoda

#include <iostream>

using namespace std;

int n, maxh;
int seed;

int main() {
	cin >> seed >> n >> maxh;
	srand(seed);
	cout << n << endl;
	for (int i= 0; i < n; i++)
		cout << (rand()%maxh) << " ";
	cout << endl;
	return 0;
}
