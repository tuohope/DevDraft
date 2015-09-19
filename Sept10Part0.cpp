#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
string compounds[] = { "FIZ", "BAR", "BAZ", "ZIF", "RAB", "ZAB" };

bool findCrys(string c){
	for (int i = 0; i < 6; i++){
		if (c == compounds[i]) return true;
	}
	return false;
}

string removeSpace(string t){
	string a;
	for (int i = 0; i < t.size(); i++){
		if (t[i] != ' '){
			a = a+t[i];
		}
	}
	return a;
}

string checkTable(string t){
	int end;
	for (int i = 0; i < t.size() - 2; i++){
		string temp(t, i, 3);
		bool foo = findCrys(temp);

		if (foo){
			t[i] = t[i + 1] = ' ';
			i += 1;
			end = i + 1;
		}
	}
	if (end) t[end] = ' ';
	t = removeSpace(t);
	
	return t;
}



int main() {
	int c;
	string line;

	string table;
	vector<int> swaps;
	int numOfCrys, numOfSwaps;

	getline(cin, line);
	stringstream(line) >> numOfCrys;

	getline(cin, table);
	
	getline(cin, line);
	stringstream(line) >> numOfSwaps;

	getline(cin, line);
	istringstream iss(line);
	while (iss >> c){
		swaps.push_back(c);
	}


	//numOfCrys = 10; numOfSwaps = 1; table = "BFIBZRAFBF";
	//swaps.push_back(3);

	for (size_t i = 0; i < numOfSwaps; i++)
	{	
		int pos = swaps[i];
		swap(table[pos], table[pos + 1]);

		table = checkTable(table);
	}

	cout<<table<<endl;

	return 0;
};



