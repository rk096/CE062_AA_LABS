#include <bits/stdc++.h>

using namespace std;

struct point{
	int x;
	int y;
};


int main()
{
	int n;
	cout << "Enter no of points" << endl;
	cin >> n;
    
	int dmin = INT_MAX;
	int ansi = 0, ansj = 0;
    
	point p[n];
    cout << "Enter points" << endl;
	for(int i=1; i<=n; i++){
    	cin >> p[i].x >> p[i].y;
	}
    
   for(int i=1; i<=n; i++){
  	 
   	for(int j = i+1; j<=n; j++){
      	 
      	 //assign co-ordinate so we can computr distance 
       	int x1 = p[i].x;
       	int x2 = p[j].x;
       	int y1 = p[i].y;
       	int y2 = p[j].y;
      	 
      	 //this will find distance between two pints
       	int d = sqrt(((x1-x2) * (x1-x2)) + ((y1-y2) * (y1-y2)));
      	 //cout << d;
      	 
       	if(d < dmin){
           	dmin = d;
           	ansi = i;
           	ansj = j;
       	}
   	}
  	 
   	                                                                                                   	 
   }
   cout <<  "minimum distance is : " << dmin << endl;
   	cout  << "minimum distance at " << ansi   << " " << ansj << endl;  

	return 0;
}
