#include "../header/hospitalsystem.h"
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

string patient_name;
string patient_medical_history;
string doc[4] = { "Ahmet Bera Celik","Enes Koy","Hasan Basri Taskin","Yakup Eroglu" };
string patient_treatment_session[8];

void write_apostrophe()
{
	cout << "----------------------------------------------------------------------------------\n";
}

void patient_registration()
{
	write_apostrophe();
	cout << "PATIENT REGISTRATION SYSTEM\n";
	write_apostrophe();
	cout << "Please enter your name: \n";
	string login_patient_name;
	getline(cin, login_patient_name);
	patient_name = login_patient_name;
	cout << "Please enter your medical history: \n";
	string login_patient_medical_history;
	getline(cin, login_patient_medical_history);
	patient_medical_history = login_patient_medical_history;
}

void patient_menu()
{
	while (true) {
		write_apostrophe();
		cout << "PATIENT SYSTEM\n";
		cout << "1 --> Appointment Scheduling\n";
		cout << "2 --> Patient Management\n";
		cout << "3 --> Integrations\n";
		cout << "4 --> Log Out Of System\n";
		write_apostrophe();
		cout << "Which action do you want to take?\n";
		int patient_menu_selection;
		cin >> patient_menu_selection;
		switch (patient_menu_selection)
		{
		case 1:
			apointment_scheduling();
			continue;
		case 2:
			patient_management();
			continue;
		case 3:
			break;
		case 4:
			break;
		default:
			write_apostrophe();
			cout << "You've entered wrong option number. Please try again...\n";
		}
		cout << "Have a nice day...";
		break;
	}
}

void patient_management()
{
	string changed_patient_name;
	string changed_medical_history;
	string delete_check;
	while (true)
	{
		write_apostrophe();
		cout << "PATIENT MANAGEMENT\n";
		cout << "1 --> Registration Update\n";
		cout << "2 --> Delete Registration\n";
		cout << "3 --> Show Patient Information\n";
		cout << "4 --> Exit Patient Management\n";
		write_apostrophe();
		cout << "Which action do you want to take?\n";
		int patient_management_menu;
		cin >> patient_management_menu;

		switch (patient_management_menu) {
		case 1:
			cout << "Please enter new name: \n";
			cin.ignore();
			getline(cin, changed_patient_name);
			patient_name = changed_patient_name;
			cout << "Please enter new medical histroy: \n";
			getline(cin, changed_medical_history);
			patient_medical_history = changed_medical_history;
			write_apostrophe();
			cout << "Your new name is: " << patient_name << "\n";
			cout << "Your new medical history is: " << patient_medical_history << "\n";
			write_apostrophe();
			continue;
		case 2:
			write_apostrophe();
			cout << "You've entered Delete Registration\n";
			cout << "If you realy want to delete your patient registration, than write 'Delete Registration'.\n";
			cout << "If you don't want, press another key.\n";
			write_apostrophe();
			cin.ignore();
			getline(cin, delete_check);
			if (delete_check == "Delete Registration")
			{
				write_apostrophe();
				cout << "Your patient registration has been deleted. Please register again.\n";
				write_apostrophe();
				patient_registration();
				break;
			}
			else
			{
				continue;
			}
			break;
		case 3:
			write_apostrophe();
			cout << "Your name is: " << patient_name << "\n";
			cout << "Your medical history is: " << patient_medical_history << "\n";
			write_apostrophe();
			continue;
		case 4:
			break;
		default:
			write_apostrophe();
			cout << "You've entered wrong option number. Please try again...\n";
			continue; //In this part,if I enter a letter I take an eror. Loop continues forever and don't stop!
		}
		break;
	}
}
