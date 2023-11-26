#include <iostream>
#include <vector>
using namespace std;
string common(string& s1,string& s2) 
{
    int l1= s1.length(), l2 = s2.length(),maxl=0,end=0;
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
    for(int i=1;i<=l1;i++) 
    {
        for(int j=1;j<=l2;j++) 
        {
            if(s1[i-1]==s2[j-1]) 
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxl = max(maxl,dp[i][j]);
                if(dp[i][j]==maxl) 
                {
                    end = i - 1;   
                }
            } 
            else 
            {
                dp[i][j] = 0;
            }
        }
    }
    cout<<"Dynamic Table:\n";
    cout<<"    ";
    for (char ch : s2) 
    {
        cout << ch << " ";
    }  
    cout << "\n";
    for (int i = 0; i <= l1; i++) 
    {
        if (i > 0) 
        {
            cout << s1[i - 1] << " "; 
        } 
        else 
        {
            cout << "  ";
        }
        for (int j = 0; j <= l2; j++) 
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return s1.substr(end-maxl+1,maxl);
}

int main() 
{
    string s1,s2;
    cin>>s1>>s2;
    string res = common(s1,s2);
    cout << "Longest Common Substring is " << res <<" and largest value is "<< res.length() <<endl;
    return 0;
}
