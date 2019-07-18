#include <iostream>
using namespace std;
int fun(){
	int A[100] = {0};
	int n = 0;
	cout << "Please input n:";
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> A[i+1];
	}
	int tot = 0;
	int best = A[1];
	for (int i = 1; i <= n; ++i){
		for (int j = i; j <= n; ++j){
			int sum = 0;
			for (int k = i; k <= j; ++k){ sum += A[k]; ++tot; }
			if (sum>best)best = sum;
		}//for2
	}//for1
	return best;
}//fun


int main(){
	while (int sum = fun()){
		cout << "max_sum is " << sum << endl;
	}
	return 0;
}
