// COMSC-210 | Lab 20 | Jed Aficial |
// github link: https://github.com/jaficial/210-lab-20

#include <iostream>
#include <iomanip>

using namespace std;
const int SIZE = 3;
const int MIN = 10000, MAX = 99999;
const int legMIN = 3, legMAX = 4;

// NOTE: Need to change the constructor:
// 	- instead of assigningnull values to the legs of the chair, assign random numbers (3 or 4 legs)
// 	- select random price between 100.00 to 999.99
// 	- create a parameter constructor to hold an array of 3 doubles (the prices)
// 	- in third code block (line 67), have the default constructors populate objects

class Chair {
private:
    int legs;
    double * prices;
public:
    // constructors
    Chair() {
        prices = new double[SIZE];
        legs = rand() % ((legMAX-legMIN) + 1) + legMIN;
        for (int i = 0; i < SIZE; i++)
            prices[i] = 0;
    }
    Chair(int l, double *prices_array) {
        prices = new double[SIZE];
        legs = rand() % ((legMAX-legMIN) + 1) + legMIN;
        for (int i = 0; i < SIZE; i++)
            prices[i] = 0;
    }

    // setters and getters
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }
	
    void setPrices() { 
        // setPrices now sets random prices from 100.00 to 999.99
	for (int i = 0; i < SIZE; i++){
		prices[i] = 100 + (rand() % (MAX-MIN + 1) / (double) 100);
	}
	//prices[0] = p1; prices[1] = p2; prices[2] = p3; <- ORIGINAL CODE  
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    cout << fixed << setprecision(2);
    
    /*
    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();

    //creating dynamic chair object with constructor
    Chair *livingChair = new Chair(3);
    livingChair->setPrices(525.25, 434.34, 252.52);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;
    */
    //creating dynamic array of chair objects
    // ORIGINAL line 67
    Chair *collection = new Chair[SIZE];
    collection[0]->setLegs();
    collection[0]->setPrices();
    collection[1]->setLegs();
    collection[1]->setPrices();
    collection[2]->setLegs();
    collection[2]->setPrices();
    for (int i = 0; i < SIZE; i++)
        collection[i]->print();
    

/*
    Chair *testing_char = new Chair;
    testing_char->setPrices();
    testing_char->print();
    delete testing_char; */
    return 0;
} //
