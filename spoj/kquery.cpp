//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define mp make_pair
#define l first
#define r second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn=3e4+10;
pii a[maxn];
int seg[25*maxn],root[maxn],L[25*maxn],R[25*maxn],
	q,n;
int sz=1;
int inc(int idx,int id,int l=0,int r=n){
	if(idx<l or idx>=r) return id;
	int nid=sz++;
	seg[nid]=seg[id]+1;
	if(r-l==1) return nid;
	int mid=(l+r) >> 1;
	L[nid]=inc(idx,L[id],l,mid);
	R[nid]=inc(idx,R[id],mid,r);
	return nid;
}
int get(int st,int en,int id,int l=0,int r=n){
	if(st>=r or l >= en) return 0;
	if( st<=l  and r<=en) return seg[id];
	int mid=(l + r) >> 1;
	return get(st,en,L[id],l,mid)+
		   get(st,en,R[id],mid,r);
}
int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	scanf("%d", &n );
	for(int i=0;i<n;i++){
		scanf("%d" , &a[i].l);
		a[i].r=i;
	}
	sort(a,a+n);
	cin>>q;
	for(int i=n-1;i>=0;i--)
		root[i]=inc(a[i].r,root[i+1]);
	for(int i=0;i<q;i++){
		int fi,se,th;
		scanf("%d%d%d" , &fi , &se , &th );
		int id=lower_bound(a,a+n,mp(th+1,-1))-a;
		printf("%d\n" , get(fi-1,se,root[id]));
	}
	return 0;
}
