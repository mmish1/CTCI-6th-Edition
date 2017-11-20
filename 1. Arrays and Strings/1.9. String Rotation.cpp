/*Q1.9) String Rotation:Assumeyou have a method isSubstringwhich checks ifoneword is 
		a substring of another. Given two strings, sl and s2, write code to check if 
		s2 is a rotation of sl using only one call to isSubstring 
		(e.g., "waterbottle" is a rotation of"erbottlewat"). */

#include<iostream>
#include<string>
using namespace std;

bool rotateString(string s1, string s2){
	if(s1.length()!=s2.length()) return false;
	if(s1==s2) return true;
	string c=s1+s1;
	if(c.find(s2)!=string::npos) return true;
	else return false;
}

main(){
	if(rotateString("waterbotwle","erbotwlewat")) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	
	if(rotateString("waterbotwle","arbotwlewat")) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	
	return 0;
}
