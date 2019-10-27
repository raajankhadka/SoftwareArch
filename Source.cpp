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


bool login(string &loginName)
{
	ifstream inFile;
	inFile.open("TextFile1.txt");

	if (inFile.fail()) {
		cerr << "Error Opening File" << endl;
		exit(1);
	}

	string userName, password;
	cout << endl;
	cout << "Username : ";
	cin >> userName;
	cout << endl;
	cout << "Password : ";
	cin >> password;

	string n, p;
	inFile >> n >> p;
	if (n == userName && p == password)
	{
		loginName = userName;
		return true;
	}
	cout << endl << "Login failure, please try again." << endl;
	return false;
}



void display(string n[],string d[],string p[],string q[],int size) {
	cout << "Here are some items we thought you might like:" << endl << endl;
	for (int i = 0; i < size; i++) {
		cout << left << setw(10) << n[i] << setw(30) << d[i] << setw(11) << p[i] << setw(10) << q[i] << endl;
	}
	cout << endl;

}
void cart(string cn, string cd, string cp, int itemQuantity) {

	cout << "Your items in the cart are : " << endl;
	cout << setw(8) << left << cn << setw(30) << cd << setw(11) << cp <<setw(10)<<itemQuantity<< endl;
}


int main() {
	int size = 0;
	string n[100], d[100] ,p[100], q[100];
	string cn, cd, cp;
	string name;
	string description;
	string price;
	string quant;
	string item;
	string user;
	string logout;
	char ans;
	int itemQuantity;
	float total = 777;
	
	while (true) {
		if (login(user)) {
			break;
		}
	}

	cout << endl << "Hi " << user << ". " << "You have successfully logged in, please enjoy shopping with us." << endl << endl;

	ifstream infile4("householdItem.txt");
	while (!infile4.eof())
	{
		getline(infile4, name, ',');
		getline(infile4, description, ',');
		getline(infile4, price, ',');
		getline(infile4, quant, '\n');
		n[size] = name;
		d[size] = description;
		p[size] = price;
		q[size] = quant;

		++size;
	}

	while (true) {
		display(n, d, p, q, size);

		cout << "Do you want to buy any of those items (Y/N) : ";
		cin >> ans;
		if (ans == 'Y')
		{
			cout << "\n What item do you want to buy : ";
			cin >> item;
			cout << "\n What quantity do you want to buy : ";
			cin >> itemQuantity;
			break;
		}
		else {
			cout << "Enter C to continue shopping or anything else to logout";
			cin >> logout;
			if (logout != "C") {
				exit(1);
			}
		}
	}

	cout << endl;
	for (int j = 0; j < size; j++) {
		if (item == n[j]) {
			//float total = p[j] * itemQuantity;
			cout << "Cart:  " << "Item: " << n[j] << "  Quantity: " << itemQuantity << "  Total: $" << total;
		}
	}
}