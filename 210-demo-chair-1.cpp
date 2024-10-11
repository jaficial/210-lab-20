// COMSC-210 | Lab 20 | Jed Aficial |
// github link: https://github.com/jaficial/210-lab-20

#include <iostream>
#include <iomanip>

using namespace std;
const int SIZE = 3;
const int MIN = 10000, MAX = 99999;
const int legMIN = 3, legMAX = 4;

class Chair {
private:
    int legs;
    double * prices;
public:
    // default constructor
    Chair() {
        // minimum and maximum values for legs are defined to select either 3 or 4 legs
        prices = new double[SIZE];
        legs = rand() % ((legMAX-legMIN) + 1) + legMIN;
        // for loop sets random prices if a parameters isn't given for the prices
        for (int i = 0; i < SIZE; i++){
		    prices[i] = 100 + (rand() % (MAX-MIN + 1) / (double) 100); // sets price to random number between 100.00 to 999.99
	    }
        
    // parameter constructor now has parameter for prices array
    }
    Chair(int l, double *prices_array) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = 0;
    }

    // setters and getters
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }
	
    void setPrices(double p1, double p2, double p3) { 
	    prices[0] = p1; prices[1] = p2; prices[2] = p3;   
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
    // creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();
    
    // creating dynamic chair object with constructor
    double *livingChair_arr[3];
    Chair *livingChair = new Chair(3, *livingChair_arr);
    livingChair->setPrices(525.25, 434.34, 252.52);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;
    
    // creating dynamic array of chair objects using the default constructor
    cout << "The following output utilizes the default constructor for the Chair class: \n\n";
    Chair *collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++)
        collection[i].print();
    delete [] collection;

    // singular chair object using the defualt constructor
    Chair *testing_chair = new Chair;
    testing_chair->print();
    delete testing_chair; 
    return 0;
} 