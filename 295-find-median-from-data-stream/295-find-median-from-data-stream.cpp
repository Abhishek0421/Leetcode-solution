class MedianFinder {
public:
    priority_queue <int> max_heap;
    priority_queue <int , vector<int>,greater<int>> min_heap;
    
    MedianFinder() {}
    
    void addNum(int num) {
        max_heap.push(num);
        min_heap.push(max_heap.top());
        max_heap.pop();
        if(min_heap.size()>max_heap.size())
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        double ans=0;
        if((min_heap.size()+max_heap.size())%2!=0) 
        {
            ans=max_heap.top();
        }
        else
        {    ans=max_heap.top()+min_heap.top();
             ans/=2;
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */