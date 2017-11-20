/*Q1.4) Palindrome Permutation: Given a string, write a function to check 
		if it is a permutation of a palindrome. A palindrome is a word or 
		phrase that is the same forwards and backwards. A permutation is a 
		rearrangement of letters. The palindrome does not need to be limited to just dictionary words. 

		EXAMPLE Input: Tact Coa Output: True 
				(permutations: "taco cat", "atco eta", etc.)*/


#include<iostream>
#include<cstring>
#include<string>

using namespace std;

bool isPalindrome(string s){
	int i=0,j=s.length()-1;
	while(i<=j){
		if(s[i]==' ') i++;
		if(s[j]==' ') j--;
		if(s[i]!=s[j]){
			return false;
		} 
		i++;
		j--; 
	}
	return true;
}

bool palindromePermutationHelper(string s,string prefix,bool &res){
	if(s.length()==0){
		if(isPalindrome(prefix)) res=true;
		return res;
	}
	else{
		for(int i=0;i<s.length();i++){
			string x=s.substr(0,i)+s.substr(i+1);
			palindromePermutationHelper(x,prefix+s[i],res);
			if(res) return res;
		}
	}
}

bool palindromePermutation(string s){
	bool r=false;
	for(int i=0;i<s.length();i++){
		s[i]=tolower(s[i]);
	}
	r=palindromePermutationHelper(s,"",r);
	return r;
}

main(){
	if(palindromePermutation("taco cati")){
		cout<<"yes"<<endl;
	}
	else cout<<"no"<<endl;
	
	return 0;
	
}
