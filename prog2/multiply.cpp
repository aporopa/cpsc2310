// Abigail Poropatich
// Prog2: Hardware Multiplication Algorithm
// CPSC 2310 001
// 11 June 2023

#include <iostream>

using namespace std;

//creating the bit strings
void binary(int val, int len){
    for(int i = len - 1; i >= 0; i--){
        if((val & (1 << i)) != 0) cout << '1';
        else cout << '0';
    }
}

//logic for doing the hardware multiplication
unsigned int multiply(unsigned int multiplicand, unsigned int multiplier) {
    unsigned int mq = multiplier;
    unsigned int mdr = multiplicand;
    unsigned int acc = 0;
    unsigned int carry = 0;

    for(int i = 1; i < 9; i++) {
        cout << "step " << i << ":   ";
        binary(carry, 1);
        cout << " ";
        binary(acc, 8);
        cout << ' ';
        binary(mq, 8);
        cout << endl;
        
        //If the least significant bit is 1
        if(mq & 1){
            cout << "        +   ";
            binary(mdr, 8);
            cout << "        ^ add based on lsb=" << (mq & 1) << endl;
            acc+=mdr;

            //set the carry to 1 if acc is greater than 265, indicating it exceeded its current place value
            //otherwise set to zero
            carry = (acc >= 256) ? 1 : 0;
        }

        //If the least significant bit is zero
        else{
            cout << "        +   ";
            binary(0, 8);
            cout << "        ^ no add based on lsb=0\n";   
            carry = 0;  
        }

        //right shift mq
        mq >>= 1;

        //setting the most signifcant bit to the least significant bit of acc
        mq = mq | (acc & 1) << 7;

        acc >>= 1;
        carry = 0;

        cout << "          ----------" << endl;
        cout << "          ";

        binary(carry, 1);
        cout << " ";
        binary(acc, 8);
        cout << ' ';
        binary(mq, 8);
        cout << endl;

        cout << "       >>                     shift right" << endl;
        cout << "          ";

        binary(carry, 1);
        cout << " ";
        binary(acc, 8);
        cout << ' ';
        binary(mq, 8);
        cout << endl;

        cout << "---------------------------------------------------" << endl;
    }

    return (acc << 8) + mq;
}

int main(){
    unsigned int multiplicand, multiplier, acc, mq = 0, mdr = 0, check;
    cout << "multiplicand: ";
    cin >> multiplicand;

    //input validation
    while(multiplicand > 255 || multiplicand < 0){
        cout << "Invalid entry. Please input a number between 0 and 255 inclusive." << endl;
        cin >> multiplicand;
    }
    cout << multiplicand << endl;
    cout << "multiplier: ";
    cin >> multiplier;

    //input validation
    while(multiplier > 255 || multiplier < 0){
        cout << "Invalid entry. Please input a number between 0 and 255 inclusive." << endl;
        cin >> multiplier;
    }
    cout << multiplier << endl;

    //technical assignments
    mq = multiplier;
    mdr = multiplicand;

    cout << "c and acc set to 0" << endl;

    cout << "mq set to multiplier    =  " << multiplier << " decimal and "; 
    binary(mq, 8);
    cout << " binary" << endl;

    cout << "mdr set to multiplicand =  " << multiplicand << " decimal and ";
    binary(mdr, 8);
    cout << " binary" << endl;

    cout << "---------------------------------------------------" << endl;


    //output formatting for the product
    check = multiply(mdr, mq);
        cout << "check:                 binary   decimal" << endl;
        cout << "                     ";
        binary(mdr, 8);
        cout << "       " << mdr << endl;
        cout << "           x         ";
        binary(multiplier, 8);
        cout << "  x    " << multiplier << endl;
        cout << "             ----------------    -----" << endl;
        cout << "             ";
        binary(check, 16);
        cout << "     " << check << endl;

    
    return 0;
}