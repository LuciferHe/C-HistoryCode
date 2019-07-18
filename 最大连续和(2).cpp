#include <iostream>
using namespace std;
int fun(){
	int A[100] = { 0 }, S[100] = {0};
	int n = 0;
	cout << "Please input n:";
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> A[i+1];
	}
	int best = A[1];
	for (int i = 1; i <= n; ++i){ S[i] = S[i - 1] + A[i]; }
	for (int i = 1; i <= n; ++i){
		for (int j = i; j <= n; ++j){
			int t = S[j] - S[i - 1];
			best = best>t ? best : t;
			//best > ? = S[j] - S[i - 1];  这个在哪里可以用？？？？
		}
	}
	return best;
}//fun


int main(){
	while (int sum = fun()){
		cout << "max_sum is " << sum << endl;
	}
	return 0;
}
