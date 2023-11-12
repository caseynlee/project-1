/**
 * focaccia.cpp
 *
 * Casey Lee
 * leecasey
 * We will be figuring out how many of each ingredient we need in order to make foccacia bread for the x amount of people.
 *
 * EECS 183: Project 1
 * Fall 2023
 * 
 * Project UID: d435ced1b1ee1e06372665b53322301c67d2d4a0
 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;


string pluralize(string singular, string plural, int number);




int main() {
    // Determine the amount of people I will need to serve
    int people = 0;
    cout << "How many people do you need to serve? ";
    cin >> people;
    cout << endl << endl;

    //Determine loaves of bread for the amount of people I will be serving
    int loavesOfBread = ceil ((double)people / 4);
    cout << "You need to make: " << loavesOfBread << " "<<
        pluralize("loaf", "loaves", loavesOfBread) << " of focaccia";
    cout << endl << endl;
    
    cout << "Shopping list for Focaccia Bread" << endl;
    cout << "--------------------------------" << endl;
    
    //Determine the number of bags of flour
    const double FLOUR_CUPS_PER_LOAF = 5 ;
    const double FLOUR_CUPS_PER_BAG = 20;
    int flourBags = ceil((double) loavesOfBread *
        FLOUR_CUPS_PER_LOAF / FLOUR_CUPS_PER_BAG);
    cout << flourBags << " " << pluralize("bag", "bags", flourBags) <<
        " of flour" << endl;

    //Determine the number of packages of yeast
    const double YEAST_TEASPOONS_PER_LOAF = 1.75;
    const double YEAST_TEASPOONS_PER_PACKAGE = 2.25;
    int packagesOfYeast = ceil((double) loavesOfBread *
        YEAST_TEASPOONS_PER_LOAF / YEAST_TEASPOONS_PER_PACKAGE);
    cout << packagesOfYeast << " " <<
        pluralize("package", "packages", packagesOfYeast) <<
        " of yeast"  << endl;
    
    //Determine the number of canister of salt
    const double SALT_GRAM_PER_TEASPOONS = 5;
    const double SALT_TEASPOONS_PER_LOAF = 1.875;
    const double SALT_TEASPOONS_PER_PACKAGE = 30;
    int canistersOfSalt = ceil((double) loavesOfBread * SALT_TEASPOONS_PER_LOAF *
        SALT_GRAM_PER_TEASPOONS / SALT_TEASPOONS_PER_PACKAGE);
    cout << canistersOfSalt << " " <<
        pluralize("canister", "canisters", canistersOfSalt) <<
        " of salt" << endl;
    
    //Determine the number of bottles of olive oil
    const double OIL_MILLILITERS_PER_TABLESPOONS = 14.8;
    const double OIL_TABLESPOONS_PER_LOAF = 2;
    const double OIL_TABLESPOONS_PER_BOTTLE = 500;
    int bottlesOfOil = ceil((double) (loavesOfBread) * (OIL_MILLILITERS_PER_TABLESPOONS) *
        (OIL_TABLESPOONS_PER_LOAF) / (OIL_TABLESPOONS_PER_BOTTLE));
    cout << bottlesOfOil << " " << pluralize("bottle", "bottles", bottlesOfOil) <<
        " of olive oil" << endl << endl;
    
    //Determine the expected cost of the ingredients
    const double FLOUR_BAG_COST = 2.69;
    const double YEAST_PACKAGE_COST = 0.40;
    const double SALT_CANISTER_COST = 0.49;
    const double OIL_BOTTLE_COST = 6.39;
    double totalCost = FLOUR_BAG_COST * flourBags + YEAST_PACKAGE_COST *
        packagesOfYeast + SALT_CANISTER_COST * canistersOfSalt +
        OIL_BOTTLE_COST * bottlesOfOil;
    cout << "Total expected cost of ingredients: $" << totalCost << endl << endl;
    
    cout << "Have a great party!";
    
    return 0;
}

// ----------------------------------------------
// *** DO NOT CHANGE ANYTHING BELOW THIS LINE ***

string pluralize(string singular, string plural, int number) {
    if (number == 1) {
        return singular;
    }
    return plural;
}
