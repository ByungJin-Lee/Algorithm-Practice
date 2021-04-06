/*
	P_Name : "Terr~"
*/
#include <stdio.h>
#include <math.h>

int calcCircleFomula(int circle_d[3]);

int sqr(int _number){
	return _number*_number;
}

int calcA(int b, int z){
	//(1+(z-b)^2)y^2
	return 1+sqr(z-b);
}
int calcB(int a, int b, int z, int J){
	//-2(zJ-bJ-az+ab-bz+b^2)y
	return -2*(z*J - b*J - a*z + a*b - b*z + sqr(b));
}
int calcC(int J, int a, int b, int r){
	//J^2 -2(a+b)J + a^2 + b^2 - r^2
	return sqr(J) - 2*(a+b)*J + sqr(a) + sqr(b) - sqr(r);
}
int returnJ(int circle_f[3], int circle_s[3]){
	if(circle_f[0] == circle_s[0]) 
		return 0;
	else 
		return (sqr(circle_f[2]) - sqr(circle_s[2]) + sqr(circle_s[1]) + sqr(circle_s[0]) - sqr(circle_f[0]) - sqr(circle_f[1]))/(2*(circle_s[0]-circle_f[0]));
}
int calcResult(int A, int B, int C){
	int rs = sqr(B) - 4*A*C;
	if(rs > 0) return 2;
	else if(rs == 0) return 1;
	else return 0;
}

int main(void){
	//Variables[a,b,radius]
	int circle_one[3], circle_two[3];
	//Input
		//Input - circle one
	for(int i = 0; i < 3; scanf("%d", &circle_one[i++]));
		//Input - circle one
	for(int i = 0; i < 3; scanf("%d", &circle_two[i++]));	
	//Work
	int J = returnJ(circle_one, circle_two);
	printf("%d\n", J);
	int A = calcA(circle_one[1], circle_two[1]);
	printf("%d\n", A);
	int B = calcB(circle_one[0], circle_one[1], circle_two[1], J);
	printf("%d\n", B);
	int C = calcC(J, circle_one[0], circle_one[1],circle_one[2]);
	printf("%d\n", C);
	//Display	
	printf("%d", calcResult(A,B,C));
	return 0;	
}

int calcCircleFomula(int circle_d[3]){
	//(x-a)^2 + (y-b)^2 = r^2
	
	
}
