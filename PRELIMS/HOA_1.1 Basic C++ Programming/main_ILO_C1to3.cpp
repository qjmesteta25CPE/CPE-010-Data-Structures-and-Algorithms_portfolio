#include<iostream>
#include<cmath>
void varswap();
float Kel_Fahr_Converter(float Kelvin);
float Distance_Computation(float x1, float x2, float y1, float y2);

int main(){

    int choice;

    do{
        std::cout<<"Welcome to the Menu \n";
        std::cout<<"Type 1 for Variable Swapping \n";
        std::cout<<"Type 2 for Kelvin to CFahrenheit convertion \n";
        std::cout<<"Type 3 for Distance Calculator \n";
        std::cout<<"Type 4 to exit program \n";
    
        std::cin>>choice;
    
        switch (choice){
            case 1:
            {
                varswap();
            }   
                break;
            case 2:
            {
                float Kelvin;
                std::cout<<"Enter The temperature in Kelvin to conver to Fahrenheit: ";
                std::cin>>Kelvin;
                float Fahr= Kel_Fahr_Converter(Kelvin);
                std::cout<<"\n The Kelvin Temperature in Fahrenheit is : "<<Fahr<<std::endl;
                break;
            }
            case 3: 
            {
                float x1, x2, y1, y2;
                
                std::cout<<"Enter your X values: \n";
                std::cout<<"X1: ";
                std::cin>>x1;
                std::cout<<"\n X2:";
                std::cin>>x2;

                std::cout << "Please Enter your Y Values: \n";
                std::cout << "\n y1: ";
                std::cin >> y1;
                std::cout << "\n y2: ";
                std::cin >> y2;
    
                float DistancebetweenTwoPoints = Distance_Computation(x1, x2, y1, y2);
                std::cout << "\n The distance between two points is: " << DistancebetweenTwoPoints<< std::endl;
                break;
            }
            case 4: 
            {
                std::cout<<"Goodbye!! \n";
                break;
            }
            default:
                std::cout<<"Invalid Input, Try Again! \n";
        }
    }while (choice !=4);
    return 0;
}

void varswap(){
    int Var1, Var2, Var3;

    std::cout<<"Enter your First Number:  \n";
    std::cin>> Var1;
    
    std::cout<<"Enter your Second Number: \n";
    std::cin>> Var2;

    std::cout<<"Your orignal numbers are: \n";
    std::cout<<"First Number: "<<Var1<<std::endl;
    std::cout<<"Second NUmber: "<<Var2<<std::endl;

    Var3=Var1;
    Var1=Var2;
    Var2=Var3;

    std::cout<<"Your Swapped Numbers are: \n";
    std::cout<<"First Number: "<<Var1<<std::endl;
    std::cout<<"Second Number: "<<Var2<<std::endl;

}
float Kel_Fahr_Converter(float Kelvin){
    
    return (9/5*(Kelvin-273.15))+ 32;
}
float Distance_Computation(float x1, float x2, float y1, float y2){
    float dif_x, dif_y;
    
    dif_x= x1-x2;
    dif_y= y1-y2;

    return sqrt(dif_x * dif_x + dif_y * dif_y);
}