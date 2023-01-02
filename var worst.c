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
	printf("enter process array");
    for(i=1;i<=n;i++){
    	scanf("%d",&p[i]);
	}
   printf("enter blocks size array");
	for(i=1;i<=m;i++){
	 	scanf("%d",&b[i]);
	 }
	 check();
	 print();
}
void check(){
		for(i=1;i<=n;i++){
			int index=-1;
			for(j=1;j<=m;j++){
		
        if(p[i]<=b[j]){
        	if(index==-1){
        		index =j;
			}
			else if(b[j]>=b[index]){
				index=j;
			}
     	}
		 if(j==m){
		 	bl[i]=-1;
		 } 
	}
	if(index!=-1){
		bl[i]=index;
		b[index]=b[index]-p[i];
	}
	}
	for(i=1;i<=m;i++){
			esum=esum+b[i];
	}		
}
void print(){
	int i;
	printf("process no\tprocess size\tblock no");
	for(i=1;i<=n;i++){
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
		if(i==n ){
			printf("\nex frag is 0");
		}
	}
}
/*
process no
4
block no
5
enter process array
212
417
112
425
enter blocks size array
100
500
200
300
600
process no      process size    block no
1               212             5
2               417             2
3               112             5
4               425             nav
 ex frag is 959
*/

