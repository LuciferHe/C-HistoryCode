#include <map>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	map<int, string> mapStudent;
	//int:key  string:value

	//插入数据  法1 可以覆盖之前的值
	/*mapStudent[1] = "one";
	mapStudent[2] = "two";
	mapStudent[3] = "three";*/

	//插入数据  法2 不能覆盖之前的值
	//如何判断插入是否成功?
	//请见 map insert 插入数据 是否成功 如何判断.txt
	mapStudent.insert(pair<int, string>(1, "student_one"));
	mapStudent.insert(pair<int, string>(2, "student_two"));
	mapStudent.insert(pair<int, string>(3, "student_three"));


	//map遍历  法1 迭代器 正向遍历
	map<int, string>::iterator iter;
	for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
	{
		cout << iter->first << " " << iter->second << endl;
	}

	//map遍历  法2 迭代器 反向遍历
	/*map<int, string>::reverse_iterator iter;
	for (iter = mapStudent.rbegin(); iter != mapStudent.rend(); iter++)
	{
		cout << iter->first << " " << iter->second << endl;
	}*/

	//map数据查找 法1 count 返回值 0或1
	cout << endl << mapStudent.count(1) << endl;


	//map数据查找 法1 find 返回 一个迭代器 如为end 则没有找到
	/*iter = mapStudent.find(1);
	if (iter != mapStudent.end()){
		cout << endl << "Find, value: " << iter->second << endl;
	}
	else{
		cout << endl << "Do not find!" << endl;
	}*/

	if (mapStudent.empty()){//判断是否为空
		cout << endl << "Map empty!" << endl;
	}
	else{
		cout << endl << "Map exist!" << endl;
	}

	cout << endl << mapStudent.size() << endl;//map的大小

	mapStudent.clear();//清空
}