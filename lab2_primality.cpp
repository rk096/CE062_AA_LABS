#include <bits/stdc++.h>

using namespace std;

//find gcd if there is comman divisor other than 1
unsigned long long int gcd(unsigned long long int a, unsigned long long int b){
	while( b != 0){
    	unsigned long long int r = a % b;
    	a = b;
    	b = r;
	}
	return a;
}

//power function to check fermat's theorm (if n is prime => a^n-1 % n = 1)
unsigned long long int power(unsigned long long int a,unsigned long long int n ,unsigned long long int p ){
	unsigned long long int res = 1;
	a = a % p;
    
	while(n > 0){
    	if(n % 2 == 1){
        	res = (res*a) % p;
    	}
    	n = n/2;
    	a = (a*a) % p;
	}
	return res;
}

bool isPrime(unsigned long long int n){
	if(n <= 1 || n == 4)
    	return false;
   	 
	if(n <= 3)
    	return true;
   	 
	int k = 100;
    
	//at least 100 times so if there is a liar than also we get correct answer
	while(k > 0){
    	srand(time(0));
    	unsigned long long int a = 2 + rand() % (n-4);
   	 
    	if(gcd(n,a) != 1)
        	return false;
       	 
    	if(power(a,n-1,n) != 1)
        	return false;
       	 
    	k--;
	}
	return true;
}

//count the no of liars present in n
double find_liar(unsigned long long int n){
	unsigned long long int count = 0;
    
	for(unsigned long long int a =2; a <= n-2; a++){
    	if(power(a,n-1,n) == 1){
        	count++;
    	}
	}
    
	return (double)count/(n-3);
}

int main()
{
	unsigned long long int n;
    
	cout << "Enter number to check for primality" << endl;
	cin >> n;
    
	bool ans = isPrime(n);
    
	if(ans){
    	cout << "It is a prime number" << endl;
	}
	else{
  	 
    	cout << "It is not a prime number" << endl;
    
	}
    
    
    double prob = find_liar(n);
	cout <<  " probability is " << prob << endl;
	return 0;
}

