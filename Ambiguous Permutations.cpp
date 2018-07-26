#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	
	int length;
	
	while(true)
	{
	    cin >> length;
	    std::string result;
	    
	    if(length == 0)
	        break;
	   
	    int arr[length];
	    int invArr[length];
	   
	    for(int i=0; i < length; i++)
	    {
	        cin >> arr[i];
	        
	        invArr[arr[i]-1] = i+1;
	    }
	    
	    bool isSame = true;
	    
	    for(int i = 0; i < length; i++)
	    {
	        if(arr[i] != invArr[i])
	        {
	            isSame = false;
	            break;
	        }
	    }
	    
	    if(isSame)
	        cout << "ambiguous" << endl;
	    else
	        cout << "not ambiguous" << endl;
	}
	
	return 0;
}
