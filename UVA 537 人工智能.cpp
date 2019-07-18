#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
using namespace std;
int Case;
int p1, p2;
string s;
double P, U, I;

void fun1(int p){
	char con = s[p - 1];
	double value;
	int punit=0;
	int flag = 0;
	double times = 1.0;

	switch (con)
	{
	case 'P':flag = 1; break;
	case 'U':flag = 2; break;
	case 'I':flag = 3; break;
	default:break;
	}

	switch (flag)
	{
	case 1:punit = s.find('W', p + 1); break;
	case 2:punit = s.find('V', p + 1); break;
	case 3:punit = s.find('A', p + 1); break;
	default:break;
	}
	switch (s[punit-1])
	{
	case 'm':times *= pow(10, -3); break;
	case 'k':times *= pow(10, 3); break;
	case 'M':times *= pow(10, 6); break;
	default:break;
	}
	stringstream ss(s.substr(p + 1, punit - p - 1));
	ss >> value;

	switch (flag)
	{
	case 1:P = value*times; break;
	case 2:U = value*times; break;
	case 3:I = value*times; break;
	default:break;
	}
}
int main(){
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif
	int i;
	cin >> Case;
	getchar();
	for (i = 1; i <= Case; ++i){
		getline(cin,s);
		p1 = s.find('=');
		p2 = s.find('=',p1+1);
		P = 0.0; U = 0.0; I = 0.0;
		fun1(p1);
		fun1(p2);
		cout << "Problem #" << i << endl;
		if (P <= pow(10, -10)){
			cout <<fixed<<setprecision(2)<<"P=" << U*I << "W\n" << endl;
		}
		else if (U <= pow(10, -10)){
			cout << fixed << setprecision(2) << "U=" << P / I << "V\n" << endl;
		}
		else if (I <= pow(10, -10)){
			cout << fixed << setprecision(2) << "I=" << P / U << "A\n" << endl;
		}
	}
	return 0;
}