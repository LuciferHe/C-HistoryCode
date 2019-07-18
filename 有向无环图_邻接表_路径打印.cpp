#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
using namespace std;

#define mem(a) memset(a, 0, sizeof(a))

const int MAXN = 100;
deque<int> Q;
int vis[MAXN];


int Search_Path(vector<int>* vecAdjs, int nVertexCnt, int nCurNumber, int nEndNumber, int nPathCount)
{
	if (nCurNumber > nVertexCnt || nCurNumber <= 0)
	{
		return nPathCount;
	}

	if (!vecAdjs[nCurNumber - 1].empty())
	{
		vector<int>::iterator it = vecAdjs[nCurNumber - 1].begin();
		for (; it != vecAdjs[nCurNumber - 1].end(); ++it)
		{
			if (!vis[*it]){
				vis[*it] = 1;
				if ((*it) == nEndNumber)
				{
					++nPathCount;
					Q.push_back(nEndNumber);
					cout << "路径" << nPathCount << ": ";
					for (int i = 0; i < Q.size(); ++i){
						cout << Q[i] << " ";
					}
					cout << "\n\n";
					Q.pop_back();
				}
				else
				{
					Q.push_back(*it);
					nPathCount = Search_Path(vecAdjs, nVertexCnt, (*it), nEndNumber, nPathCount);
					Q.pop_back();
				}
				vis[*it] = 0;

			}
		}

	}


	return nPathCount;
}

int main()
{
	const int VertexCnt = 14;

	// respectively represent {m, n, o, p, q, r, s, t, u, v, w, x, y, z } 
	int arrVertex[VertexCnt] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
	vector<int> vecAdjs[MAXN];
	//顶点数 不能超过MAXN个
	//默认顶点编号 1,2,3...n-1,n


	// m
	vecAdjs[0].push_back(5);
	vecAdjs[0].push_back(6);
	vecAdjs[0].push_back(12);

	// n
	vecAdjs[1].push_back(3);
	vecAdjs[1].push_back(5);
	vecAdjs[1].push_back(9);

	// o
	vecAdjs[2].push_back(6);
	vecAdjs[2].push_back(7);
	vecAdjs[2].push_back(10);

	// p
	vecAdjs[3].push_back(3);
	vecAdjs[3].push_back(7);
	vecAdjs[3].push_back(14);

	// q
	vecAdjs[4].push_back(8);

	// r
	vecAdjs[5].push_back(9);
	vecAdjs[5].push_back(13);

	// s
	vecAdjs[6].push_back(6);

	// u
	vecAdjs[8].push_back(8);

	// v
	vecAdjs[9].push_back(11);
	vecAdjs[9].push_back(12);

	// w
	vecAdjs[10].push_back(14);

	// y
	vecAdjs[12].push_back(10);

	// t, x, z no adjacent list

	int nPathCount = 0;

	// start at p to v ( 4 -> 10)
	const int nStartNumber = 2;
	const int nEndNumber = 10;
	mem(vis);
	Q.clear();
	Q.push_back(nStartNumber);
	nPathCount = Search_Path(vecAdjs, VertexCnt, nStartNumber, nEndNumber, nPathCount);s
	cout << "simple paths: " << nPathCount << endl;

	system("pause");
	return 0;
}