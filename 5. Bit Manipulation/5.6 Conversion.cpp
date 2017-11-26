/*Q5.6) Conversion: Write a function to determine the number of bits you would need to flip to convert integer A to integer B. 
		EXAMPLE Input: 29 (or: 11101), 15 (or: 01111) 
			Output: 2 */

#include<iostream>

using namespace std;

int conversion(int a, int b){
	int count=0;
	int mask=1;
	while(a || b){
		if((a&1)^(b&1)) {
			count++;
		}
		a>>=1;
		b>>=1;
	}
	return count;
}

main(){
	int a,b;
	cout<<"Enter two integers: ";
	cin>>a>>b;
	cout<<"Number of bits to flip so A->B = "<<conversion(a,b);
	
	return 0;
}
