class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int>dp1(n),dp2(n);
        int x=nums[n-1];
        
        // nums[n-1]=0;
        dp1[0]=nums[0],dp1[1]=max(nums[1],dp1[0]);
        for(int i=2;i<n;i++){
            int a=nums[i]+dp1[i-2];
            dp1[i]=max(a,dp1[i-1]);
        }
        nums[n-1]=x;
        nums[0]=0;
        dp2[0]=nums[0],dp2[1]=max(nums[1],dp2[0]);
        for(int i=2;i<n;i++){
            dp2[i]=nums[i]+dp2[i-2];
            dp2[i]=max(dp2[i],dp2[i-1]);
        }
        return max(dp1[n-1],0);

    }
};
