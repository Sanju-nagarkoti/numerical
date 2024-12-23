
#include<stdio.h>
#include<math.h>
int fact(int n){
    if(n==1) return 1;
    else return(n*fact(n-1));
}
int main(){
    int n,i,j,k;
    float val=0,p,term1,term2,xp,x[10],fx[10],bd[10],h,s,prev;
    printf("enter the number of points:");
    scanf("%d",&n);
    printf("enter values of x & f(x)\n");
    for(i=0;i<n;i++){
        scanf("%f%f",&x[i],&fx[i]);
    }
    printf("enter the value at which derivative is required :");
    scanf("%f",&xp);
    h=x[1]-x[0];
    s=(xp-x[n-1])/h;
    //calculating backward difference
    for(i=0;i<n;i++){
        bd[i]=fx[i];
    }
    for(i=n;i>0;i--){
        for(j=0;j<i;j++){
            bd[j]=(bd[j+1]-bd[j]);
        }
    }
    //calculating value of derivative
    val=bd[n-2];
    prev=1;
    for(i=2;i<n;i++){
        term1=1;
        for(k=2;k<=i;k++){
            term1=term1*(s+k-2);
        }
        term2=(s+i-1)*prev;
        prev=term1+term2;
        val=val+(bd[n-i-1]*(term1+term2))/fact(i);
    }
    val=val/h;
    printf("Values of first derivative=%f",val);
    return 0;
}

