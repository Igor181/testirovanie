#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
	int a,b,m;
	vector <int> x, rez;
	fstream file(argv[1]);
	if (file.is_open())
	{
		while (true) {
			file >> m;
			x.push_back(m);
			if (file.eof())
				break;
		}
	}
	else
		cout << "ERROR with reading \"file\"";
	file.close();

	b = *max_element(x.begin(), x.end());
	a = *min_element(x.begin(), x.end());
	for (int i = a; i <= b; i++)
	{
		m = abs(i - x[0]);
		for (int j = 1; j < x.size(); j++)
		{
			m += abs(i - x[j]);
		}
		rez.push_back(m);
	}

	cout << *min_element(rez.begin(), rez.end());
}
