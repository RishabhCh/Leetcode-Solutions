class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        if(numRows==1)
        {
            return s;
        }
        char zz[numRows][s.length()];
        string resultstr = "";
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<s.length();j++)
            {
                zz[i][j]='0';
            }
        }
    
    int k=0,i=0,j=0,incr=0;
    
    while(k<s.length())
    {
        if(incr==0)
        {
            zz[i++][j] = s[k++];
        }
        else if(incr==1)
        {
            zz[i--][j++] = s[k++];
        }
        if(i==numRows)
        {
            incr=1;
            i-=2;
            j++;
        }
        if(i<0)
        {
            incr=0;
            i+=2;
            j--;
        }
    }
    
    for(int i=0;i<numRows;i++)
    {
        for(int j=0;j<s.length();j++)
        {
            if(zz[i][j]!='0')
            {
                resultstr+=zz[i][j];
            }
        }
    }
    
    return resultstr;
  }
};
