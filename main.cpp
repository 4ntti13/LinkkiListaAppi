#include <iostream>
#include <string>
#include<map>


using namespace std;

#include "List.h"
List list;

// pääohjelma
int main()
{

	string rivi;
	string valinta;

	cout << "   ----MENU----\n" << endl;
	cout << "1. inserthead" << endl;
	cout << "2. inserttail" << endl;
	cout << "3. printlist" << endl;
	cout << "4. insert" << endl;
	cout << "5. removehead" << endl;
	cout << "6. removetail" << endl;
	cout << "7. remove" << endl;
	cout << "8. search\n" << endl;
	cout << "Mitäpä haluat tehdä?" << endl;

	int index = 0;
	string s;


	map<string, int> valinnat = { {"inserthead", 1}, {"inserttail", 2}, {"printlist", 3}, {"insert", 4}, {"removehead", 5}, {"removetail",6},
		{"remove",7}, {"search",8} };


	while (cout << "Anna valinta: ", getline(cin, s), s != "")
	{
		switch (valinnat[s])
		{
		case 1:
			cout << "Annoit inserthead" << endl;
			cout << "Anna head: ";
			getline(cin, rivi);
			list.InsertHead(rivi);
			break;

		case 2:
			cout << "Annoit inserttail" << endl;
			cout << "Anna tail: ";
			getline(cin, rivi);
			list.InsertTail(rivi);
			break;

		case 3:
			cout << "Annoit printlist" << endl;
			list.PrintList();
			break;

		case 4:
		    cout << "Annoit insert" << endl;  
			cout << "Anna indeksi ja nimi: ";
			getline(cin, rivi);
		    list.Insert(index, rivi );
		    break;

		case 5:
			cout << "Annoit removehead" << endl;
			list.RemoveHead();
			break;

		case 6:
			cout << "Annoit removetail" << endl;
			list.RemoveTail();
			break;

		case 7:
			cout << "Annoit remove" << endl;
			cout << "Monennenko alkion haluat poistaa? ";
			getline(cin, rivi);
			index = std::stoi(rivi);
			list.Remove(index);
			break;

		case 8:
			cout << "Annoit search" << endl;
			cout << "Anna alkion nimi: ";
			getline(cin, rivi);
			list.Search(rivi);
			
			break;
		

		default:
			cout << "Annoit väärän valinnan" << endl;
			break;
		}
	}




	list.PrintList();

	cout << list << flush;

	return 0;
}