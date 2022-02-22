class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        int n = s.length();
        bool dp[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j] = false;
            }
        }
        int max = 1, max_i = 0, max_j = 0;
        for(int i=0;i<n-1;i++)
        {
            dp[i][i] = true;
            dp[i][i+1] = (s[i]==s[i+1]);
            if(dp[i][i+1])
            {
                max = 2;
                max_i = i;
                max_j = i+1;
            }
        }
        dp[n-1][n-1] = true;
        
        for(int i=n-3;i>=0;i--)
        {
            for(int j=n-1;j>i+1;j--)
            {
                dp[i][j] = (dp[i+1][j-1] && (s[i]==s[j]));
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j])
                {
                    if(j-i+1>max)
                    {
                        max = j-i+1;
                        max_i = i;
                        max_j = j;
                    }
                }
            }
        }
        return s.substr(max_i,max);
    }
};
