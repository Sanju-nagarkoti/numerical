#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f1(x,y,z) z
#define f2(x,y,z) exp(-x)-2*(z)-(y)
int main()
{
	float x,xp,x0,y0,z0,y,z,ny,nz,h;
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
		ny=y+(f1(x,y,z))*h;
		nz=z+(f2(x,y,z))*h;
		y=ny;
		z=nz;
	}
	printf("Function value at x=%f is %f\n",xp,y);
	getch();
	return 0;
}
