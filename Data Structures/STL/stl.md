**STANDARD TEMPLATE LIBRARY**
**PAIR**
pair<int, int> p={1,3}
p.first p.second
pair<int, pair<int,int>> p = {1,{3,4}};
pair<int, int> arr[]


**VECTOR**
vector<int> v;
v.push_back(1);
v.emplace_back(2);
vector<pair<int,int>> vec;
v.push_back({1,2});
v.emplace_back(1,2);

vector<int> v(5,100);
vector<int> v2(v1);

**ITERATOR**
vector<int> :: iterator it = v.begin();
vector<int> :: iterator it = v.end();//points to memory address after last element
vector<int> :: iterator it = v.rend(); //points to memory address before the first element
vector<int> :: iterator it = v.rbegin();//points to the last memory address exactly
it++;
cout<<*(it)<<" ";

for not allowing to move the iterator we are doing cbegin() and cend()
v.at() works exactly like v[0];
v.back() -> last element

**PRINT VECTOR**
for(vector<int>::iterator it = v.begin();it!=v.end();i++)
*(it);
for(auto it = v.begin();it!=v.end();i++)
*(it);
for(auto it :v)
*(it);

**FUNCTIONS**
v.erase(v.begin()) //first element is gone
v.erase(v.begin() +2, v.begin()+4);// erases a range but doenot erase the last memory address

v.insert(v.begin(),300) //insert an element at that position
v.insert(v.begin()+1,2,10) //insert series of elements (position, number of times, element)
v.insert(v,begin(), copy,begin(), copy.end()); //copy other vector inside one vector

v.size()
v.pop_back()//erases last element
v.swap(v1) //swaps two elements
 
v.erase()//erases all elements

**LIST**
list<int> ls;
ls.push_back();
ls.emplace_back();

ls.push_front()//we can push in the front as well 
ls.emplace_front()
rest all the functions are similar to vector
vector works better tho

**DEQUE**
deque<int> dq;
works similar to list or vector
just little more like dq.pop_back dq.pop_front, dq.back(), dq.front();

**STACK**
stack<int> st;
st.push()
st.emplace() //similar to push
st.top()//gets the top element
st.pop()
st.size()
st.empty()
st1.swap(st2);

**QUEUE**
queue<int> q;
q.push();
q.emplace();
q.back()//last element of the queue;
q.front()
q.pop() //pops the first
others are similar to stacks

**PRIORITY QUEUE**
**MAX HEAP**
priority_queue<int> pq;
pq.push();
pq.emplace();
pq.top();
others are same as before
**MIN HEAP**
priority_queue<int, vector<int>, greater<int>> pq;
pq.push()
pq.emplace()
pq.top() //prints the minimum element first

**SET**
set<int> st;
st.insert();
st.emplace(); //inserts and does it in sorted order and unique only
other functions like vector can be used 

auto it =st.find(3)//return the memory location of that
auto it = st.find()//if not present return st.end()
st.erase(5) //uses a logarithmic time so many use
st.count(6); //get the number of elemnts but it will be always one

auto it = st.find(3);
st.erase(it); // constant time
st.erase(st.find(2), st.find(3))// can erase a range of the elemnt
auto it = st.lower_bound(2);
auto it = st.upper_bound();

**MULTISET**
multiset<int> ms;// allows you to stor multiple elemts
ms.insert()
ms.count() can >= 1
ms.erase(1)//deletes all occurences of one
ms.erase(ms.find(1))//if erase one of the one 
ms.erase(ms.find(1),ms.find(1)+2);// deleted two ones

**UNORDERED SET**
lowerbound upper bound doesnot work rest of them are same when array is sorted
it doesnot have any order has better time complexity than set but collision can occur at times
unordered_set<int> st;
all functions are same as set

**MAP**
map<int,int> mp; //stores once that is unique key value and in sorted order
map<int, pair<int,int>> mp;
map<pair<int, int>, int> mp;
mp.emplace()
mp.insert()
stores in a sorted order of the key
for(auto it: mp){
    it.first(), it.second()
}
mp.find(2) // 2 is a key here returns an iterator
mp[1]- prints the data stored in the key
lower_bound upper_bound can be used. The other functions like erase swap size, empty can be used

**MULTI MAP**
everything like map but unique thing is not present, multiple items can be there
func like mp[index] doesnot work

**UNORDERED MAP**
unordered form and works similar to map, we have unique keys as well but collision happens
so preferred is map, all other functions work like maps

//SORT**
sort(a,a+n);
sorts whole array in ascending order
sort(a+2, a+4) //sorts a range and last element is not considered
sort(a, a+n, comp);// to sort them in a proper order

**write a self comparator can be written in any where**
bool comp(pair<int,int> p1 (data type of array), pair<int,int>p2){
    if(p1.second()<p2.second()){
        return true;
    }
    else if(p1.second()==p2.second()){
        if(p1.first>p2.second) return true;
    }
    return false;
}

**BUILTIN POP**
int cnt =__builtin_popcount();
counts the number of set bits in the binary representations
use __builtin_popcountll() for long long

**NEXT PERMUTATION**
next_permutation(s.begin(),s.end())
prints the next perm in dictionary order reaches the descending order then it finishes

**MAX_ELEMENT**
int maxi=*max_element(a, a+n);


