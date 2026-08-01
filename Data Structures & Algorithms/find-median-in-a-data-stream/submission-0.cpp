class MedianFinder {
    priority_queue<int, vector<int>, less<int>> smaller;
    priority_queue<int, vector<int>, greater<int>> larger;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        smaller.push(num);
        if (!larger.empty() && smaller.top()>larger.top()){
            larger.push(smaller.top());
            smaller.pop();
        }
        if (smaller.size()>larger.size()+1){
            larger.push(smaller.top());
            smaller.pop();
        }
        if(larger.size()>smaller.size()+1){
            smaller.push(larger.top());
            larger.pop();
        }
    }
    
    double findMedian() {
        if (smaller.size()==larger.size()){
            return (smaller.top()+larger.top())/2.0;
        }
        else if(smaller.size()==larger.size()+1) return smaller.top();
        else return larger.top();
    }
};
