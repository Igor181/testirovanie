#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

struct val 
{ 
	string id;
	string s; 
};

int main(int argc, char *argv[])
{
	float a, b, r, l;
	int n = 0;
	vector <val> v;
	val v_per;
	string rest, str, strok;
	ifstream file2(argv[2]);
	if (file2.is_open())
	{
		regex r1{ "\\d+" }, r2{ "passed|failed" }, r3{ "\"id\": \\d+" };
		smatch mr1, mr2;
		while (getline(file2, str, '}'))
		{
			if (regex_search(str, mr1, r1))
				if (regex_search(str, mr2, r2))
				{
					v_per.id = mr1[0];
					v_per.s = mr2[0];
					v.push_back(v_per);
					//cout << mr1[0] << " " << mr2[0] << "  ";
				}
			//cout << endl;
		}	
	}
	file2.close();
	ifstream file1(argv[1]);
	ofstream fin("report.json");
	if (file1.is_open())
	{
		regex r1{ "\\s*\"value\": \"" }, r3{ "\"id\": \\d+" };
		smatch mr3, mr4;
		while (!file1.eof())
		{
			getline(file1, str);
			if (regex_search(str, mr3, r3))
			{
				rest = mr3[0];
				rest = rest.substr(6);
			}
			if (regex_search(str, mr4, r1))
			{
				strok = mr4[0];
				for (int i = 0; i < v.size(); i++)
					if (v[i].id == rest)
						strok += v[i].s;
				fin << strok << "\"" << "\n";
			}
			else
				fin << str << "\n";
		}
	}
	else
		cout << "ERROR with reading \"file1\"";
	file1.close();
	fin.close();
}
