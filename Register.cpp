
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Register();
void Login();



int main() {
	int c;
	cout << "Welcome to the User Authentication System\n";
	cout << "[1] Login\n[2] Register\n";
	cout << "Enter your choice: ";
	cin >> c;
	switch (c)
	{
	case 1:
		system("cls");
		Login();
		break;
	case 2:
		system("cls");
		Register();
		break;
	default:
		cout << "SELECT A SERVICE";
		break;
	}
}

void Register() {
	cout << "=== Registration ===\n";
	string username, password;
	cout << "ENTER A USERNAME: ";
	cin >> username;
	cout << "ENTER A PASSWORD: ";
	cin >> password;
	ofstream file("login.txt", ios::app);
	file << username << " " << password;
	file.close();
	system("cls");
	main();
	
}

void Login() {
	cout << "=== Login ===\n";
	string line;
	string x, y;
	cout << "ENTER YOUR USERNAME: ";
	cin >> x;
	cout << "ENTER YOUR PASSWORD: ";
	cin >> y;
	ifstream InputFile("login.txt");
	bool found = false;

	while (getline(InputFile, line)) {
		size_t pos = line.find(" ");
		if (pos != string::npos) {
			string storedUsername = line.substr(0, pos);
			string storedPassword = line.substr(pos + 1);
			if (x == storedUsername && y == storedPassword)
			{
				cout << storedUsername << " IS LOGGED IN. ";
				found = true;
				break;
			}
		}

	}

	InputFile.close();

	if (found) {
		// Clear the contents of the file
		ofstream clearFile("login.txt", ofstream::out | ofstream::trunc);
		clearFile.close();
		cout << "File cleared after successful login." << endl;
	}
	else {
		cout << "ERROR: Invalid username or password" << endl;
	}
}