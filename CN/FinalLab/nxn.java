import java.io.*;
import java.util.*;
import java.math.*;

public class normal
{
	public int unique(int a[])
	{
		int temp,i,j,count=1;
		 
        for(i = 0; i <a.length; i++)
        {
            for(j = 1; j<(a.length -i); j++)
            {
                if(a[j-1]>a[j])
                {
                    temp = a[j-1];
                    a[j-1]=a[j];
                    a[j]=temp;
                }
            }
        }
        
        for(i=1;i<a.length;i++)
        {
        	if(a[i]!=a[i-1])
        		count++;
        }
        
        return count;
	}
	public static void main(String ar[])throws Exception
	{
		BufferedReader kk=new BufferedReader(new InputStreamReader(System.in));
		
		normal dd=new normal();
		int i,j,k,m,n=10,nm;
		double sum=0,rn,thro,uni;
		
		for(i=1;i<=n;i++)
		{
			int a[]=new int[i];
			int count[]=new int[i];
			
			sum=0;
			for(j=0;j<50000;j++)
			{
				uni=0;
				for(k=0;k<i;k++)
				{
					rn=Math.random();
					nm=(int)(rn*i);
					a[k]=nm;
					count[nm]++;
					
				}
				//uni=(double)(dd.unique(a));
				for(m=0;m<i;m++)
				{
					if(count[m]>0)
					{
						uni=uni+1;
						count[m]--;
					}
				}
				sum=sum+uni/i;
				//System.out.println(sum);
	
			}
			
			thro=sum/50000;
			System.out.println("throughput of "+ (i) + " = " + thro);
			
		}
	}
}