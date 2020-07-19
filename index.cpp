#include <iostream>
using namespace std;

#define max 10
int top;
string availableDeparture[4] = {"jogja", "magelang", "solo", "klaten"};
string availableDestination[4] = {"jakarta", "bogor", "depok", "tangerang"};

struct PROCESS{
    int id;
    string res;
};
struct busTicket {
    string idBus;
    string custName;
    string custPhone;
    string departure;
    string destination;
    int distance;
    string price;
    PROCESS proses;
} ticket[max];


void init(){
    top = -1;
}

bool isEmpty(){
    if(top <= 0 ){
        return true;
    } else {
        return false;
    }
}

bool isFull(){
    if(top == max - 1){
        return true;
    } else {
        return false;
    }
}

void mainMenu();
void bookTicket();


void addTicket(string idBus, string custName, string custPhone, string departure, string destination, int distance, string price){
    string totalPrice = "";

    if(isFull()){
        cout<<"Kursi sudah penuh";
    } else {
        top++;

        totalPrice = distance * 4000;

        ticket[top].idBus = idBus;
        ticket[top].custName = custName;
        ticket[top].custPhone = custPhone;
        ticket[top].departure = departure;
        ticket[top].destination = destination;
        ticket[top].distance = distance;
        ticket[top].price = totalPrice;

    }
}

void showTicket(){
    int backMenu;
    if(isEmpty()){
        cout<<"Data tiket kosong";
    } else {
        for(int i=1; i<top+1; i++){
            cout<<"BUS ID      : " <<ticket[i].idBus <<endl;
            cout<<"Customer    : " <<ticket[i].custName  <<endl;
            cout<<"Phone       : " <<ticket[i].custPhone <<endl;
            cout<<"Departure   : " <<ticket[i].departure <<endl;
            cout<<"Destination : " <<ticket[i].destination <<endl;
            cout<<"Distance    : " <<ticket[i].distance <<endl;
            cout<<"Price       : " <<ticket[top].proses.res <<endl;
        }
    }

    cout <<"\n\nPress 11 to back to menu : "; cin>>backMenu;
    if(backMenu == 11){
       mainMenu();
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

    cout<<"\n\nSilahkan ketik 11 untuk memesan tiket : "; cin>>backMenu;

    if(backMenu == 11){
        bookTicket();
    }


}

void bookTicket(){
    string idBus, custName, custPhone, Departure, Destination; int Distance, choice, availableService, backMenu;
    string price = "";

    cout<<"BUS ID          : "; cin.ignore(); getline(cin, idBus);
    cout<<"Customer Name   : "; cin>>custName;
    cout<<"Customer Phone  : "; cin.ignore(); getline(cin, custPhone);
    cout<<"Departure       : "; cin>>Departure;
    cout<<"Destination     : "; cin>>Destination;
    cout<<"Distance        : "; cin>>Distance;

    for(int i=0; i<4; i++){
        if( Departure != availableDeparture[i]  ){
            cout<<"Maaf, Keberangkatan dari " << Departure <<"untuk saat ini tidak tersedia";
            cout<<"\n\nSilahkan ketik 11 untuk melihat daftar keberangkatan dan tujuan : "; cin>>backMenu;

            if(availableService == 11){
                availableServiceList();
            }
        } else {
            addTicket(idBus, custName, custPhone, Departure, Destination, Distance, price);
            mainMenu();
        }

    }


    
}


void mainMenu(){

    int choice;
    menu : 
    system("clear");

    cout<<"______________________________________" <<endl;
    cout<<"|                                     |" <<endl;
    cout<<"|                                     |" <<endl;
    cout<<"|           BUS RESERVATION           |" <<endl;
    cout<<"|                                     |" <<endl;
    cout<<"|_____________________________________|" <<endl;
    cout<<"|                                     |" <<endl; 
    cout<<"|1.book     2.destination    3.price  |" <<endl;        
    cout<<"|_____________________________________|" <<endl <<endl;        

	cout << "Select menu : "; cin >> choice;

    switch(choice){
        case 1:
            bookTicket();
        break;
        case 2:
            showTicket();
        break;
        case 3:
            availableServiceList();
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