// Exercise 11 Chapter 4

#include "../../../std_lib_facilities.h"

vector<int> prime;

bool is_prime(int n)
{
	for (int p = 0; p<prime.size(); ++p)
		if (n%prime[p]==0) return false;	// no remainder: prime[p] divided
	return true;	// no smaller prime could divide
}

int main()
{
    prime.push_back(2);

    for(int i = 3; i<101; ++i){
        if(is_prime(i)) prime.push_back(i);
    }

    for(int i = 0; i < prime.size(); ++i){
        cout<<prime[i]<<" ";
    }
}