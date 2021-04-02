#include <iostream>
#include <stack>

 using namespace std;
//need to understand this using an example

void insertAtBottom(stack<int> &st,int element){
    if(st.empty()){
        st.push(element);
        return;
    }
    int topelement=st.top();
    st.pop();
    insertAtBottom(st,element);
    st.push(topelement);//add the element in the top
}

void reverse(stack<int> &st){

    if(st.empty())
    return;

    int element=st.top();
    st.pop();
    reverse(st);//go in reverse order
    insertAtBottom(st,element);// send the element here

}

int main(){
    stack<int> st;//making a stack

    for (int i=10;i>=0;i--){//entering the elements in reverse so that last element is 0. So stack starts from 0 at the top 
        st.push(i);
    }

    reverse(st);//revrsing the stack

    while(!st.empty()){//printing the elements of the reverse stack
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
  return 0;
 }
