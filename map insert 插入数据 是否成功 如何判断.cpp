#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	map<int, string> mapStudent;
	pair<map<int, string>::iterator, bool> Insert_Pair;
	Insert_Pair = mapStudent.insert(pair<int, string>(1, "student_one"));
	if(Insert_Pair.second == true)
	{
		cout << "Insert Successfully" << endl;
	}
	else
	{
		cout << "Insert Failure" << endl;
	}
	Insert_Pair = mapStudent.insert(pair<int, string>(1, "student_two"));

	if(Insert_Pair.second == true)
	{
		cout << "Insert Successfully" << endl;
	}
	else
	{
		cout << "Insert Failure" << endl;
	}

	map<int, string>::iterator iter;

	for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
	{
		cout << iter->first << " " << iter->second << endl;
	}
}