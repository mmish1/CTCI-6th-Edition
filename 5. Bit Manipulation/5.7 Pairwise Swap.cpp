/*Q5.7) Pairwise Swap: Write a program to swap odd and even bits in an integer with as few instructions as possible (e.g., bit O and 
		bit 1 are swapped, bit 2 and bit 3 are swapped, and so on). */
		
#include<iostream>

using namespace std;

int pairwiseSwap(int n){
	int mask=0xAAAAAAAA;
	return (((n&mask)>>11)|((n&(mask>>1))<<1));
}

main(){
	int n;
	cout<<"Enter an integer: ";
	cin>>n;
	cout<<"The number after swapping all odd and even bits is: "<<pairwiseSwap(n)<<endl;
	return 0;
}
