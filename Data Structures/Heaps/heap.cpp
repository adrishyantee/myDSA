#include <bits/stdc++.h>
using namespace std;

//heaps using stl

int main(){
    priority_queue<int, vector<int>> pq;
    pq.push(2);
    pq.push(3);
    pq.push(1);

    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;

    priority_queue<int, vector<int>, greater<int>> pqm;
    pqm.push(2);
    pqm.push(3);
    pqm.push(1);

    cout<<pqm.top()<<endl;
    pq.pop();
    cout<<pqm.top()<<endl;

    
    return 0;

}