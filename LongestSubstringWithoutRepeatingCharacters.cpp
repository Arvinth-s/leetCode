//OM NAMO NARAYANA
#include"my_template.h"
using namespace std;
//https://leetcode.com/problems/longest-substring-without-repeating-characters/

int lengthOfLongestString(string s)
{
    int start = 0, count = 0, max_count = 0;
    bool visited[256];
    memset(visited, false, sizeof(visited));
    long n = s.size();
    loop(i, n)
    {
        while(visited[s[i]])
        {
            count--;
            visited[s[start]] = false;
            start++;
        }
        visited[s[i]]=true;
        count++;
        if(max_count < count)max_count = count;
    }
    return max_count;
}

int main()
{
    fastio;
    string s;
    cin>>s;
    cout<<lengthOfLongestString(s);
    return 0;
}