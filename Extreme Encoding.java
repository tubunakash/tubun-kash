        import java.util.*;
        class Extreme_encoding
        {
        	public static void main(String[]args)
        	{
        		int t;
        		Scanner sc=new Scanner(System.in);
        		t=sc.nextInt();
        		for(int l=1;l<=t;l++)
        		{
        			int n;
        			n=sc.nextInt();
        			int[] a=new int[n];
        			int[] b=new int[n];
        			for(int i=0;i<n;i++)
        			{
        				int p;
        				p=sc.nextInt();
        				String s=Integer.toBinaryString(p);
        				a[i]=p&((1<<16)-1);
    	            		b[i]=(p>>16);
        			}
        			System.out.println("Case "+l+":");
        			for(int i=0;i<n;i++)
        				System.out.print(a[i]+" ");
        			System.out.println();
        			for(int i=0;i<n;i++)
        				System.out.print(b[i]+" ");
        			System.out.println();
        		}
        	}
        }  