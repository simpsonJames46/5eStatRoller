#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

int doubleSet;
int raceRoll;
//Initialises lists of races based on the stat bonuses they confer
string strRaces[3] = {"Dragonborn", "Half-Orc", "Locathah"};
string dexRaces[6] = {"Elf", "Halfling", "Grung", "Kor", "Aven", "Khenra"};
string conRaces[6] = {"Dwarf", "Warforged", "Naga", "Loxodon", "Simic Hybrid", "Leonin"};
string intRaces[4] = {"Gnome", "Blue Merfolk", "Ula Creed Merfolk", "Vedalken"};
string wisRaces[3] = {"Kalashtar", "Green Merfolk", "Emeria Creed Merfolk"};
string chaRaces[7] = {"Half-Elf", "Tiefling", "Verdan", "Aetherborn", "Siren", "Cosi Creed Merfolk", "Vampire"};

int statGen()
{
    int stat = 0;
    //Generates the random numbers for the dice rolls
    int die1 = 1+ (rand()%6);
    int die2 = 1+ (rand()%6);
    int die3 = 1+ (rand()%6);
    int die4 = 1+ (rand()%6);
    //Finds and eliminates the lowest roll
    int rolls[4] = {die1, die2, die3, die4};
    sort(rolls, rolls+4);
    rolls[0] = 0;
    //Adds the 3 highest rolls together and returns the result
    for(int i = 0; i<4; i++){
        stat+=rolls[i];
    }
    return stat;
}

string rollRace()
{
    //Asks the user to select a stat to roll a race for and selects a random item from the relevant list to return
    string race;
    cout<<"Which stat?"<<endl<<"1: STR"<<endl<<"2: DEX"<<endl<<"3: CON"<<endl<<"4: INT"<<endl<<"5: WIS"<<endl<<"6: CHA"<<endl;
        cin>>raceRoll;
        switch (raceRoll){
        case 1:
            {
            int strIndex = rand()%3;
            race = strRaces[strIndex];
            break;
            }
        case 2:
            {
            int dexIndex = rand()%6;
            race = dexRaces[dexIndex];
            break;
            }
        case 3:
            {
            int conIndex = rand()%6;
            race = conRaces[conIndex];
            break;
            }
        case 4:
            {
            int intIndex = rand()%4;
            race = intRaces[intIndex];
            break;
            }
        case 5:
            {
            int wisIndex = rand()%3;
            race = wisRaces[wisIndex];
            break;
            }
        case 6:
            {
            int chaIndex = rand()%7;
            race = chaRaces[chaIndex];
            break;
            }
        }
    return race;
}

int main()
{
    srand(time(NULL));
    cout<<"Roll 1 Set or 2?"<<endl<<"1: 1 Set"<<endl<<"2: 2 Sets"<<endl;
    cin>>doubleSet;
    //Runs the function to generate a stat 6 times and outputs the results
    cout<<"Set 1:"<<endl;
    for(int i = 0; i<6; i++){
        cout<<statGen()<<endl;
    }
    //Runs the function a second time if the user has selected to have two sets of stats
    if (doubleSet == 2){
        cout<<"Set 2:"<<endl;
        for(int i = 0; i<6; i++){
        cout<<statGen()<<endl;
        }
    }
    cout<<"Roll a race for your preferred stat?"<<endl<<"1: Yes"<<endl<<"2: No"<<endl;
    cin>>raceRoll;
    //Runs the function to roll a random race for the user
    if (raceRoll == 1){
        cout<<rollRace()<<endl;
    }
    system("pause");
    return 0;
}
