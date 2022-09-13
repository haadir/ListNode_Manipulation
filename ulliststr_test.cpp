/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
using namespace std;


int main(int argc, char* argv[])
{
	ULListStr dat;
	string str1 = "1";
	string str2 = "2";
	string str3 = "3";
	string str4 = "4";
	string str5 = "5";
	// dat.push_front(str1);
	// dat.push_front(str2);
	// dat.push_front(str3);
	dat.push_back(str1); // 1
	dat.push_back(str2); // 1 2
	dat.push_back(str3); // 1 2 3
	dat.push_front(str4); // 4 1 2 3
	dat.pop_front(); // 1 2 3
	dat.pop_back(); // 1 2 
	dat.push_back(str5); // 1 2 5
	dat.push_back(str2); // 1 2 5 2
	dat.push_back(str3); // 1 2 5 2 3
	dat.push_front(str4); // 4 1 2 5 2 3
	dat.pop_front(); // 1 2 5 2 3
	dat.pop_back(); // 1 2 5 2
	cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << " " << dat.get(3) << " " << endl;
  return 0;

	// 1 2 3 5 without popback
}
