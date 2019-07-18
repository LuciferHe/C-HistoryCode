//题目：Word Pattern https://leetcode.com/problems/word-pattern/
//题解：http://blog.csdn.net/u012290414/article/details/48966135

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream is(str);
        unordered_map<char, string> hashmap;
        unordered_set<string> hashset;
        string word;
        int sz = pattern.length();
        int i = 0;
        while (is >> word) {
            hashset.insert(word);
            if (i == sz) {
                return false;
            }
            char tmp_val = pattern[i++];
            auto found = hashmap.find(tmp_val);
            if (found == hashmap.end()) {
                hashmap[tmp_val] = word;
            }
            else {
                if (hashmap[tmp_val] != word) {
                    return false;
                }
            }
        }
        return (hashset.size() == hashmap.size() and i == sz);
    }
};