/*Q5.2) Binary to String: Given a real number between O and 1 (e.g., 0.72) that is passed 
		in as a double, print the binary representation. If the number cannot be represented 
		accurately in binary with at most 32 characters, print "ERROR:*/

#include<iostream>
#include<string>

using namespace std;

string binaryToString(double n){
	string res="0.";
	int i=2;
	while(n!=double(0) && i<32){
		n=n*2;
		res+=(int(n)==1?"1":"0");
		i++;
		n-=int(n);
	}
	if(i==32) res="ERROR";
	return res;
}

main(){
	double ip;
	cout<<"Enter a number between 0 and 1: ";
	cin>>ip;
	cout<<"Binary Rep = "<<binaryToString(ip);
	return 0;
}
