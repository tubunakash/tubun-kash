    import java.io.*;
    class Main{
    	public static void main(String[] args)throws IOException{
    		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    		int count,t=Integer.parseInt(br.readLine());
    		String a;
    		while(t-->0){
    			a=(br.readLine());
    			count=(a.replace("4","00")).length()-a.length();
    			System.out.println(count);						
    		}
    	}
    } 