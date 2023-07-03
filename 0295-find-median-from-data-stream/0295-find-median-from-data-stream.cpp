class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.empty() || num<maxheap.top()) maxheap.push(num);
        else minheap.push(num);

        if(maxheap.size()>minheap.size()+1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(maxheap.size()+1<minheap.size())
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }

    }
    
    double findMedian() {
        if(minheap.size()==maxheap.size())
        {
            if(minheap.size()==0) return 0;
            else return (maxheap.top()+minheap.top())/2.0;
        }
        else if(minheap.size()>maxheap.size()) return minheap.top();
        else return maxheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */