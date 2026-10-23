#include<iostream>
using namespace std;

void compute_quiztotal_avg();

int main(){
    compute_quiztotal_avg();

    return 0;
}

void compute_quiztotal_avg(){
    double quiz_grade, average, total = 0;
    int count = 0;
    char choice;

    do{
        cout<<"Enter quiz Grade: \n";
        cin >> quiz_grade;

        total += quiz_grade;
        count++;

        cout<<"Do you want to continue inputting quiz Grades? Type (Y/N): \n";
        cin >> choice;
    }while (choice == 'Y'||choice == 'y');

    average = total/count;

    cout<<"Total quiz grade is: " << total << endl;
    cout<< "Average quiz grade is: "<< average << endl;
}
