#include<stdio.h>
int n,m,b[10],p[10],in[10],bl[10],v[10],sum=0,esum=0,i,j;
void check();
void print();
int main()
{
	printf("process no");
	scanf("%d",&n);
	printf("block no");
	scanf("%d",&m);
	printf("process size");
    for(i=1;i<=n;i++)
    {
    	scanf("%d",&p[i]);
	}
	printf("block size");
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
				bl[i]=j;
				b[j]=b[j]-p[i];
				v[j]=1;
			
			break;}
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
void print(){
	int i;
	printf("pno\tpsize\tbno");
	for(i=1;i<=n;i++)
	{
		if(bl[i]!=-1){
		printf("\n%d\t\t%d\t\t%d",i,p[i],bl[i]);
	   }
	   else{
	   		printf("\n%d\t\t%d\t\tnav",i,p[i]);
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
process no
4
block no
5
process size
212
417
112
425
block size
100
500
200
300
600
pno     psize   bno
1               212             2
2               417             5
3               112             2
4               425             nav
 ex frag is 600
 */
