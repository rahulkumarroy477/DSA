#include <bits/stdc++.h>
using namespace std;

// recursion

// bool isScrambled(std::string a, std::string b)
// {
//     int n = a.length();
//     if (n != b.length())
//         return false;
//     if (n == 0 or a == b)
//         return true;

//     for (int i = 1; i < n; i++)
//     {
//         if ((isScrambled(a.substr(0, i), b.substr(i)) and isScrambled(a.substr(i), b.substr(0, i))) or
//             (isScrambled(a.substr(0, i), b.substr(0, i)) and isScrambled(a.substr(i), b.substr(i))))
//             return true;

//         if ((isScrambled(a.substr(0, i), b.substr(0, i)) &&
//              isScrambled(a.substr(i), b.substr(i))) ||
//             (isScrambled(a.substr(0, i), b.substr(n - i)) &&
//              isScrambled(a.substr(i), b.substr(0, n - i))))
//             return true;
//     }
//     return false;
// }

// memoized
bool isScramble(string a, string b, unordered_map<string, bool> &mp)
{
    int n = a.length();
    if (a.length() != b.length())
        return false;

    if (n == 0 or a == b)
        return true;
    string key = a + '_' + b;
    if (mp.find(key) != mp.end())
        return mp[key];
    bool scrambled = false;
    for (int i = 1; i < n and !scrambled; i++)
    {
        scrambled = (isScramble(a.substr(0, i), b.substr(i),mp) and isScramble(a.substr(i), b.substr(0, i),mp)) or
                    (isScramble(a.substr(0, i), b.substr(0, i),mp) and isScramble(a.substr(i), b.substr(i),mp));
    }
    return mp[key]= scrambled;
}
int main()
{
    unordered_map<string,bool> mp;
    string a,b;
    cin>>a>>b;
    if(isScramble(a,b,mp)) cout<<"True\n";
    else cout<<"NO\n";
}