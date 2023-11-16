#ifndef HOSPITALSYSTEM_H
#define HOSPITALSYSTEM_H
#include "../../utility/header/commonTypes.h"
using namespace std;

struct Informations
{
	string patient_name;
	string patient_medical_history;
	string default_patient_names[2] = { "Radi Yilmaz","Ayse Batmaz" };
	string doc[4] = { "Ahmet Bera Celik","Enes Koy","Hasan Basri Taskin","Yakup Eroglu" };
	string nurse[4] = { "Gamze Kaplan","Merve Demir","Sevda Ozturk","Bilgi Vural" };
	string patient_treatment_session[8];
	string drug_features[3];
};

int write_apostrophe();

int login();

int patient_registration();
int patient_menu();
int appointment_scheduling();
int patient_management();
int staff_management();
int integrations();

int doctor_menu();
int prescription_management();
int patient_progress_tracking();

int switch_user();

#endif // HOSPITALSYSTEM_H