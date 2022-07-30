class MedianFinder {
public:
    
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    int size;
    
    MedianFinder() {
        size=0;
    }
    
    void addNum(int num) {
        size++;
        if(size==1)
        {
            maxh.push(num);
            return;
        }
        if(maxh.top()>=num)
            maxh.push(num);
        else
            minh.push(num);
        
        if(size%2==0){
            if(minh.size()!=maxh.size()){
                minh.push(maxh.top());
                maxh.pop();
            }    
        }
        else{
            if(maxh.size()<minh.size()){
                maxh.push(minh.top());
                minh.pop();
            } 
        }
    }
    
    double findMedian() {
        
        if(size==0)
            return 0;
        
        if(size%2==0)
            return (maxh.top()+minh.top())/2.0;
        else
            return maxh.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */