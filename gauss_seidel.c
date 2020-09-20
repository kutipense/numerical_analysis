#include <stdio.h>

int main(){
    int i,j,k,b,m,n;
    printf("# variables: ");
    scanf("%d",&n);
    float A[n][n],D[n][n],B[n],C[n],h,s;
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("row %d, column %d: ",i+1,j+1);
            scanf("%f",&A[i][j]);
            D[i][j]=A[i][j];
        }
    }
    
    for(i=0;i<n;i++){
        printf("value #%d: ",i+1);
        scanf("%f",&B[i]);
        C[i] = B[i];
    }

    printf("\n---------------------@\n");
    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<n;j++){
            printf("%7.2f ",A[i][j]);
        }
        printf("   |%7.2f",B[i]);
    }
    printf("\n");
    
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(A[i][i]!=0){
                h = A[j][i]/A[i][i];
                B[j]-=h*B[i];
                for(k=i;k<n;k++)
                    A[j][k] -= h*A[i][k];
            }
        }
        printf("\n---------------------@\n");
        for(b=0;b<n;b++){
            printf("\n");
            for(m=0;m<n;m++)
                printf("%7.2f ",A[b][m]);
            printf("   |%7.2f",B[b]);
        }
        printf("\n");
    }
        
    for(i=n-1;i>=0;i--){
        for(j=n-1;j>i;j--){
            B[i]-=A[i][j]*B[j];
        }
        B[i]/=A[i][i];
    }
    
    printf("\n---------------------@\n\n");
    for(i=0;i<n;i++){
        printf("x%d: %.2f\n",i,B[i]);
    }
    printf("\n");
    for(i=0;i<n;i++){
        s = 0;
        for(j=0;j<n;j++){
            s+=D[i][j]*B[j];
        }
        printf("c%1$d: %2$f  c%1$d': %3$f\n",i,C[i],s);
    }
    	
    return 0;
}

