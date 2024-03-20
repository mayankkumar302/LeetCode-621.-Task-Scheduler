class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        // t.c. O(N) + log(size i.e. 26) for max heap
        
        priority_queue<int>pq; // max heap

        vector<int>mpp (26,0);

        for (int i=0;i<tasks.size();i++){
            mpp[tasks[i]-'A']++;
        }
        for (int i=0;i<26;i++){
            if (mpp[i]>0){
                pq.push(mpp[i]);
            }
        }


        int time=0;
        while (!pq.empty()){
            vector<int>temp;

            for (int i=1;i<=1+n;i++){

                if (!pq.empty()){
                    temp.push_back(pq.top()-1);
                    pq.pop();
                }
            }
            for (int a:temp){
                if (a>0){
                    pq.push(a);
                }
            }

            if (pq.size()>0){
                time+=(n+1);
            }
            else if (pq.size()==0){
                time+=(temp.size());
            }
        }
        return time;
    }
};
