#include<bits/stdc++.h>
using namespace std;
const int N=505;
int t,n,p[N],l,r;
int main(void)
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);l=-1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&p[i]);
			if(p[i]!=i&&l==-1) l=i; 
			if(p[i]==l) r=i;
		}
		if(l!=-1) reverse(p+l,p+r+1);
		for(int i=1;i<=n;i++) printf("%d ",p[i]);
		printf("\n");
	}
	return 0;
}