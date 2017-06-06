//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef complex<LD> point;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()
#define x real()
#define y imag()

const int maxn = 100;
const LD Eps = 1e-5;
bool mark[maxn][maxn];
point p[maxn];
int a[maxn],
	b[maxn];
int n;
vector<pii> ans,
	seg;

int sgn(LD v){
	return v < 0 ? -1 : v > 0 ? +1 : 0;
}

LD zcross(point A, point B){
	return A.x * B.y - A.y * B.x;
}

LD leng(point A){
	return sqrt(A.x * A.x + A.y * A.y);
}

point &mnof(point &A, point &B){
	return (A.x < B.x or (A.x == B.x and A.y < B.y)) ? A : B;
}

point &mxof(point &A, point &B){
	return (A.x > B.x or (A.x == B.x and A.y > B.y)) ? A : B;
}

bool onseg(point &A, point &B, point &C){
	return abs(zcross(B - A, C - A)) < Eps and min(A.x, B.x) <= C.x and C.x <= max(A.x, B.x)
		and min(A.y, B.y) <= C.y and C.y <= max(A.y, B.y);
}

bool tagh(point A, point B, point C, point D){
	if(onseg(A, B, C) or onseg(A, B, D) or onseg(C, D, A) or onseg(C, D, B)) return false;
	if(sgn(zcross(B - A, C - A)) == sgn(zcross(B - A, D - A))) return false;
	swap(A, C), swap(B, D);
	if(sgn(zcross(B - A, C - A)) == sgn(zcross(B - A, D - A))) return false;
	return true;
}

bool lexo(int i1, int i2, int j1, int j2){
	stringstream ss1, ss2;
	ss1 << i1 << ' ' << i2;
	ss2 << j1 << ' ' << j2;
	return ss1.str() < ss2.str();
}

bool can(int p1, int p2){
	for(auto sg : seg)
		if(tagh(p[p1], p[p2], p[sg.L], p[sg.R])) return false;
	for(int i = 0; i < n; i++)
		if(i != p1 and i != p2)
			if(onseg(p[p1], p[p2], p[i]))
				return false;
	point pp = (p[p1] + p[p2]) / (LD)2;
	LD sum = 0;
	for(int i = 0; i < n; i++)
		sum += arg((p[i]-pp) / (p[(i+1)%n]-pp));
	if(abs(sum) < 1.) return false;
	return true;
}

void find(int id){
	int p1 = -1, p2 = -1;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			if(!mark[i][j] and !mark[j][i] and i != (j + 1) % n and j != (i + 1) % n and can(i, j)){
				//if(id == 4 and i == 1 and j == 4) cout << "HI" << lexo(i, j, j, i) << endl;
				if(lexo(i, j, j, i) and (p1 == -1 or lexo(i, j, p1, p2))) p1 = i, p2 = j;
				else if(lexo(j, i, i, j) and (p1 == -1 or lexo(j, i, p1, p2))) p1 = j, p2 = i;
			}
	mark[p1][p2] = true;
	ans.PB(MP(p1, p2));
	seg.PB(MP(p1, p2));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i], p[i] = point(a[i], b[i]);
	//cout <<tagh(p[0], p[1], p[2], p[3]) << endl;
	for(int i = 0; i < n; i++)
		seg.PB(MP(i, (i+1)%n));
	/*ans.PB(MP(1, 3));
	mark[1][3] = true;
	seg.PB(MP(1, 3));
	cout << can(1, 4) << endl;
	*/for(int i = 3; i < n; i++)
		find(i);
	for(auto sg : ans)
		cout << sg.L << ' ' << sg.R << '\n';
	return 0;
}
