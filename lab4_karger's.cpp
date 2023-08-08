#include <bits/stdc++.h>

using namespace std;

void mincut(int n, vector<vector<int>> g){
    
    while(n > 2){
        
    
// 	srand(time(NULL));
// 	int u = rand()% n;
// 	int v = rand()%n;
    
	vector<vector<int>> g1 = g;
	
	int u,v;
    cout<<"Enter Edge:"<<endl;
    cout<<"Enter U:"<<endl;
    cin>>u;
    cout<<"Enter V:"<<endl;
    cin>>v;
    int count =0;
    
    //find upper triangle
	for(int i=0; i<n; i++){
    	for(int j=i+1; j<n; j++){
        	count = 0;
        	
        	//if selected edge itself
        	if(i == u && j == v){
            	g1[i][j] = g1[j][i] = 0;
        	}
        	//one of the i match then try to contract it
        	else if(i == u || i == v){
           	 
            	if(g[u][j] > 0)
                	count += g[u][j];
            	if(g[v][j] > 0)
                	count += g[v][j];
               	 
            	(u < j) ? g1[u][j] = count : g1[j][u] = count;
               	 
            	(v < j) ? g1[v][j] = count : g1[j][v] = count;
           	 
        	}
        	//one of the j match then try to contarct it
        	else if(j == u || j == v){
           	 
            	if(g[u][i] > 0)
                	count += g[u][i];
            	if(g[v][i] > 0)
                	count += g[v][i];
               	 
            	(i < u) ? g1[i][u] = count : g1[u][i] = count;
           	 
            	(i < v) ? g1[i][v] = count : g1[v][i] = count;
        	}
        	else{
            	g1[i][j] = g[i][j];
        	}
    	}
	}
    
        
        // 	cout << "graph g1 is: " << endl;
    	   // for(auto x : g1){
		      //  for(auto y: x){
        // 	        cout << y << " ";
	       // 	}
	       //	    cout << endl;
	       //}
        
        
        //now we are assign value to the lower triangle
    	for(int i=0; i<n; i++){
        	for(int j=0; j<n; j++){
            	if(i >= j){
                	g1[i][j] = g1[j][i];
            	}
        	}
    	}
    	
    	cout << "graph g1 is: " << endl;
    	    for(auto x : g1){
		        for(auto y: x){
        	        cout << y << " ";
	        	}
	       	    cout << endl;
	       }
    	
    	int x  = n-1;
    	int a = 0, b = 0;
    	vector<vector<int>> g2 (x, vector<int>(x,0));
    	
    	//remove vth row and vth coloum from graph g1 and assign it to a g2
    	for(int i=0; i<n; i++){
    	   
    	       if(i == v)
    	            continue;
    	       b = 0;
    	       
    	       for(int j=0; j<n; j++){
    	           if(j == v)
    	            continue;
    	           else if(i != v && j != v){
    	               g2[a][b] = g1[i][j];
    	               b++;
    	           }
    	       }
    	       a++;
    	}
    	
    	cout << "graph g2 is: " << endl;
    	    for(auto x : g2){
		        for(auto y: x){
        	        cout << y << " ";
	        	}
	       	    cout << endl;
	       }
    	
    	//assign g2 into g so g = g2
    	for(int i=0; i<x; i++){
    	    for(int j=0; j<x; j++){
    	        g[i][j] = g2[i][j];
    	    }
    	}
    	
    	n --;
    
    }
    
    cout << "min cut is : " << g[0][1];
    
    
}

int main()
{
    
    
	int n;
	cout << "enter no of vertices" << endl;
	cin >> n;
    
	vector<vector<int>> g;
    
	for(int i=0; i<n; i++){
    	vector<int> t;
    	for(int j=0; j<n; j++){
        	int a;
        	cin >> a;
        	t.push_back(a);
    	}
        	g.push_back(t);
	}
    
	mincut(n,g);
    
    
    
// 	for(auto x : g){
// 		for(auto y: x){
        	 
// 	    	cout << y << " ";
// 		}
// 		cout << endl;
// 	}
    
    
    
    

	return 0;
}


