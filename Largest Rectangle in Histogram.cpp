//-----------------------------------------------------
//All Rights Reserved, Copyright (C) 2015, beyourself
//-----------------------------------------------------

/*
原题：https://leetcode.com/problems/largest-rectangle-in-histogram/
题解：http://www.cnblogs.com/felixfang/p/3676193.html

样例输入：2 1 5 6 2 3
样例输出：10

样例输入：2 1 2
样例输出：3

样例输入：0 0 0 0 2
样例输出：2

样例输入：0 1 0 2 0 3
样例输出：3
*/
#include<vector>
#include<iostream>
#include<stack>
using namespace std;
#define MAX(a,b) ((a)>(b)?(a):(b))

int largestRectangleArea(vector<int>& height) {
	int maxArea = 0;
	if (height.size() == 0) return 0;
	height.push_back(0);
	stack<int> s;
	int i, j;
	for (i = 0; i < height.size(); ++i){
		if (!s.empty() && height[i] < height[s.top()]){
			while (height[i] <= height[s.top()]){
				int tmp = s.top();
				s.pop();
				int area = (s.empty() ? i : i - s.top() - 1) * height[tmp];
				maxArea = (maxArea>area) ? maxArea : area;
				if (s.empty())break;
			}
		}
		s.push(i);
	}//for
	return maxArea;
}


int main(){
	int i, j;
	vector<int> height;
	
	height.push_back(2);
	height.push_back(1);
	height.push_back(2);
	int ans = largestRectangleArea(height);
	height.push_back(2);
	cout << "ans:" << ans << endl;
	return 0;
}

