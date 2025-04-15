// Project:OTP Generator and Validation of the OTP
//Author: Parmeet Randhawa
#include <iostream>
#include <cstdlib>  
#include <ctime>     
using namespace std;
void generateOTP(int otp[], int length)
{
    for (int i = 0; i < length; i++) 
    {
        otp[i] = rand() % 10; 
    }
}
void displayOTP(int otp[], int length)
{
    cout << "Generated OTP: ";
    for (int i = 0; i < length; i++)
    {
        cout << otp[i];
    }
    cout << endl;
}
bool validateOTP(int otp[], int length)
{
    cout << "\nEnter the OTP: ";
    int userInput[10]; 
    for (int i = 0; i < length; i++) 
    {
        char ch;
        cin >> ch;
        userInput[i] = ch - '0';
    }
    for (int i = 0; i < length; i++) {
        if (otp[i] != userInput[i]) {
            return false;
        }
    }
    return true;
}
int main()
{
    int otpLength =4;
    int otp[10]; 
    srand(time(0)); 
    generateOTP(otp, otpLength);
    displayOTP(otp, otpLength);
    if (validateOTP(otp, otpLength)) 
    {
        cout << "\nOTP Verified Successfully!" << endl;
    } else {
        cout << "\n Incorrect OTP. Access Denied." << endl;
    }

    return 0;
}
