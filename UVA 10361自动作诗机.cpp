#include<iostream>
#include<string>
using namespace std;
int main(){
	int sub, p1, p2, p3, p4, p6;
	string str, s1, s2, s3, s4, s5, s6;

	cin >> sub;
	getline(cin, str);
	while (sub--){
		getline(cin, str);
		getline(cin, s6);
		p1 = str.find('<');
		p2 = str.find('>', p1 + 1);
		p3 = str.find('<', p2 + 1);
		p4 = str.find('>', p3 + 1);
		p6 = s6.find('.');
		s1 = str.substr(0, p1);
		s2 = str.substr(p1 + 1, p2 - p1 - 1);
		s3 = str.substr(p2 + 1, p3 - p2 - 1);
		s4 = str.substr(p3 + 1, p4 - p3 - 1);
		s5 = str.substr(p4 + 1, str.length());
		s6 = s6.substr(0, p6);
		cout << s1 << s2 << s3 << s4 << s5 << endl;
		cout << s6 << s4 << s3 << s2 << s5 << endl;
	}
}