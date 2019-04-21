#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	cout<<"Enter the number of processes: "<<endl;
	ll num;
	cin>>num;
	ll  pri[num],bur[num],arr[num],ret[num]={},arrd[num]={};
	vector<pair<pair<ll,ll>,pair<ll,ll> > >vect1;
	//vector<pair<pair<ll,ll>,pair<ll,ll> > >vect2;
	//vector<pair<pair<ll,ll>,pair<ll,ll> > >vect3;
	for (ll i=0;i<num;i++)
	{
		cout<<"Enter the priority :";
		cin>>pri[i];
		cout<<"Enter the burst time :";
		cin>>bur[i];
		cout<<"Enter the  arrival time"<<endl;
		cin>>arr[i];
		arrd[i]=arr[i];
		vect1.push_back(make_pair(make_pair(arr[i],bur[i]),make_pair(pri[i],i)));
		//vect2.push_back(make_pair(make_pair(bur[i],arr[i]),make_pair(pri[i],i)));
		//vect3.push_back(make_pair(make_pair(arr[i],bur[i]),make_pair(pri[i],i)));
	}
	vect1.push_back(make_pair(make_pair(0,10000000),make_pair(10000000,num)));
	//sort(vect1.begin(),vect1.end());
	//sort(vect2.begin(),vect2.end());
	/*for(ll i=0;i<num+1;i++)
	{
		cout<<i<<" element "<<vect1[i].first.second<<" ";
	}*/
	/*for(ll i=0;i<num;i++)
	{
		cout<<vect2[i].second.second<<" ";
	}*/
	ll time=0,maxi=0;
	while(1)
	{
		vector <ll> sect;
		for(ll i=0;i<num+1;i++)
		{
			if((time>=vect1[i].first.first)&&(vect1[i].first.second>0))
			{
				//cout<<"Pushed "<</*vect1[i].first.second*/i<<endl;
				sect.push_back(i);
			}
		/*	else
			{
				cout<<"Empty"<<endl;
			}*/
		}
		ll maxi=1000000000,index=0;
		for(ll i=0;i<sect.size();i++)
		{
			if(maxi>vect1[sect[i]].first.second)
			{
				maxi=vect1[sect[i]].first.second;
				index=sect[i];
			}
		}
		//cout<<"index= "<<index<<endl;
		vect1[index].first.second=vect1[index].first.second-1;
		time++;
		//cout<<vect1[index].second.second<<" "<<time<</*" "<<vect1[index].first.second<<*/endl;
		if(vect1[index].first.second==0)
		{
			ret[index]=time;
		}
		ll frag=0;
		for(ll i=0;i<num;i++)
		{
			//cout<<vect1[i].first.second<<" ";
			if(vect1[i].first.second!=0)
			frag=1;
		}
		if(frag==0)
		break;
		//for(ll i=0)
	}
	cout<<"Process\t\tArrival Time\t\tBurst Time\t\tTurn Around Time\t\tWaiting Time\n";
	int total_wait=0;
	for(int i=0;i<num;i++)
	{
		cout<<i+1<<"\t\t"<<arrd[i]<<"\t\t\t"<<bur[i]<<"\t\t\t"<<ret[i]-arr[i]<<"\t\t\t\t"<<ret[i]-arrd[i]-bur[i]<<endl;
		total_wait=total_wait+ret[i]-arrd[i]-bur[i];
	}
	cout<<endl<<"Average waiting time: "<<double(total_wait)/double(num);
	cout<<endl<<"Total Elapsed time: "<<time;
	return 0;
}
/*
5
5
20
10
2
25
0
10
10
5
10
10
5
15
5
5
*/
