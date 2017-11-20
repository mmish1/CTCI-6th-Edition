/*Q1.5) One Away: There are three types of edits that can be performed on strings: insert a character, 
				  remove a character, or replace a character. Given two strings, write a function to 
				  check if they are one edit (or zero edits) away. 
				  EXAMPLE pale, ple -> true 
						  pales, pale -> true 
						  pale, bale -> true 
						  pale, bake -> false*/

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

bool isOneEdit(string s1, string s2){
	if(abs(s1.length()-s2.length())>1) return false;
	if(s1==s2) return true;
	bool c=false;
	int l1=s1.length();
	int l2=s2.length();
	string b=l1<l2?s2:s1; 
	string s=l1<l2?s1:s2;
	int i=0,j=0;
	cout<<s<<" "<<b<<"\n";
	while(i<s.length() && j<b.length()){
		if(s[i]!=b[j]){
			if(c) {
				return false;	
			}
			c=true;
			if(l1==l2) i++;
		}
		else{
			i++;
		}
		j++;
	}
	return true;
}

main(){
	if(isOneEdit("pale","ple")) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	
	if(isOneEdit("pales","pale")) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	
	if(isOneEdit("pale","base")) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	
	if(isOneEdit("pale","bake")) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	
	return 0;
}
