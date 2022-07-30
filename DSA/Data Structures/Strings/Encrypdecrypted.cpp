#include <iostream>
#include <string>

using namespace std;

int main()
{
    string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key{"qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM"};
    string sen{};
    string st{};
   
    cout<<"Enter your secret message...";
    getline(cin,sen);
    
    cout<<"Encrypting....\n";
    cout<<"The encrypted message is...\n";
    for (char i:sen)
    {
        size_t pos = alphabet.find(i);
        if(pos!=string::npos)
        {
        char ch = key[pos];
        st=st+ch;
        }
        else
        st=st+i;   
    }
    cout<<st<<"\n";

    string st1{};
    cout<<"Decrypting....\n";
    cout<<"The decrypted message is...\n";
    for (char i:st)
    {
        size_t pos = key.find(i);
        if(pos!=string::npos)
        {
        char ch = alphabet[pos];
        st1=st1+ch;
        }
        else
        st1+=i; 
    }
    cout<<st1<<endl;
return 0;
}