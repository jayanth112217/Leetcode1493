class Solution {
public:
    int longestSubarray(vector<int>& nums) {
     int cnt=0;
     int n = nums.size();
     int j=0;
     int flag=0;
     for(int i=0;i<n-1;i++){
       if(nums[i]!=0) continue;
       else{
           flag=1;
           int k;
           if(nums[j]==1) k=j;
           else k=j+1;
           int count=0;
           while(1){
               if((k>i && nums[k]==0) || k>n-1) break;
               if(k==i) {
                   k++;
                   continue;
               }
               if(nums[k]!=0){
                count++;
                if(k==n-1) break;
                 k++;
               }
           }
           cnt = max(cnt,count);
           if(nums[i]==0 && i>0) j=i+1;
       }
     }
     if(flag==0) return n-1;
     return cnt;   
    }
};