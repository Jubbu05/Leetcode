class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap to store the larger half of the numbers
    priority_queue<int> maxHeap; // Max-heap to store the smaller half of the numbers

    MedianFinder(){}

    void addNum(int num) {
        if (maxHeap.empty() or maxHeap.top() > num) {
            maxHeap.push(num); // Add the number to the max-heap if it is smaller than the current largest number in the max-heap
        } else {
            minHeap.push(num); // Add the number to the min-heap if it is greater than or equal to the current largest number in the max-heap
        }

        // Balance the heaps by ensuring the size difference between them is at most 1
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top()); // Move the largest number from the max-heap to the min-heap
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top()); // Move the smallest number from the min-heap to the max-heap
            minHeap.pop();
        }
    }
    
    double findMedian() {
		//even length so median will be average max form maxHeap and min from minHeap
        if (maxHeap.size() == minHeap.size()) {
            if (maxHeap.empty()) {
                return 0;
            } else {
                double avg = (maxHeap.top() + minHeap.top()) / 2.0;
                return avg;
            }
        } else {
			//odd length so median will be maxHeap top
            return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top(); // Return the top element of the heap with the larger size as the median
        }
    }
};
