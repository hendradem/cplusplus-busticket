#include <iostream>
using namespace std;

// void MainMenu(){
//     Console.Clear();
//     Console.WriteLine(" ____________________________________________________");
//     Console.WriteLine("|                                                   |");
//     Console.WriteLine("|                                                   |");
//     Console.WriteLine("|                       WELCOME                     |");
//     Console.WriteLine("|                    Ticketing App                  |");
//     Console.WriteLine("|                                                   |");
//     Console.WriteLine("|___________________________________________________|");
//     Console.WriteLine("|                                                   |");
//     Console.WriteLine("| 1.HOME |  2.BOOK | 3.EVENT LIST | 4.BOOKING HOTEL |");
//     Console.WriteLine("|___________________________________________________|");
//     Console.Write("\r\nSelect an option: ");

//     switch (Console.ReadLine())
//     {
//         case 1:
//             cout<<"asdasd";
//             return true;
//         case 2:
//             cout<<"asdasd";
//             return true;
//         case 3:
//             cout<<"asdasd";
//             return true;
//         case 4:
//             cout<<"asdasd";
//             return true;
//         default:
//             return true;
//     }
// }



bool processMenu() {
	cout << "Main Menu" << endl;
	cout << "Select your favorite food" << endl;
	cout << "1. Cheese Burger" << endl;
	cout << "2. Ramen" << endl;
	cout << "3. Mashed Potatos" << endl;

	char choice;
	cin >> choice;

	if (choice=='1') {
		cout << "Hold the pickle, hold the lettuce." << endl;
	} else if (choice=='2') {
		cout << "Yum, with extra naruto." << endl;
	} else if (choice=='3') {
		cout << "Don't forget the gravy." << endl;
	} else {
		return false;
	}

	return true;
}


int main(void){

    while (!processMenu()) {
		cout << "Sorry, that is not a valid choice." << endl;
		cout << "Please try again." << endl << endl << endl;
	}


}