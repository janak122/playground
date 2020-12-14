#include <bits/stdc++.h>
#include <iterator>
#include <map>
#include <limits.h>
using namespace std;
#define ULL unsigned long long

void naiveAlgo(string str, string pat)
{
    int n = str.length(), m = pat.length();
    cout << "matching indexes : ";
    if (n >= m)
        for (int i = 0; i <= n - m; i++)
            if (str.compare(i, m, pat) == 0)
                cout << i << " ";
    cout << "\n";
}

int horspolMatch_getValue(map<char, int> jump, char key, int defaultVal)
{
    map<char, int>::iterator it = jump.find(key);
    return (it == jump.end()) ? defaultVal : it->second;
}

void horspolMatch(string str, string pat)
{
    int n = str.length(), m = pat.length();
    cout << "matching indexes : ";
    if (n >= m)
    {
        map<char, int> jump;
        for (int i = 0; i < m - 1; i++)
            jump[pat[i]] = m - i - 1;
        int endId = m - 1;
        while (endId < n)
        {
            if (str.compare(endId - m + 1, m, pat) == 0)
                cout << endId - m + 1 << " ";
            endId += horspolMatch_getValue(jump, str[endId], m);
        }
    }
    cout << "\n";
}

void kmp(string str, string pat)
{
    int n = str.length(), m = pat.length();
    cout << "matching indexes : ";

    int piTable[m];
    fill_n(piTable, m, -1);

    int i = 1, j = 0;
    while (i < m)
    {
        if (pat[i] == pat[j])
            piTable[i++] = j++;
        else
        {
                }
    }

    i = 0;
    j = -1;
    while (i < n)
    {
        if (pat[j + 1] == str[i])
        {
            i++;
            j++;
        }
        else if (j == -1)
            i++;
        else
            j = piTable[j];
        if (j == m - 1)
        {
            cout << i - m << " ";
            j = -1;
        }
    }
    cout << "\n";
}
ULL power(ULL x, ULL n, ULL p)
{ //x^n%p
    ULL ans = 1;
    x = x % p;
    while (n > 0){
        if (n & 1) //odd
            ans = (ans * x) % p;
        n = n >> 1;
        x = (x * x) % p;
    }
    return ans;
}
ULL getHashVal(string str, int start, int end, ULL prevVal)
{
    ULL hash = 0, rdx = 10, mul = 1,U_LIMIT=LLONG_MAX/rdx;
    if (prevVal == 0){
        for (int i = end; i >= start; i--){
            hash += mul * (str[i] + 1);
            hash %= U_LIMIT;
            mul *= rdx;
        }
    }
    else
        hash = (prevVal - ((str[start-1] + 1) * power(rdx, end - start, U_LIMIT))) * rdx
         + (str[end] + 1);
    
    return hash;
}

void RabinCarp(string str, string pat)
{
    int n = str.length(), m = pat.length();
    cout << "matching indexes : ";
    ULL hashPat = getHashVal(pat, 0, m - 1, 0), hashCurr = 0;
    for (int i = m; i <= n; ++i)
    {
    	hashCurr = getHashVal(str, i - m, i - 1, hashCurr);
        if (hashCurr == hashPat && (str.compare(i - m, m, pat) == 0))
            cout << i - m << " ";
    }
    cout << "\n";
}

int main(int argc, char const *argv[])
{
    RabinCarp("ram gopal ram kisan", "ram");
    RabinCarp("geeksforgeeks is for geeks", "geeks");
    return 0;
}

  // naiveAlgo("ram gopal ram kisan", "ram");
    // naiveAlgo("geeksforgeeks is for geeks", "geek");
    // horspolMatch("ram gopal ram kisan", "ram");
    // horspolMatch("geeksforgeeks is for geeks", "geek");
    // kmp("ram gopal ram kisan", "ram");
    // kmp("geeksforgeeks is for geeks", "geeks");