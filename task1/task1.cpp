#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[])
{
	int n, m, i;
	vector <int> path;
	path.push_back(1);
	n = atoi(argv[1]);
	m = atoi(argv[2]);
	i = m;
	while (i != 1)
	{
		path.push_back(i);
		i += m - 1;
		if (i > n)
			i -= n;
	}
	for (i = 0; i < path.size(); i++) {
		cout << path[i];
	}
}
