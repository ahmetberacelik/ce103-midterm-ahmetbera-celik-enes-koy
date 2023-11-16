#include "../header/hospitalsystem.h"
#include <iostream>
#include <string>
using namespace std;

Informations informations;

int write_apostrophe()// Function to display a line of dashes as a separator
{
	cout << "----------------------------------------------------------------------------------\n";
	return 0;
}

int login()
{
	while (true)
	{
		// Function call to display a line separator
		write_apostrophe();
		cout << "Please select your user type number.\n" << "1--> Doctor\n2--> Patient\n";
		write_apostrophe();
		int user_type;
		if (!(cin >> user_type)) {
			// If the input is not a valid integer:
			cin.clear();  // Clear the error flag in cin to allow further input
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			// Ignore and discard the invalid input up to the maximum buffer size or newline character
			write_apostrophe();
			cout << "Invalid input. Please enter a number.\n";
			write_apostrophe();
			continue;
		}
		if (user_type == 1)
		{
			// Function call to display the doctor's menu
			doctor_menu();
			cout << "Have a nice day...";
			break; // Exit the loop, ending the process
		}
		else if (user_type == 2)
		{
			// Ignores the current line if the user is a patient
			cin.ignore();
			if (informations.patient_name.empty()) //We defined this because if the user enters the patient once they won't need to enter it again.
			{
				// Function call to register the patient
				patient_registration();
			}
			// Function call to display the patient's menu
			patient_menu();
			break;
		}
		else
		{
			write_apostrophe();
			cout << "You've entered wrong option number. Please try again...\n";
			write_apostrophe();
			continue; //Go back to the beginning of the loop to wait for valid input
		}
	}
	return 0;// The function completes successfully
}

int patient_registration()
{
	write_apostrophe();
	cout << "PATIENT REGISTRATION SYSTEM\n";
	write_apostrophe();
	// Prompt the user to enter their name
	cout << "Please enter your name: \n";
	string login_patient_name;
	// Store the entered name in a variable
	getline(cin, login_patient_name);
	// Store the entered patient name in the 'informations' structure
	informations.patient_name = login_patient_name;
	// Prompt the user to enter their medical history
	cout << "Please enter your medical history: \n";
	string login_patient_medical_history;
	// Store the entered medical history in a variable
	getline(cin, login_patient_medical_history);
	// Store the entered patient medical history in the 'informations' structure
	informations.patient_medical_history = login_patient_medical_history;
	// The function completes successfully
	return 0;
}

int patient_menu()
{
	while (true) {
		write_apostrophe();
		cout << "PATIENT SYSTEM\n";
		cout << "1 --> Appointment Scheduling\n";
		cout << "2 --> Patient Management\n";
		cout << "3 --> Staff Management\n";
		cout << "4 --> Integrations\n";
		cout << "5 --> Switch User\n";
		cout << "6 --> Log Out Of System\n";
		write_apostrophe();
		cout << "Which action do you want to take?\n";
		int patient_menu_selection;
		// Check if the input is not a valid integer
		if (!(cin >> patient_menu_selection)) {
			// If the input is not a valid integer:
			cin.clear();  // Clear the error flag in cin to allow further input
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			// Ignore and discard the invalid input up to the maximum buffer size or newline character
			write_apostrophe();
			cout << "Invalid input. Please enter a number.\n";
			continue;// Go back to the beginning of the loop to wait for valid input
		}
		switch (patient_menu_selection)
		{
		case 1:
			// Function call to handle appointment scheduling
			appointment_scheduling();
			// Continue to display the patient menu after scheduling
			continue;
		case 2:
			// Function call to handle patient management
			patient_management();
			continue;
		case 3:
			// Function call to handle staff management
			staff_management();
			continue;
		case 4:
			// Function call to handle integrations
			integrations();
			continue;
		case 5:
			// Function call to switch user (login screen)
			login();
			break;
		case 6:
			// Exit the loop, ending the process
			break;
		default:
			write_apostrophe();
			cout << "You've entered wrong option number. Please try again...\n";
			continue;
		}
		// Sends a farewell message to the user
		cout << "Have a nice day...";
		break;
	}
	return 0;
}

int appointment_scheduling()
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
		// Check if the input is not a valid integer
		if (!(cin >> apointment_scheduling_menu)) {
			// If the input is not a valid integer:
			cin.clear();  // Clear the error flag in cin to allow further input
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			// Ignore and discard the invalid input up to the maximum buffer size or newline character

			write_apostrophe();
			cout << "Invalid input. Please enter a number.\n";
			continue;
		}

		switch (apointment_scheduling_menu)
		{
		case 1:
			// Displays doctors' availability schedule for different days and time slots
		// Information regarding each doctor's availability on specific days is printed
		// (assuming `informations.doc[]` stores this information)
			write_apostrophe();
			cout << informations.doc[0] << " --> Monday (10:30-12:00)(Avaiable)		Thursday (13:00-16:30)(Avaiable)\n";
			cout << informations.doc[1] << " --> Wednesday (09:30-11:00)(Avaiable)	                Friday (09:00-13:30)(Avaiable)\n";
			cout << informations.doc[2] << " --> Tuesday (10:30-12:00)(Avaiable)		Wednesday (13:00-15:00)(Avaiable)\n";
			cout << informations.doc[3] << " --> Monday (08:30-12:00)(Avaiable)		        Thursday (08:00-11:00)(Avaiable)\n";
			write_apostrophe();
			cout << "Press any key to continue...\n";// Prompts the user to press any key to continue
			cin.ignore();
			getline(cin, any_key);// Accepts the user's input (stores in any_key variable)
			continue; //Continues the loop, allowing the user to select another action
		case 2:
			// Check if the patient has any treatment sessions registered
			if (informations.patient_treatment_session[0].empty() && informations.patient_treatment_session[1].empty()
				&& informations.patient_treatment_session[2].empty() && informations.patient_treatment_session[3].empty()
				&& informations.patient_treatment_session[4].empty() && informations.patient_treatment_session[5].empty()
				&& informations.patient_treatment_session[6].empty() && informations.patient_treatment_session[7].empty())
			{
				// If no treatment sessions are registered for the patient:
				write_apostrophe();
				cout << "You do not currently have an appointment registered.\n";// Informs the user about the absence of appointments
				write_apostrophe();
				continue;// Continues the loop, allowing the user to select another action
			}
			else
			{
				// If treatment sessions are registered for the patient:
				write_apostrophe();
				for (int i = 0; i < 8; i++)
				{
					if (informations.patient_treatment_session[i].empty())
					{
						continue;// Skips empty treatment sessions
					}
					else {
						cout << informations.patient_treatment_session[i] << "\n";// Displays the registered treatment sessions
					}
				}
				continue;
			}
			break;// Exit the switch block
		case 3:
			// Display the available sessions for doctors
			write_apostrophe();
			cout << informations.doc[0] << " (1) --> Monday (10:30-12:00)(Avaiable)		(2) --> Thursday (13:00-16:30)(Avaiable)\n";
			cout << informations.doc[1] << " (3) --> Wednesday (09:30-11:00)(Avaiable)	(4) --> Friday (09:00-13:30)(Avaiable)\n";
			cout << informations.doc[2] << " (5) --> Tuesday (10:30-12:00)(Avaiable)		(6) --> Wednesday (13:00-15:00)(Avaiable)\n";
			cout << informations.doc[3] << " (7) --> Monday (08:30-12:00)(Avaiable)		(8) --> Thursday (08:00-11:00)(Avaiable)\n";
			write_apostrophe();
			cin.ignore();// Ignores a character input (waits for user action)
			cout << "Please select a session.\n";
			// Check if the input is not a valid integer
			if (!(cin >> surgery_no)) {
				// If the input is not a valid integer:
				cin.clear();  // Clear the error flag in cin to allow further input
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				// Ignore and discard the invalid input up to the maximum buffer size or newline character

				write_apostrophe();
				cout << "Invalid input. Please enter a number.\n";
				continue;
			}
			switch (surgery_no)
			{
			case 1:
				// For session number 1, updates and displays the patient's treatment session
				write_apostrophe();
				cout << "Yout took session number 1...\n";// Informs the user about the session selection
				informations.patient_treatment_session[0] = "(Session 1) --> " + informations.doc[0] + " --> Monday (10:30-12:00)\n";
				cout << informations.patient_treatment_session[0];// Displays the selected treatment session
				write_apostrophe();
				break;
			case 2:
				// For session number 2, updates and displays the patient's treatment session
				write_apostrophe();
				cout << "Yout took session number 2...\n";
				informations.patient_treatment_session[1] = "(Session 2) --> " + informations.doc[0] + " --> Thursday (13:00-16:30)(Avaiable)\n";
				cout << informations.patient_treatment_session[1];
				write_apostrophe();
				break;
			case 3:
				// For session number 3, updates and displays the patient's treatment session
				write_apostrophe();
				cout << "Yout took session number 3...\n";
				informations.patient_treatment_session[2] = "(Session 3) --> " + informations.doc[1] + " --> Wednesday (09:30-11:00)\n";
				cout << informations.patient_treatment_session[2];
				write_apostrophe();
				break;
			case 4:
				// For session number 4, updates and displays the patient's treatment session
				write_apostrophe();
				cout << "Yout took session number 4...\n";
				informations.patient_treatment_session[3] = "(Session 4) --> " + informations.doc[1] + " --> Friday (09:00-13:30)\n";
				cout << informations.patient_treatment_session[3];
				write_apostrophe();
				break;
			case 5:
				// For session number 5, updates and displays the patient's treatment session
				write_apostrophe();
				cout << "Yout took session number 5...\n";
				informations.patient_treatment_session[4] = "(Session 5) --> " + informations.doc[2] + " --> Tuesday (10:30-12:00)\n";
				cout << informations.patient_treatment_session[4];
				write_apostrophe();
				break;
			case 6:
				// For session number 6, updates and displays the patient's treatment session
				write_apostrophe();
				cout << "Yout took session number 6...\n";
				informations.patient_treatment_session[5] = "(Session 6) --> " + informations.doc[2] + " --> Wednesday (13:00-15:00)\n";
				cout << informations.patient_treatment_session[5];
				write_apostrophe();
				break;
			case 7:
				// For session number 7, updates and displays the patient's treatment session
				write_apostrophe();
				cout << "Yout took session number 7...\n";
				informations.patient_treatment_session[6] = "(Session 7) --> " + informations.doc[3] + " --> Monday (08:30-12:00)\n";
				cout << informations.patient_treatment_session[6];
				write_apostrophe();
				break;
			case 8:
				// For session number 8, updates and displays the patient's treatment session
				write_apostrophe();
				cout << "Yout took session number 8...\n";
				informations.patient_treatment_session[7] = "(Session 8) --> " + informations.doc[3] + " --> Thursday (08:00-11:00)\n";
				cout << informations.patient_treatment_session[7];
				write_apostrophe();
				break;
			default:
				write_apostrophe();
				cout << "You've entered wrong session number. Please try again...\n";
				continue;
			}
			continue;
		case 4:
			// Check if the patient has any treatment sessions registered
			if (informations.patient_treatment_session[0].empty() && informations.patient_treatment_session[1].empty()
				&& informations.patient_treatment_session[2].empty() && informations.patient_treatment_session[3].empty()
				&& informations.patient_treatment_session[4].empty() && informations.patient_treatment_session[5].empty()
				&& informations.patient_treatment_session[6].empty() && informations.patient_treatment_session[7].empty())
			{
				// If no treatment sessions are registered for the patient:
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
					if (informations.patient_treatment_session[i].empty())
					{
						continue; // Skips empty treatment sessions
					}
					else {
						cout << informations.patient_treatment_session[i] << "\n";
					}
				}
				cout << "Please select the session you want to delete\n";
				// Check if the input is not a valid integer
				if (!(cin >> delete_session)) {
					// If the input is not a valid integer:
					cin.clear();  // Clear the error flag in cin to allow further input
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					// Ignore and discard the invalid input up to the maximum buffer size or newline character

					write_apostrophe();
					cout << "Invalid input. Please enter a number.\n";
					continue;
				}
				switch (delete_session)
					// Cases 1 to 8 handle deletion of sessions based on user selection
				{
				case 1:
					if (informations.patient_treatment_session[0].empty())
					{
						write_apostrophe();
						cout << "You made a mistake. The session that you selected is not exist.\n";
						continue;
					}
					else
					{
						informations.patient_treatment_session[0] = "";
						write_apostrophe();
						cout << "Your session has been deleted...\n";
						continue;
					}
				case 2:
					if (informations.patient_treatment_session[1].empty())
					{
						write_apostrophe();
						cout << "You made a mistake. The session that you selected is not exist.\n";
						continue;
					}
					else
					{
						informations.patient_treatment_session[1] = "";
						write_apostrophe();
						cout << "Your session has been deleted...\n";
						continue;
					}
				case 3:
					if (informations.patient_treatment_session[2].empty())
					{
						write_apostrophe();
						cout << "You made a mistake. The session that you selected is not exist.\n";
						continue;
					}
					else
					{
						informations.patient_treatment_session[2] = "";
						write_apostrophe();
						cout << "Your session has been deleted...\n";
						continue;
					}
				case 4:
					if (informations.patient_treatment_session[3].empty())
					{
						write_apostrophe();
						cout << "You made a mistake. The session that you selected is not exist.\n";
						continue;
					}
					else
					{
						informations.patient_treatment_session[3] = "";
						write_apostrophe();
						cout << "Your session has been deleted...\n";
						continue;
					}
				case 5:
					if (informations.patient_treatment_session[4].empty())
					{
						write_apostrophe();
						cout << "You made a mistake. The session that you selected is not exist.\n";
						continue;
					}
					else
					{
						informations.patient_treatment_session[4] = "";
						write_apostrophe();
						cout << "Your session has been deleted...\n";
						continue;
					}
				case 6:
					if (informations.patient_treatment_session[5].empty())
					{
						write_apostrophe();
						cout << "You made a mistake. The session that you selected is not exist.\n";
						continue;
					}
					else
					{
						informations.patient_treatment_session[5] = "";
						write_apostrophe();
						cout << "Your session has been deleted...\n";
						continue;
					}
				case 7:
					if (informations.patient_treatment_session[6].empty())
					{
						write_apostrophe();
						cout << "You made a mistake. The session that you selected is not exist.\n";
						continue;
					}
					else
					{
						informations.patient_treatment_session[6] = "";
						write_apostrophe();
						cout << "Your session has been deleted...\n";
						continue;
					}
				case 8:
					if (informations.patient_treatment_session[7].empty())
					{
						write_apostrophe();
						cout << "You made a mistake. The session that you selected is not exist.\n";
						continue;
					}
					else
					{
						informations.patient_treatment_session[7] = "";
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
			continue;
		}
		break;
	}
	return 0;
}

int patient_management()
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
		// Check if the input is not a valid integer
		if (!(cin >> patient_management_menu)) {
			// If the input is not a valid integer:
			cin.clear();  // Clear the error flag in cin to allow further input
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			// Ignore and discard the invalid input up to the maximum buffer size or newline character

			write_apostrophe();
			cout << "Invalid input. Please enter a number.\n";
			continue;
		}
		switch (patient_management_menu) {
		case 1:
			cout << "Please enter new name: \n";
			cin.ignore();
			getline(cin, changed_patient_name);
			informations.patient_name = changed_patient_name;
			cout << "Please enter new medical histroy: \n";
			getline(cin, changed_medical_history);
			informations.patient_medical_history = changed_medical_history;
			write_apostrophe();
			cout << "Your new name is: " << informations.patient_name << "\n";
			cout << "Your new medical history is: " << informations.patient_medical_history << "\n";
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
			cout << "Your name is: " << informations.patient_name << "\n";
			cout << "Your medical history is: " << informations.patient_medical_history << "\n";
			write_apostrophe();
			continue;
		case 4:
			break;
		default:
			write_apostrophe();
			cout << "You've entered wrong option number. Please try again...\n";
			continue;
		}
		break;
	}
	return 0;
}

int staff_management()
{
	string any_key_2;
	while (true) {
		write_apostrophe();
		cout << "STAFF MANAGEMENT\n";
		cout << "1 --> Doctor And Nurse Schedules\n";
		cout << "2 --> Specialization Tracking\n";
		cout << "3 --> Staff Training Records\n";
		cout << "4 --> Exit Staff Management\n";
		write_apostrophe();
		cout << "Which action do you want to take?\n";
		int staff_management_number;
		// Check if the input is not a valid integer
		if (!(cin >> staff_management_number)) {
			// If the input is not a valid integer:
			cin.clear();  // Clear the error flag in cin to allow further input
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			// Ignore and discard the invalid input up to the maximum buffer size or newline character

			write_apostrophe();
			cout << "Invalid input. Please enter a number.\n";
			continue;
		}
		switch (staff_management_number)
		{
		case 1:
			write_apostrophe();
			cout << "Doctor Schedules:\n";
			cout << informations.doc[0] << " --> Monday (10:30-12:00)(Avaiable)		Thursday (13:00-16:30)(Avaiable)\n";
			cout << informations.doc[1] << " --> Wednesday (09:30-11:00)(Avaiable)	                Friday (09:00-13:30)(Avaiable)\n";
			cout << informations.doc[2] << " --> Tuesday (10:30-12:00)(Avaiable)		Wednesday (13:00-15:00)(Avaiable)\n";
			cout << informations.doc[3] << " --> Monday (08:30-12:00)(Avaiable)		        Thursday (08:00-11:00)(Avaiable)\n";
			write_apostrophe();
			write_apostrophe();
			cout << "Nurse Schedules:\n";
			cout << informations.nurse[0] << " --> Monday (10:30-12:00)(Avaiable)		Thursday (13:00-16:30)(Avaiable)\n";
			cout << informations.nurse[1] << " --> Wednesday (09:30-11:00)(Avaiable)	                Friday (09:00-13:30)(Avaiable)\n";
			cout << informations.nurse[2] << " --> Tuesday (10:30-12:00)(Avaiable)		Wednesday (13:00-15:00)(Avaiable)\n";
			cout << informations.nurse[3] << " --> Monday (08:30-12:00)(Avaiable)		        Thursday (08:00-11:00)(Avaiable)\n";
			write_apostrophe();
			cout << "Press any key to continue...\n";
			cin.ignore();
			getline(cin, any_key_2);
			continue;
		case 2:
			write_apostrophe();
			cout << informations.doc[0] << " --> Specialization: Neurology  Education/Experience: Doctorate in Medicine"
				<< "Proficiency Level: Specialist\n";
			write_apostrophe();
			cout << informations.doc[1] << " --> Specialization: Cardiology  Education/Experience:"
				<< "Echocardiography Training  Proficiency Level : Advanced Level\n";
			write_apostrophe();
			cout << informations.doc[2] << " --> Specialization: Dermatology  Education/Experience:"
				<< "Dermatology Course   Proficiency Level : Entry Level\n";
			write_apostrophe();
			cout << informations.doc[3] << " --> Specialization: Pediatrics  Education/Experience:"
				<< "Pediatric Medicine Course  Proficiency Level : Advanced Level\n";
			write_apostrophe();
			cout << "Press any key to continue...\n";
			cin.ignore();
			getline(cin, any_key_2);
			continue;
		case 3:
			write_apostrophe();
			cout << "1 --> Staff Name: Mehmet Aksoy // Training Name: First Aid // Notes: Basic first aid training\n";
			cout << "2 --> Staff Name: Zeynep Karadeniz // Training Name: Fire Safety // Notes: Introduction to fire extinguishers\n";
			write_apostrophe();
			continue;
		case 4:
			break;
		default:
			write_apostrophe();
			cout << "You've entered wrong option number. Please try again...\n";
			continue;
		}
		break;
	}
	return 0;
}

int integrations()
{
	while (true)
	{
		write_apostrophe();
		cout << "INTERGATIONS\n";
		cout << "1--> Pharmacy System\n";
		cout << "2--> Telehealth platform\n";
		cout << "3--> Exit Integrations\n";
		write_apostrophe();
		cout << "Which action do you want to take?\n";
		int integrations_menu;
		// Check if the input is not a valid integer
		if (!(cin >> integrations_menu)) {
			// If the input is not a valid integer:
			cin.clear();  // Clear the error flag in cin to allow further input
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			// Ignore and discard the invalid input up to the maximum buffer size or newline character

			write_apostrophe();
			cout << "Invalid input. Please enter a number.\n";
			continue;
		}
		if (integrations_menu == 1)
		{
			write_apostrophe();
			if (!(informations.drug_features[2].empty()))
			{
				cout << "Active medications in your prescription: " << informations.drug_features[2] << "\n";
			}
			else
			{
				cout << "There is no drug record that you have...\n";
				cout << "To have active medication, you must have a doctor's prescription.\n";
			}
			continue;
		}
		else if (integrations_menu == 2)
		{
			write_apostrophe();
			cout << "Welcome to telehealth platform\n" << "Please select a problem in the list:\n";
			write_apostrophe();
			cout << "1--> My head is aching\n2--> I feel nauseous\n3-->I have muscle pain\n" <<
				"4-->I feel anxious\n5--> I have pain in one of my internal organs\n";
			write_apostrophe();
			cout << "Please select a issue.\n";
			int complaint_number;
			cin.ignore();
			// Check if the input is not a valid integer
			if (!(cin >> complaint_number)) {
				// If the input is not a valid integer:
				cin.clear();  // Clear the error flag in cin to allow further input
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				// Ignore and discard the invalid input up to the maximum buffer size or newline character

				write_apostrophe();
				cout << "Invalid input. Please enter a number.\n";
				continue;
			}
			switch (complaint_number)
			{
			case 1:
				write_apostrophe();
				cout << "You can take a painkiller. If you think it's something more serious, you can see a neurologist.\n";
				continue;
			case 2:
				write_apostrophe();
				cout << "You should avoid heavy meals when experiencing nausea or you can go aemergency service...\n";
				continue;
			case 3:
				write_apostrophe();
				cout << "You can take a painkiller or just rest\n";
				continue;
			case 4:
				write_apostrophe();
				cout << "Deep breathing can help reduce bodily stress or you can go to the psychiatric service.\n";
				cout << "A psychologist or psychiatrist can provide support through individual or group therapy\n";
				continue;
			case 5:
				write_apostrophe();
				cout << "You should go to the internal medicine department\n";
				continue;
			default:
				write_apostrophe();
				cout << "You've entered wrong option number. Please try again...\n";
				continue;
			}
			continue;
		}
		else if (integrations_menu == 3)
		{
			break;
		}
		else
		{
			write_apostrophe();
			cout << "You've entered wrong option number. Please try again...\n";
			continue;
		}
	}
	return 0;
}

int doctor_menu()
{
	while (true)
	{
		write_apostrophe();
		cout << "DOCTOR SYSTEM\n";
		cout << "1 --> Medical Records\n";
		cout << "2 --> Switch User\n";
		cout << "3 --> Log Out Of System\n";
		write_apostrophe();
		cout << "Which action do you want to take?\n";
		int doctor_menu_selection;
		cin >> doctor_menu_selection;
		if (doctor_menu_selection == 1)
		{
			while (true) {
				write_apostrophe();
				cout << "1 --> Prescription Management\n";
				cout << "2 --> Patient Progress Tracking\n";
				cout << "3 --> Turn Back\n";
				write_apostrophe();
				cout << "Which action do you want to take?\n";
				int records_number;
				// Check if the input is not a valid integer
				if (!(cin >> records_number)) {
					// If the input is not a valid integer:
					cin.clear();  // Clear the error flag in cin to allow further input
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					// Ignore and discard the invalid input up to the maximum buffer size or newline character

					write_apostrophe();
					cout << "Invalid input. Please enter a number.\n";
					continue;
				}
				switch (records_number)
				{
				case 1:
					cin.ignore();
					prescription_management();
					break;
				case 2:
					patient_progress_tracking();
					continue;
				case 3:
					break;
				default:
					write_apostrophe();
					cout << "You've entered wrong option number. Please try again...\n";
					continue;
				}
				break;
			}
		}
		else if (doctor_menu_selection == 2)
		{
			login();
			break;
		}
		else if (doctor_menu_selection == 3)
		{
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

int prescription_management()
{
	string patient_prescription;//I defined this in here because if I define in swtich-case there is a error.
	string drug_features_update;
	while (true)
	{
		write_apostrophe();
		cout << "Prescription Management\n";
		cout << "1 --> Add Prescription\n";
		cout << "2 --> Clean Prescription Record\n";
		cout << "3 --> Show Current Prescriptions\n";
		cout << "4 --> Exit Prescription Management\n";
		write_apostrophe();
		cout << "Which action do you want to take?\n";
		int prescription_menu_number;
		// Check if the input is not a valid integer
		if (!(cin >> prescription_menu_number)) {
			// If the input is not a valid integer:
			cin.clear();  // Clear the error flag in cin to allow further input
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			// Ignore and discard the invalid input up to the maximum buffer size or newline character

			write_apostrophe();
			cout << "Invalid input. Please enter a number.\n";
			continue;
		}
		switch (prescription_menu_number)
		{
		case 1:
			write_apostrophe();
			cout << "Patients:\n" << informations.default_patient_names[0] << "\n" << informations.default_patient_names[1] << "\n" << informations.patient_name << "\n";
			write_apostrophe();
			cout << "Which patient do you want to add prescription? Please write his/her name.\n";
			cin.ignore();
			getline(cin, patient_prescription);
			cout << "Please write the drug name and dosage\n";
			getline(cin, drug_features_update);
			if (patient_prescription == informations.default_patient_names[0])
			{
				informations.drug_features[0] = drug_features_update;
				continue;
			}
			else if (patient_prescription == informations.default_patient_names[1])
			{
				informations.drug_features[1] = drug_features_update;
				continue;
			}
			else if (patient_prescription == informations.patient_name)
			{
				informations.drug_features[2] = drug_features_update;
				continue;
			}
			else
			{
				write_apostrophe();
				cout << "You writed wrong patient name!\n";
				continue;
			}
		case 2:
			write_apostrophe();
			cout << "Patients:\n" << informations.default_patient_names[0] << "\n" << informations.default_patient_names[1] << "\n" << informations.patient_name << "\n";
			write_apostrophe();
			cout << "Which patient's prescription do you want to clean? Please write his/her name.\n";
			cin.ignore();
			getline(cin, patient_prescription);
			if (patient_prescription == informations.default_patient_names[0])
			{
				informations.drug_features[0] = "";
				cout << "Prescription has been cleaned!\n";
				continue;
			}
			else if (patient_prescription == informations.default_patient_names[1])
			{
				informations.drug_features[1] = "";
				cout << "Prescription has been cleaned!\n";
				continue;
			}
			else if (patient_prescription == informations.patient_name)
			{
				informations.drug_features[2] = "";
				cout << "Prescription has been cleaned!\n";
				continue;
			}
			else
			{
				write_apostrophe();
				cout << "You writed wrong patient name!\n";
				continue;
			}
		case 3:
			write_apostrophe();
			cout << "Patients:\n" << informations.default_patient_names[0] << "\n" << informations.default_patient_names[1] << "\n" << informations.patient_name << "\n";
			write_apostrophe();
			cout << "Which patient's prescription do you want to know ? Please write his/her name.\n";
			cin.ignore();
			getline(cin, patient_prescription);
			if (patient_prescription == informations.default_patient_names[0] && !(informations.drug_features[0].empty()))
			{
				write_apostrophe();
				cout << informations.default_patient_names[0] << "'s prescription is:\n" << informations.drug_features[0] << "\n";
				write_apostrophe();
				continue;
			}
			else if (patient_prescription == informations.default_patient_names[1] && !(informations.drug_features[1].empty()))
			{
				write_apostrophe();
				cout << informations.default_patient_names[1] << "'s prescription is:\n" << informations.drug_features[1] << "\n";
				write_apostrophe();
				continue;
			}
			else if (patient_prescription == informations.patient_name && !(informations.drug_features[2].empty()))
			{
				write_apostrophe();
				cout << informations.patient_name << "'s prescription is:\n" << informations.drug_features[2] << "\n";
				write_apostrophe();
				continue;
			}
			else
			{
				write_apostrophe();
				cout << "You writed wrong patient name or your patient which you selected has no prescription!\n";
				continue;
			}
		case 4:
			break;
		default:
			write_apostrophe();
			cout << "You've entered wrong option number. Please try again...\n";
			continue;
		}
		break;
	}
	return 0;
}

// This function, patient_progress_tracking(), simulates patient progress tracking within the system.
// It displays the status of the patients, such as missed appointments or the status of ongoing treatment.
// For instance, it notes that one patient missed their last appointment while the other patient's treatment continues without issues.
// This function provides a simple demonstration of patient progress information but doesn't incorporate real-time data.
int patient_progress_tracking()
{
	write_apostrophe();
	cout << "Patient " << informations.default_patient_names[0] << " has missed the last appointment.\n";
	cout << "Patient " << informations.default_patient_names[1] << "'s treatment continues without any problems.\n";
	write_apostrophe();
	return 0;
}