#include<iostream>
using namespace std;

void compute_total_change();

int main(){
    compute_total_change();

    return 0;
}

void compute_total_change(){
    double item_price, change, total = 0, received_Amount;
    char choice;

    do{
        cout<<"Enter Item price: \n";
        cin >> item_price;

        total += item_price;

        cout<<"Do you want to continue inputting Item price? Type (Y/N): \n";
        cin >> choice;
    }while (choice == 'Y'||choice == 'y');
    cout<< "Enter Received Amount: \n";
    cin>> received_Amount;
    change = received_Amount - total ;

    cout<<"Total Price is: " << total << endl;
    cout<< "Received amount is: "<< received_Amount << endl;
    cout<< "The Change is: "<< change << endl;
}