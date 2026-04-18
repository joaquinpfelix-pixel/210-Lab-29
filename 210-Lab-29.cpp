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
const int MIN_FILE_LINES = 100;
const string INPUT_FILE = "traffic_data.txt";

// Function prototypes
void displayMap(
    const map<string, array<list<string>, VEHICLE_TYPES>> & traffic_map);

void run_simulation(
    map<string, array<list<string>, VEHICLE_TYPES>> & traffic_map);

bool load_data(
    map<string, array<list<string>, VEHICLE_TYPES>> & traffic_map);

int main () 
{
    srand(time(0));

    map<string, array<list<string>, VEHICLE_TYPES>>  traffic_map;

    cout << "Loading traffic data...\n";

    if (!load_data(traffic_map))
    {
        cout << "Program terminated due to file error." << endl;
        return 1;
    }

    cout << "Initial Traffic Map:\n";
    displayMap(traffic_map);

    run_simulation(traffic_map);

    cout << "\nFINAL STATE:\n";
    displayMap(traffic_map);

    return 0;
}

void displayMap(
    const map<string, array<list<string>, VEHICLE_TYPES>> & traffic_map)
{
    for (auto &entry : traffic_map)
    {
        cout << "\nIntersection: " << entry.first << endl;

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
    string intersection, type, id;

    while (file >> intersection >> type >> id)
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
    
    if (count < MIN_FILE_LINES)
    {
        cout << "WARNING: File contains fewer than "
             << MIN_FILE_LINES << " lines." << endl;
    }
    return true;
}

void run_simulation(
    map<string, array<list<string>, VEHICLE_TYPES>> & traffic_map)
{
    for (int t = 0; t < TIME_PERIODS; t++)
    {
        cout << "\n=== Time Period: " << t << endl;

        for (auto &entry : traffic_map)
        {
            entry.second[0].push_back("car_" + to_string(t));

            if (!entry.second[1].empty() && t % 3 == 0)
            {
                entry.second[1].pop_front();
            }
        }

        if (t % 5 == 0)
        {
            cout << "EVENT: Traffic surge detected!" << endl;
        }
    }
}
