#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define l long int
#define pb push_back
#define fast ios_base::sync_with_stdio(false)
int maxnode;
int visited[100001];
void dfs(vector<pair<int,int> > v[],int source,int prvlen,int *maxlen)
{
	visited[source]=1;
	int currlen=0;
	pair<int,int> adj;
	for(int i=0;i<v[source].size();i++)
	{
		adj=v[source][i];
		if(!visited[adj.first])
		{
			currlen=prvlen+adj.second;
			dfs(v,adj.first,currlen,maxlen);
		}
		if((*maxlen)<currlen)
		{
			*maxlen=currlen;
			maxnode=adj.first;
		}
	}
}
int main()
{
   fast;
   cin.tie(0);
   cout.tie(0);
   
   ll n,m,a,b,w,t,cost=0;
   cin>>t;
   while(t--)
   {
   cin>>n;
   vector<pair<int,int> > v[n+1];
   m=n-1;
   while(m--)
   {
   	 cin>>a>>b>>w;
   	 v[a].push_back(make_pair(b,w));
   	 v[b].push_back(make_pair(a,w));
   }
   int maxlen=INT_MIN,len=INT_MIN;
   	 for(int j=1;j<=n;j++)
   	 visited[j]=0;
   	 dfs(v,1,0,&maxlen);
   	 //cout<<maxlen<<" "<<maxnode<<endl;
   	 for(int j=1;j<=n;j++)
   	 visited[j]=0;
   	 dfs(v,maxnode,0,&len);
   	 //cout<<len;
   if(len<100)
   cost=0;
   if(len>100)
   cost=100;
   if(len>1000)
   cost=1000;
   if(len>10000)
   cost=10000;
   cout<<cost<<" "<<len<<endl;
   }
}

