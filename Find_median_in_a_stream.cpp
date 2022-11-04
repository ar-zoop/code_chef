class Solution
{
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int> >  min_heap;
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(max_heap.empty() || max_heap.top()>x){
            max_heap.push(x);
        }
    
        else{
            min_heap.push(x);
        }
        if(max_heap.size()-min_heap.size()>1){
            balanceHeaps();
        }
        else if(min_heap.size()>max_heap.size()){
            balanceHeaps();
        }
        
        getMedian();
        
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(max_heap.size()>min_heap.size()){
            // cout<<max_heap.top()<<" "<<min_heap.top()<<endl;
            // cout<<"here";
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else{
            // cout<<"no here";
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if((max_heap.size()+min_heap.size())%2==0){
            return (max_heap.top()+min_heap.top())/2.0;
        }
        else
            return max_heap.top();
    }
};