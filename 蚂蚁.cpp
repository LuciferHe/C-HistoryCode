# include<cstdio>
# include<algorithm>
using namespace std;

const int maxn = 10000 + 5;

struct Ant{
	int id, p, d;
	bool operator < (const Ant& a) const {
		return p < a.p;
	}
} before[maxn], after[maxn];

const char dirName[][10] = {"L", "Turning", "R"};

int order[maxn];

int main(){
	int k;
	scanf ("%d", &k);
	for(int kcase = 1; kcase<=k; kcase++){
		int L, T, n;
		int i;
		printf ( "Case #%d:\n", kcase );
		scanf("%d%d%d", &L, &T, &n);
		for(i=0; i<n; i++) {
			int p, d;
			char c;
			scanf("%d %c", &p, &c);
			d = (c == 'L'? -1 : 1);
			before[i].id = i;
			before[i].p = p;
			before[i].d = d;
			after[i].id = 0;
			after[i].p = p+T*d;
			after[i].d = d;
		}
		sort(before, before+n);
		for( i=0; i<n; i++)
			order[before[i].id] = i;

		sort(after, after+n);
		for(i = 0 ; i < n-1; i++)
			if(after[i].p == after[i+1].p) after[i].d = after[i+1].d = 0;

		for(i = 0; i < n; i++){
			int a = order[i];			
			if(after[a].p < 0 || after[a].p > L) printf("Fell off\n");
			else printf("%d %s\n", after[a].p, dirName[after[a].d+1]);
		}
		printf("\n");
	}
	return 0;
}