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
    
    
    
    for(int s=0; s<=(n-m); s++){
   	 int i=1;
   	 
   	 //compare every window char with pattern
   	 while(i <= m && t[s+i] == p[i] ){
   		 i++;
   	 }
   	 
   	 
   	 if(i == m+1){
   		 cout << "pattern matched" << endl;
   		 cout << "shift occures at index : " << s << endl;
   		 return 0;
   	 }
    }
    
    cout << "pattern doesn't match" << endl;

    return 0;
}
