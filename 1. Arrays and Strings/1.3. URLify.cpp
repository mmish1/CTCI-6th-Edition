/*Q1.3) URLify: Write a method to replace all spaces in a string with '%20'. 
		You may assume that the string has sufficient space at the end to hold the 
		additional characters, and that you are given the "true" length of the string. 
		(Note: If implementing in Java, please use a character array so that you can 
		perform this operation in place.) 
		EXAMPLE Input: "Mr John Smith ", 13 
				Output: "Mr%20John%20Smith"*/


#include<iostream>
#include<cstring>
#include<string>

using namespace std;

class URLify{
	string x;
	public:		
		void convert_extra_space(string s, int l){
			x=s;
			for(int i=0;i<l;i++){
				if(s[i]==' ') x=x.substr(0,i)+"%20"+s.substr(i+1);
			}
		}
		
		void convert_in_space(string &s, int l){
			int j=l-1, i=s.length()-1;
			while(i>=0){
				if(s[j]!=' '){
					s[i--]=s[j];
				}
				else if(s[j]==' '){
					s[i--]='2';
					s[i--]='0';
					s[i--]='%';
				}
				j--;
			}
		}
		
		void display(){
			cout<<x<<endl;
		}
};

main(){
	string d="Mr India number 1      ";
	URLify s;
	s.convert_extra_space(d,17);
	s.display();
	s.convert_in_space(d,17);
	cout<<d<<endl;
	return 0;
}
