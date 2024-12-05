#include <iostream>
#include <vector>
using namespace std:

class Solution{
    public:

        int findContentPackage(vector<int>&p, vector <int> & b)

        {
            sort(p.begin(), p.end());
            sort(b.begin(), b.end());

            int i=0, j=0, count =0;

            while( i < p.size()&&j<b.size)())
            {
                if(b[j]>=g[i])
                {
                    count ++;
                    i ++;
                    j ++;

                else
                    j++;

        return count;
                }
            }
        }
}