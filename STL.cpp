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
