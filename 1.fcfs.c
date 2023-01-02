#include<stdio.h>
int a[10],b[10],c[10],t[10],wt[10],n,p[10];
float t1=0,wt1=0;
void sort();
int main(){
	int i,j,count=0;
	printf("enter number of process");
	scanf("%d",&n);
	printf("enter arrival time");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("enter burst time");
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
		for(i=0;i<n;i++){
		p[i]=i;
	}
	sort();
	printf("arrival time  and burst time after sorting");
	printf("\n");
	for(i=0;i<n;i++){
		printf("%d and %d",a[i],b[i]);
			printf("\n");
	}

	c[0]=a[0]+b[0];
	for(i=1;i<n;i++){
		if(a[i]<=c[i-1]){
		c[i]=c[i-1]+b[i];
	}
	else{
		c[i]=a[i]+b[i];
	}
		
	}
	for(i=0;i<n;i++){
		t[i]=c[i]-a[i];
	}
	for(i=0;i<n;i++){
		wt[i]=t[i]-b[i];
	}

	printf("arival,burst,completion,turn around,waiting");
	printf("\n");
	for(i=0;i<n;i++){
		printf("%d\t%d\t%d\t%d\t\t%d",a[i],b[i],c[i],t[i],wt[i]);
		printf("\n");
	}

	for(i=0;i<n;i++){
		t1=t1+t[i];
		wt1=wt1+wt[i];
		
	}
	printf("average turn around and average waiting time");
	printf("\n");
	printf("%f %f ",t1/n,wt1/n);
//	for(i=0;i<n;i++){
		if(a[0]==0){
			count=1;
		}
	//}
	printf("gantt chart");
	printf("\n");
	if(count==0){
		printf("\nidle");
	}
	else{
		printf(" ");
	}
	
    for(i=0;i<n;i++){
		printf(" P%d ",(p[i]+1));
		if(c[i]<a[i+1] && (i+1)<n)
		   printf(" idle ");
	}
}
void sort(){
	int i,j,temp;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
			if(a[j]==a[j+1]){
				if(p[j]>p[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
				
			}
		}
	}
}
