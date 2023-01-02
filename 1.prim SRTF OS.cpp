#include<stdio.h>
#include<limits.h>
int a[10],b[10],c[10],tat[10],wt[10],n,p[20],count=0,v[10],t=0,tq=1,bt[10];
//char s[10];
void sort1();
void sort2();
void chart();
int min_at_i(){
	int min=INT_MAX-1,i,min_i;
	for(i=0;i<n;i++){
			if(a[i]<min){
				min=a[i];
				min_i=i;
			}
	}
	return min_i;
}
int min_bt_i(){
		int min=INT_MAX-1,i,min_i,mint=t;
		for(i=0;i<n;i++){
			if(v[i]!=1&&a[i]<=mint){
			 if(b[i]<=min){
				mint=a[i];
				min=b[i];
				min_i=i;
		}
	}
	}
	return min_i;	
}
int main(){
	int i,j,avgtat=0,avgwt=0;	
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
		p[i]=i+1;
		bt[i]=b[i];
	}
	sort1();
	printf("arrival time  and burst time after sorting burst time");
	printf("\n");
	for(i=0;i<n;i++){
		printf("%d and %d",a[i],b[i]);
			printf("\n");
	}
	printf("GANTT CHAT\n");
	chart();
	sort2();
	printf("\n*********************TABLE**********************:\n");
		printf(" p\t\tat\t\tbt\t\tct\t\ttat\t\twt\n");
	for(i=0;i<n;i++){
			printf(" %d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],a[i],bt[i],c[i],tat[i],wt[i]);
	}
	printf("average weighting time and time ariund time\n");
	for(i=0;i<n;i++){
		avgtat=avgtat+tat[i];
		avgwt=avgwt+wt[i];
	}
	printf("%d %d",avgtat/n,avgwt/n);
}
void chart(){
	int i,j,temp,k=0,time[30],count=0,x;
	x=min_at_i();
	for(i=0;i<n;i++){
		v[i]=0;
			
	}
	if(a[x]>0){
		printf("idle ");
		t=tq;
		x=min_bt_i();
		printf("p%d ",p[x]);
		t=t+tq;
		time[k]=t;
		k++;
		b[x]=b[x]-1;
	  if(b[x]==0){
   		v[x]=1;
   		c[x]=t;
   		tat[x]=c[x]-a[x];
   		wt[x]=tat[x]-bt[x];
   		count++;
   		
       }
}
   if(a[x]==0){
   		printf("p%d ",p[x]);
   		t=t+tq;
   		time[k]=t;
   		k++;
   		b[x]=b[x]-1;
   		if(b[x]==0){
   		v[x]=1;
   		c[x]=t;
   		tat[x]=c[x]-a[x];
   		wt[x]=tat[x]-bt[x];
   		count++;
   }
}
   while(count<n){
   		x=min_bt_i();
   		printf("p%d ",p[x]);
   		t=t+tq;
   		time[k]=t;
   	    k++;
   		b[x]=b[x]-1;
   		if(b[x]==0){
   		v[x]=1;
   		c[x]=t;
   		tat[x]=c[x]-a[x];
   		wt[x]=tat[x]-bt[x];
   		count++;
   }
}
}
void sort1(){
	int i,j,temp;
		for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
		    if(b[j]>b[j+1]){
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
				temp=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				temp=p[j];
				p[j]=p[j+1];//8 3 6 2 5 4 2
				p[j+1]=temp;
		   }
		   if(b[j]==b[j+1]){
		   	if(a[j]>a[j+1]){
		   		temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				temp=p[j];
				p[j]=p[j+1];//8 3 6 2 5 4 2
				p[j+1]=temp;
		   		
			   }
		   }
		}
    }
}
void sort2(){
	int i,j,temp;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
		    if(p[j]>p[j+1]){
				temp=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				temp=p[j];
				p[j]=p[j+1];//8 3 6 2 5 4 2
				p[j+1]=temp;
				temp=c[j];
				c[j]=c[j+1];
				c[j+1]=temp;
				temp=tat[j];
				tat[j]=tat[j+1];
				tat[j+1]=temp;
				temp=wt[j];
				wt[j]=wt[j+1];
				wt[j+1]=temp;//2 2 5 6 3 1 8
			}		
		}
	}
}
