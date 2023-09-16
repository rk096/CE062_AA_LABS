#include <bits/stdc++.h>

using namespace std;

void lps_table( string &p, vector<int> lps)
{
    int m = p.length();
    lps[0] = 0;
    int k = 0;
    
    for(int q=1; q<m; q++){
        
        while( k > 0 && p[q] != p[k]){
            k = lps[k-1];
        }
        if(p[q] == p[k]){
            k = k+1;
        }
        lps[q] = k;
    }
    
    
    //for lps table output
    // for(int i=0; i<m; i++){
    //     cout << lps[i] << " ";
    // }
    
}


void kmp_sm(string &t, string &p){
    
    int n = t.length();
    int m = p.length();
    
    vector<int> lps(m);
    
    
    lps_table(p,lps);
    
    int q = 0;
    
    for(int i=0; i<n; i++){
        
        while(q > 0 && p[q] != t[i]){
            q = lps[ q -1];
        }
        
        if(p[q] == t[i]){
            q++;
        }
        
        if(q == m){
            cout << "found string matching at shift : " << i - m + 1 << endl;
            q = lps[q - 1];
        }
    }
    
    
}



int main()
{
    string text, pattern;
    cout << "Enter text" << endl;
    cin >> text;
    
    cout << "Enter pattern" << endl;
    cin >> pattern;
    
    kmp_sm(text,pattern);
    
    

    return 0;
}





