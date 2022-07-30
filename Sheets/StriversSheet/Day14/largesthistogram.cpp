class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       int n = heights.size();
        if(n==1)
            return heights[0];
        vector<int> nle(n,0);
        vector<int> ple(n,0);
        stack<pair<int,int>> st; 
        //least to the right
        for(int i = n-1;i>=0;i--) {
            while(!st.empty() && st.top().second >= heights[i]) {
                st.pop(); 
            }
                if(!st.empty()) 
                    nle[i] = st.top().first-1; 
                else
                    nle[i]=n-1;
            st.push({i,heights[i]});
        }
        while(!st.empty()) st.pop();
          for(int i = 0;i<n;i++) {
            while(!st.empty() && st.top().second >= heights[i]) {
                st.pop(); 
            }
                if(!st.empty()) 
                    ple[i] = st.top().first+1;
              else
                    ple[i]=0;
            st.push({i,heights[i]});
        }
        int calc= 0;
        for(int i=0;i<n;i++){
           calc = max((nle[i]-ple[i]+1)*heights[i],calc);
        }
        return calc;
        
    }
};

//

   stack<int> st; 
        int maxA = 0; 
        int n = heights.size(); 
        for(int i = 0;i<=n;i++) {
            while(!st.empty() && (i==n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop(); 
                int width; 
                if(st.empty()) width = i; 
                else width = i - st.top() - 1; 
                
                // cout << i << " " << width << " " << height << endl; 
                maxA = max(maxA, width * height); 
            }
            st.push(i); 
        }
        return maxA;
    }