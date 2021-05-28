#include<iostream>
#include<conio.h>
#include<fstream>
#include<vector>
#include<iomanip>
#include<cstdio>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;

class Inventory;
int main();
class Costumer
{
protected:
	string f_name, last_name, gender;
	int age = 0;
public:
	virtual int inputdetails() = 0;
	virtual int verifydetails() = 0;
};

class Registered : public Costumer
{
	string password;
	string username;
public:
	~Registered()
	{
		delete this;
	}
	int inputdetails()
	{
		cout << "\n\t\t\t\t   LOGIN YOUR ACCOUNT";
		cout << "\n\t\t\t\t   ******************";
		cout << "\n\n\n\t\t\tENTER USERNAME: ";
		cin >> username;
		cout << "\n\t\t\tENTER PASSWORD: ";
		cin >> password;
		this->verifydetails();
		system("cls");
		return 1;
	}
	int verifydetails()
	{
		ifstream fin("D:/Username&Password.txt", ios::in);
		int flag = -1;
		string userid;
		string pass;
		while (!fin.eof())
		{
			while (fin >> userid >> pass)
			{
				if (username == userid && password == pass)
				{
					flag = 1;
				}
			}
		}
		if (flag == 1)
		{
			cout << "\n\n\t\t\tACCOUNT SUCCESSFULLY LOGIN!\n";
			cout << "\n\t\t\tPRESS ANY KEY TO VIEW MENU...\n";
			cin.ignore();
			cin.get();
			fin.close();
			return 1;
		}
		else
		{
			cout << "\n\n\t\t\tIN-CORRECT DETAILS!\n";
			cout << "\n\t\t\tPRESS ANY KEY TO RE-ENTER DETAILS...";
			cin.ignore();
			cin.get();
			system("cls");
			inputdetails();
		}
	}
};

class Unregistered : public Costumer
{
	string username;
	string password;
public:
	~Unregistered()
	{
		delete this;
	}
	void re_enterdetails()
	{
		cout << "\n\t\t\t   REGISTRATION OF COSTUMER\n";
		cout << "\t\t\t     ************************";
		cout << "\n\n\n\t\t\tFIRST NAME: " << f_name << endl << endl;
		cout << "\t\t\tLAST NAME: " << last_name << endl << endl;
		cout << "\t\t\tAGE: " << age << endl << endl;
		cout << "\t\t\tGENDER: " << gender << endl << endl;
		cout << "\t\t\tENTER USERNAME: ";
		cin >> username;
		cout << "\t\t\tENTER PASSWORD: ";
		cin >> password;
		this->verifydetails();
	}
	int inputdetails()
	{
		cout << "\n\t\t\t   REGISTRATION OF COSTUMER\n";
		cout << "\t\t\t   ************************";
		cout << "\n\n\n\t\t\tENTER FIRST NAME: ";
		cin >> f_name;
		cout << "\n\t\t\tENTER LAST NAME: ";
		cin >> last_name;
		cout << "\n\t\t\tENTER AGE: ";
		cin >> age;
		cout << "\n\t\t\tENTER GENDER: ";
		cin >> gender;
		cout << "\n\t\t\tENTER USERNAME: ";
		cin >> this->username;
		cout << "\n\t\t\tENTER PASSWORD: ";
		cin >> password;
		this->verifydetails();
		return 1;
	}
	int verifydetails()
	{
		ofstream P;
		ofstream U;
		ifstream fin1("D:/Username&Password.txt");
		int flag = 0;
		string userid;
		while (!fin1.eof())
		{
			while (fin1 >> userid)
			{
				if (username == userid)
				{
					flag = 1;
				}
			}
		}
		fin1.close();
		if (flag == 1)
		{
			cout << "\n\n\t\t\tACCOUNT NOT CREATED!\n";
			cout << "\n\t\t\tTHIS USERNAME IS ALREADY TAKEN!\n";
			cout << "\t\t\tPRESS ANY KEY TO RE-ENTER USERNAME!\n";
			cin.ignore();
			cin.get();
			system("cls");
			re_enterdetails();
		}
		else
		{
			ofstream fout1("D:/RegisteredAccounts.txt", ios::app);
			U.open("D:/Username&Password.txt", ios::app);
			cout << "\n\n\t\t\tACCOUNT SUCCESSFULLY CREATED!\n";
			fout1 << "REGISTERED COSTUMER\n";
			fout1 << "*******************\n";
			fout1 << "first name: " << f_name << endl;;
			fout1 << "last name: " << last_name << endl;
			fout1 << "age: " << age << endl;
			fout1 << "gender: " << gender << endl;
			fout1 << "username: " << username << endl;
			fout1 << "password: " << password << endl << endl;

			U << username << "\t\t" << password << endl;

			fout1.close();
			U.close();
			cout << "\n\n\t\t\tDO YOU WANT TO LOGIN YOUR ACCOUNT?\n";
			cout << "\n\t\t\t1.YES\t\t\t2.NO\n\n";
			cout << "\t\t\tYOUR CHOICE: ";
			int n;
			cin >> n;
			system("cls");
			if (n == 1)
			{
				return 1;
			}
			else
			{
				exit(0);
			}

		}
	}
};
class Inventory;
double static bill = 0;

class Admin;
class Products
{
	friend class Admin;
	friend class Inventory;
public:
	int static overallstock;
};
int Products::overallstock = 0;

class MensFashion : public Products
{
public:
	MensFashion()
	{}
};

class Shirt : public MensFashion
{
	friend class Admin;
	friend class Inventory;
	int stock_shirt;
	double p_shirt;
public:
	Shirt()
	{
		p_shirt = 1000.0;
		stock_shirt = 50;
		Products::overallstock += stock_shirt;
	}
};

class Pant : public MensFashion
{
	friend class Admin;
	friend class Inventory;
	int stock_pant;
	double p_pant;
public:
	Pant()
	{
		p_pant = 1500.0;
		stock_pant = 50;
	}
};

class WomensFashion : public Products
{
public:
	WomensFashion()
	{}

};


class Heels : public WomensFashion
{
	friend class Inventory;
	friend class Admin;
	int stock_heels;
	double p_heels;
	Heels()
	{
		p_heels = 580.5;
		stock_heels = 20;
		Products::overallstock += stock_heels;
	}
};

class Skirt : public WomensFashion
{
	friend class Inventory;
	friend class Admin;
	int stock_skirt;
	double p_skirt;
	Skirt()
	{
		p_skirt = 800.0;
		stock_skirt = 23;
		Products::overallstock += stock_skirt;
	}
};


class Groceries : public Products
{

public:
	Groceries()
	{}
};


class Rice : public Groceries
{
	friend class Inventory;
	friend class Admin;
	int stock_rice;
	double p_rice;
public:
	Rice()
	{
		p_rice = 499.9;
		stock_rice = 34;

	}
};


class Cookies : public Groceries
{
	friend class Inventory;
	friend class Admin;
	int stock_cookies;
	double p_cookies;
public:
	Cookies()
	{
		p_cookies = 50.0;
		stock_cookies = 30;
		Products::overallstock += stock_cookies;
	}
};


class Electronics : public Products
{

public:

	Electronics()
	{}
};

class TV : public Electronics
{
	friend class Inventory;
	friend class Admin;
	int stock_tv;
	double p_tv;
public:
	TV()
	{
		p_tv = 2000.0;
		stock_tv = 60;
		Products::overallstock += stock_tv;
	}
};

class Oven : public Electronics
{
	friend class Inventory;
	friend class Admin;
	int stock_oven;
	double p_oven;
public:
	Oven()
	{
		p_oven = 4000.0;
		stock_oven = 33;
		Products::overallstock += stock_oven;
	}
};
class Inventory;

class Delivery
{
	friend class Inventory;
	string firstname, lastname;
	string email_address;
	long int contact_no;
	string address;
	string creditno;
	string debitno;
	int cv_code;
public:
Delivery()
{
	cv_code = 0;
	contact_no = 0;
}
void Bill()
{
	string name1, name2;
	cout << "\n\n\t\t\tYOUR ORDER HAS BEEN COMPLETED!";
	cout << "\n\n\t\t\tTHANKYOU FOR SHOPPING!\n\n";
	ifstream cart("D:/Cart.txt", ios::in);
	ofstream temp1("D:/Record.txt", ios::app);
	temp1 << "-NAME OF COSTUMER\n";
	temp1 << "----------------\n";
	temp1 << firstname << " " << lastname << endl;
	temp1 << "\n-ITEMS BOUGHT\n";
	temp1 << "--------------\n";
	while (!cart.eof())
	{
		while (cart >> name1 >> name2)
		{
			temp1 << name1 << "  " << name2 << endl;
		}
	}
	temp1 << "\n-TOTAL BILL IS: " << bill << endl << "********************"<< endl << endl;
	temp1.close();
	cart.close();
	exit(0);
}
void payment_method()
{
	int choice;
	cout << "\n\n\t\t\tSELECT YOUR PAYMENT METHOD\n";
	cout << "\t\t\t**************************\n";
	cout << "\n\n\t\t\t1. CREDIT CARD\n\n\t\t\t2. EASY PAISA\n\n\t\t\t3. CASH ON DELIVERY\n";
	cout << "\n\t\t\tYOUR CHOICE: ";
	cin >> choice;
	system("cls");
	switch (choice)
	{
	case 1:
		cout << "\n\n\t\t\tINPUT CREDIT CARD INFORMATION!\n";
		cout << "\t\t\t******************************";
		CreditCard();
	case 2:
		cout << "\n\n\t\t\tINPUT DEBIT CARD INFORMATION!\n";
		cout << "\t\t\t*****************************";
		DebitCard();
	case 3:
		inputinformation();
	default:
		cout << "\n\n\n\t\t\tTHANKYOU FOR VISITING!";
		cout << "\t\t\t**********************";
		exit(0);
	}
}
void inputinformation()
{
	cout << "\n\n\t\t\tENTER YOUR DELIEVERY INFORMATION!\n";
	cout << "\t\t\t*********************************";
	cout << "\n\n\t\t\tENTER YOUR FIRST NAME: ";
	cin.ignore();
	cin >> firstname;
	cout << "\n\t\t\tENTER YOUR LAST NAME: ";
	cin.ignore();
	cin >> lastname;
	cout << "\n\t\t\tENTER E-MAIL ADRESS: ";
	cin.ignore();
	cin >> email_address;
	cout << "\n\t\t\tENTER CONTACT NUMBER: ";
	cin.ignore();
	cin >> contact_no;
	cout << "\n\t\t\tENTER YOUR ADDRESS: ";
	cin.ignore();
	getline(cin, address);
	cout << "\n\t\t\tPRESS ANY KEY TO COMPLETE YOUR ORDER!\n";
	_getch();
	system("cls");
	Bill();
}
void CreditCard()
{
	int y;
	cout << "\n\n\t\t\tCREDIT CARD PATTERN (xxxx-xxxx-xxxx-xxxx)";
	cout << "\n\n\t\t\tENTER CREDIT CARD NUMBER: ";
	cin >> creditno;
	cout << "\n\t\t\tENTER CV CODE: ";
	cin >> cv_code;
	int l1 = creditno.length();
	if (l1 < 19 || l1 > 19)
	{
		cout << "\n\n\t\t\tINVALID CREDIT CARD NUMBER!\n";
		cout << "\n\t\t\tDO YOU WANT TO RE-ENTER DETAILS ?";
		cout << "\n\n\t\t\t1. YES\n\n\t\t\t2. NO";
		cout << "\n\n\t\t\tENTER YOUR CHOICE: ";
		cin >> y;
		system("cls");
		if (y == 1)
		{
			CreditCard();
		}
		else
		{
			cout << "\n\n\t\t\tTHANKYOU FOR VISITING!";
			exit(0);
		}
	}
	else
	{
		cout << "\n\n\t\t\tYOU HAVE ENTERED CORRECT PIN!\n";
		cout << "\n\n\t\t\tPRESS ANY KEY TO ENTER YOUR DELIEVERY INFORMATION...";
		cin.ignore();
		cin.get();
		system("cls");
		inputinformation();
	}
}
void DebitCard()
{
	int x;
	cout << "\n\n\t\t\tDEBIT CARD PATTERN (xxxx-xxxx-xxxx-xxxx)";
	cout << "\n\t\t\tENTER DEBIT CARD NUMBER: ";
	cin >> debitno;
	cout << "\n\t\t\tENTER CV CODE: ";
	cin >> cv_code;
	int l1 = debitno.length();
	if (l1 < 19 || l1 > 19)
	{
		cout << "\n\n\t\t\tINVALID DEBIT CARD NUMBER!\n";
		cout << "\n\t\t\tDO YOU WANT TO RE-ENTER DETAILS ?";
		cout << "\n\n\t\t\t1. YES\n\n\t\t\t2. NO";
		cout << "\n\n\t\t\tENTER YOUR CHOICE: ";
		cin >> x;
		system("cls");
		if (x == 1)
		{
	
			DebitCard();
		}
		else
		{
			cout << "\n\n\t\t\tTHANKYOU FOR VISITING!";
			exit(0);
		}
	}
	else
	{
		cout << "\n\n\t\t\tYOU HAVE ENTERED CORRECT PIN!\n";
		cout << "\n\n\t\t\tPRESS ANY KEY TO ENTER YOUR DELIEVERY INFORMATION...";
		cin.ignore();
		cin.get();
		system("cls");
		inputinformation();
	}
}
};

class Inventory
{
	vector<string>obj;
	Shirt* checkeredshirt;
	Shirt* tshirt;
	Pant* jeanspant;
	Pant* cottonpant;
	Heels* muleheels;
	Heels* coneheels;
	Skirt* straightskirt;
	Skirt* flyskirt;
	Rice* basmatirice;
	Rice* selarice;
	Cookies* chocolatecookies;
	Cookies* creamycookies;
	TV* ledtv;
	TV* lcdtv;
	Oven* gasoven;
	Oven* microwaveoven;
	Delivery* delivery;
public:
Inventory()
{
	checkeredshirt = new Shirt;
	tshirt = new Shirt;
	jeanspant = new Pant;
	cottonpant = new Pant;
	muleheels = new Heels;
	coneheels = new Heels;
	straightskirt = new Skirt;
	flyskirt = new Skirt;
	basmatirice = new Rice;
	selarice = new Rice;
	chocolatecookies = new Cookies;
	creamycookies = new Cookies;
	ledtv = new TV;
	lcdtv = new TV;
	gasoven = new Oven;
	microwaveoven = new Oven;
	delivery = new Delivery;
}
~Inventory()
{
	delete this->checkeredshirt;
	delete this->tshirt;
	delete this->jeanspant;
	delete this->cottonpant;
	delete this->muleheels;
	delete this->coneheels;
	delete this->straightskirt;
	delete this->flyskirt;
	delete this->basmatirice;
	delete this->selarice;
	delete this->chocolatecookies;
	delete this->creamycookies;
	delete this->ledtv;
	delete this->lcdtv;
	delete this->gasoven;
	delete this->microwaveoven;
	delete this->delivery;
	delete this;
}
void AddInCart()
{
	cout << "\n\t\t\t   WELCOME TO PRIMESPOT ONLINE STORE";
	cout << "\n\t\t\t   *********************************\n\n";
	cout << "\t\t\tWHICH CATEGORY ITEMS YOU WANT TO SEE ?\n";
	cout << "\t\t\t**************************************\n\n";
	cout << "\t\t\t1. MENS FASHION\n\n\t\t\t2. WOMENS FASHION\n\n\t\t\t3. GROCERIES\n\n\t\t\t4. ELECTRONICS\n\n";
	int c1;
	cout << "\t\t\tYOUR CHOICE: ";
	cin >> c1;
	system("cls");
	switch (c1)
	{
	case 1:
		cout << "\n\n\n\n\t\t\tWHICH ITEMS YOU WANT TO ADD IN YOUR CART ?\n";
		cout << "\t\t\t******************************************\n\n";
		cout << "\t\t\t1.SHIRT\n\n\t\t\t2.PANT\n";
		cout << "\n\t\t\tYOUR CHOICE: ";
		int c;
		cin >> c;
		system("cls");
		if (c == 1)
		{
			cout << "\n\n\n\t\t\tWHICH TYPE OF SHIRT YOU WANT TO ADD IN YOUR CART ?\n";
			cout << "\t\t\t**************************************************\n";
			cout << "\n\t\t\t1.Checkered Shirt\n\n\t\t\t2.T shirt\n";
			cout << "\n\t\t\tYOUR CHOICE: ";
			int n1;
			cin >> n1;
			system("cls");
			if (n1 == 1)
			{
				obj.push_back({ "Checkered Shirt" });
				checkeredshirt->stock_shirt--;
				Products::overallstock--;
			}
			else if (n1 == 2)
			{
				obj.push_back({ "T Shirt" });
				tshirt->stock_shirt--;
				Products::overallstock--;
			}
			else
			{
				exit(0);
			}
		}
		else if (c == 2)
		{
			cout << "\n\n\n\t\t\tWHICH TYPE OF PANT YOU WANT TO ADD IN YOUR CART ?\n";
			cout << "\t\t\t*************************************************\n";
			cout << "\n\t\t\t1.Jeans Pant\n\n\t\t\t2.Cotton Pant\n";
			cout << "\n\t\t\tYOUR CHOICE: ";
			int n2;
			cin >> n2;
			system("cls");
			if (n2 == 1)
			{
				obj.push_back({ "Jeans Pant" });
				jeanspant->stock_pant--;
				Products::overallstock--;
			}
			else if (n2 == 2)
			{
				obj.push_back({ "Cotton Pant" });
				cottonpant->stock_pant--;
				Products::overallstock--;
			}
			else
			{
				exit(0);
			}
		}
		break;
	case 2:
		cout << "\n\n\n\t\t\tWHICH ITEMS YOU WANT TO ADD IN YOUR CART ?\n";
		cout << "\t\t\t******************************************\n\n";
		cout << "\t\t\t1.HEELS\n\n\t\t\t2.SKIRT\n";
		cout << "\n\t\t\tYOUR CHOICE: ";
		int c2;
		cin >> c2;
		system("cls");
		if (c2 == 1)
		{
			cout << "\n\n\n\t\t\tWHICH TYPE OF HEEL YOU WANT TO ADD IN YOUR CART ?\n";
			cout << "\t\t\t*************************************************\n";
			cout << "\n\t\t\t1.Mule Heels\n\n\t\t\t2.Cone Heels\n";
			cout << "\n\t\t\tYOUR CHOICE: ";
			int n3;
			cin >> n3;
			system("cls");
			if (n3 == 1)
			{
				obj.push_back({ "Mule Heels" });
				muleheels->stock_heels--;
				Products::overallstock--;
			}
			else if (n3 == 2)
			{
				obj.push_back({ "Cone Heels" });
				coneheels->stock_heels--;
				Products::overallstock--;
			}
			else
			{
				exit(0);
			}
		}
		else if (c2 == 2)
		{
			cout << "\n\n\n\t\t\tWHICH TYPE OF SKIRT YOU WANT TO ADD IN YOUR CART ?\n";
			cout << "\t\t\t**************************************************\n";
			cout << "\n\t\t\t1.STRAIGHT SKIRT\n\n\t\t\t2.FLY SKIRT\n";
			cout << "\n\t\t\tYOUR CHOICE: ";
			int n4;
			cin >> n4;
			system("cls");
			if (n4 == 1)
			{
				obj.push_back({ "Straight Skirt" });
				straightskirt->stock_skirt--;
				Products::overallstock--;
			}
			else if (n4 == 2)
			{
				obj.push_back({ "Fly Skirt" });
				flyskirt->stock_skirt--;
				Products::overallstock--;
			}
			else
			{
				exit(0);
			}
		}
		break;
	case 3:
		cout << "\n\n\n\t\t\tWHICH ITEMS YOU WANT TO ADD IN YOUR CART ?\n";
		cout << "\t\t\t******************************************\n\n";
		cout << "\t\t\t1.RICE\n\n\t\t\t2.COOKIES\n";
		cout << "\n\t\t\tYOUR CHOICE: ";
		int c3;
		cin >> c3;
		system("cls");
		if (c3 == 1)
		{
			cout << "\n\n\n\t\t\tWHICH TYPE OF RICE YOU WANT TO ADD IN YOUR CART ?\n";
			cout << "\t\t\t*************************************************\n";
			cout << "\n\t\t\t1.BASMATI RICE\n\n\t\t\t2.SELA RICE\n";
			cout << "\n\t\t\tYOUR CHOICE: ";
			int n5;
			cin >> n5;
			system("cls");
			if (n5 == 1)
			{
				obj.push_back({ "Basmati Rice" });
				basmatirice->stock_rice--;
				Products::overallstock--;
			}
			else if (n5 == 2)
			{
				obj.push_back({ "Sela Rice" });
				selarice->stock_rice--;
				Products::overallstock--;
			}
			else
			{
				exit(0);
			}
		}
		else if (c3 == 2)
		{
			cout << "\n\n\n\t\t\tWHICH TYPE OF COOKIES YOU WANT TO ADD IN YOUR CART ?\n";
			cout << "\t\t\t****************************************************\n";
			cout << "\n\t\t\t1.Chocolate cookies\n\n\t\t\t2.Creamy cookies\n";
			cout << "\n\t\t\tYOUR CHOICE: ";
			int n6;
			cin >> n6;
			system("cls");
			if (n6 == 1)
			{
				obj.push_back({ "Chocolate cookies" });
				chocolatecookies->stock_cookies--;
				Products::overallstock--;
			}
			else if (n6 == 2)
			{
				obj.push_back({ "Creamy cookies" });
				creamycookies->stock_cookies--;
				Products::overallstock--;
			}
			else
			{
				exit(0);
			}
		}
		break;
	case 4:
		cout << "\n\n\n\t\t\tWHICH ITEMS YOU WANT TO ADD IN YOUR CART ?\n";
		cout << "\t\t\t******************************************\n\n";
		cout << "\t\t\t1.TV\n\n\t\t\t2.OVEN\n";
		cout << "\n\t\t\tYOUR CHOICE: ";
		int c4;
		cin >> c4;
		system("cls");
		if (c4 == 1)
		{
			cout << "\n\n\n\t\t\tWHICH TYPE OF TV YOU WANT TO ADD IN YOUR CART ?\n";
			cout << "\t\t\t***********************************************\n";
			cout << "\n\t\t\t1.LED TV\n\n\t\t\t2.LCD TV\n";
			cout << "\n\t\t\tYOUR CHOICE: ";
			int n7;
			cin >> n7;
			system("cls");
			if (n7 == 1)
			{
				obj.push_back({ "LED TV" });
				ledtv->stock_tv--;
				Products::overallstock--;
			}
			else if (n7 == 2)
			{
				obj.push_back({ "LCD TV" });
				lcdtv->stock_tv--;
				Products::overallstock--;
			}
			else
			{
				exit(0);
			}
		}
		else if (c4 == 2)
		{
			cout << "\n\n\n\t\t\tWHICH TYPE OF OVEN YOU WANT TO ADD IN YOUR CART ?\n";
			cout << "\t\t\t*************************************************\n";
			cout << "\n\t\t\t1.Gas Oven\n\n\t\t\t2.Microwave Oven\n";
			cout << "\n\t\t\tYOUR CHOICE: ";
			int n8;
			cin >> n8;
			system("cls");
			if (n8 == 1)
			{
				obj.push_back({ "Gas Oven" });
				gasoven->stock_oven--;
				Products::overallstock--;
			}
			else if (n8 == 2)
			{
				obj.push_back({ "Microwave Oven" });
				microwaveoven->stock_oven--;
				Products::overallstock--;
			}
		}
		break;
	}
	system("cls");
	cout << "\n\n\n\t\t\tDO YOU WANT TO DO MORE SHOPPING?\n";
	cout << "\t\t\t********************************\n";
	cout << "\n\t\t\t1. YES\n\n\t\t\t2. NO\n";
	cout << "\n\t\t\tYOUR CHOICE: ";
	int choice;
	cin >> choice;
	system("cls");
	if (choice == 1)
	{
		this->AddInCart();
	}
	else
	{
		ofstream fout("D:/Cart.txt");
		for (int i = 0; i < obj.size(); i++)
		{
			fout << obj[i] << endl;
		}
		fout.close();
		cout << "\n\n\n\t\t\tDO YOU WANT TO REMOVE ANY ITEM FROM YOUR CART?\n";
		cout << "\t\t\t**********************************************\n\n";
		cout << "\t\t\t1. YES\n\n\t\t\t2. NO\n";
		int c;
		cout << "\n\t\t\tYOUR CHOICE: ";
		cin >> c;
		system("cls");
		if (c == 1)
		{
			RemoveFromCart();
		}
		else
		{
			CalculatePrice();
		}
	}
}

void CalculatePrice()
{
	string val, l;
	ifstream f("D:/Cart.txt", ios::in);
	while (!f.eof())
	{
		while (f >> val >> l)
		{
			if (val == "Checkered" && l == "Shirt")
			{
				bill += checkeredshirt->p_shirt;
			}
			if (val == "T" && l == "Shirt")
			{
				bill += tshirt->p_shirt;
			}
			if (val == "Jeans" && l == "Pant")
			{
				bill += jeanspant->p_pant;
			}
			if (val == "Cotton" && l == "Pant")
			{
				bill += cottonpant->p_pant;
			}
			if (val == "Mule" && l == "Heels")
			{
				bill += muleheels->p_heels;
			}
			if (val == "Cone" && l == "Heels")
			{
				bill += coneheels->p_heels;
			}
			if (val == "Straight" && l == "Skirt")
			{
				bill += straightskirt->p_skirt;
			}
			if (val == "Fly" && l == "Skirt")
			{
				bill += flyskirt->p_skirt;
			}
			if (val == "Basmati" && l == "Rice")
			{
				bill += basmatirice->p_rice;
			}
			if (val == "Sela" && l == "Rice")
			{
				bill += selarice->p_rice;
			}
			if (val == "Chocolate" && l == "cookies")
			{
				bill += chocolatecookies->p_cookies;
			}
			if (val == "LED" && l == "TV")
			{
				bill += ledtv->p_tv;
			}
			if (val == "LCD" && l == "TV")
			{
				bill += lcdtv->p_tv;
			}
			if (val == "Gas" && l == "Oven")
			{
				bill += gasoven->p_oven;
			}
			if (val == "Microwave" && l == "Oven")
			{
				bill += microwaveoven->p_oven;
			}
		}
	}
	f.close();
	cout << "\n\n\t\t\tYOUR TOTAL BILL IS: " << bill << endl;
	cout << "\n\t\t\tDO YOU WANT TO PROCEED?";
	cout << "\n\n\t\t\t1. YES\n\n\t\t\t2. NO";
	cout << "\n\n\t\t\tYOUR CHOICE: ";
	int z;
	cin >> z;
	system("cls");
	if (z == 1)
	{
		delivery->payment_method();
	}
	else
	{
		cout << "\n\n\t\t\tTHANKYOU FOR VISITING!";
		exit(0);
	}
}
void RemoveFromCart()
{
	int i = 0;
	int deleteline;
	string line, l;
	string value;
	ifstream fin1("D:/Cart.txt", ios::in);
	ofstream temp("temp.txt", ios::out);
	cout << "\n\n\t\t\tWHICH ITEM YOU WANT TO REMOVE FROM YOUR CART: \n";
	cout << "\t\t\t*******************************************\n\n";
	int ctr = 0;
	while (!fin1.eof())
	{
		while (fin1 >> value >> l)
		{
			ctr++;
			cout << "\t\t\t" << ctr << ". " << value << " " << l << endl << endl;
		}
	}
	cout << "\t\t\tYOUR CHOICE: ";
	cin >> deleteline;
	fin1.close();
	fstream fin("D:/Cart.txt", ios::in);
	while (fin >> line >> l)
	{
		i++;
		if (i != deleteline)
			temp << line << " " << l << endl;
	}
	temp.close();
	fin.close();
	int r;
	remove("D:/Cart.txt");
	r = rename("temp.txt", "D:/Cart.txt");
	system("cls");
	cout << "\n\n\t\t\tDO YOU WANT TO REMOVE ANY ITEM FROM YOUR CART?\n";
	cout << "\n\t\t\t1.YES\n\n\t\t\t2.NO";
	int a;
	cout << "\n\n\t\t\tYOUR CHOICE: ";
	cin >> a;
	system("cls");
	if (a == 1)
	{
		this->RemoveFromCart();
	}
	else if (a == 2)
	{
		CalculatePrice();
	}
}
};

class Admin
{
	char pincode[5] = { '1','2','3','4','5' };
	Products* products;
	Shirt* checkeredshirt;
	Shirt* tshirt;
	Pant* jeanspant;
	Pant* cottonpant;
	Heels* muleheels;
	Heels* coneheels;
	Skirt* straightskirt;
	Skirt* flyskirt;
	Rice* basmatirice;
	Rice* selarice;
	Cookies* chocolatecookies;
	Cookies* creamycookies;
	TV* ledtv;
	TV* lcdtv;
	Oven* gasoven;
	Oven* microwaveoven;
public:
Admin()
{
	int counter = 0;
	products = new Products;
	checkeredshirt = new Shirt;
	tshirt = new Shirt;
	jeanspant = new Pant;
	cottonpant = new Pant;
	muleheels = new Heels;
	coneheels = new Heels;
	straightskirt = new Skirt;
	flyskirt = new Skirt;
	basmatirice = new Rice;
	selarice = new Rice;
	chocolatecookies = new Cookies;
	creamycookies = new Cookies;
	ledtv = new TV;
	lcdtv = new TV;
	gasoven = new Oven;
	microwaveoven = new Oven;

}
~Admin()
{
	delete this->checkeredshirt;
	delete this->tshirt;
	delete this->jeanspant;
	delete this->cottonpant;
	delete this->muleheels;
	delete this->coneheels;
	delete this->straightskirt;
	delete this->flyskirt;
	delete this->basmatirice;
	delete this->selarice;
	delete this->chocolatecookies;
	delete this->creamycookies;
	delete this->ledtv;
	delete this->lcdtv;
	delete this->gasoven;
	delete this->microwaveoven;
	delete this;
}
void menu()
{
	cout << "\n\t\t\t\tWELCOME TO ADMIN MODE\n";
	cout << "\t\t\t\t***********************\n";
	cout << "\n\n\t\t\tWHICH OPERATION YOU WANT TO DO?\n\n";
	cout << "\t\t\t1.CHECK STOCK\n\n\t\t\t2.ADD STOCK\n\n\t\t\t3.REMOVE STOCK\n\n\t\t\t4.EDIT PRICE\n\n\t\t\t5.EXIT ADMIN MODE\n\n";
	cout << "\t\t\tYOUR CHOICE: ";
	int c;
	cin >> c;
	switch (c)
	{
	case 1:
		system("cls");
		checkstock();
		break;
	case 2:
		system("cls");
		addstock();
		break;
	case 3:
		system("cls");
		removestock();
		break;
	case 4:
		system("cls");
		editprice();
		break;
	case 5:
		system("cls");
		main();
		break;
	default:
		exit(0);
	}
}
void inputpincode()
{
	int flag = -1;
	system("cls");
	cout << "\nEnter Password  : ";
	char pass[20];
	int i = 0;
	char a;
	for (i = 0;;)
	{
		a = _getch();
		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))

		{
			pass[i] = a;
			++i;
			cout << "*";
		}
		if (a == '\b' && i >= 1)

		{
			cout << "\b \b";
			--i;
		}
		if (a == '\r')
		{
			pass[i] = '\0';
			break;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (pass[i] != pincode[i])
		{
			flag = 1;
		}
	}
	if (flag != 1)
	{
		system("cls");
		system("Color A");
		cout << "\nACCESS GRANTED!\n\n";
		cout << "\tPress any key to see menu...\n";
		cin.ignore();
		cin.get();
		system("Color 7");
		system("cls");
		menu();
	}
	else
	{
		system("cls");
		system("Color C");
		cout << "\nACCESS DENIED!\n\n";
		exit(0);
	}
}
void checkstock()
{
	cout << "\n\n\t\t\t\tCHECK STOCK MODE";
	cout << "\n\t\t\t\t  ****************";
	cout << "\n\n\t\t\twhich stock do you want to check?\n";
	cout << "\n\n\t\t\t1.overall stock\n\n\t\t\t2.item stock\n";
	int ch;
	cin >> ch;
	system("cls");
	if (ch == 1)
	{
		cout << "\n\n\t\t\toverall stock is: " << products->overallstock << endl;
		cout << "\n\n\t\t\tpress any key to go back to menu...";
		cin.ignore();
		cin.get();
		system("cls");
		menu();
	}
	else if (ch == 2)
	{
		cout << "\n\n\t\t\tSelect any 1 category!";
		cout << "\n\n\t\t\t1.Mens Fashion\n\n\t\t\t2.Womens Fashion\n\n\t\t\t3.Groceries\n\n\t\t\t4.Electronics\n";
		int c;
		cout << "\n\t\t\tenter your choice: ";
		cin >> c;
		system("cls");
		switch (c)
		{
		case 1:
			cout << "\n\n\t\t\tWhich item's stock you want to see?";
			cout << "\n\n\t\t\t1.Shirts\n\n\t\t\t2.Pants\n";
			cout << "\n\t\t\tenter your choice: ";
			int c1;
			cin >> c1;
			switch (c1)
			{
			case 1:
				cout << "\n\n\t\t\tWhich shirt's stock you want to see?\n";
				cout << "\n\t\t\t1.Checkered Shirt\t\t2.T Shirt\n";
				cout << "\n\t\t\tenter your choice: ";
				int ch1;
				cin >> ch1;
				system("cls");
				if (ch1 == 1)
				{
					cout << "\n\n\t\t\tCheckered Shirt stock is: " << checkeredshirt->stock_shirt << endl;
				}
				else if (ch1 == 2)
				{
					cout << "\n\n\t\t\tT Shirt stock is: " << tshirt->stock_shirt << endl;
				}
				else
				{
					exit(0);
				}
				break;
			case 2:
				cout << "\n\n\t\t\tWhich pant's stock you want to see?\n";
				cout << "\n\t\t\t1.Jeans Pant\n\n\t\t\t2.Cotton Pant\n";
				cout << "\n\t\t\tenter your choice: ";
				int ch2;
				cin >> ch2;
				system("cls");
				if (ch == 1)
				{
					cout << "\n\n\t\t\tJeans Pant stock is: " << jeanspant->stock_pant << endl;
				}
				else if (ch == 2)
				{
					cout << "\n\n\t\t\tCotton Pant stock is: " << cottonpant->stock_pant << endl;
				}
				else
				{
					exit(0);
				}
				break;
			default:
				exit(0);
			}
			break;
		case 2:
			cout << "\n\n\t\t\tWhich item's stock you want to see?\n";
			cout << "\n\t\t\t1.Heels\n\n\t\t\t2.Skirt\n";
			cout << "\n\t\t\tenter your choice: ";
			int c2;
			cin >> c2;
			switch (c2)
			{
			case 1:
				cout << "\n\n\t\t\tWhich heel's stock you want to see?\n";
				cout << "\n\t\t\t1.Mule Heels\n\n\t\t\t2.Cone Heels\n";
				cout << "\n\t\t\tenter your choice: ";
				int ch3;
				cin >> ch3;
				system("cls");
				if (ch3 == 1)
				{
					cout << "\n\n\t\t\tMule Heels stock is: " << muleheels->stock_heels << endl;
				}
				else if (ch3 == 2)
				{
					cout << "\n\n\t\t\tCone Heels stock is: " << coneheels->stock_heels << endl;
				}
				else
				{
					exit(0);
				}
				break;
			case 2:
				cout << "\n\n\t\t\tWhich Skirt's stock you want to see?\n";
				cout << "\n\t\t\t1.Straight Skirt\n\n\t\t\t2.Fly Skirt\n";
				cout << "\n\t\t\tenter your choice: ";
				int ch4;
				cin >> ch4;
				system("cls");
				if (ch4 == 1)
				{
					cout << "\n\n\t\t\tStraight Skirt stock is: " << straightskirt->stock_skirt << endl;
				}
				else if (ch4 == 2)
				{
					cout << "\n\n\t\t\tFly Skirt stock is: " << flyskirt->stock_skirt << endl;
				}
				else
				{
					exit(0);
				}
				break;
			default:
				exit(0);
			}
			break;
		case 3:
			cout << "\n\n\t\t\tWhich item's stock you want to see?\n";
			cout << "\n\t\t\t1.Rice\n\n\t\t\t2.Cookies\n";
			cout << "\n\t\t\tenter your choice: ";
			int c3;
			cin >> c3;
			switch (c3)
			{
			case 1:
				cout << "\n\n\t\t\tWhich Rice's stock you want to see?\n";
				cout << "\n\t\t\t1.Basmati Rice\n\n\t\t\t2.Sela Rice\n";
				cout << "\n\t\t\tenter your choice: ";
				int ch5;
				cin >> ch5;
				system("cls");
				if (ch5 == 1)
				{
					cout << "\n\n\t\t\tBasmati Rice stock is: " << basmatirice->stock_rice << endl;
				}
				else if (ch == 2)
				{
					cout << "\n\n\t\t\tSela Rice stock is: " << selarice->stock_rice << endl;
				}
				else
				{
					exit(0);
				}
				break;
			case 2:
				cout << "\n\n\t\t\tWhich Cookies's stock you want to see?\n";
				cout << "\n\t\t\t1.Chocolate cookies\n\n\t\t\t2.Creamy cookies\n";
				cout << "\n\t\t\tenter your choice: ";
				int ch6;
				cin >> ch6;
				system("cls");
				if (ch6 == 1)
				{
					cout << "\n\n\t\t\tChocolate cookies stock is: " << chocolatecookies->stock_cookies << endl;
				}
				else if (ch6 == 2)
				{
					cout << "\n\n\t\t\tCreamy cookies stock is: " << creamycookies->stock_cookies << endl;
				}
				else
				{
					exit(0);
				}
				break;
			default:
				exit(0);
			}
			break;
		case 4:

			cout << "\n\n\t\t\tWhich item's stock you want to see?\n";
			cout << "\n\t\t\t1.TV\n\n\t\t\t2.Oven\n";
			cout << "\n\t\t\tenter your choice: ";
			int c4;
			cin >> c4;
			switch (c4)
			{
			case 1:
				cout << "\n\n\t\t\tWhich TV's stock you want to see?\n";
				cout << "\n\t\t\t1.LED TV\n\n\t\t\t2.LCD TV\n";
				cout << "\n\t\t\tenter your choice: ";
				int ch7;
				cin >> ch7;
				system("cls");
				if (ch7 == 1)
				{
					cout << "\n\n\t\t\tLED TV stock is: " << ledtv->stock_tv << endl;
				}
				else if (ch7 == 2)
				{
					cout << "\n\n\t\t\tLCD TV stock is: " << lcdtv->stock_tv << endl;
				}
				else
				{
					exit(0);
				}
				break;
			case 2:
				cout << "\n\n\t\t\tWhich Oven's stock you want to see?\n";
				cout << "\n\t\t\t1.Gas Oven\n\n\t\t\t2.Microwave Oven\n";
				cout << "\n\t\t\tenter your choice: ";
				int ch8;
				cin >> ch8;
				system("cls");
				if (ch8 == 1)
				{
					cout << "\n\n\t\t\tGas Oven stock is: " << gasoven->stock_oven << endl;
				}
				else if (ch8 == 2)
				{
					cout << "\n\n\t\t\tMicrowave Oven stock is: " << microwaveoven->stock_oven << endl;
				}
				else
				{
					exit(0);
				}
				break;
			default:
				exit(0);
			}
			break;
		default:
			cout << "ERROR!";
			exit(0);
		}
		cout << "\n\n\t\t\tDo yo want to check stock again?\n";
		cout << "\n\t\t\t1.Yes\n\n\t\t\t2.No\n";
		cout << "\n\t\t\tenter your choice: ";
		int num;
		cin >> num;
		system("cls");
		if (num == 1)
		{
			this->checkstock();
		}
		else if (num == 2)
		{
			menu();
		}
	}
}
void addstock()
{
	cout << "\n\n\t\t\t\tADD STOCK MODE";
	cout << "\n\t\t\t\t**************";
	cout << "\n\n\t\t\tSelect any category!\n";
	cout << "\n\n\t\t\t1.Mens Fashion\n\n\t\t\t2.Womens Fashion\n\n\t\t\t3.Groceries\n\n\t\t\t4.Electronics\n";
	cout << "\n\t\t\tenter your choice: ";
	int ch;
	cin >> ch;
	system("cls");
	switch (ch)
	{
	case 1:
		cout << "\n\n\t\t\tWhich item's stock you want to increase?\n";
		cout << "\n\t\t\t1.Shirt\t\t2.Pants\n";
		cout << "\n\t\t\tenter your choice: ";
		int ch1;
		int val1;
		cin >> ch1;
		system("cls");
		switch (ch1)
		{
		case 1:
			cout << "\n\n\t\t\tWhich type of shirt's stock you want to increase?\n";
			cout << "\n\t\t\t1.Checkered Shirt\t\t2.T Shirt\n";
			cout << "\n\t\t\tenter your choice: ";
			int a1;
			cin >> a1;
			system("cls");
			if (a1 == 1)
			{
				cout << "\n\n\t\t\tHow much stock you want to increase?\n";
				cin >> val1;
				checkeredshirt->stock_shirt += val1;
			}
			else if (a1 == 2)
			{
				cout << "\n\n\t\t\tHow much stock you want to increase?\n";
				cin >> val1;
				tshirt->stock_shirt += val1;
			}
			else
			{
				exit(0);
			}
			break;
		case 2:
			cout << "\n\n\t\t\tWhich type of pant's stock you want to increase?\n";
			cout << "\n\t\t\t1.Jeans Pant\t\t2.Cotton Pant\n";
			cout << "\n\t\t\tenter your choice: ";
			int a2;
			cin >> a2;
			system("cls");
			if (a2 == 1)
			{
				cout << "\n\n\t\t\tHow much stock you want to increase?\n";
				cin >> val1;
				jeanspant->stock_pant += val1;
			}
			else if (a2 == 2)
			{
				cout << "\n\n\t\t\tHow much stock you want to increase?\n";
				cin >> val1;
				cottonpant->stock_pant += val1;
			}
			else
			{
				exit(0);
			}
			break;
		default:
			exit(0);
		}
		break;
	case 2:
		cout << "\n\n\t\t\tWhich item's stock you want to increase?\n";
		cout << "\n\t\t\t1.Heels\t\t2.Skirt\n";
		cout << "\n\t\t\tenter your choice: ";
		int ch2;
		cin >> ch2;
		system("cls");
		switch (ch2)
		{
		case 1:
			cout << "\n\n\t\t\tWhich type of heel's stock you want to increase?\n";
			cout << "\n\t\t\t1.Mule Heels\t\t2.Cone Heels\n";
			cout << "\n\t\t\tenter your choice: ";
			int a3;
			cin >> a3;
			system("cls");
			if (a3 == 1)
			{
				cout << "\n\n\t\t\tHow much stock you want to increase?\n";
				cin >> val1;
				muleheels->stock_heels += val1;
			}
			else if (a3 == 2)
			{
				cout << "\n\n\t\t\tHow much stock you want to increase?\n";
				cin >> val1;
				coneheels->stock_heels += val1;
			}
			else
			{
				exit(0);
			}
			break;
		case 2:
			cout << "\n\n\t\t\tWhich type of skirt's stock you want to increase?\n";
			cout << "\n\t\t\t1.Straight Skirt\t\t2.Fly Skirt\n";
			cout << "\n\t\t\tenter your choice: ";
			int a4;
			cin >> a4;
			system("cls");
			if (a4 == 1)
			{
				cout << "\n\n\t\t\tHow much stock you want to increase?\n";
				cin >> val1;
				straightskirt->stock_skirt += val1;
			}
			else if (a4 == 2)
			{
				cout << "\n\n\t\t\tHow much stock you want to increase?\n";
				cin >> val1;
				flyskirt->stock_skirt += val1;
			}
			else
			{
				exit(0);
			}
			break;
		default:
			exit(0);
		}
		break;
	case 3:
		cout << "\n\n\t\t\tWhich item's stock you want to increase?\n";
		cout << "\n\t\t\t1.Rice\t\t2.Cookies\n";
		cout << "\n\t\t\tenter your choice: ";
		int ch3;
		cin >> ch3;
		system("cls");
		switch (ch3)
		{
		case 1:
			cout << "\n\n\t\t\tWhich type of Rice's stock you want to increase?\n";
			cout << "\n\t\t\t1.Basmati Rice\t\t2.Sela Rice\n";
			cout << "\n\t\t\tenter your choice: ";
			int a5;
			cin >> a5;
			if (a5 == 1)
			{
				cout << "\n\n\t\t\tHow much stock you want to increase?\n";
				cin >> val1;
				basmatirice->stock_rice += val1;
			}
			else if (a5 == 2)
			{
				cout << "\n\n\t\t\tHow much stock you want to increase?\n";
				cin >> val1;
				selarice->stock_rice += val1;
			}
			else
			{
				exit(0);
			}
			break;
		case 2:
			cout << "\n\n\t\t\tWhich type of Cookies's stock you want to increase?\n";
			cout << "\n\n\t\t\t1.Chocolate cookies\t\t2.Creamy Cookies\n";
			cout << "\n\t\t\tenter your choice: ";
			int a6;
			cin >> a6;
			system("cls");
			if (a6 == 1)
			{
				cout << "\n\n\t\t\tHow much stock you want to increase?\n";
				cin >> val1;
				chocolatecookies->stock_cookies += val1;
			}
			else if (a6 == 2)
			{
				cout << "\n\n\t\t\tHow much stock you want to increase?\n";
				cin >> val1;
				creamycookies->stock_cookies += val1;
			}
			else
			{
				exit(0);
			}
			break;
		default:
			exit(0);
		}
		break;
	case 4:
		cout << "\n\n\t\t\tWhich item's stock you want to increase?\n";
		cout << "\n\t\t\t1.TV\t\t2.Oven\n";
		cout << "\n\t\t\tenter your choice: ";
		int ch4;
		cin >> ch4;
		system("cls");
		switch (ch4)
		{
		case 1:
			cout << "\n\n\t\t\tWhich type of TV's stock you want to increase?\n";
			cout << "\n\t\t\t1.LED TV\t\t2.LCD TV\n";
			cout << "\n\t\t\tenter your choice: ";
			int a7;
			cin >> a7;
			system("cls");
			if (a7 == 1)
			{
				cout << "\n\n\t\t\tHow much stock you want to increase?\n";
				cin >> val1;
				ledtv->stock_tv += val1;
			}
			else if (a7 == 2)
			{
				cout << "\n\n\t\t\tHow much stock you want to increase?\n";
				cin >> val1;
				lcdtv->stock_tv += val1;
			}
			else
			{
				exit(0);
			}
			break;
		case 2:
			cout << "\n\n\t\t\tWhich type of Oven's stock you want to increase?\n";
			cout << "\n\t\t\t1.Gas Oven\t\t2.Microwave Oven\n";
			int a8;
			cout << "\n\t\t\tenter your choice: ";
			cin >> a8;
			system("cls");
			if (a8 == 1)
			{
				cout << "\n\n\t\t\tHow much stock you want to increase?\n";
				cin >> val1;
				gasoven->stock_oven += val1;
			}
			else if (a8 == 2)
			{
				cout << "\n\n\t\t\tHow much stock you want to increase?\n";
				cin >> val1;
				microwaveoven->stock_oven += val1;
			}
			else
			{
				exit(0);
			}
			break;
		default:
			exit(0);
		}
		break;
	default:
		exit(0);
	}
	cout << "\n\n\t\t\tDo yo want to add stock again?\n";
	cout << "\n\t\t\t1.Yes\t\t2.No\n";
	cout << "\n\t\t\tenter your choice: ";
	int num;
	cin >> num;
	system("cls");
	if (num == 1)
	{
		this->addstock();
	}
	else if (num == 2)
	{
		menu();
	}
}
void removestock()
{
	cout << "\n\n\t\t\t\tREMOVE STOCK MODE";
	cout << "\n\t\t\t\t*****************";
	cout << "\n\n\t\t\tSelect any category!\n";
	cout << "\n\t\t\t1.Mens Fashion\n\n\t\t\t2.Womens Fashion\n\n\t\t\t3.Groceries\n\n\t\t\t4.Electronics\n";
	cout << "\n\t\t\tenter your choice: ";
	int ch;
	cin >> ch;
	system("cls");
	switch (ch)
	{
	case 1:
		cout << "\n\n\t\t\tWhich item's stock you want to decrease?\n";
		cout << "\n\n\t\t\t1.Shirt\t\t2.Pants\n";
		cout << "\n\t\t\tenter your choice: ";
		int ch1;
		int val1;
		cin >> ch1;
		switch (ch1)
		{
		case 1:
			cout << "\n\n\t\t\tWhich type of shirt's stock you want to decrease?\n";
			cout << "\n\t\t\t1.Checkered Shirt\t\t2.T Shirt\n";
			cout << "\n\t\t\tenter your choice: ";
			int b1;
			cin >> b1;
			system("cls");
			if (b1 == 1)
			{
				cout << "\n\n\t\t\tHow much stock you want to decrease?\n";
				cin >> val1;
				checkeredshirt->stock_shirt -= val1;
			}
			else if (b1 == 2)
			{
				cout << "\n\n\t\t\tHow much stock you want to decrease?\n";
				cin >> val1;
				tshirt->stock_shirt -= val1;
			}
			else
			{
				exit(0);
			}
			break;
		case 2:
			cout << "\n\n\t\t\tWhich type of pant's stock you want to decrease?\n";
			cout << "\n\t\t\t1.Jeans Pant\t\t2.Cotton Pant\n";
			cout << "\n\t\t\tenter your choice: ";
			int b2;
			cin >> b2;
			system("cls");
			if (b2 == 1)
			{
				cout << "\n\n\t\t\tHow much stock you want to decrease?\n";
				cin >> val1;
				jeanspant->stock_pant -= val1;
			}
			else if (b2 == 2)
			{
				cout << "\n\n\t\t\tHow much stock you want to decrease?\n";
				cin >> val1;
				cottonpant->stock_pant -= val1;
			}
			else
			{
				exit(0);
			}
			break;
		default:
			exit(0);
		}
		break;
	case 2:
		cout << "\n\n\t\t\tWhich item's stock you want to decrease?\n";
		cout << "\n\t\t\t1.Heels\t\t2.Skirt\n";
		cout << "\n\t\t\tenter your choice: ";
		int ch2;
		cin >> ch2;
		switch (ch2)
		{
		case 1:
			cout << "\n\n\t\t\tWhich type of heel's stock you want to decrease?\n";
			cout << "\n\n\t\t\t1.Mule Heels\t\t2.Cone Heels\n";
			cout << "\n\t\t\tenter your choice: ";
			int b3;
			cin >> b3;
			system("cls");
			if (b3 == 1)
			{
				cout << "\n\n\t\t\tHow much stock you want to decrease?\n";
				cin >> val1;
				muleheels->stock_heels -= val1;
			}
			else if (b3 == 2)
			{
				cout << "\n\n\t\t\tHow much stock you want to decrease?\n";
				cin >> val1;
				coneheels->stock_heels -= val1;
			}
			else
			{
				exit(0);
			}
			break;
		case 2:
			cout << "\n\n\t\t\tWhich type of skirt's stock you want to decrease?\n";
			cout << "\n\t\t\t1.Straight Skirt\t\t2.Fly Skirt\n";
			cout << "\n\t\t\tenter your choice: ";
			int b4;
			cin >> b4;
			system("cls");
			if (b4 == 1)
			{
				cout << "\n\n\t\t\tHow much stock you want to decrease?\n";
				cin >> val1;
				straightskirt->stock_skirt -= val1;
			}
			else if (b4 == 2)
			{
				cout << "\n\n\t\t\tHow much stock you want to decrease?\n";
				cin >> val1;
				flyskirt->stock_skirt -= val1;
			}
			else
			{
				exit(0);
			}
			break;
		default:
			exit(0);
		}
		break;
	case 3:
		cout << "\n\n\t\t\tWhich item's stock you want to decrease?\n";
		cout << "\n\t\t\t1.Rice\t\t2.Cookies\n";
		cout << "\n\t\t\tenter your choice: ";
		int ch3;
		cin >> ch3;
		switch (ch3)
		{
		case 1:
			cout << "\n\n\t\t\tWhich type of Rice's stock you want to decrease?\n";
			cout << "\n\t\t\t1.Basmati Rice\t\t2.Sela Rice\n";
			cout << "\n\t\t\tenter your choice: ";
			int b5;
			cin >> b5;
			system("cls");
			if (b5 == 1)
			{
				cout << "\n\n\t\t\tHow much stock you want to decrease?\n";
				cin >> val1;
				basmatirice->stock_rice -= val1;
			}
			else if (b5 == 2)
			{
				cout << "\n\n\t\t\tHow much stock you want to decrease?\n";
				cin >> val1;
				selarice->stock_rice -= val1;
			}
			else
			{
				exit(0);
			}
			break;
		case 2:
			cout << "\n\n\t\t\tWhich type of Cookies's stock you want to increase?\n";
			cout << "\n\t\t\t1.Chocolate cookies\t\t2.Creamy Cookies\n";
			cout << "\n\t\t\tenter your choice: ";
			int b6;
			cin >> b6;
			system("cls");
			if (b6 == 1)
			{
				cout << "\n\n\t\t\tHow much stock you want to decrease?\n";
				cin >> val1;
				chocolatecookies->stock_cookies -= val1;
			}
			else if (b6 == 2)
			{
				cout << "\n\n\t\t\tHow much stock you want to decrease?\n";
				cin >> val1;
				creamycookies->stock_cookies -= val1;
			}
			else
			{
				exit(0);
			}
			break;
		default:
			exit(0);
		}
		break;
	case 4:
		cout << "\n\n\t\t\tWhich item's stock you want to decrease?\n";
		cout << "\n\t\t\t1.TV\t\t2.Oven\n";
		cout << "\n\t\t\tenter your choice: ";
		int ch4;
		cin >> ch4;
		switch (ch4)
		{
		case 1:
			cout << "\n\n\t\t\tWhich type of TV's stock you want to decrease?\n";
			cout << "\n\t\t\t1.LED TV\t\t2.LCD TV\n";
			cout << "\n\t\t\tenter your choice: ";
			int b7;
			cin >> b7;
			system("cls");
			if (b7 == 1)
			{
				cout << "\n\n\t\t\tHow much stock you want to decrease?\n";
				cin >> val1;
				ledtv->stock_tv -= val1;
			}
			else if (b7 == 2)
			{
				cout << "\n\n\t\t\tHow much stock you want to decrease?\n";
				cin >> val1;
				lcdtv->stock_tv -= val1;
			}
			else
			{
				exit(0);
			}
			break;
		case 2:
			cout << "\n\n\t\t\tWhich type of Oven's stock you want to decrease?\n";
			cout << "\n\t\t\t1.Gas Oven\t\t2.Microwave Oven\n";
			cout << "\n\t\t\tenter your choice: ";
			int b8;
			cin >> b8;
			system("cls");
			if (b8 == 1)
			{
				cout << "\n\n\t\t\tHow much stock you want to decrease?\n";
				cin >> val1;
				gasoven->stock_oven -= val1;
			}
			else if (b8 == 2)
			{
				cout << "\n\n\t\t\tHow much stock you want to decrease?\n";
				cin >> val1;
				microwaveoven->stock_oven -= val1;
			}
			else
			{
				exit(0);
			}
			break;
		default:
			exit(0);
		}
		break;
	default:
		exit(0);
	}
	cout << "\n\n\t\t\tDo yo want to remove stock again?\n";
	cout << "\n\t\t\t1.Yes\t\t2.No\n";
	cout << "\n\t\t\tenter your choice: ";
	int num;
	cin >> num;
	system("cls");
	if (num == 1)
	{
		this->removestock();
	}
	else if (num == 2)
	{
		menu();
	}
}
void editprice()
	{
		cout << "\n\n\t\t\t\tEDIT PRICE MODE";
		cout << "\n\t\t\t\t***************";
		cout << "\n\n\t\t\tWhich Category item's price you want to edit?\n";
		cout << "\n\t\t\t1.Mens Fashion\n\n\t\t\t2.Womens Fashion\n\n\t\t\t3.Groceries\n\n\t\t\t4.Electronics\n";
		cout << "\n\t\t\tenter your choice: ";
		int ch;
		cin >> ch;
		system("cls");
		switch (ch)
		{
		case 1:
			cout << "\n\n\t\t\tWhich item's price you want to edit?\n";
			cout << "\n\t\t\t1.Shirt\t\t2.Pant\n";
			cout << "\n\t\t\tenter your choice: ";
			int c1;
			cin >> c1;
			system("cls");
			if (c1 == 1)
			{
				cout << "\n\n\t\t\tWhich Shirt's price you want to edit: \n";
				cout << "\n\t\t\t1.Checkered Shirt\t\t2.T Shirt\n";
				cout << "\n\t\t\tenter your choice: ";
				int p1;
				cin >> p1;
				system("cls");
				if (p1 == 1)
				{
					checkeredshirt->p_shirt = 0;
					cout << "\n\n\t\t\tEnter new price of checkered shirt: ";
					cin >> checkeredshirt->p_shirt;
				}
				else if (p1 == 2)
				{
					tshirt->p_shirt = 0;
					cout << "\n\n\t\t\tEnter new price of t shirt: ";
					cin >> tshirt->p_shirt;
				}
				else
				{
					exit(0);
				}
			}
			else if (c1 == 2)
			{
				cout << "\n\n\t\t\tWhich Pant's price you want to edit: \n";
				cout << "\n\t\t\t1.Jeans Pant\t\t2.Cotton Pant\n";
				cout << "\n\t\t\tenter your choice: ";
				int p2;
				cin >> p2;
				system("cls");
				if (p2 == 1)
				{
					jeanspant->p_pant = 0;
					cout << "\n\n\t\t\tEnter new price of jeans pant: ";
					cin >> jeanspant->p_pant;
				}
				else if (p2 == 2)
				{
					cottonpant->p_pant = 0;
					cout << "\n\n\t\t\tEnter new price of cotton pant: ";
					cin >> cottonpant->p_pant;
				}
				else
				{
					exit(0);
				}
			}
			else { exit(0); }
			break;
		case 2:
			cout << "\n\n\t\t\tWhich item's price you want to edit?\n";
			cout << "\n\t\t\t1.heels\t\t2.skirt\n";
			cout << "\n\t\t\tenter your choice: ";
			int c2;
			cin >> c2;
			system("cls");
			if (c2 == 1)
			{
				cout << "\n\n\t\t\tWhich Heel's price you want to edit: \n";
				cout << "\n\t\t\t1.Mule Heels\t\t2.Cone Heels\n";
				cout << "\n\t\t\tenter your choice: ";
				int p3;
				cin >> p3;
				system("cls");
				if (p3 == 1)
				{
					muleheels->p_heels = 0;
					cout << "\n\n\t\t\tEnter new price of mule heels: ";
					cin >> jeanspant->p_pant;
				}
				else if (p3 == 2)
				{
					coneheels->p_heels = 0;
					cout << "\n\n\t\t\tEnter new price of Cone Heels: ";
					cin >> coneheels->p_heels;
				}
				else
				{
					exit(0);
				}
			}
			else if (c2 == 2)
			{
				cout << "\n\n\t\t\tWhich Skirt's price you want to edit: \n";
				cout << "\n\t\t\t1.Straight Skirt\t\t2.Fly Skirt\n";
				cout << "\n\t\t\tenter your choice: ";
				int p4;
				cin >> p4;
				system("cls");
				if (p4 == 1)
				{
					straightskirt->p_skirt = 0;
					cout << "\n\n\t\t\tEnter new price of Straight Skirt: ";
					cin >> straightskirt->p_skirt;
				}
				else if (p4 == 2)
				{
					flyskirt->p_skirt = 0;
					cout << "\n\n\t\t\tEnter new price of Fly Skirt: ";
					cin >> flyskirt->p_skirt;
				}
				else
				{
					exit(0);
				}
			}
			else { exit(0); }
			break;
		case 3:
			cout << "\n\n\t\t\tWhich item's price you want to edit?\n";
			cout << "\n\t\t\t1.rice\t\t2.cookies\n";
			cout << "\n\t\t\tenter your choice: ";
			int c3;
			cin >> c3;
			system("cls");
			if (c3 == 1)
			{
				cout << "\n\n\t\t\tWhich Rice's price you want to edit: \n";
				cout << "\n\t\t\t1.Basmati Rice\t\t2.Sela Rice\n";
				cout << "\n\t\t\tenter your choice: ";
				int p5;
				cin >> p5;
				system("cls");
				if (p5 == 1)
				{
					basmatirice->p_rice = 0;
					cout << "\n\n\t\t\tEnter new price of Basmati Rice: ";
					cin >> basmatirice->p_rice;
				}
				else if (p5 == 2)
				{
					selarice->p_rice = 0;
					cout << "\n\n\t\t\tEnter new price of Sela Rice: ";
					cin >> selarice->p_rice;
				}
				else
				{
					exit(0);
				}
			}
			else if (c3 == 2)
			{
				cout << "\n\n\t\t\tWhich Cookies's price you want to edit: \n";
				cout << "\n\t\t\t1.Chocolate cookies\t\t2.Creamy cookies\n";
				cout << "\n\t\t\tenter your choice: ";
				int p6;
				cin >> p6;
				system("cls");
				if (p6 == 1)
				{
					chocolatecookies->p_cookies = 0;
					cout << "\n\n\t\t\tEnter new price of Chocolate cookies: ";
					cin >> chocolatecookies->p_cookies;
				}
				else if (p6 == 2)
				{
					creamycookies->p_cookies = 0;
					cout << "\n\n\t\t\tEnter new price of Creamy Cookies: ";
					cin >> creamycookies->p_cookies;
				}
				else
				{
					exit(0);
				}
			}
			else { exit(0); }
			break;
		case 4:
			cout << "\n\n\t\t\tWhich item's price you want to edit?\n";
			cout << "\n\t\t\t1.TV\t\t2.Oven\n";
			cout << "\n\t\t\tenter your choice: ";
			int c4;
			cin >> c4;
			system("cls");
			if (c4 == 1)
			{
				cout << "\n\n\t\t\tWhich TV's price you want to edit: \n";
				cout << "\n\t\t\t1.LED TV\t\t2.LCD TV\n";
				cout << "\n\t\t\tenter your choice: ";
				int p7;
				cin >> p7;
				system("cls");
				if (p7 == 1)
				{
					ledtv->p_tv = 0;
					cout << "\n\n\t\t\tEnter new price of LED TV: ";
					cin >> ledtv->p_tv;
				}
				else if (p7 == 2)
				{
					lcdtv->p_tv = 0;
					cout << "\n\n\t\t\tEnter new price of LCD TV: ";
					cin >> lcdtv->p_tv;
				}
				else
				{
					exit(0);
				}
			}
			else if (c4 == 2)
			{
				cout << "\n\n\t\t\tWhich Oven's price you want to edit: \n";
				cout << "\n\t\t\t1.Gas Oven\t\t2.Microwave Oven\n";
				cout << "\n\t\t\tenter your choice: ";
				int p8;
				cin >> p8;
				system("cls");
				if (p8 == 1)
				{
					gasoven->p_oven = 0;
					cout << "\n\n\t\t\tEnter new price of Gas Oven: ";
					cin >> gasoven->p_oven;
				}
				else if (p8 == 2)
				{
					microwaveoven->p_oven = 0;
					cout << "\n\n\t\t\tEnter new price of Microwave Oven: ";
					cin >> microwaveoven->p_oven;
				}
				else
				{
					exit(0);
				}
			}
			else { exit(0); }
			break;
		default:
			exit(0);
		}
		cout << "\n\n\t\t\tDo yo want to edit price again?\n";
		cout << "\n\n\t\t\t1.Yes\t\t2.No\n";
		cout << "\n\t\t\tenter your choice: ";
		int num;
		cin >> num;
		system("cls");
		if (num == 1)
		{
			this->editprice();
		}
		else if (num == 2)
		{
			menu();
		}
	}
};



int main()
{
	int val = 0;
	int choice;
	int choice1;
	Registered* r1 = new Registered;
	Unregistered* ur1 = new Unregistered;
	cout << "\n\n\t\t\tWELCOME TO PRIMESPOT ONLINE STORE\n";
	cout << "\t\t\t*********************************\n";
	cout << "\n\t\t\tWHICH ONE ARE YOU? \n\n\t\t\t1.ADMIN\n\n\t\t\t2.COSTUMER\n";
	cout << "\n\t\t\tYOUR CHOICE: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		Admin* a1 = new Admin;
		system("cls");
		a1->inputpincode();
		break;
	}
	case 2:
	{
		system("cls");
		cout << "\n\t\t\tWELCOME TO PRIMESPOT ONLINE STORE";
		cout << "\n\t\t\t*********************************\n\n";
		cout << "\n\t\t\tWHICH TYPE OF COSTUMER ARE YOU: \n\n\t\t\t1.REGISTERED\n\n\t\t\t2.UNREGISTERED\n";
		cout << "\n\t\t\tYOUR CHOICE: ";
		cin >> choice1;
		switch (choice1)
		{
		case 1:
			system("cls");
			r1->inputdetails();
			break;

		case 2:
			system("cls");
			val = ur1->inputdetails();
			break;
		default:
			cout << "Error found!";
			exit(0);
		}
	}
	}
	if (val == 1)
	{
		r1->inputdetails();
	}
	Inventory i1;
	i1.AddInCart();
}
