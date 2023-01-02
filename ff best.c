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
	 }
	 check();
	 print(); 
}
void check()
{
   for(i=1;i<=m;i++)
   {
	v[i]=0;}
for(i=1;i<=n;i++)
{
	int index=-1;
	for(j=1;j<=m;j++)
	{
	 if(p[i]<=b[j] &&v[j]==0)
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
	in[i]=b[index]-p[i];
	sum=sum+in[i];
	bl[i]=index;
	v[index]=1;
	}	
	}
	for(i=1;i<=m;i++)
	{
		if(v[i]==0)
			esum=esum+b[i];
	}
}
void print()
{
	printf("pno\tpsize\tbno\tbsize\tinternal frag\n");
	for(i=1;i<=n;i++)
	{
		if(bl[i]!=-1)
		{
			printf("%d\t%d\t%d\t%d\t%d\n",i,p[i],bl[i],b[bl[i]],in[i]);	
		}
		else
		{
			printf("%d\t%d\tnav\tnav\tnav\n",i,p[i]);
			if(esum<p[i])
			{
				printf("ex frag is 0\n");
			}
			else
			{
				printf("ex frag is %d",esum);
			}
		}
	}
	printf("int frag is %d",sum);

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
426
block sizes
100
500
200
300
600
pno     psize   bno     bsize   internal frag
1       212     4       300     88
2       417     2       500     83
3       112     3       200     88
4       426     5       600     174
ex frag is 433
*/
