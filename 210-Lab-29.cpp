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

bool load_data(
    map<string, array<list<string>, VEHICLE_TYPES>> & traffic_map)
{
    ifstream file(INPUT_FILE);
    
    if (!file.is_open())
    {
        cout << "ERROR: Could not open file " << INPUT_FILE << endl;
        cout << "Make sure the file exists and is in the correct location." << endl;
        return false;
    }

    int count = 0;
    stirng intersection, type, id;

    while (file >> intersectiopn >> type >> id)
    {
        if (traffic_map.find(intersection) == traffic_map.end())
        {
            traffic_map[intersection] = {};
        }

        if (type == "car")
        {
            traffic_map[intersection][0].push_back(id);
        }
        else if (type == "bus")
        {
            traffic_map[intersection][1].push_back(id);
        }
        else if (type == "emergency")
        {
            traffic_map[intersection][2].push_back(id);
        }

        count++;
    }

    file.close();
    
    if (count < MIN_FILES_LINES)
    {
        cout << "WARNING: File contains fewer than "
             << MIN_FILES_LINES << " lines." << endl;
    }
    return true;
}

