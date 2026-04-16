// COMSC-210 | Lab 29 | Joaquin Felix
#include <iostream>
#include <string>
#include <array>
#include <map>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <list>

using namespace std;

// Constants
const int VEHICLE_TYPES = 3;
const int TIME_PERIODS = 25;
const int MIN_FILES_LINES = 100;
const string INPUT_FILE = "traffic_data.txt";

// Function prototypes
void dispalyMap(
    const map<string, array<list<string>, VEHICLE_TYPES>> & traffic_map);

void run_simulation();


int main () 
{

}

void displayMap(
    const map<string, array<list<string>, VEHICLE_TYPES>> & traffic_map)
{
    for (auto &entry : traffic_map)
    {
        cout << "Time Period: " << entry.first << endl;

        cout << "Cars: ";
        for (auto &v : entry.second[0])
        {
            cout << v << " ";
        }

        cout << "\n Buses: ";
        for (auto &v : entry.second[1])
        {
            cout << v << " ";
        }

        cout << "\n Emergency Vehicles: ";
        for (auto &v : entry.second[2])
        {
            cout << v << " ";
        }

        cout << "\n-----------------------------\n";
    }
}