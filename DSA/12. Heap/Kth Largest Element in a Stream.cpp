class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap to store the k largest elements
    int gk; // The value of k

    KthLargest(int k, vector<int>& nums) {
        gk = k;

        // Initialize the min-heap with the first k elements from the input  
        for(auto x : nums){
            if(minHeap.size() < k) minHeap.push(x); // Push the element into the min-heap if its size is less than k
            if(minHeap.size() > k) minHeap.pop(); // If the size of the min-heap exceeds k, remove the smallest element
        }
    }
    
    int add(int val) {
        minHeap.push(val); // Add the new element to the min-heap

        if(minHeap.size() > gk) minHeap.pop(); // If the size of the min-heap exceeds k, remove the smallest element

        return minHeap.top(); // Return the current kth largest element
    }
};
