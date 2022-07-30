#include <bits/stdc++.h>
using namespace std;
#define d 256

void search(char pat[], char txt[], int q)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int i, j;
    int p=0;
    int t=0;

	for (i = 0; i<M; i++)
     p +=(int)pat[i]*(pow(10,i));

    for (i = 0; i<M; i++)
     t +=(int)txt[i]*(pow(10,i));

     if(t==p){
     cout<<"Found"<<endl;
     return;
    }

	for (i = 1; i <= N - M; i++)
	{
        t = (t -(int)txt[i-1])/10 + txt[M+i-1]*pow(10,M-1);
        if( p == t )
		{
            cout<<"Found"<<endl;
            return;
        }
	}
    cout<<"Not found"<<endl;
    return;
}

int main()
{
	char txt[] = "GEEKS FOR GEEKS";
	char pat[] = "GEEP";
	int q = 101;
	search(pat, txt, q);
	return 0;
}
