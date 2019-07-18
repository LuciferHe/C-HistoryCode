#include<iostream>
#include<cstring>
using namespace std;

const int N = 100;

class String{
public:
	int length;
	String(){
		memset(a, 0, sizeof(a));
		length = 0;
	}
	String(int l){
		memset(a, 0, sizeof(a));
		length = l;
	}
	String(const char* &p){
		strcpy(a, p);
		length = strlen(p);
	}
	friend istream& operator >> (istream &cin, String &s);
	friend ostream& operator << (ostream &cout, String &s);
	friend String operator + (String, String);
	char & operator [](int i){
		char c = 0;
		if (i<length && i>-1){
			return a[i];
		}
		else{
			cout << "Index out of range!" << endl;
			return c;
		}
	}
	void fresh(){
		length = strlen(a);
	}
private:
	char a[N];
};


istream& operator >> (istream &cin, String &s){
	cin.getline(s.a, N - 1);
	return cin;
}


ostream& operator << (ostream &cout, String &s){
	cout << s.a << endl;
	return cout;
}


String operator + (String s1, String s2){
	String s3;
	int l = strlen(strcat(s1.a, s2.a));
	strcpy(s3.a, s1.a);
	return s3;
}

void main(){
	String s1, s2, s3;
	cin >> s1;
	cin >> s2;
	s3 = s1 + s2;
	cout << s3;
	s3.fresh();
	for (int i = 0; i < s3.length; ++i){
		cout << s3[i] << " ";
	}
	cout << endl;
}
