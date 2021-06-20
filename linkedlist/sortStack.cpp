#include <iostream>
#include <stack>
using namespace std;

/*int main()
{
    int n, a;
    cin >> n;
    stack<int> s1, s2;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        s1.push(a);
    }
    while (!s1.empty())
    {
        int k = s1.top();
        s1.pop();
        while (!s2.empty() && s2.top() < k)
        {
            s1.push(s2.top());
            s2.pop();
        }
        s2.push(k);
    }
    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << "\n";
    return 0;
} */

//Word break 1

class Solution
{
public:
    unordered_map<string, bool> mp; // Map dic words
    unordered_map<int, bool> mem;

    bool solve(string s)
    {
        if (s.size() == 0)
        {
            return true;
        }
        if (mem.find(s.length()) != mem.end())
        { //If string with length value is precalculated then return.
            return mem[s.length()];
        }
        string curr = "";
        for (int i = 0; i < s.size(); i++)
        {
            curr += s[i];
            if (mp[curr] == true)
            {
                if (solve(s.substr(i + 1, s.size() - i - 1)) == true)
                {
                    return mem[s.length()] = true;
                }
            }
        }
        return mem[s.length()] = false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        for (string ss : wordDict)
        {
            mp[ss] = true;
        }
        return solve(s);
    }
};
//Word Break 2 :
class Solution
{
    unordered_map<string, vector<string>> dp;

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        if (dp.find(s) != dp.end())
        {
            return dp[s];
        }
        vector<string> result;
        for (string w : wordDict)
        {
            if (s.substr(0, w.length()) == w)
            {
                if (w.length() == s.length())
                {
                    result.push_back(w);
                }
                else
                {
                    vector<string> temp = wordBreak(s.substr(w.length()), wordDict);
                    for (string t : temp)
                    {
                        result.push_back(w + " " + t);
                    }
                }
            }
        }
        dp[s] = result;
        return result;
    }
};