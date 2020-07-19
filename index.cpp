#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define max 10
int top;

string availableDeparture[4] = {"jogja", "magelang", "solo", "klaten"};
string availableDestination[4] = {"jakarta", "bogor", "depok", "tangerang"};


struct busTicket {
    string idBus;
    string custName;
    string custPhone;
    string departure;
    string destination;
    int distance;
    int price;
} ticket[max];


void init(){
    top = -1;
}

// cek apakah data kosong
bool isEmpty(){
    if(top <= 0 ){
        return true;
    } else {
        return false;
    }
}

// cek apakah data penuh
bool isFull(){
    if(top == max - 1){
        return true;
    } else {
        return false;
    }
}

void mainMenu();
void bookTicket();

// push method (nambah data)
void addTicket(string idBus, string custName, string custPhone, string departure, string destination, int distance, int price){
    int totalPrice;

    if( isFull() ){
        cout<<"Kursi sudah penuh";
    } else {
        top++;

        totalPrice = distance * 40000;

        ticket[top].idBus = idBus;
        ticket[top].custName = custName;
        ticket[top].custPhone = custPhone;
        ticket[top].departure = departure;
        ticket[top].destination = destination;
        ticket[top].distance = distance;
        ticket[top].price = totalPrice;

    }
}

// pop (delete data)
void deleteTicket(){

    if( isEmpty() ){
        cout<<"Data stack kosong";
    } else {
        // tampilkan data terakhir
        cout<<"BUS ID      : " <<ticket[top].idBus <<endl;
        cout<<"Customer    : " <<ticket[top].custName  <<endl;
        cout<<"Phone       : " <<ticket[top].custPhone <<endl;
        cout<<"Departure   : " <<ticket[top].departure <<endl;
        cout<<"Destination : " <<ticket[top].destination <<endl;
        cout<<"Distance    : " <<ticket[top].distance <<endl;
        cout<<"Price       : " <<"Rp." <<ticket[top].price <<endl;
        
        // hapus data pertama
        top--;
    }
}

void showTicket(){
    int backMenu;
    int delMenu;

    if(isEmpty()){
        cout<<"Data tiket kosong";
    } else {
            cout<<" ==== data penumpang ===" <<endl;

        for( int i=1; i<top+1; i++ ){
            cout<<"BUS ID      : " <<ticket[i].idBus <<endl;
            cout<<"Customer    : " <<ticket[i].custName  <<endl;
            cout<<"Phone       : " <<ticket[i].custPhone <<endl;
            cout<<"Departure   : " <<ticket[i].departure <<endl;
            cout<<"Destination : " <<ticket[i].destination <<endl;
            cout<<"Distance    : " <<ticket[i].distance <<endl;
            cout<<"Price       : " <<"Rp." <<ticket[i].price <<endl <<endl;
        }

    }

    cout <<"\n\n33 to delete first ticket || 11 to back to main menu : "; cin>>delMenu;
    
    if(delMenu == 11){
        mainMenu(); // kembali ke menu utama
    } else if(delMenu == 33){
        deleteTicket(); // fungsi pop / delete data 
    }

}

void availableServiceList(){
    int backMenu;
    cout<<endl<<endl;

    cout<<" ______________________________________"  <<endl;
    cout<<"|                                      |" <<endl;
    cout<<"|  Kota keberangkatan yang tersedia :  |" <<endl<<endl;
    for(int i=0; i<4; i++){
        cout<<"   - " <<availableDeparture[i] <<endl;
    }
    cout<<"|______________________________________|" <<endl;


    cout<<" ______________________________________"  <<endl;
    cout<<"|                                      |" <<endl;
    cout<<"|      Kota tujuan yang tersedia :     |" <<endl<<endl;
    for(int i=0; i<4; i++){
        cout<<"   - " <<availableDestination[i] <<endl;
    }
    cout<<"|______________________________________|" <<endl;

    cout<<"\n\nSilahkan ketik 22 untuk kembali ke menu utama : "; cin>>backMenu;

    if(backMenu == 22){
        system("clear");
        mainMenu();
    }


}

void bookTicket(){
    // buat variable
    string idBus, custName, custPhone, Departure, Destination; int Distance, choice, availableService, backMenu;
    int price;
    string finalDistance = "";

    // tangkap user input
    cout<<"BUS ID          : "; cin.ignore(); getline(cin, idBus);
    cout<<"Customer Name   : "; cin>>custName;
    cout<<"Customer Phone  : "; cin.ignore(); getline(cin, custPhone);
    cout<<"From            : "; cin>>Departure;
    cout<<"Destination     : "; cin>>Destination;
    cout<<"Distance        : "; cin>>Distance;

    // cek, apakah kota asal tersedia
    for(int i=0; i<4; i++){
        if( Departure == availableDeparture[i]  ){
            // panggil fungsi push
            addTicket(idBus, custName, custPhone, Departure, Destination, Distance, price);
            mainMenu();
        }  
    }
    
}


void mainMenu(){

    int choice;
    menu : 
    system("clear");

    cout<<"_________________________________________________" <<endl;
    cout<<"|                                                |" <<endl;
    cout<<"|                                                |" <<endl;
    cout<<"|                 BUS RESERVATION                |" <<endl;
    cout<<"|                                                |" <<endl;
    cout<<"|________________________________________________|" <<endl;
    cout<<"|                                                |" <<endl; 
    cout<<"|1.booking   2.destination   3.booked ticket     |" <<endl;        
    cout<<"|________________________________________________|" <<endl <<endl;        

	cout << "Select menu : "; cin >> choice;

    switch(choice){
        case 1:
            bookTicket();
        break;
        case 2:
            availableServiceList();
        break;
        case 3:
            showTicket();
        break;
        case 4:
            init();
        break;
        case 5:
            system("exit");
        break;  
    }
}




int main(void){

    mainMenu();


}