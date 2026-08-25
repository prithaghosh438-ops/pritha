class Solution{
    public:
    int maximumWealth(vector<vector<int>>& accounts){
        int m=accounts.size();
        int n=accounts[0].size();
        int i,sums=0,sum1=0;
        for(i=0;i<m;i++){
            int sum=0,j=0;
            while(j<n){
                sum=sum+accounts[i][j];
                j++;
            }
            if(sum1<sum){
                sum1=sum;

            }
            else sums=sum;
        }
        if(sum1>sums)return sum1;
        else return sums;
    }
};