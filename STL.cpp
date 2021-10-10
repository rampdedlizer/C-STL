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


//Elements of row of triangle
#include<iostream>
#include<vector>

std::vector<unsigned long long> odd_row(unsigned long long n)

{
    std::vector<unsigned long long> result;
    
    unsigned long long firstelement=((n*(n-1))+1);
    
    for(unsigned long long i=1;i<=n;i++)
    {
        result.push_back(firstelement);
        firstelement=firstelement +2;
    }
    return result;
}

int main()
{
    std::string output;
    std::vector<unsigned long long> result=odd_row(10);
    
    std::cin>>output;
    std::cout<<output;

    std::cout<<""<<std::endl;
    std::cout<<""<<std::endl;
    
    for(auto value:result)
    {
        std::cout<<value <<" ";
    }
}

//Encryption
#include<iostream>
#include<string>
using namespace std;
std::string encrypt(std::string text, int n)
{
    if(n<=0||text.empty())
      return text;
    std::string resulteven;
    std::string resultodd;
    do
    {
      resultodd="";
      resulteven="";
      for(int i=0;i<text.length();i++)
      {
        if(i%2!=0)
          resultodd=resultodd+text[i];
        else
          resulteven=resulteven+text[i];
      }
      text="";
      text=(resultodd+resulteven);
      n--;
    }while(n!=0);
    
    return text;
}

int main()
{
  std::cout<<encrypt("32104",1);
}
