#include <iostream>
using namespace std;
char map[500][500];
#define DEBUG 0
int R, C;
int fun(int r, int c){
	if (map[r][c] != '#'){
		return 0;
	}
	int s = 1,flag,ms=0;
	while (s){
		flag = 1;

		for (int i = r - s; i <= r + s;i++){
			if (i<0||i>=R||flag == 0){
				flag = 0;
				break;
			}
			for (int j = c - s; j <= c + s; j++){
				if (j < 0 || j >= C){
					flag = 0;
					break;
				}
				if (abs(r - i) + abs(c - j) <= s){
					if (DEBUG)cout << r << " " << c << " " << i << " " << j << endl;
					if (map[i][j] == '.'){
						flag = 0;
						break;
					}
				}
			}
			
		}
		if (flag == 1){
			if (DEBUG)cout << "find " << s << endl;
			if (s > ms){
				ms = s;
			}
			
			s = s + 1;
		}else{
			break;
		}
		
	}
	ms = ms * 2 + 1;
	if (DEBUG)cout << "fun(int,int) return " << ms << endl;
	return ms;
}
int fun(){
	int s,ms=0;
	for (int r = 0; r < R; r++){
		for (int c = 0; c < C; c++){
			s = fun(r, c);
			if (s>ms){
				if (DEBUG)cout << "fun() ms=" << ms << endl;
				ms = s;
			}
		}
	}
	if (DEBUG)cout << "fun() return " << ms << endl;
	return ms;
}
int main(){
	int T;
	cin >> T;
	while (T--){
		cin >> R >> C;
		for (int i = 0; i < R; i++){
			cin >> map[i];
		}
		cout << fun()<<endl;
	}
	return 0;
}