#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int alloc[10][10], max[10][10], need[10][10];
int work[10], avail[10];
bool finish[10], allocated;
int p,v=0,j,i,r,k;

bool check(int i){
    for(int k=0;k<r;k++){
        if(need[i][k] < work[k])
            return true;
    }
    return false;
}

int main(){

	printf("Enter the number of processes and resources\n");
	scanf("%d %d",&p,&r);
	int seq[p];
	printf("Enter the allocation values\n");
	for(int i=0;i<p;i++)
		for(j=0;j<r;j++)
			scanf("%d",&alloc[i][j]);
	printf("Enter the max values\n");
	for(int i=0;i<p;i++)
		for(j=0;j<r;j++)
			scanf("%d",&max[i][j]);	
	for(int i=0;i<p;i++)
		for(j=0;j<r;j++)
			need[i][j]=max[i][j]-alloc[i][j];
	printf("Enter the available matrix\n");
	for(i=0;i<r;i++)
	{
		scanf("%d",&avail[i]);
		work[i]=avail[i];
	}

    // Safety Algorithm
    for(int i=0;i<p;i++)
        finish[i] = false;

    while(v < p){
        allocated = false;
        for(k=0;k<p;k++){
            if(!finish[k] && check(k)){
                for(j=0;j<r;j++)
                    work[j] += alloc[k][j];
                finish[k] = allocated = true;
                seq[v] = k;
                v++;
            }
        }
        if(!allocated)
            break;
    }
    for(i=0;i<p;i++)
        printf("%d\t", seq[i]);
}