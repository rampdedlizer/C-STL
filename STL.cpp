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


//Two sum solutions
std::pair<std::size_t,std::size_t> two_sum(std::vector<int> numbers, int target)
{
  for(int i=0;i<numbers.size();i++)
  {
    for(int j=(i+1);j<numbers.size();j++)
    {
      if(numbers[i]+numbers[j]==target)
        return{i,j};
    }
  }   
  return{0,0};
}

//Is it in ?
class WhichAreIn
{

  public:
  static std::vector<std::string> inArray(std::vector<std::string> array1, std::vector<std::string> array2)
  {
    std::vector<std::string> result;
  
    for(auto value1:array1)
    {
      for(auto value2:array2)
      {
        if(value2.find(value1)!=std::string::npos)
          {
            result.push_back(value1);
            break;
          }

      }
    }
    std::sort(result.begin(),result.end());
    return result;
  }  
};
//Common Array Elements
#include <vector>

int common(std::vector<int> a, std::vector<int> b, std::vector<int> c)
{
  int total=0;
  int check=0;
  for(int i=0;i<a.size();i++)
  {
    check=0;
    int sum=0;
    for(int j=0;j<b.size();j++)
    {
      if(a[i]==b[j])
      {
        check++;
        break;
      }
    }
    for(int k=0;k<c.size();k++)
    {
      if(a[i]==c[k])
      {
        check++;
        break;
      }
    }
    if(check==2)
      total=total+a[i];
  }
  return(total);
}

//Matrix addition
std::vector<std::vector<int> > matrixAddition(std::vector<std::vector<int> > a,std::vector<std::vector<int> > b)
{
  const int size=a.size();
  int copy=size;
  int size1=copy;
  std::vector<std::vector<int > > result;
  for(int i=0;i<size;i++)
  {
    std::vector<int> temp;
    
    int j=0;
    
    do
    {
      temp.push_back(a[i][j]+b[i][j]);
      j++;
    }while(j!=(size));
    result.push_back(temp);
  }
  std::cout<<"Size:"<<result.size()<<std::endl;
  return result;
}


//Prime goals
#include<math.h>
#include<iostream>

bool boolprime(int value)
{
  int check=0;
  for(int i=1;i<=value;i++)
  {
    if(value%i==0)
      check++;
  }
  if(check==2)
    return true;
  else
    return false;
}

int sumofdigits(int number)
{
  int summed=0;
  int s=0;
  do 
  {
    s=(number%10);
    summed=summed+pow(s,2);
    number=number/10;
  }while(number!=0);
  
  return summed;
}


int solve(int a,int b)
{
  int number;
  int total=0;
  for(int i=a;i<=b;i++)
  {
      if(boolprime(i))
      {
          number=i;
          do
          {
              number=sumofdigits(number);
          }while(number>=10);
          if(number==1){
            total++;}
      }
  }

  return total;
}

//Yalsumming
#include<bits/stdc++.h>

long long solve(long long n)
{
  std::map<int,int,std::greater<int>> stored;
  int number=1;
  int sum=0;
  for(int i=1;i<=n;i++)
  {
    number=i;
    sum=0;
    do
    {
      sum=sum+(number%10);
      number=number/10;
    }while(number!=0);
    stored[sum]=i;
  }
  
  auto it=stored.begin();
  return((*it).second);
}

//Duplicates ?

#include<bits/stdc++.h>

size_t duplicateCount(std::string in)

{
  std::for_each(in.begin(), in.end(), [](char & c){
    c = ::toupper(c);});

  std::map<char,int> checks;
  std::vector<char> values;
  for(auto value:in)
  {
    values.push_back(value);
  }
  
  for(int i=0;i<values.size();i++)
  {
    checks[values[i]]=checks[values[i]]+1;
  }
  size_t count=0;
  for(auto it=checks.begin();it!=checks.end();it++)
  {
    if((*it).second>1)
      count++;    
  }
  return count;
}

//Correct Walk
bool isValidWalk(std::vector<char> walk)
{
 int size=walk.size();
int sum=0;
 //Precheck
 if(size==10){
 for(auto value:walk)
{
  if(value=='e' || value=='s')
    sum=sum+-1;
  if(value=='w' || value=='n')
    sum=sum+1;
}
if(sum==0)
  return true;
else
  return false;}
else
  return false;
}
