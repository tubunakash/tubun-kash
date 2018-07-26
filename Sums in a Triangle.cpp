#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	
	int testCases,numberOfRows;
	
	cin >> testCases;
	
	while(testCases > 0)
	{
	    cin >> numberOfRows;
	    
	    int triangleSize = (numberOfRows*(numberOfRows + 1))/2;
	    
	    int arr[triangleSize];
	    
	    int maxSum = 0;
	    
	    for(int i = 0; i<triangleSize; i++)
	    {
	        cin >> arr[i];
	    }
	    
	    if(triangleSize == 1)
	    {
	        cout << arr[0] << endl;
	    }
	    else
	    {
	        for(int i = 1; i < numberOfRows; i++)
	        {
	            int loopStart = (i*(i+1))/2;
	            int loopEnd = ((i+1)*(i+2))/2;
	            int loopItr = 0;
	            for(int j = loopStart; j < loopEnd; j++)
	            {
	                if(loopItr == 0)
	                {
	                    arr[j] = arr[j] + arr[j-i];
	                    if(maxSum < arr[j])
	                        maxSum = arr[j];
	                }
	                else if(loopItr == i)
	                {
	                    arr[j] = arr[j] + arr[j-i-1];
	                    if(maxSum < arr[j])
	                        maxSum = arr[j];
	                }
	                else
	                {
	                    if(arr[j-i] > arr[j-i-1])
	                    {
	                        arr[j] = arr[j] + arr[j-i];
	                        if(maxSum < arr[j])
	                            maxSum = arr[j];
	                    }
	                    else
	                    {
	                        arr[j] = arr[j] + arr[j-i-1];
	                        if(maxSum < arr[j])
	                            maxSum = arr[j];
	                    }
	                }
	                
	                loopItr++;
	            }
	        }
	        
	        cout << maxSum << endl;
	    }
	    
	    testCases --;
	}
	
	return 0;
}
