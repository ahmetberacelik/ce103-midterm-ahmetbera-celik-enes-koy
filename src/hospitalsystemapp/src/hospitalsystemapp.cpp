
// Standard Libraries
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>
#include "../../hospitalsystem/header/hospitalsystem.h"  // Adjust this include path based on your project structure
using namespace std;

int main()
{
	cout << "WELCOME TO HOSPITAL APPOINTMENT AND MANAGEMENT SYSTEM\n";
	write_apostrophe();
	while (true)
	{
		cout << "Please select your user type number.\n" << "1--> Admin\n2--> Doctor\n3--> Patient\n";
		write_apostrophe();
		int user_type;
		cin >> user_type;
		if (user_type == 1)
		{
			break;
		}
		else if (user_type == 2)
		{
			break;
		}
		else if (user_type == 3)
		{
			cin.ignore();
			patient_registration();
			patient_menu();
			break;
		}
		else
		{
			cout << "You've entered wrong option number. Please try again...\n";
			continue;
		}
	}
	return 0;
}