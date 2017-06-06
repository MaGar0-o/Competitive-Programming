//sobskdrbhvk
//remember the flying, the bird dies ):(
#include "grader.h"
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

inline int comp(int setid, int mask1, int mask2, int n, long long **sets){
	LL su1 = 0,
		su2 = 0;
	for(int i = 0; i < n; i++){
		if((mask1 >> i) & 1) su1 += sets[setid][i];
		if((mask2 >> i) & 1) su2 += sets[setid][i];
	}
	return su1 < su2 ? -1 : su1 == su2 ? 0 : +1;
}

int identify_set(int n, int k, long long **sets) {
	srand(time(0));
	int act = (1 << k) - 1;
	for(int i0 = 0; i0 < n; i0++)
		for(int i1 = i0 + 1; i1 <= n; i1++){
			int mask1 = (1 << i1) - (1 << i0);
			for(int j0 = i1; j0 < n; j0++)
				for(int j1 = j0 + 1; j1 <= n; j1++){
					int mask2 = (1 << j1) - (1 << j0);
					int lst = -1;
					for(int i = 0; i < k; i++)
						if((act >> i) & 1){
							if(~lst){
								if(comp(lst, mask1, mask2, n, sets) != comp(i, mask1, mask2, n, sets)){
									int ty = compare(mask1, mask2);
									for(int j = 0; j < k; j++)
										if(((act >> j) & 1) and (comp(j, mask1, mask2, n, sets) != ty))
											act ^= 1 << j;
									break;
								}
							}
							lst = i;
						}
				}
		}
	if((act & (act - 1)) == 0)
    	return __builtin_ctz(act);
	/*
	for(int _ = 0; _ < 20000 and ((act) & (act - 1)); _++){
		int mask1 = rand() & ((1 << n) - 1),
			mask2 = rand() & ((1 << n) - 1);
		int dna = mask1 & mask2;
		mask1 ^= dna;
		mask2 ^= dna;
		int lst = -1;
		for(int i = 0; i < k; i++){
			if((act >> i) & 1){
				if(~lst){
					if(comp(lst, mask1, mask2, n, sets) ^ comp(i, mask1, mask2, n, sets)){
						int ty = compare(mask1, mask2);
						for(int j = 0; j < k; j++)
							if((act >> j) & 1)
								if(comp(j, mask1, mask2, n, sets) ^ ty)
									act ^= 1 << j;
						goto hell2;
					}
				}
				lst = i;
			}
		}
hell2:;
	}
	*/
	if((act & (act - 1)) == 0)
    	return __builtin_ctz(act);
	return -1;
}
