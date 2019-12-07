//Clumio vowel Rahul
#include <bits/stdc++.h>
using namespace std;
bool isvowel(char c)
{
    if(c == 'a' || c =='e' || c == 'i' || c== 'o' || c=='u')
        return true;
    return false;
} 
int func(string s)
{
    int count =0 ;
    int n = s.length();
    map <char,int> hashmap;
    int start = 0;
    for(int i=0;i<n;i++)
    {
        hashmap[s[i]]++;
        while(hashmap.size() >= 5)
        {
            count += n-i;
            hashmap[s[start]]--;
            if(hashmap[s[start]]  == 0)
            {
                hashmap.erase(s[start]);
            }
            start++;
        }
    }
    return count;
}
int main()
{
    string s;
    cin>>s;
    int n = s.length();
    int count  =0 ;
    string temp="";
    for(int i=0;i<s.length();i++)
    {
        if(isvowel(s[i]))
        {
            temp.push_back(s[i]);
        }
        else
        {
            if(temp.length() >= 5)
            {
                count+= func(temp);
            }
            temp="";
        }
    }
    if(temp.length() >= 5)
    {
        count+=func(temp);
    }
    cout<<count<<endl;
    return 0;
}