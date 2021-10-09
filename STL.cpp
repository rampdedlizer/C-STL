using namespace std;
#include<iostream>
#include<map>

long long divsum(long long value )
{
    long long sum=0;
    for(int i=1;i<=(value-1);i++)
    {
        if(value%i==0)
            sum=sum+i;
    }
    return sum;
}

namespace Bud
{
    string buddy(long long start, long long limit)
    {
        long long n=start;
        long long m=limit;
        
        map <long long, long long>N;
        map <long long, long long>M;
        
        do
        {
            long long ndivsum=0;
            long long mdivsum=0;

            ndivsum=divsum(n);
            
            mdivsum=divsum(m);

            N[n]=ndivsum;
            M[m]=mdivsum;

            n++;
            m++;
        }
        while(n!=limit);

        for(auto it=N.begin();it!=N.end();it++)
        {
            for(auto it1=M.begin();it1!=M.end();it1++)
            {
                if( (*it).second==(*it1).first+1 and (*it1).second==(*it).first+1 )
                {
                    return("("+std::to_string((*it).first)+" "+std::to_string((*it1).first)+")");
                }    
            }
        }
        return "Nothing";
    }
}


int main()
{
    cout<<Bud::buddy(1071625, 1103735);
}
