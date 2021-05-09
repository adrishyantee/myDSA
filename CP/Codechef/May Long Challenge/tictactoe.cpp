#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll T;
    cin>>T;
    while(T--){
         
        int cx=0, co=0, cd=0;

        char arr[3][3];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cin>>arr[i][j];

                if(arr[i][j]=='X')
                cx++;
                if(arr[i][j]=='O')
                co++;
                if(arr[i][j]=='_')
                cd++;

            }
        }

        int wx=0,wo=0;
        if(arr[0][0]=='X' && arr[1][0]=='X' && arr[2][0]=='X')
        wx=1;
        if(arr[0][1]=='X' && arr[1][1]=='X' && arr[2][1]=='X')
        wx=1;
        if(arr[0][2]=='X' && arr[1][2]=='X' && arr[2][2]=='X')
        wx=1;
        if(arr[0][0]=='X' && arr[1][1]=='X' && arr[2][2]=='X')
        wx=1;
        if(arr[0][0]=='X' && arr[0][1]=='X' && arr[0][2]=='X')
        wx=1;
        if(arr[1][0]=='X' && arr[1][1]=='X' && arr[1][2]=='X')
        wx=1;
        if(arr[2][0]=='X' && arr[2][1]=='X' && arr[2][2]=='X')
        wx=1;        
        if(arr[0][2]=='X' && arr[1][1]=='X' && arr[2][0]=='X')
        wx=1;


        if(arr[0][0]=='O' && arr[1][0]=='O' && arr[2][0]=='O')
        wo=1;
        if(arr[0][1]=='O' && arr[1][1]=='O' && arr[2][1]=='O')
        wo=1;
        if(arr[0][2]=='O' && arr[1][2]=='O' && arr[2][2]=='O')
        wo=1;
        if(arr[0][0]=='O' && arr[1][1]=='O' && arr[2][2]=='O')
        wo=1;
        if(arr[0][0]=='O' && arr[0][1]=='O' && arr[0][2]=='O')
        wo=1;
        if(arr[1][0]=='O' && arr[1][1]=='O' && arr[1][2]=='O')
        wo=1;
        if(arr[2][0]=='O' && arr[2][1]=='O' && arr[2][2]=='O')
        wo=1;        
        if(arr[0][2]=='O' && arr[1][1]=='O' && arr[2][0]=='O')
        wo=1;

        if((wx==1 && wo ==1)||((cx-co)<0)||((cx-co)>1))
        cout<<3<<endl;
        else if(cx == 0 && co ==0 && cd ==9)
        cout<<2<<endl;
        else if(wx ==1 && wo ==0 && cx>co)
        cout<<1<<endl;
        else if(wx == 0 && wo ==1 && cx==co)
        cout<<1<<endl;
         else if(wx ==0 && wo ==0 && cd ==0)
        cout<<1<<endl;
        else if(wx == 0 && wo ==0 && cd > 0)
        cout<<2<<endl;
        else 
        cout<<3<<endl;

    }
    return 0;

}