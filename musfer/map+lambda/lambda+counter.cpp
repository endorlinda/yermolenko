#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

map<char, int> counter(string fileName) 
{
	char x;
	map<char, int> frequencies;
	ifstream inFile;

	inFile.open(fileName);
	while (inFile >> x) 
	{
		frequencies[x]++;
	}
	inFile.close();

	return frequencies;
}


void sortSecond(vector< pair<char, int> > & v) {
	auto sortingFunc = [](pair<char, int> x, pair<char, int> y)
	{
		return x.second > y.second;
	};

	sort(v.begin(), v.end(), sortingFunc);
}


void printV(const vector< pair<char, int> > & v) {
	for_each(v.begin(), v.end(), [](pair<char, int> x)
	{
		cout << x.first << " was found " << x.second << " times." << endl;
	});
}

int main()
{
	map<char, int> freqs = counter("input.txt");
	vector< pair<char, int> > freqs_vec(freqs.begin(), freqs.end());
	
	sortSecond(freqs_vec);

	printV(freqs_vec);

    return 0;
}

