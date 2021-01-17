#include <vector>
#include <iostream>
using namespace std;

int calculate_pairs(vector<int> vec) {
    //----WRITE YOUR CODE BELOW THIS LINE----
    int p=1,result = 0;
    if (vec.size()==1)
    result=0;
    else 
    for(int i=0;i<vec.size()-1;i++)
    {
        for (int j=i+1;j<vec.size();j++)
        {
        p=vec[i]*vec[j];
        result+=p;
        }
    }
     
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    return result;
}
int main()
{
   cout<<calculate_pairs({2,4,6,8});
    return 0; 
}