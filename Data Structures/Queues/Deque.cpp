#include <bits/stdc++.h>
#include <deque>

using namespace std;

int main(){//deque acts very similar to queue but can be popped from both back and front side
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(3);
    dq.push_front(4);
    for(auto i: dq)
    cout<<i<<" ";
    cout<<endl;
    dq.pop_back();
    dq.pop_front();
    for(auto i: dq)
    cout<<i<<" ";
    cout<<endl;
    cout<<dq.size();
}