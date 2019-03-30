#include<iostream>
using namespace std;

bool _isPal(string s, short i, short j){
	if(i>=j) return true;
	return (s[i]==s[j] && _isPal(s,i+1,j-1));
}


bool _isPal(string s, short i){
	cout << "chiamata" << endl;
	if(i>=s.length()-i-1) return true;
	return (s[i]==s[s.length()-i-1] && _isPal(s,++i));
}

bool isPal(string s){
	return _isPal(s,0);
}

int main(){
    
    string s = "abba";
    
    if(isPal(s)) cout << "Palindroma";
    else cout << "NON Palindroma";

return 0;
}


