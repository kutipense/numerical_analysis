#include <stdio.h>
#include <math.h>

float f(float x, float *a){
	float y = 0;
	for(int j=4; j>=0; j--){
		y+=a[j]*pow(x,j);
	}
	return y;
}

int main(){
	float arr[4], E, xL, yL, xM, yM = 1, xR, yR;
	float xLt,xRt;
	int iter;
	
	printf("iter, E, xL, xR:  ");
	
	scanf("%d",&iter);
	scanf("%f",&E);
	scanf("%f",&xL);
	scanf("%f",&xR);

	xRt = xR;
	xLt = xL;

	for(int i=4;i>=0;i--){
		printf("coeff #%1$d (a%1$d * x^%1$d): ",i);
		scanf("%f",&arr[i]);
	}
	
	printf("\n\nf(xL)=%-26s f(xM)=%-26s f(xR)=yR\n","yL","yM");
	printf("---------\n");
	
	while (iter-- && fabs(yM)>E){	
		xM=(xL+xR)/2;
		yM=f(xM, arr);
		yL=f(xL,arr);
		yR=f(xR,arr);
		printf("f(%.5f)=%-20.5f, f(%.5f)=%-20.5f, f(%.5f)=%.5f\n",xL,yL,xM,yM,xR,yR);
		if (yL*yM<0)
			xR = xM;
		else
			xL = xM;
	}

	if (fabs(yM)<E)
		printf("\nReal Root @ %f in [%f,%f]\n",xM,xLt,xRt);
	else
		printf("\nNo Root\n");

	return 0;
}
