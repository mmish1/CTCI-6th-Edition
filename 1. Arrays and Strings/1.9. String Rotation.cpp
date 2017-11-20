/*Q1.9) String Rotation: Assumeyou have a method isSubstring which checks if one word is 
		a substring of another. Given two strings, sl and s2, write code to check if 
		s2 is a rotation of sl using only one call to isSubstring 
		(e.g., "waterbottle" is a rotation of"erbottlewat"). */

#include<iostream>
#include<string>
using namespace std;

bool isSubstring(string s1, string s2){
	if(s1.length()!=s2.length()) return false;
	if(s1==s2) return true;
	string c=s1+s1;
	if(c.find(s2)!=string::npos) return true;
	else return false;
}

main(){
	string s1,s2;
	s1="waterbotwle";
	s2="erbotwlewat";
	cout<<"Is "<<s1<<" a rotation of "<<s2<<"? ";
	if(isSubstring(s1,s2)) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	
	s1="waterbotwle";
	s2="arbotwlewat";
	cout<<"Is "<<s1<<" a rotation of "<<s2<<"? ";
	if(isSubstring(s1,s2)) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	
	return 0;
}
