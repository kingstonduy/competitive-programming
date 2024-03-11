class Solution {
    public static int min(int a, int b)
    {
        return (a<=b)?a:b;
    }
    public int minFallingPathSum(int[][] matrix) {
        int res=10000000;
        var pre= new int[matrix.length];
        for(int i=0;i<matrix.length;i++)
        {
            var a= new int[matrix.length];
            for(int j=0;j<matrix.length;j++)
            {
                a[j]= pre[j];
                if(j-1>=0)  a[j]=min(a[j], pre[j-1]);
                if(j+1<matrix.length)   a[j]= min(a[j], pre[j+1]);
                a[j]+=matrix[i][j];
                if(i==matrix.length-1)  res=min(res, a[j]);
            }
            pre=a;
        }
        return res;

    }
}