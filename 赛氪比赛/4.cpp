#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int maxstring(string s)
{
    int n = s.size();
    unordered_map<string, int> occ;
    int ans = 0;
    int i, j;
    for (int r = 1; r <= n; r++)
    {
        for (i = 0; i < n; i++)
        {
            j = (i + r - 1) % n;
            string cur;
            if (i <= j)
                cur = s.substr(i, r);
            else
            {
                cur = s.substr(i, n - i);
                cur += s.substr(0, j + 1);
            }
            ++occ[cur];
            if (occ[cur] == 1)
                ans++;
        }
    }
    return ans;
}
int main()
{
    string s;
    cin>>s;
    int b = maxstring(s);
    cout << b << endl;
    return 0;
}