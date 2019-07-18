#include<iostream>
#include<cmath>
using namespace std;

int main(){
	double y;
	int x, xtemp, m;
	for (y = 1; y >= -1; y -= 0.1){
		m = acos(y) * 10;  //Ç¿ÖÆ×ª»»
		for (x = 1; x < m; ++x) cout << " ";
		cout << "*";

		for (; x < 62 - m; ++x) cout << " ";
		cout << "*";
		for (x = 1; x < m; ++x) cout << " ";
		for (xtemp = 1; xtemp < m; ++xtemp) cout << " ";
		cout << "*";
		for (; xtemp < 62 - m; ++xtemp) cout << " ";
		cout << "*" << endl;
	}
	return 0;
}
