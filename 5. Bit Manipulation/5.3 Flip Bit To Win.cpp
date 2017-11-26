/*Q5.3) Flip Bit to Win: You have an integer and you can flip exactly one bit from a 0 to a 1. Write 
		code to find the length of the longest sequence of 1s you could create. 
		EXAMPLE Input: 1775 (or: 11011101111)
				Output: 8 */
				
#include<iostream>

using namespace std;

int longestSeq(int n){
	if(n==-1) return 8;
	int currCount=0;
	int prevCount=0;
	int maxSeq=0;
	while(n){
		if(n&1){
			currCount++;
		}
		else{
			if((n>>1)&1) prevCount=currCount;
			else prevCount=0;
			currCount=0;
		}
		maxSeq=max(prevCount+currCount+1, maxSeq);
		n>>=1;
	}
	return maxSeq;
}

main(){
	int n;
	cout<<"Enter an integer: ";
	cin>>n;
	cout<<"Longest Seequence of 1s after flipping one bit in "<<n<<" : "<<longestSeq(n);
	
	return 0;
}
