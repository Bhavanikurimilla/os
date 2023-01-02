#include<stdio.h>
int p[10],b[10],v[10],bl[10],b[10],in[10],esum=0,sum=0,n,m,i,j;
 void check();
 void print();
int main()
{
	 printf("no.of process");
	 scanf("%d",&n);
	  printf("no.of blocks");
	 scanf("%d",&m);
	 	 printf("process sizes");
	 for(i=1;i<=n;i++)
	 {
	 	scanf("%d",&p[i]);
	 }
	 printf("block sizes");
	 for(i=1;i<=m;i++)
	 {
	 	scanf("%d",&b[i]);
	 	v[i]=0;
	 }
	 check();
	 print(); 
}
void check()
{
for(i=1;i<=n;i++)
{
	int index=-1;
	for(j=1;j<=m;j++)
	{
	 if(p[i]<=b[j])
	 { 
	 if(index==-1)
	 	index=j;
	 else if(b[j]<=b[index])
	 	index=j;
	 }

if(j==m)
	bl[i]=-1;
}
if(index!=-1)
{
	bl[i]=index;
	bl[index]=b[index]-p[i];
	}	
	}
	for(i=1;i<=m;i++)
	{
			esum=esum+b[i];
	}
}
void print(){
	int i;
	printf("pno\tpsize\tbno");
	for(i=1;i<=n;i++)
	{
		if(bl[i]!=-1){
		printf("\n%d\t%d\t%d",i,p[i],bl[i]);
	   }
	   else{
	   		printf("\n%d\t%d\tnav",i,p[i]);
	   }
    }
	for(i=1;i<=n;i++){
		if(bl[i]==-1&&esum>=p[i]){
			printf("\n ex frag is %d",esum);
			break;
		}
		if(i==n){
			printf("\nex frag is 0");
		}
	}
}
/*
no.of process
4
no.of blocks
5
process sizes
212
417
112
425
block sizes
100
500
200
300
600
pno     psize   bno
1       212     4
2       417     75
3       112     88
4       425     2
ex frag is 0
*/
