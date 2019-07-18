#include<iostream>
#include<fstream>
using namespace std;
void display_file(char* filename){
	ifstream infile(filename, ios::in | ios::_Nocreate);//ios::_Nocreate这个是VS2013版本的函数
	if (!infile){
		cerr << filename<<" open error!" << endl;
		exit(1);
	}
	char ch;
	while (infile.get(ch)){
		cout.put(ch);
	}
	cout << endl;
	infile.close();
}