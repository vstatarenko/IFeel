#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector<int> PrimeFactorization(int N);

int main() {
	unsigned int start_time = clock();
	int N;
	cin >> N;
	for (int i = 1; i < N; i++) {
		PrimeFactorization(N);
		//PrimeFactorization(N);
	}
	
	
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << "runtime = " << search_time << endl;
	system("PAUSE");
	return 0;
}


vector<int> PrimeFactorization(int N)
{
	int n = N;
	std::vector<int> factors;
	factors.push_back(1);

	for (int prime = 2; prime*prime <= n;)
	{
		if (N % prime == 0)
		{
			factors.push_back(prime);
			N = N / prime;
		}

		else
			prime++;
	}
	if (N > 1)
		factors.push_back(N);
	
	return factors;
}