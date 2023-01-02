#include<stdio.h>
#include<stdlib.h>
struct node{
	int pno;
	int at;
	int bt;
	struct node *next;
};
struct node *front=NULL;
struct node *createnode(int pno,int at,int bt)
{
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	nn->pno=pno;
	nn->at=at;
	nn->bt=bt;
	return nn;
}
void readyqueue(int pno,int at,int bt)
{  // inserting node into ready queue according to attival time
	struct node *nn,*temp=front;
	nn=createnode(pno,at,bt);
	if(front==NULL || at<front->at )
	{
		nn->next=front;
		front=nn;
	}
	else
	{
		while(temp->next!=NULL && temp->next->at<=at)
		{
			temp=temp->next;
		}
	 	nn->next=temp->next;
		temp->next=nn;
	}
}
// 6 0 1 2 3 4 5 4 5 6 1 3 4 2

int roundrobin(int at[],int bt[],int ct[],int n,int timequantum)
{   for(int i=0;i<n;i++)
    {   // inserting all the given nodes
		readyqueue(i,at[i],bt[i]);
	}
	struct node *nn,*temp=front;
    int time=0;
    while(temp!= NULL)
    { if(temp->at>time)
      {
      		printf(" %d idle %d ",time,temp->at);
      		time=temp->at;
	  }
      if((temp->bt)>timequantum)
      {
      		printf(" %d P:%d %d ",time,temp->pno+1,time+timequantum);
      		time=time+timequantum;
      		readyqueue(temp->pno,time,temp->bt-timequantum);
      		// since the process is prempted the new arrivel time
			// becomes the time variable and it was inerted into ready queue
	  }
	  else
	  {
	  	printf(" %d P:%d %d ",time,temp->pno+1,time+temp->bt);
	  	time=time+temp->bt;
	  	ct[temp->pno]=time;
	   }
	  temp=temp->next;    	
	}    
}
int main ()
{
	int n;
	printf("enter no of process \n");
	scanf("%d",&n);
	int at[n],bt[n],btt[n],ct[n];
	printf("enter arrval time \n");
	for(int i=0;i<n;i++)
    {
    	scanf("%d",&at[i]);
	}
	printf("enter burst time \n");
	for(int i=0;i<n;i++)
    {
    	scanf("%d",&bt[i]);
    	btt[i]=bt[i];
	}
	int timequantum;
	printf("enter timequantum \n");
	scanf("%d",&timequantum);
	roundrobin(at,btt,ct,n,timequantum);
	int total_turnaround_time=0;
	int tat[n];
	for(int i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
		total_turnaround_time+=tat[i];
	}
	int total_waiting_time;
	int wt[n];
	for(int i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
		total_waiting_time+=wt[i];
	}
	
	printf("the chart after \n");
	printf("process 	   	 at		 bt		 ct		 tat		wt \n");
	for(int i=0;i<n;i++)
	{
	  printf("process  :%d		 %d		 %d		 %d		 %d		 %d \n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);	
	}
	
	printf("total turn around time is %d  and avg turnaround time is %f  \n\n\n ",total_turnaround_time,float(total_turnaround_time)/float(n));
	printf("total waiting time is %d  and avg waiting time is %f \n",total_waiting_time,float(total_waiting_time)/float(n));
}
