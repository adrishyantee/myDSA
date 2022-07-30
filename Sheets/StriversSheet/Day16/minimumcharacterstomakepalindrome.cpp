#include <bits/stdc++.h>
using namespace std;

bool  ispalindrome(string s)
{
    int l = s.length();
    int j;
     
    for(int i = 0, j = l - 1; i <= j; i++, j--)
    {
        if(s[i] != s[j])
            return false;
    }
    return true;
}

int solve(string s) {
    int cnt = 0;
    int flag = 0;
     
    while(s.length()>0)
    {
        // if string becomes palindrome then break
        if(ispalindrome(s))
        {
            flag = 1;
             break;
        }
        else
        {
        cnt++;
         
        // erase the last element of the string
        s.erase(s.begin() + s.length() - 1);
        }
    }
     
    // print the number of insertion at front
    if(flag)
        return cnt;
}


//OPTIMISED CODE
vector<int> computeLPSArray(string pat, int M, vector<int> &lps){
	int len = 0;
	lps[0] = 0; // lps[0] is always 0

	// the loop calculates lps[i] for i = 1 to M-1
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else{
			if (len != 0) {
				len = lps[len - 1];
			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
    return lps;
}

int solve(string str) {
    string revStr = str;
    reverse(revStr.begin(), revStr.end());

    string concat = str+"$"+revStr;
    int M = concat.size();
    vector<int> lps(M);
    lps = computeLPSArray(concat, M, lps);

    return (str.size()-lps[M-1]);

}

