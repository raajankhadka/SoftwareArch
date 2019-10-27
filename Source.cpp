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

void archiveOrder(string user, string grand_total, string card, string address, int size, string n[100], string p[100], int buy[100]) {
	ofstream outfile;
	outfile.open("OrderHistory.txt", std::ios_base::app);
	outfile << user << "," << grand_total << "," << card << "," << address << ",";
	for (int j = 0; j < size; j++) {
		if (0 != buy[j]) {
			outfile << n[j] << "," << p[j] << "," << to_string(buy[j]) << ";";
		}
	}
	outfile << endl;
}

void display(string n[],string d[],string p[],string q[],int size) {
	cout << "Here are some items we thought you might like:" << endl << endl;
	for (int i = 0; i < size; i++) {
		cout << left << setw(10) << n[i] << setw(30) << d[i] << setw(1) << "$" << setw(11) << p[i] << setw(10) << q[i] << endl;
	}
	cout << endl;

}
void cart(string cn, string cd, string cp, int itemQuantity) {

	cout << "Your items in the cart are : " << endl;
	cout << setw(8) << left << cn << setw(30) << cd << setw(11) << cp <<setw(10)<<itemQuantity<< endl;
}


int main() {
	int size = 0;
	string n[100], d[100], p[100], q[100];
	int buy[100] = { 0 };
	string cn, cd, cp;
	string name;
	string description;
	string price;
	string quant;
	string item;
	string user;
	string logout;
	string navigation;
	string user_found;
	string order_description;
	char ans;
	int itemQuantity;
	float grand_total = 0;
	float total;
	
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
		cout << endl << "Enter S to shop, C to view cart, R to remove items, B to buy, V to view order history, or L to logout" << endl;
		cin >> navigation;

		if (navigation == "S") {
			display(n, d, p, q, size);

			cout << "Do you want to buy any of those items (Y/N) : ";
			cin >> ans;
			if (ans == 'Y')
			{
				cout << "\n What item do you want to buy : ";
				cin >> item;
				cout << "\n What quantity do you want to buy : ";
				cin >> itemQuantity;
				for (int j = 0; j < size; j++) {
					if (item == n[j]) {
						if (stoi(q[j]) < itemQuantity) {
							cout << endl << "This exceeds amount available to purchase." << endl;
						}
						else {
							buy[j] = itemQuantity;
							cout << endl << "Added to cart." << endl;
						}
					}
				}
			}
		}
		if (navigation == "L") {
			exit(1);
		}
		if (navigation == "C") {
			grand_total = 0;
			cout << endl << "Cart:" << endl;
			for (int j = 0; j < size; j++) {
				if (0 != buy[j]) {
					total = stoi(p[j]) * itemQuantity;
					grand_total = grand_total + total;
					cout << "Item: " << n[j] << "  Quantity: " << buy[j] << "  Cost: $" << total << endl;
				}
			}
			cout << "Total Cost: $" << grand_total;
		}
		if (navigation == "R") {
			cout << endl << "Enter name of item to remove from cart: ";
			string item_to_remove;
			cin >> item_to_remove;
			for (int j = 0; j < size; j++) {
				if (item_to_remove == n[j]) {
					buy[j] = 0;
				}
			}
		}
		if (navigation == "B") {
			string shipping_address;
			string credit_card;
			string confirm;
			cout << endl << "Please enter shipping address: ";
			cin >> shipping_address;
			while (true) {
				cout << endl << "Please enter 10-digit OSC card number: ";
				cin >> credit_card;
				if (credit_card.length() == 10) {
					break;
				}
				cout << endl << "Number not 10 digits long, please try again" << endl;
			}
			cout << endl << "Confirm Purchase? (Y/N) ";
			cin >> confirm;
			if (confirm == "Y") {
				archiveOrder(user, to_string(grand_total), credit_card, shipping_address, size, n, p, buy);
				cout << endl << "Order Processed!" << endl;
				fill(begin(buy), end(buy), 0);
			}
			else {
				cout << endl << "Order Canceled." << endl;
			}
		}
		if (navigation == "V") {
			ifstream infile4("OrderHistory.txt");
			cout << endl << "Order history format is total purchase price, card number, address, then items bought. Items bought are in format item name, price, quantity bought. Each order is shown on a new line." << endl << endl;
			while (!infile4.eof())
			{
				getline(infile4, user_found, ',');
				getline(infile4, order_description, '\n');
				if (user_found == user) {
					cout << order_description << endl;
				}
			}
			cout << endl;
		}
	}
}