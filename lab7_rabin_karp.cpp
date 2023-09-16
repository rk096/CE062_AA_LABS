#include <bits/stdc++.h>

using namespace std;

int power(int a,int n ,int p ){
    int res = 1;
    a = a % p;
    
    while(n > 0){
   	 if(n % 2 != 0){
   		 res = (res*a) % p;
   	 }
   	 n = n/2;
   	 a = (a*a) % p;
    }
    return res;
}

void rabin_karp(string text, string pattern, int q){
    
	int m = pattern.length();
	int n = text.length();
    
	int p = 0, t = 0, d = 10;
    
	int h = power(d,m-1,q);

	for(int i=0; i<m; i++){
    	p = (( d * p) + ( pattern[i]-'0' )) % q;
    	t = (( d * t) + ( text[i]-'0' )) % q;
	}

	cout << p << " " << t << endl;

	for(int s=0; s<=(n-m); s++){
  	 
    	if(p == t){
  	    	 
  	     	if(pattern == text.substr(s,m)){
  	         	cout << s;
   		 }

    	}
    	if(s < (n-m)){
         	t = (( t - (text[s]-'0') * h) * d + (text[s+m] - '0')) % q;
         	if(t < 0){
            	t += q;
        	}
    	}
	}              	 

}

int main(){

	string text, pattern;
	int q;
	cout << "Enter text :" << endl;
	cin >> text;
	cout << "Enter pattern : " << endl;
	cin >> pattern;
	cout << "Enter q :" << endl;
	cin >> q;

	rabin_karp(text,pattern,q);
   

	return 0;
}


