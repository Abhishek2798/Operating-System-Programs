#include<iostream>
using namespace std;
int main()
{
int p,q;
cout<<"Enter the Number of Processes\n";
cin>>p;
cout<<"\nEnter The Number of Resources\n";
cin>>q;
int alloc[p][q],max[p][q],rem[p][q],avail[q],total[q],abb[q],ss[p];
//Allocated Resources
cout<<"\nEnter The Allocated Resources Process wise : \n";
for(int i=0;i<p;i++)
{
	cout<<"\nEnter Resources for Process"<<i+1<<endl;
	for(int j=0;j<q;j++)
	{
		cin>>alloc[i][j];
	}
}
//Total instances 
cout<<"\nEnter The Total Resource Instance For All Process : \n";
for(int i=0;i<q;i++)
{
	cin>>total[i];
}
//Max Need Resources
cout<<"\nEnter The Max Needed Resources Process wise : \n";
for(int i=0;i<p;i++)
{
	cout<<"\nEnter Resources for Process"<<i+1<<endl;
	for(int j=0;j<q;j++)
	{
		cin>>max[i][j];
	}
}
//Calculating Remaining Needed Resources by Process
cout<<"\nCalculating Remaining Needed Resources Process wise ... \n";
for(int i=0;i<p;i++)
{

	for(int j=0;j<q;j++)
	{
		rem[i][j]=max[i][j]-alloc[i][j];
	}
}
//Calculating Total Available Resource
cout<<"\nCalculating Total Available Resources...\n";
for(int i=0;i<q;i++)
{
	abb[i]=0;
	for(int j=0;j<p;j++)
	{
		abb[i]=abb[i]+alloc[j][i];
	}
	avail[i]=total[i]-abb[i];
}
cout<<"Available resources are :\n";
for(int i=0;i<q;i++)
{
	cout<<avail[i]<<" ";
}
//Calculating the safe state and sequence
int c=0,pw=0;
while(c!=p)
{
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<q;j++)
		{
			if(avail[j]>=rem[i][j])
			{
				pw=pw+1;
			}
		}
		if(pw==q)
		{
			c=c+1;
			ss[c]=i+1;
			for(int x=0;x<q;x++)
			{
				//cout<<" "<<avail[x];
				//cout<<"  "<<alloc[i][x];
				avail[x]=avail[x]+alloc[i][x];
				cout<<"  "<<alloc[i][x];
				alloc[i][x]=0;
				rem[i][x]=0;
				max[i][x]=0;
				
			}
		}
		pw=0;
	}
}
/*
if(c==p)
{
	cout<<"\n\nThe System is in Safe State With Safe Sequence : \n";
	for(int i=1;i<=p;i++)
	 cout<<"P"<<ss[i]<<" ";
}
else
{
	cout<<"\n The System is in Unsafe State \n";
}*/
return 0;
}//end main
