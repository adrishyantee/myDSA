#include <bits/stdc++.h>
using namespace std;

#define n 100

class Queue{//queue class made
    int *arr;//an array
    int front;//the front part
    int back;//the back part which will only increase when elements gets in

    public:
    //queue constructor
    Queue(){
        arr=new int[n];// an array is created
        front =-1;//these are set to -1 as no data is present
        back=-1;
    }

    //push function to enter new element
    void push(int x){
        if(back==n-1){//when queue is empty
        cout<<"Queue overflowed"<<endl;
        return;
        }
       back++;//increase by an unit
       arr[back]=x;//enter value
       if(front==-1){//for the first element to be inserted the front has to shifted to the 0th pos
        front++;
       }
    }

    //pop the 1st element from the front
    void pop(){
        if(front ==-1 || front >back){//checking edge case if the queue is empty
            cout<<"No elements in queue"<<endl;
            return;
        }
        front++;//pop out from the first
    }

    //to get the front most value
    int peek(){
         if(front ==-1 || front >back){//if queue is empty
            cout<<"No elements in queue"<<endl;
            return -1;
         }
            return arr[front];//get the front element
    }

    //check whether queue is empty
    bool empty(){
        if(front==-1 || front>back){//if the front is at it place or the front crosses the back
            return true;
        }
        return false;
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek();
    return 0;
}