#include <bits/stdc++.h>

using namespace std;

int extractIntegerWords(string str) 
{ 
    stringstream ss;     
    ss << str; 
    string temp; 
    int found; 
    while (!ss.eof()) { 
        ss >> temp; 
        if (stringstream(temp) >> found) 
		{
           return found;
		}
        temp = ""; 
    }
}

bool number(string c)
{
    if (c.find('0') != std::string::npos ||
        c.find('1') != std::string::npos ||
        c.find('2') != std::string::npos ||
        c.find('3') != std::string::npos ||
        c.find('4') != std::string::npos ||
        c.find('5') != std::string::npos ||
        c.find('6') != std::string::npos ||
        c.find('7') != std::string::npos ||
        c.find('8') != std::string::npos ||
        c.find('9') != std::string::npos)
    {
        return true;
    }

    return false;
}

int main() {
	int n,i,c1=0,c2=0;
	vector <string> arr;
	vector<int> s;
	string str;
	cin >> n;
	for(i = 0; i<n; i++)
	{
		getline (cin, str);
        arr[i] = str;
	}
    for (i=0; i<n; i++)
	{ 
		if(number(arr[i])==true)
		{
        s.push_back(extractIntegerWords(arr[i]));
		}		
	}
	for(int j=0;j<s.size();j++)
	{
		if (s[j]==19 || s[j]==20)
		c1++;
		else
		c2++;
	}
	if(c1>c2)
	{
		cout<<"Date";
	}
	else
	{
		cout<<"No date";
	}
	
	return 0;
}


