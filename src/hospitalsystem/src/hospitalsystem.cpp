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

void apointment_scheduling()
{
	string any_key;
	int surgery_no;
	int delete_session;
	while (true) {
		write_apostrophe();
		cout << "APOINTMENT SCHEDULING\n";
		cout << "1 --> Doctor Availability\n";
		cout << "2 --> Treatment Sessions\n";
		cout << "3 --> Surgery Bookings\n";
		cout << "4 --> Delete Sessions\n";
		cout << "5 --> Exit Appointment Scheduling\n";
		write_apostrophe();
		cout << "Which action do you want to take?\n";
		int apointment_scheduling_menu;
		cin >> apointment_scheduling_menu;
		switch (apointment_scheduling_menu)
		{
		case 1:
			write_apostrophe();
			cout << doc[0] << " --> Monday (10:30-12:00)(Avaiable)		Thursday (13:00-16:30)(Avaiable)\n";
			cout << doc[1] << " --> Wednesday (09:30-11:00)(Avaiable)	                Friday (09:00-13:30)(Avaiable)\n";
			cout << doc[2] << " --> Tuesday (10:30-12:00)(Avaiable)		Wednesday (13:00-15:00)(Avaiable)\n";
			cout << doc[3] << " --> Monday (08:30-12:00)(Avaiable)		        Thursday (08:00-11:00)(Avaiable)\n";
			write_apostrophe();
			cout << "Press any key to continue...\n";
			cin.ignore();
			getline(cin, any_key);
			continue;
		case 2:
			if (patient_treatment_session[0].empty() && patient_treatment_session[1].empty()
				&& patient_treatment_session[2].empty() && patient_treatment_session[3].empty()
				&& patient_treatment_session[4].empty() && patient_treatment_session[5].empty()
				&& patient_treatment_session[6].empty() && patient_treatment_session[7].empty())
			{
				write_apostrophe();
				cout << "You do not currently have an appointment registered.\n";
				write_apostrophe();
				continue;
			}
			else
			{
				write_apostrophe();
				for (int i = 0; i < 8; i++)
				{
					if (patient_treatment_session[i].empty())
					{
						continue;
					}
					else {
						cout << patient_treatment_session[i] << "\n";
					}
				}
				continue;
			}
			break;
		case 3:
			write_apostrophe();
			cout << doc[0] << " (1) --> Monday (10:30-12:00)(Avaiable)		(2) --> Thursday (13:00-16:30)(Avaiable)\n";
			cout << doc[1] << " (3) --> Wednesday (09:30-11:00)(Avaiable)	(4) --> Friday (09:00-13:30)(Avaiable)\n";
			cout << doc[2] << " (5) --> Tuesday (10:30-12:00)(Avaiable)		(6) --> Wednesday (13:00-15:00)(Avaiable)\n";
			cout << doc[3] << " (7) --> Monday (08:30-12:00)(Avaiable)		(8) --> Thursday (08:00-11:00)(Avaiable)\n";
			write_apostrophe();
			cin.ignore();
			cout << "Please select a session.\n";
			cin >> surgery_no;
			switch (surgery_no)
			{
			case 1:
				write_apostrophe();
				cout << "Yout took session number 1...\n";
				patient_treatment_session[0] = "(Session 1) --> " + doc[0] + " --> Monday (10:30-12:00)\n";
				cout << patient_treatment_session[0];
				write_apostrophe();
				break;
			case 2:
				write_apostrophe();
				cout << "Yout took session number 2...\n";
				patient_treatment_session[1] = "(Session 2) --> " + doc[0] + " --> Thursday (13:00-16:30)(Avaiable)\n";
				cout << patient_treatment_session[1];
				write_apostrophe();
				break;
			case 3:
				write_apostrophe();
				cout << "Yout took session number 3...\n";
				patient_treatment_session[2] = "(Session 3) --> " + doc[1] + " --> Wednesday (09:30-11:00)\n";
				cout << patient_treatment_session[2];
				write_apostrophe();
				break;
			case 4:
				write_apostrophe();
				cout << "Yout took session number 4...\n";
				patient_treatment_session[3] = "(Session 4) --> " + doc[1] + " --> Friday (09:00-13:30)\n";
				cout << patient_treatment_session[3];
				write_apostrophe();
				break;
			case 5:
				write_apostrophe();
				cout << "Yout took session number 5...\n";
				patient_treatment_session[4] = "(Session 5) --> " + doc[2] + " --> Tuesday (10:30-12:00)\n";
				cout << patient_treatment_session[4];
				write_apostrophe();
				break;
			case 6:
				write_apostrophe();
				cout << "Yout took session number 6...\n";
				patient_treatment_session[5] = "(Session 6) --> " + doc[2] + " --> Wednesday (13:00-15:00)\n";
				cout << patient_treatment_session[5];
				write_apostrophe();
				break;
			case 7:
				write_apostrophe();
				cout << "Yout took session number 7...\n";
				patient_treatment_session[6] = "(Session 7) --> " + doc[3] + " --> Monday (08:30-12:00)\n";
				cout << patient_treatment_session[6];
				write_apostrophe();
				break;
			case 8:
				write_apostrophe();
				cout << "Yout took session number 8...\n";
				patient_treatment_session[7] = "(Session 8) --> " + doc[3] + " --> Thursday (08:00-11:00)\n";
				cout << patient_treatment_session[7];
				write_apostrophe();
				break;
			default:
				write_apostrophe();
				cout << "You've entered wrong session number. Please try again...\n";
				continue; //In this part,if I enter a letter I take an eror. Loop continues forever and don't stop!
			}
			continue;
		case 4:
			if (patient_treatment_session[0].empty() && patient_treatment_session[1].empty()
				&& patient_treatment_session[2].empty() && patient_treatment_session[3].empty()
				&& patient_treatment_session[4].empty() && patient_treatment_session[5].empty()
				&& patient_treatment_session[6].empty() && patient_treatment_session[7].empty())
			{
				write_apostrophe();
				cout << "You do not currently have an appointment registered.\n";
				write_apostrophe();
				continue;
			}
			else
			{
				write_apostrophe();
				for (int i = 0; i < 8; i++)
				{
					if (patient_treatment_session[i].empty())
					{
						continue;
					}
					else {
						cout << patient_treatment_session[i] << "\n";
					}
				}
				cout << "Please select the session you want to delete\n";
				cin >> delete_session;
				switch (delete_session)
				{
				case 1:
					if (patient_treatment_session[0].empty())
					{
						write_apostrophe();
						cout << "You made a mistake. The session that you selected is not exist.\n";
						continue;
					}
					else
					{
						patient_treatment_session[0] = "";
						write_apostrophe();
						cout << "Your session has been deleted...\n";
						continue;
					}
				case 2:
					if (patient_treatment_session[1].empty())
					{
						write_apostrophe();
						cout << "You made a mistake. The session that you selected is not exist.\n";
						continue;
					}
					else
					{
						patient_treatment_session[1] = "";
						write_apostrophe();
						cout << "Your session has been deleted...\n";
						continue;
					}
				case 3:
					if (patient_treatment_session[2].empty())
					{
						write_apostrophe();
						cout << "You made a mistake. The session that you selected is not exist.\n";
						continue;
					}
					else
					{
						patient_treatment_session[2] = "";
						write_apostrophe();
						cout << "Your session has been deleted...\n";
						continue;
					}
				case 4:
					if (patient_treatment_session[3].empty())
					{
						write_apostrophe();
						cout << "You made a mistake. The session that you selected is not exist.\n";
						continue;
					}
					else
					{
						patient_treatment_session[3] = "";
						write_apostrophe();
						cout << "Your session has been deleted...\n";
						continue;
					}
				case 5:
					if (patient_treatment_session[4].empty())
					{
						write_apostrophe();
						cout << "You made a mistake. The session that you selected is not exist.\n";
						continue;
					}
					else
					{
						patient_treatment_session[4] = "";
						write_apostrophe();
						cout << "Your session has been deleted...\n";
						continue;
					}
				case 6:
					if (patient_treatment_session[5].empty())
					{
						write_apostrophe();
						cout << "You made a mistake. The session that you selected is not exist.\n";
						continue;
					}
					else
					{
						patient_treatment_session[5] = "";
						write_apostrophe();
						cout << "Your session has been deleted...\n";
						continue;
					}
				case 7:
					if (patient_treatment_session[6].empty())
					{
						write_apostrophe();
						cout << "You made a mistake. The session that you selected is not exist.\n";
						continue;
					}
					else
					{
						patient_treatment_session[6] = "";
						write_apostrophe();
						cout << "Your session has been deleted...\n";
						continue;
					}
				case 8:
					if (patient_treatment_session[7].empty())
					{
						write_apostrophe();
						cout << "You made a mistake. The session that you selected is not exist.\n";
						continue;
					}
					else
					{
						patient_treatment_session[7] = "";
						write_apostrophe();
						cout << "Your session has been deleted...\n";
						continue;
					}
				default:
					write_apostrophe();
					cout << "You made a mistake. The session that you selected is not exist.\n";
					continue;
				}
				continue;
			}
			continue;
		case 5:
			break;
		default:
			write_apostrophe();
			cout << "You've entered wrong option number. Please try again...\n";
			continue; //In this part,if I enter a letter I take an eror. Loop continues forever and don't stop!
		}
		break;
	}
}