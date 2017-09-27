#include <iostream>
#include <vector>
#include <utility>      // std::pair, std::make_pair

using namespace std;

int main()
{
	int n, m = 0;

	cout << "Input vector's size" << endl;
	cin >> n;
	cout << "Input vector's divide parametr" << endl;
	cin >> m;
	vector<int> vec(n, 0);
	vector<pair<int, int>> subvector_pos; //stores [start, end] subvector's position
	
	if (n < m)
	{
		cout << "error. n must be greater than m" << endl;
		return -1;
	}

	int subvector_size = n / m;
	int subvector_id = 1;
	
	int head_shift = (n % m) / 2;
	int tail_shift = (n % m) - head_shift;
	vector<int>::iterator start = vec.begin() + head_shift;
	vector<int>::iterator end = vec.end() - tail_shift;
	
	while (start <= end){
		int left_pos = distance(vec.begin(), start);
		start += subvector_size;
		if (start >= end){
			int right_pos = distance(vec.begin(), end) - 1;
			subvector_pos.push_back(make_pair(left_pos, right_pos));
			break;
		}
		int right_pos = distance(vec.begin(), start) - 1;
		subvector_pos.push_back(make_pair(left_pos, right_pos));
	}

	for (auto p : subvector_pos)
		cout << "[" << p.first << ", " << p.second << "]" << endl;
	return 0;
}