class Solution {
public:
   
    int myAtoi(string s) {
	// here we input all necessary variables
        long int num =0; //our number to be returned
        int n=s.size(); //size of the string
        long int minimum = INT_MIN; //minimum possible value
        long int maximum = INT_MAX; //maximum possible value
        int neg=0; // to check if the number is negative
        int check=0; // to check if we got the numbers before encountering any words
		
		//lets just skip all the spaces in the front
        int i=0;
        while(s[i]==' ')
                i++;
        
		
		//now we might get a sign or may not get a sign 
        if(s[i]=='-' || s[i]=='+')
        {
		//we check if we get a neg sign and mark it in our neg variable
            if(s[i]=='-')
                neg=1;
				//lets move to next
                i++;
        }
		
		//lets traverse to find our number now
       while(i<n){
	   
	       //if we encounter a '.' we dont do anything beyond this since we need to return an integer.
            if(s[i]=='.')
                break;
			
      //checking if this is a number now
            if( (s[i]>='0' && s[i]<='9')){
                count=1;
				//required operations to convert it into an integer
                num = (num*10) + (long int)(s[i]-'0');
				
				//num has our number now so we check if it is becoming greater than maximum
				//num is a positive number till now
				//if it is we dont have to do anything more because it will be out of range
                if(num>=maximum){
                    break;
                }
              }
			 // now if the character is not an integer than it might be that we got our required number 
			 //or it might be that we didnot get it yet.
          else{
		  // if we got already then lets not go further we will get only words or unuseful words
                if(count!=0)
                  break; 
                else
			// if we have not got a number before then it is the first time we are getting a word so we return 0 
			//since it will be useless to go any further
                    return 0;
            }
			// move to next
			i++;
        }
		
		//after everything we got the absolute value of our number so check if that is to be made negative
        if(neg==1){
		//make it negative if it is to be made
            num = -1*num;
        }
		 //we will use the below function for clamping that is if something outpasses a range
         //so print the max or min possible value in the range
         //clamping - max(minimum, min(maximum, a))
        return (int)max(minimum, min(maximum, num));
    }
};