#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

// (2K+N+1) * N = 2 * G
     // K=9

void test_case() {
	long long g;
	scanf("%lld", &g);
	g *= 2;
	long long answer = 0;
	
	
	
	auto consider = [&](long long n) {
		debug() << imie(n);
		long long other = g / n; // 5
		// other = 2k+n+1
		other -= n;
		other -= 1; // 0
		if(other < 0) {
			return;
		}
		if(other % 2 != 0) {
			return;
		}
		long long k = other / 2;
		debug() << imie(k) imie(n);
		assert((2 * k + n + 1) * n == g);
		answer++;
	};
	
	for(long long d = 1; d * d <= g; ++d) {
		if(g % d == 0) {
			consider(d);
			if(d * d != g) {
				consider(g / d);
			}
		}
	}
	printf("%lld\n", answer);
}

int main() {
	int T;
	scanf("%d", &T);
	for(int z = 1; z <= T; z++) {
		printf("Case #%d: ", z);
		test_case();
	}
}
