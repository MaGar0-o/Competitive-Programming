#include <iostream>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#define FOR(i,x,n) for(__typeof(x) i = (x); i != (n); i++)
#define FR(i,n) FOR(i,0,n)
#define FRI(it,v) FOR(it,v.begin(),v.end())
#define SZ size()
#define MP make_pair
#define show(x) cerr<<#x<<"="<<x<<endl;
#define ALL(v) v.begin(),v.end()
#define RS random_shuffle
#define PB push_back
#define isin(v,x) (v.find(x) != v.end())
#define sqr(x) ( (x) * (x) )
#define X first
#define Y second
using namespace std;

const int MAX_N = 100*1000 + 13;
typedef pair<int,int> PII;
typedef vector<int> VI;

int n, m;
int a[MAX_N];
PII b[MAX_N];
int p[MAX_N];
VI child[MAX_N];

bool cmp(const PII &p1, const PII &p2) {
  return (p1.X == p2.X) ? (p1.Y > p2.Y)
    : (p1.X < p2.X);
}

#define siz(j) (b[j].Y - b[j].X)

int solve(int ind) {
  int from = (ind == m) ? 0 : b[ind].X;
  int to = (ind == m) ? n-1 : b[ind].Y;

  int ans = 0;
  int odds = 0, evens = 0;
  VI &c = child[ind];

  if (c.size() == 0)
    for (int k=from; k<=to; k++)
      { odds += a[k]; evens += !a[k]; }
  else {
    for (int k = from; k<b[c[0]].X; k++)
      { odds += a[k]; evens += !a[k]; }
    
    FR(i,(int)c.size()) {
      ans += solve(c[i]);
      if (i != 0)
	for (int k=b[c[i-1]].Y+1; k<b[c[i]].X; k++)
	  { odds += a[k]; evens += !a[k]; }
    }
    for (int k=b[c.back()].Y+1; k<=to; k++)
      { odds += a[k]; evens += !a[k]; }
  }
  
  int r = 0;
  if (ind == m) r = odds + ans;
  else r =  max(odds+ans, evens+ans);

//   cerr << ind << " : ( " << from << "," << to << ") : " 
//        << ans << " " << odds << " " << evens 
//        << " ===> " << r << endl;
  return r;
}

int main() {
  int testn; cin>>testn;
  FR(testi,testn) {
    cin >> n;
    FR(i,n) { cin >> a[i]; a[i] &= 1; }
    cin >> m;
    FR(i,m) { cin >> b[i].X >> b[i].Y; b[i].X--; b[i].Y--; }

    sort(b,b+m,cmp);

    vector<pair<PII, int> > events; events.clear();
    FR(i,m) {
      events.PB(MP(MP(b[i].X,0),i)); // OPEN
      events.PB(MP(MP(b[i].Y,1),i)); // CLOSE
    }
    sort(events.begin(),events.end());
    

    int dead[MAX_N]; memset(dead, false, sizeof dead);
    vector<int> open; open.clear();   
    FRI(it,events) {
      int who = it->second;
      if (it->first.second == 1) { // CLOSE
	dead[who] = true;
	continue;
      }
      else { // open
	while (open.size() && dead[open.back()])
	  open.pop_back();
	if (open.empty()) p[who] = m;
	else p[who] = open.back();
	open.push_back(who);
      }
    }

    FR(i,m+1) child[i].clear();
    FR(i,m) { 
      //cerr << i << " = " << p[i] << endl; 
      child[p[i]].PB(i);
    }

    int ans = solve(m);
    cout << ans << endl;
  }

  return 0;
}
