#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
using namespace std;

#define  ADDD(a,b) rawIntervals.push_back(Interval(a,b))

enum RELATION{ 
	ERROR=-1, 
	A1B1A2B2, //相离 [a1 b1] [a2 b2]
	A1B2,     //相交 [a1 b2]
	A1B1      //内含 [a1  b1]
};

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

//该函数 默认a1 <= a2  ai<=bi
int relation(int a1, int b1, int a2, int b2){
	if (b1 < a2){//a 与 b 相离 
		return A1B1A2B2;//[a1 b1] [a2 b2]
	}
	else if (a2 <= b1 && b1 <= b2){// a 与 b 相交
		return A1B2;//[a1 b2]
	}
	else if (b2 <= b1){// a 包含 b 
		return A1B1;//[a1  b1]
	}
	else {
		return ERROR;
	}
}


//void printAns(vector<Interval>& inter){
//	cout << "This :\n";
//	int i = 0;
//	for (i = 0; i < inter.size(); ++i){
//		cout << inter[i].start << ", " << inter[i].end << "\n";
//	}
//}

bool cmp(Interval a, Interval b){
	return ((a.start < b.start) || (a.start == b.start && b.end < a.end));
}


vector<Interval> merge(vector<Interval>& intervals) {
	vector<Interval> ans;
	if (intervals.size() == 0){ 
		return ans; 
	}
	sort(intervals.begin(), intervals.end(), cmp);

	int i, j, k;
	int itemCount = intervals.size();
	for (i = 0; i < itemCount;){

		int a1 = intervals[i].start, 
			b1 = intervals[i].end;

		if (i == itemCount - 1){ 
			ans.push_back(Interval(a1, b1)); 
			break; 
		}

		bool _end = true;

		for (j = i + 1; j < itemCount; ++j){
			int a2 = intervals[j].start, 
				b2 = intervals[j].end;
			int rela = relation(a1, b1, a2, b2);

			switch (rela)
			{
			case A1B1A2B2: 
				ans.push_back(Interval(a1, b1));
				i = j;
				_end = false;
				break;

			case A1B1:
				break;

			case A1B2:
				b1 = b2;
				break;

			default:
				cout << "Error\n\n";
				break;
			}
			
		}// j

		if (_end){ 
			ans.push_back(Interval(a1, b1)); 
			break;
		}

	}// i
	return ans;
}

int main(){
#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int i, j;
	vector<Interval> rawIntervals;
	vector<Interval> mergedIntervals;
	rawIntervals.clear();
	mergedIntervals.clear();
	srand((int)time(0));

	for (i = 0; i < 1000; ++i){
		int a = rand() % 100;
		int b = rand() % 100;
		while (a > b){
			b = rand() % 100;
		}
		ADDD(a, b);
	}
	//printAns(V);
	mergedIntervals = merge(rawIntervals);
	//printAns(Vans);
	return 0;
}