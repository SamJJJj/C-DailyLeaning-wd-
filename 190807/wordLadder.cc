#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using std::cout;
using std::endl;
using std::queue;
using std::string;
using std::unordered_set;
using std::vector;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end())
        {
            return 0;
        }
        queue<string> q;
        int length = beginWord.length();
        q.push(beginWord);
        int depth = 0;
        while (!q.empty())
        {
            ++depth;
            for (int i = q.size(); i > 0; --i)
            {
                string word = q.front();
                q.pop();
                for (int j = 0; j < length; ++j)
                {
                    char c = word[j];
                    for (int k = 'a'; k <= 'z'; ++k)
                    {
                        word[j] = k;
                        if(word == endWord)
                        {
                            return ++depth;
                        }
                        if(!wordSet.count(word))
                        {
                            continue;
                        }
                        wordSet.erase(word);
                        q.push(word);
                    }
                    word[j] = c;
                }
            }
        }
        return 0;
    }
};


int main(int argc, char **argv)
{
    Solution s;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout << s.ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}