class Solution {
public:
    double calcAverage(queue<int>& q) {
        double res = 0.;
        double size = q.size();
        for(int i = 0; i < size; i++) {
            int num = q.front();
            res += num;
            q.pop();
            q.push(num);
        }
        return res / size;
    }
    
    double findMaxAverage(vector<int>& nums, int k) {
        queue<int> q;
        for(int i = 0; i < k; i++) {
            q.push(nums[i]);
        }
        double maxAverage = calcAverage(q);
        for(int i = k + 1; i < nums.size(); i++) {
            q.pop();
            q.push(nums[i]);
            double currAverage = calcAverage(q);
            if(maxAverage < currAverage) {
                maxAverage = currAverage;
            }
        } 
        return maxAverage;
    }
};
