#include <bits/stdc++.h>

using namespace std;

struct point{
	double x;
	double y;
};


//compute determinant of p1p3 with respect to p1p2

double direction(point p1, point p2, point p3){
	double a = p2.x - p1.x;
	double b = p2.y - p1.y;
	double c = p3.x - p1.x;
	double d = p3.y - p1.y;
    
	double ans = (c * b) -(a * d);
    
	return ans;
}

//check if lines are co-liner or not

bool onsegment(point p1, point p2, point p3){
    
	double x1 = min(p1.x, p2.x);
	double x2 = max(p1.x, p2.x);
    
	double y1 = min(p1.y, p2.y);
	double y2 = max(p1.y, p2.y);
    
    
	if( (x1 < p3.x < x2) && (y1 < p3.y < y2)){
    	return true;
	}
	else{
    	return false;
	}
}


bool line_intersect(point p1, point p2, point p3, point p4){
    
	double d1 = direction(p3,p4,p1);
	double d2 = direction(p3,p4,p2);
	double d3 = direction(p1,p2,p3);
	double d4 = direction(p1,p2,p4);
    
	if((d1 * d2) < 0 && (d3 * d4) < 0){
    	return true;
	}
    
	//check that lines are co-liner or not and also intersect in that or not
    
	else if( d1 == 0 && onsegment(p3,p4,p1)){
    	return true;
	}
	else if( d2 == 0 && onsegment(p3,p4,p2)){
    	return true;
	}
	else if( d3 == 0 && onsegment(p1,p2,p3)){
    	return true;
	}
	else if( d4 == 0 && onsegment(p1, p2, p4)){
    	return true;
	}
	else{
    	return false;
	}
}

int main()
{
	point p1, p2, p3, p4;
	cout << "Enter point p1, p2" << endl;
	cin >> p1.x >> p1.y >> p2.x >> p2.y;
    
	cout << "Enter point p3, p4" << endl;
	cin >> p3.x >> p3.y >> p4.x >> p4.y;
    
	bool ans = line_intersect(p1, p2, p3,p4);
    
	if(ans) {
    	cout << "lines are intersect with each other" << endl;
	}
	else{
    	cout << "lines are not intersect" << endl;
	}

	return 0;
}

