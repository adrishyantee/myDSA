class Solution {
public:
    string addBinary(string a, string b) {
        int s=0;
        string result="";
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || s == 1){
        s += ((i >= 0)? a[i] - '0': 0);
        s += ((j >= 0)? b[j] - '0': 0);
            //may contain 1,2 or 3.
        //takes care of the edge cases when one is exhausted

        result = char(s % 2 + '0') + result;
        s /= 2;//the carry
        i--; 
        j--;
    }
    return result;
    }
};