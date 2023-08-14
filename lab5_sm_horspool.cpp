#include <bits/stdc++.h>

using namespace std;

int main()
{
	string t,p;
	cout << "Enter string" << endl;
	cin >> t;
	cout << "Enter pattern to match" << endl;
	cin >> p;
    
	int n = t.length();
	int m = p.length();
	//cout << n << " " << m << endl;
    
    
	//preprocessing and making shift table
	int shift[26];
    
	for(int i=0; i<26; i++){
    	shift[i] = m;
	}
    
	for(int i=0; i<=m-2; i++){
    	shift[p[i]-'a'] = m-1-i;
	}
    
	// for(int i=0; i<26; i++){
	// 	cout << shift[i] << " " ;
	// }

    
	int j = 0;
	while(j + m <= n){
   	 
    	//if last chaarcter is match
    	if(t[j+m-1] == p[m-1]){
       	 
        	//now see for remaining one
        	int i = m-2;
        	while(i >= 0 && t[j+i] == p[i]){
            	i--;
        	}
       	 
        	//if in betwwen it is not matched
        	if(i == -1){
            	cout << "pattern fount at : " << j << endl;
        	}
    	}
   	 
   	 
    	if(t[j+m-1] == '_' || t[j+m-1] == ' ' || t[j+m-1] == '.'){
        	j += m;
    	}
    	else{
        	//shift j with char shift from table
        	j = j + shift[t[j+m-1]-'a'];
    	}
	}

	return 0;
}
