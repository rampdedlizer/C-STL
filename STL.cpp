class GapInPrimes
	{
	public:
	    static std::pair<long, long> gap(int g, long long m, long long n)
	  {
	    std::vector<long> i1;
	    for(long i=(m+1);i<=n;i++)
	    {	
	    	long sum=0;
	    	for(long j=1;j<=i;j++)
	    	{
	    		if(i%j==0)
	    			sum++;
			}
			if(sum==2)
				i1.push_back(i);
		}
		
		for(auto it=i1.begin();it!=i1.end();it++)
		{
			if((*(it+1)-*(it))==g)
				return {*(it),*(it+1)};
		}
		return{0,0};
	  }
	};

