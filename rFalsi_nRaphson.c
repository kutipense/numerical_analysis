// __author__ : KUTAY YILMAZ
#include <stdio.h>
#include <math.h>


float f(float x, float *a){
	float y = 0;
	for(int j=4; j>=0; j--){
		y+=a[j]*pow(x,j);
	}
	return y;
}

float fDerivative(float x, float *a){
	float y = 0;
	for(int j=4; j>0; j--){
		y+=a[j]*j*pow(x,j-1);
	}
	return y;
}

int newtonRaphson(float * arr, float E, int iter){
	float x0,y0=10,yd0,x1=1;

	printf("x0:  ");
	scanf("%f",&x0);

	y0 = f(x0,arr);
	printf("\nf(%.5f)=%.5f\n",x0,y0);

	while (iter-- && fabs(y0)>E){
		yd0 = fDerivative(x0,arr);
		x0 -= y0/yd0;
		printf("f(%.5f)=%.5f\n",x0,f(x0,arr));
		y0 = f(x0,arr);		
	}
	if (fabs(y0)<E)
		printf("\nReal Root @ %f \n",x0);
	else
		printf("\nNo Root\n");

	return 0;
}

int regulaFalsi(float * arr, float E, int iter){
	
	float xL, yL, xM, yM = 10, xR, yR;
	float xLt,xRt;

	printf("xL, xR:  ");
	scanf("%f",&xL);
	scanf("%f",&xR);

	xRt = xR;
	xLt = xL;
	
	printf("\n\nf(xL)=%-26s f(xM)=%-26s f(xR)=yR\n","yL","yM");
	printf("----------------------------------------------------------------------------------------\n");
	
	while (iter-- && fabs(yM)>E){			
		yL=f(xL,arr);
		yR=f(xR,arr);
		xM=(xR*yL-xL*yR)/(yL-yR);
		yM=f(xM, arr);
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

int main(){
	float arr[4], E;
	int iter,flag;

	printf("[1] Regula Falsi\n[2] Newton Raphson\n(press 1 or 2)\n");
	scanf("%d",&flag);

	for(int i=4;i>=0;i--){
		printf("coeff #%1$d (a%1$d * x^%1$d): ",i);
		scanf("%f",&arr[i]);
	}

	printf("iter, E:  ");
	scanf("%d",&iter);
	scanf("%f",&E);

	if(flag==1)
		regulaFalsi(arr,E,iter);
	else
		newtonRaphson(arr,E,iter);

	return 0;	
}
