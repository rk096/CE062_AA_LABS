#include <bits/stdc++.h>

using namespace std;

int comp=0;

int partition(int a[], int p, int r){
	int x = a[r];
	int i = p-1,j;
    
	for(j=p; j<=r-1;j++){
    	comp++;
    	if(a[j] <=x){
       	 
        	i++;
        	swap(a[i],a[j]);
    	}
  	 
	}
 	swap(a[i+1],a[r]);
    	return i+1;
    
}

//randomly select an element and swap it with the last one
int random_partition(int a[], int p, int r){
	srand(time(NULL));
	int i = p + (rand()%(r-p+1));
	swap(a[i],a[r]);
	return partition(a,p,r);
}


void random_quicksort(int a[], int p, int r){
	if(p<r){
	int q = random_partition(a,p,r);
	random_quicksort(a,p,q-1);
	random_quicksort(a,q+1,r);
	}
}


int main()
{
    
	int n;
	cout << "enter no" << endl;
	cin >> n;
    
	int a[n];
	for(int i=0; i<n; i++){
    	a[i] = i;
	}
    
    
	random_quicksort(a,0,n);
    
	for(int i=0; i<n; i++){
    	cout << a[i] << " ";
	}
	cout << endl;
   cout << " count is " << comp;

	return 0;
}
