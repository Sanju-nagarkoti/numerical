#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f1(x,y,z) z
#define f2(x,y,z) -6*(x)+3*(y)-2*(z)
int main()
{
	float x,xp,x0,y0,z0,y,z,m1y,m2y,m1z,m2z,h;
	printf("Enter initial values of x,y &z\n");
	scanf("%f%f%f",&x0,&y0,&z0);
	printf("Enter x at which function to be evaluated\n");
	scanf("%f",&xp);
	printf("Enter the step size\n");
	scanf("%f",&h);
	y=y0;
	x=x0;
	z=z0;
	for(x=x0;x<xp;x=x+h){
		m1y=f1(x,y,z);
		m1z=f2(x,y,z);
		m2y=f1(x+h,y+h*m1y,z+h*m1z);
		m2z=f2(x+h,y+h*m1y,z+h*m1z);
		
		y=y+h/2*(m1y+m2y);
		z=z+h/2*(m1z+m2z);
	}
	printf("Function value at x=%f is %f\n",xp,y);
	getch();
	return 0;
}
