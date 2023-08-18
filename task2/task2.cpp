#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char *argv[])
{
	float a, b, r, l;
	vector <float> x, y;
	fstream file1(argv[1]);
	if (file1.is_open())
	{
		file1 >> a >> b;
		file1 >> r;

	}
	else
		cout << "ERROR with reading \"file1\"";
	file1.close();
	fstream file2(argv[2]);
	if (file2.is_open())
	{
		while (true) {
			file2 >> l;
			x.push_back(l);
			file2 >> l;
			y.push_back(l);
			if (file2.eof())
				break;
		}	
	}
	else
		cout << "ERROR with reading \"file2\"";
	file2.close();

	for (int i = 0; i < (int)x.size(); i++) 
	{
		l = sqrt((x[i] - a)*(x[i] - a) + (y[i] - b)*(y[i] - b));
		if (l > r)
			cout << 2 << "\n";
		else 
			if (l < r)
				cout << 1 << "\n";
			else 
				cout << 0 << "\n";
	}
}
