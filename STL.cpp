//Vector


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printvector(vector<int>v)
{
	std::cout<<"Size : "<<v.size()<<std::endl;
	
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}	
}
int main()
{
	int choice;
	vector<int>v(3);
	
	std::cout<<"Do you want to enter some initialize values from your side : ";
	std::cin>>choice;
	
	if(choice==0)
		goto x;
	else
		{
			int o;
			std::cout<<"Enter extra members you want to enter : ";
			std::cin>>o;
			
			for(int i=0;i<o;i++)
			{
				int x;
				cin>>x;
				
				v.push_back(x);
			}
		}
	x:
	printvector(v); 
}


//Vector of pairs
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
printvector(std::vector<std::pair<int,int> > &x)
{
	for(int i=0;i<x.size();i++)
	{
		std::cout<<x[i].first<<" "<<x[i].second<<std::endl;
	}
	std::cout<<"Size : "<<x.size()<<std::endl;
}

int main()
{
	vector<pair<int,int> > v;
	for(int i=0;i<3;i++)
	{
		int x,y;
		std::cin>>x>>y;
		v.push_back({x,y});
	}
	
	printvector(v);
	
}

//Array of vectors

void printvector(std::vector<int>&x)
{
	for(int i=0;i<x.size();i++)
	{
		std::cout<<x[i]<<" ";
	}
	std::cout<<""<<std::endl;
}
int main()
{
	int N;
	
	std::cout<<"Enter the number of vectors you want : ";
	std::cin>>N;
	
	std::vector<int> v[N];
	for(int i=0;i<N;i++)
	{
		int n;//inner sized
		std::cin>>n;
		for(int j=0;j<n;j++)
		{
			int x;
			std::cin>>x;
			v[i].push_back(x);
		}
	}
	std::cout<<""<<std::endl;

	for(int i=0;i<N;i++)
	{
		printvector(v[i]);
	}
	
}


//CodeWars Soln

#include<bits/stdc++.h>
#include<iostream>
class StepInPrimes
{
public:
static std::pair<long long, long long> step(int g, long long m, long long n)
{
	int z=0;
	std::vector<int>a;
	int f=0;
	std::pair<long long, long long> v;
	for(int i=m;i<=n;i++)
	{
		int sum=0;
		for(int j=1;j<=i;j++)
		{
			if(i%j==0)
				sum++;
		}
		if(sum==2)
		{
			a.push_back(i);
			f++;
		}
	}
	int k=0;
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<f;j++)
		{
			if((a[i]-a[j])==-g)
				{
					v.first=a[i];
					v.second=a[j];
					goto x;
				}
		}
	}
	if(k==0)
		return{0,0};
	x:
	return v;
}
};
int main()
{
	StepInPrimes a1;
	std::pair<long long, long long> v=a1.step(11,30000,100000);
	std::cout<<v.first<<" ";
	std::cout<<v.second;
}
