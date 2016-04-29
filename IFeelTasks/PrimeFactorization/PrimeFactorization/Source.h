#include <iostream>
#include <cmath>
#include <vector>
#include <ctime> 
using namespace std;

void PrimeFactorization(int number, std::vector<int>& prime);
bool IsPrime(int number, std::vector<int>& prime);

/*int main()
{
	unsigned int start_time = clock();
	std::vector<int> prime;
	prime.push_back(2);
	int numb = 0;
	cin >> numb;

	for (int i = 2; i < numb + 1; ++i)
	{
		//cout << i << " = 1";
		PrimeFactorization(i, prime);
		//cout << endl;
	}
	
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << "runtime = " << search_time << endl;
	system("PAUSE");
	return 0;
}
*/
void PrimeFactorization(int number, std::vector<int>& prime)
{
	std::vector<int>::iterator prime_begin = prime.begin();
	std::vector<int>::iterator prime_end = prime.end();
	if (IsPrime(number, prime))
	{
		//cout << " * " << number;
		return;
	}

	else
	{
		while (prime_begin != prime_end && number != 1)
		{
			if (number % *prime_begin == 0)
			{
				number = number / *prime_begin;
				//cout << " * " << *prime_begin;
				prime_begin = prime.begin();

			}

			prime_begin++;
		}

		if (prime_begin == prime_end)
		{
			prime.push_back(number);
			//cout << " * " << number;
			return;
		}
	}
}

bool IsPrime(int number, std::vector<int>& prime)
{
	std::vector<int>::iterator prime_begin = prime.begin();
	std::vector<int>::iterator prime_end = prime.end();
	while (prime_begin != prime_end)
	{
		if (number == *prime_begin)
			return true;
		prime_begin++;
	}
	return false;
}