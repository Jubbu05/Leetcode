class data{
    public:
    int val, apos, vpos;
    data(int v, int ap, int vp){
        val = v;
        apos = ap;  //array position
        vpos = vp; //position of value in array
    }
};
struct mycomp{
    bool operator()(data &d1, data &d2){
        return d1.val > d2.val; //this will create minheap
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        vector<int> ans;
        priority_queue<data, vector<data>, mycomp> pq;
        
        for(int i=0; i<k; i++){
            data d(arr[i][0], i, 0); //insert first col
            pq.push(d);
        }
        
        while(!pq.empty()){
            data curr = pq.top();
            pq.pop();
            ans.push_back(curr.val);
            int ap = curr.apos;
            int vp = curr.vpos;
            
            if(vp+1 < arr[ap].size()){
                data d(arr[ap][vp+1], ap, vp+1);
                pq.push(d);
            }
        }
        return ans;
    }
};