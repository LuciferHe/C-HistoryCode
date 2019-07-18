//给出n个整数xi和m个询问，对于每个询问(a,b)，输出闭区间[a,b]内的整数xi的个数
#include <iostream>
#include <algorithm>
using namespace std;

int v[1000] = {0};
int main(){
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i != n; ++i){
		cin >> v[i];
	}
	sort(v,v+n);
	for (int i = 0; i != m; ++i){
		cin >> a >> b;
		cout << upper_bound(v, v + n, b) - lower_bound(v,v+n,a)<<endl;
	}
	return 0;
}
