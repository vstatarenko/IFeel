#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

queue<int> Decompose(int , std::vector<int>&);

int main()
{
	vector<int> prime_numbs;  //vector of prime numbers
	int numb = 0;
	cout << "input number N" << endl;
	cin >> numb;

	//index i of the vector factorized corresponds to the
	//decomposition of the inger i+1 as a queue of prime numbers
	vector<queue<int>> factorized; 

	for (int i = 1; i <= numb; ++i){
		queue<int> d = Decompose(i, prime_numbs);
		factorized.push_back(d);
	}
	return 0;
}

queue<int> Decompose(int number, std::vector<int>& array_prime)
{
	queue<int> decomposition; //stores the factorized variant of the number

	std::vector<int>::iterator runner = array_prime.begin();
	while (runner != array_prime.end() && number != 1) {
		if (number % *runner == 0) {
			number = number / *runner;
			decomposition.push(*runner);
			runner = array_prime.begin();
		}
		runner++;
	}

	if (runner == array_prime.end()){
		decomposition.push(number);
		array_prime.push_back(number);
	}
	return decomposition;
}
