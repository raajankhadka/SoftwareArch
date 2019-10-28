#include<iostream>
#include <fstream>
#include <string>
#include <iomanip>
#define null 0

using namespace std;

string name;
string description;
string price;
string n[100], d[100], p[100];
string tn[100], td[100], tp[100];
string cn, cd, cp;
int total;
int quantity;
int itemQuantity[50];
int s;
int size2 = 0;
char cont;
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
		return false;
}



void dispaly(string n[],string d[],string p[]) {

	for (int i = 0; i < 6; i++) {
		cout << left << setw(8) << n[i] << setw(30) << d[i] << setw(11) << p[i] << endl;
	}

}
void cart(int itemQuantity[]) {
	
}
void viewCart()
{
	cout << "Your Updated cart: " << endl;
	cout << "\n";
	cout << "\n";
	cout << left << setw(8) << "Item" << setw(30) << "Description" << setw(11) << "Price" << setw(10) << "Item Quantity" << endl;
	
	for (int j = 0; j < size2; j++)
	{
		cout << left << setw(8) << tn[j] << setw(30) << td[j] << setw(11) << tp[j] << setw(10) << itemQuantity[j] << endl;
		int price = stoi(tp[j]);
		total = price * itemQuantity[j];
	}
	cout << "total : " <<total<< endl;
}

void removeFromCart(string removeName) {

	for (int i = 0; i < size2; i++) {

		if (tn[i].find(removeName, 0) != std::string::npos)
		{
			for (int j = i; j < (size2 - 1); j++)
			{
				tn[j] = tn[j + 1];
				td[j] = td[j + 1];
				tp[j] = tp[j + 1];
			}
			size2--;
		}
		viewCart();
	}

}
void checkout()
{
	string cName;
	string cShippingAddress;
	string cNumber;
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "Please enter your name: ";
	cin >> cName;
	cout << "\n Enter your shipping address: ";
	cin >> cShippingAddress;
	cout << "\n Enter your creditcard info: ";
	cin >> cNumber;
	cout << "********************************************************************************************************************" << endl;
	cout << "********************************************Receipt*******************************************************************" << endl;
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << left << setw(8) << "Name: "<<cName<<endl;
	cout << left << setw(8) << "Shipping Address: " << cShippingAddress<<endl;
	cout << left << setw(8) << "Your total: " << total << endl;
	cout << left << setw(8) << "Your credit card with numbers " << cNumber << " was charged $" << total << endl;

}


int main() {

	int size = 0;
	
	string item;
	string userName, password;
	string addName, removeName;

	char ans;
	int Quantity;
	int numAns;
	cout << "Username : ";
	cin >> userName;
	cout << endl;
	cout << "Password : ";
	cin >> password;


	ifstream infile4("householdItem.txt");
	while (!infile4.eof())
	{
		//getline(infile4, itemNumber, ',');
		getline(infile4, name, ',');
		getline(infile4, description, ',');
		getline(infile4, price);
		n[size] = name;
		d[size] = description;
		p[size] = price;
		++size;
	}

	while (s != true) {
		s = login(userName, password);
	}

	dispaly(n, d, p);



	while (true) {
		cout << "Do you wan to add any of those items to your cart(Y/N): ";
		cin >> ans;
		if (toupper(ans) == 'Y')
		{
			cout << "\n What item do you want to buy: ";
			cin >> item;

			cout << "What quantity do you want to buy : ";
			cin >> Quantity;
			for (int i = 0; i < 6; i++) {

				if (n[i].find(item, 0) != std::string::npos)
				{
					cn = n[i];
					tn[size2] = cn;
					cd = d[i];
					td[size2] = cd;
					cp = p[i];
					tp[size2] = cp;
					
					itemQuantity[size2] = Quantity;
					size2++;
					
				}
			}
		}
		else
		{
			cout << " Press (1) to view your cart" << endl;
			cout << "press (2) to delete/edit your cart" << endl;
			cout << "press(3) to checkout" << endl;
			cout << "press(4) to exit" << endl;
			cout << "What do you want to do? : ";
			cin >> numAns;
			switch (numAns)
			{
			case 1:
				viewCart();
				break;
			case 2:
				cout << "Which item do you want to delete: ";
				cin >> removeName;
				removeFromCart(removeName);
				break;
			case 3:
				checkout();
				break;
			case 4:
				exit(1);
				break;
			default:
				break;
			}
		}

	}
}