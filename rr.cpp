#include<bits/stdc++.h>
using namespace std;
int main()
{
	int num_process1,quantum1;
	cout<<"Enter number of process: ";
	cin>>num_process1;
	cout<<"Enter the time quantum1: ";
	cin>>quantum1;
	cout<<endl<<endl;
	vector<pair<int,pair<int,int> > >vect;
	int prioritys[num_process1],burst[num_process1],arrival[num_process1];
	for(int i=0;i<num_process1;i++)
	{
		cout<<"Enter the priority of P"<<i+1<<" : ";
		cin>>prioritys[i];
		cout<<"Enter the burst time of P"<<i+1<<" : ";
		cin>>burst[i];
		cout<<"Enter the arrival time of P"<<i+1<<" : ";
		cin>>arrival[i];
		vect.push_back(make_pair(arrival[i],make_pair(burst[i],prioritys[i])));
		cout<<endl;
	}
	vect.push_back( make_pair ( 0 , make_pair (10000,10000) ) );
	int time=0,last=-1;
	for(time=quantum1;time>-10000;time=time+quantum1)
	{
		cout<<time<<endl;
	    vector < pair < pair < int , int > , pair < int , int > > > sect;
	    for(int i=0;i<vect.size()-1;i++)
	    {
	        if(vect[i].first>=0&&vect[i].first<=time&&vect[i].second.first!=0&&i!=last)
	        {
	            sect.push_back(make_pair(make_pair(i,vect[i].first),make_pair(vect[i].second.first,vect[i].second.second)));
	        }
	        if(sect.size()==0&&last!=-1&&vect[last].second.first!=0)
	        {
	        	sect.push_back(make_pair(make_pair(last,vect[last].first),make_pair(vect[last].second.first,vect[last].second.second)));
			}
			if(sect.size()==0)
			{
				sect.push_back(make_pair(make_pair(num_process1,vect[num_process].first),make_pair(vect[num_process1].second.first,vect[num_process1].second.second)));
			}
	    }
	    int maxpris=10001,maxpris_ind;
	    for(int i=0;i<sect.size();i++)
	    {
	        if(sect[i].second.second<maxpris)
	        {
	            maxpris=sect[i].second.second;
	            maxpris_ind=i;
	        }
	    }
	    if(vect[sect[maxpris_ind].first.first].second.first>quantum1&&maxpris_ind!=num_process1)
	    vect[sect[maxpris_ind].first.first].second.first=vect[sect[maxpris_ind].first.first].second.first-quantum1;
	    else if(maxpris_ind!=num_process1)
	    {
	        time=time-vect[sect[maxpris_ind].first.first].second.first;
	        vect[sect[maxpris_ind].first.first].second.first=0;
	    }
	    else
	    time=time-quantum1+1;
	    last=sect[maxpris_ind].first.first;
	    for(int i=0;i<num_process;i++)
		{
	    	cout<<vect[i].first<<" "<<vect[i].second.first<<" "<<vect[i].second.second<<endl;
		}
		cout<<endl;
		int check=0;
		for(int x1=0;x1<num_process1;x1++)
		{
			if(vect[x1].second.first==0)
			check++;
		}
		if(check==num_process)
		break;
	}
	return 0;
}

