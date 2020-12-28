#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include<conio.h>
using namespace std;

void showFile();
void menu();
void show_currentDateTime();
void show_doctors();
void show_nurses();

string doctors[100];
string nurses[100];

int doc = 0;
int nur = 0;

int main()
{
	
	showFile();
	menu();
	int option;
	cout << '\n';
	cout << "Your option : ";
	cin >> option;
	switch(option)
	{
		case 1: show_doctors();				break;
		case 2: show_nurses();				break;
		case 3: show_currentDateTime();		break;
		default: exit(0);
	}
	
	cout << "\nEnter any key to exit !!  ";
	getch();
}

void menu()
{
	cout << "\n\n";
	cout << "Enter one of options below :\n";
	cout << "1.Show doctors list\n";
	cout << "2.Show nurses list\n";
	cout << "3.Show cuurent time\n";
	cout << "4.exit\n";
}

void showFile()
{
	
	ifstream read;
	read.open("myfile.csv");
	
	if(!read)
	{
		cout << "No such file directory !!\n";
		exit(0);
	}
	
	cout << '\n';
	cout << "My excel file doctors and nurses list [name, last name, id, salary, job]\n\n";	
	string line , tmp;
	char x;
	read >> x >> x >> x ;
	char comma = ',';
	while(read >> line)
	{
		cout << "\t" << line << "\n";
		if(line[line.size() - 1] == 'r')
			doctors[doc++] = line.substr(0, line.size() - 7);
		else
			nurses[nur++] = line.substr(0, line.size() - 6);
	}
		
	read.close();	

}

void show_currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d  %X", &tstruct);
    cout << "\nCurrent date and time :\t" << buf << "\n";
}

void show_doctors()
{
	cout << "\n";
	cout << "Doctors list [name, last name, id, salary] :\n\n";
	for(int i = 0 ; i < doc; i++)
		cout << "\t" << doctors[i] << "\n";
	
	cout << "\n";	
}

void show_nurses()
{
	cout << "\n";
	cout << "Nurses list [name, last name, id, salary] :\n\n";
	for(int i = 0; i < nur; i++)
		cout << "\t" << nurses[i] << "\n";
	
	cout << "\n";
}

