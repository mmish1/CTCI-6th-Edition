/*Q5.4) Next Number: Given a positive integer, print the next smallest and the next largest number that have the 
		same number of 1 bits in their binary representation. */

#include<iostream>

using namespace std;

int getPrev(int n){
	int ncopy=n;
	int nZero=0, nOne=0, p;
	while((ncopy&1) == 1){
		nOne++;
		ncopy>>=1;
	}
	
	if(ncopy==0) return -1;
	
	while(((ncopy&1) == 0) && (ncopy!=0)){
		nZero++;
		ncopy>>=1;
	}
	p=nZero+nOne; 
	n&=-1<<(p+1); //clear bits p to 0;
	int mask=(1<<(nOne+1))-1; //set nOne+1 bits;
	n|=mask<<(nZero-1); //set first nOne+1 bits after p in n;
	return n;
}

int getNext(int n){
	int ncopy=n;
	int nZero=0, nOne=0, p;
	while(((ncopy&1)==0) && (ncopy!=0)){
		nZero++;
		ncopy>>=1;
	}
	
	while((ncopy&1)==1){
		nOne++;
		ncopy>>=1;
	}
	
	if(nZero+nOne==31 || nZero+nOne==0) {
		return -1;
	}
	//cout<<nZero<<" "<<nOne;
	p=nZero+nOne;
	n|=(1<<p); //set bit at p
	n&=(-1<<p); //clear bits p+1 to 0;
	int mask=(1<<(nOne-1))-1; //set nOne-1 bits
	n|=mask; //set bits 0 to nOne-1
	
	return n;	
}

main(){
	int n;
	do{
		cout<<"Enter a positive integer: ";
		cin>>n;
	}while(n<0);
	
	cout<<"Next smallest number with the same number of 1s in binary: "<<getPrev(n)<<endl;	
	cout<<"Next largest number with the same number of 1s in binary: "<<getNext(n)<<endl;
	
	return 0;
}
