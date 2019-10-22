#include<iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>


using namespace std;
string name;
string description;
string price;
int quantity;


bool login(string userName, string password)
{
	ifstream inFile;
	inFile.open("TextFile1.txt");

	if (inFile.fail()) {
		cerr << "Error Opening File" << endl;
		exit(1);
	}
	string n, p;
	inFile >> n >> p;
	if (n == userName && p == password)
	{
		return true;
	}
	else
		cout << "login failure";
}



void dispaly(string n[],string d[],string p[]) {

	for (int i = 0; i < 5; i++) {
		cout << left << setw(8) << n[i] << setw(30) << d[i] << setw(11) << p[i] << endl;
	}

}
void cart(string cn, string cd, string cp, int itemQuantity) {

	cout << "Your items in the cart are : " << endl;
	cout << left << setw(8) << cn<< setw(30) << cd << setw(11) << cp <<setw(10)<<itemQuantity<< endl;
}


int main() {
	int size = 0;
	string n[100], d[100],p[100];
	string cn, cd, cp;
	string name;
	string description;
	string price;
	string userName, password, item;
	char ans;
	int itemQuantity;
	cout << "Username : ";
	cin >> userName;
	cout << endl;
	cout << "Password : ";
	cin >> password;
	

	ifstream infile4("householdItem.txt");
	while (!infile4.eof())
	{
		getline(infile4, name, ',');
		getline(infile4, description, ',');
		getline(infile4, price, ',');
		n[size] = name;
		d[size] = description;
		p[size] = price;
		++size;	
	}
	
	if (login(userName, password))
		dispaly(n, d, p);

	cout << "Do you want to buy any of those items (Y/N) : ";
	cin >> ans;
	if (ans == 'Y')
	{
		cout << "\n What item do you want to buy : ";
		cin >> item;
		cout << "\n What quantity do you want to buy : ";
		cin >> itemQuantity;
	}


	
	for (int j = 0; j < 5; j++) {
		//if (item == n[j])
			//cout <<n[j];
		/*{
			cn = n[j];
			cd = d[j];
			cp = p[j];
			cart(cn, cd, cp, itemQuantity);
		}*/
		if(item.compare(n[j])!=0)
			cout << n[j];
	}
}
