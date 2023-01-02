#include<stdio.h>
int p[10],b[10],v[10],bl[10],in[10],esum=0,sum=0,n,m,i,j;
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
		for(j=1;j<=m;j++)
		{
			if(p[i]<=b[j])
			{
				b[j]=b[j]-p[i];
				bl[i]=j;
				v[j]=1;
				break;
			}
			if(j==m)
			{
				bl[i]=-1;
				break;
			}
		}
	}
		for(i=1;i<=m;i++)
		{
			if(v[i]==0)
			{
				esum=esum+b[i];
			}
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
	printf("ex frag is %d",sum);

}
/*
no.of process3
no.of blocks4
process sizes
1
4
7
block sizes
5
8
4
10
pno     psize   bno     bsize   internal frag
1       1       1       5       4
2       4       2       8       4
3       7       4       10      3
ex frag is 11
*/
