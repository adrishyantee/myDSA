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

const int mod = 1000050131;

char s[10005];

int hasz(int a) {
	return ((100594677LL * (a + 450617412)) ^ 208774486) % mod;
}

int merge(int a, int b, char ope) {
	if(ope == '+') {
		return (a + b) % mod;
	}
	if(ope == '*') {
		return (long long) a * b % mod;
	}
	assert(ope == '#');
	return (((337807718LL * hasz(a)) + 254452523) ^ ((842188890LL * hasz(b)) + 900099649)) % mod;
}

int get_balance(char c) {
	if(c == '(') {
		return 1;
	}
	if(c == ')') {
		return -1;
	}
	return 0;
}

int rec(int L, int R) {
	// debug() << imie(L) imie(R);
	int bal = 0;
	for(int i = L; i <= R; ++i) {
		bal += get_balance(s[i]);
	}
	assert(bal == 0);
	if(s[L] == '(') {
		int balance = 1;
		int i = L + 1;
		while(balance > 0) {
			balance += get_balance(s[i]);
			i++;
		}
		// past closing bracket
		int a = rec(L + 1, i - 2); // this was inside the brackets
		if(i >= R) {
			return a;
		}
		assert(s[i] == '#' || s[i] == '+' || s[i] == '*');
		// debug() << imie(i+1) imie(R);
		int b = rec(i + 1, R);
		return merge(a, b, s[i]);
	}
	int a = 0;
	while(L <= R && isdigit(s[L])) {
		a = (10LL * a + (s[L] - '0')) % mod;
		L++;
	}
	if(L > R) {
		return a;
	}
	// debug() << imie(L);
	assert(s[L] == '+' || s[L] == '*' || s[L] == '#');
	int b = rec(L + 1, R);
	return merge(a, b, s[L]);
}

void test_case() {
	int n;
	scanf("%d", &n);
	map<int, int> mapping;
	for(int i = 0; i < n; ++i) {
		scanf("%s", s);
		int value = rec(0, (int) strlen(s) - 1);
		if(mapping.find(value) == mapping.end()) {
			int nxt = mapping.size();
			nxt++;
			mapping[value] = nxt;
		}
			printf(" %d", mapping[value]);
		// debug() << imie(value);
	}
		puts("");
}

int main() {
	int T;
	scanf("%d", &T);
	for(int z = 1; z <= T; z++) {
		printf("Case #%d:", z);
		test_case();
	}
}
