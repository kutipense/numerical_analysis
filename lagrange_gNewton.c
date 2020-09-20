#include <stdio.h>
#include <math.h>

float comb(float A[], int n, int m){
	int i, j, k;
	float t;
	if(n==m){
		t = 1;
		for(i=0; i<m; i++)
			t *= A[i];
	} else {
		t = 0;
		for(i=0; i<n ; i++){
			k = A[0];
			A[0] = A[i];
			A[i] = k;
			float arr[n-1];
			for(j=n-2; j>-1; j--)
				arr[j] = A[j+1];
			t += comb(arr, n-1, m);
		}
	}
	return t;
}

float absf(float a){
	if(a<0)
		return -a;
	return a;
}

float fact(int x){
	if(x>1)
		return x*fact(x-1);
	else
		return 1;
}

void gregoryNewton(float* X, float* Y, float x, int len){
	float coefficents[len], fonk[len], diff, s;
	int i,j,k,t;
	for(i=0; i<len; i++)
		fonk[i] = 0;
	coefficents[0] = fonk[0] = Y[0];
	diff = X[1]- X[0];
	for(j=len; j>1; j--){
		
		for(i=1; i<j; i++)
			Y[i-1] = Y[i]-Y[i-1];

		k = len-j+1;
		coefficents[k] = Y[0];

		float dizi[k];

		for(i=0; i<k; i++)
			dizi[i] = X[i];

		for(i=0; i<=k; i++)
			fonk[k-i] += pow(-1,i)*(comb(dizi,k,i)/fact(k-i))*coefficents[k]/fact(k)/pow(diff,k);
	}
	printf("\n\nGregory-Newton:\n\n");
	s = fonk[0];
	printf("\n    Function:\n\n        (%.4f) * x^%d", s, 0);
	for(i=1; i<len; i++){
		if(absf(fonk[i])>0.00001){
			s += pow(x,i)*fonk[i];
			printf(" + (%.4f) * x^%d", fonk[i], i);
		}
	}
	printf("\n\n    Result:\n\n        %.4f\n\n",s);
}

int lagrange(float* X, float* Y, float x, int len){
	int i,j,k,t;
	float arr[len-1],func[len],s;
	for(i=0; i<len; i++)
		func[i] = 0;
	for(i=0; i<len; i++){
		s = Y[i];
		t = 0;
		for(j=0; j<len; j++){
			if(j!=i){
				s /= X[i]-X[j];
				arr[t++] = X[j];
			}
		}
		t = k = len-1;

		for(j=0; j<len; j++)
			func[t--] += pow(-1,j)*(comb(arr,k,j)/fact(k-j))*s;
	}

	printf("\n\nLagrange:\n\n");
	s = func[0];
	printf("\n    Function:\n\n        (%.4f) * x^%d", s, 0);
	for(i=1; i<len; i++){
		if(absf(func[i])>0.00001){
			s += pow(x,i)*func[i];
			printf(" + (%.4f) * x^%d", func[i], i);
		}
	}
	printf("\n\n    Result:\n\n        %.4f\n\n",s);
}

int main(){
	int i, len, sbt_fark = 1;

	printf("Number of samples: ");
	scanf("%d", &len);

	float X[len], Y[len], fark, x;

	printf("x value #0: ");
	scanf("%f", &X[0]);
	printf("x value #1: ");
	scanf("%f", &X[1]);

	fark = X[1] - X[0];
	for(i=2; i<len; i++){
		printf("x value #%d: ",i);
		scanf("%f", &X[i]);

		if(absf(X[i]-X[i-1]-fark)>0.00001)
			sbt_fark = 0;
	}

	for(i=0; i<len; i++){
		printf("y value #%d: ",i);
		scanf("%f", &Y[i]);
	}

	printf("x value to compute: ");
	scanf("%f", &x);

	lagrange(X, Y, x, len);
	if(sbt_fark)
		gregoryNewton(X, Y, x, len);

	return 0;
}