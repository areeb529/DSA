class MedianFinder {
public:
    priority_queue<int> maxQ;
    priority_queue<int,vector<int>,greater<int>> minQ;
    
    MedianFinder() {
    
    }
    void addNum(int num) {
        if(maxQ.size()==minQ.size()){
            maxQ.push(num);
        }
        else{
            minQ.push(num);
        }
        minQ.push(maxQ.top());
        maxQ.pop();
        maxQ.push(minQ.top());
        minQ.pop();
    }
    
    double findMedian() {
        double median=0.0;
        if(maxQ.size()==minQ.size()){
            median=(maxQ.top()+minQ.top())/2.0;
        }
        else{
            median=maxQ.top();
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */