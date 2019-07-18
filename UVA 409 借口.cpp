#include<iostream>
#include<string>
#include<cctype>
#include<ctime>
using namespace std;
const int MAXN = 30 + 5;
string key[MAXN],word[MAXN],tword;
int words, keys, pos[MAXN],nummax,Max;
int main(){
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int Case = 1, i, j, k;
	while (cin >> keys >> words){
		Max = -1; nummax = 0;
		getchar();
		for (i = 0; i < keys; ++i){getline(cin, key[i]);}
		for (i = 0; i < words; ++i){
			getline(cin, word[i]);
			tword = word[i];
			int len = word[i].length();
			for (j = 0; j < len; ++j){tword[j] = tolower(tword[j]);}
			int count = 0;
			for (j = 0; j < len; ++j){
				for (k = 0; k < keys; ++k){
					int keylen = key[k].length();
					if (tword[j] == key[k][0] && (j + keylen) <= len && (j == 0 || !isalpha(tword[j - 1]) || !isalpha(tword[j + keylen - 1]))){
							if (tword.substr(j, keylen) == key[k]) ++count;
					}
				}
			}
			if (count > Max){ Max = count; nummax = 0; pos[nummax++] = i; }
			else if (count == Max){ pos[nummax++] = i; }
		}
		cout << "Excuse Set #" << Case++ << endl;
		for (i = 0; i < nummax; ++i){cout << word[pos[i]] << endl;}
		cout << endl;
	}
	cout << endl << (double)clock() / CLOCKS_PER_SEC << endl;
	return 0;
}