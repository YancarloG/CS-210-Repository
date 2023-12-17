/*
Name: Yancarlo Guzman
Class: CS 210 
Assignment: Project 2 (Grocery)
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

// Function to load data from the input file into a map
void loadData(map<string, int> &groceryMap)
{
    // Open the input file
    ifstream inputFile("CS210_Project_Three_Input_File.txt");

    // Check if the file is successfully opened
    if (!inputFile)
    {
        cerr << "Error: Cannot open input file." << endl;
        exit(1); // Exit the program with an error code
    }

    string item;

    // Read each line as an item and update the map
    while (getline(inputFile, item))
    {
        // Update the quantity for the corresponding item in the map
        groceryMap[item] += 1;
    }

    // Close the input file
    inputFile.close();
}

// Function to list all items with their frequencies
void listItems(const map<string, int> &groceryMap)
{
    // Iterate through the map and print item frequencies
    for (const auto &entry : groceryMap)
    {
        cout << entry.first << " " << entry.second << endl;
    }
}

// Function to display a histogram of item frequencies
void displayHistogram(const map<string, int> &groceryMap)
{
    // Iterate through the map and print a histogram for each item
    for (const auto &entry : groceryMap)
    {
        cout << entry.first << " ";
        for (int i = 0; i < entry.second; i++)
        {
            cout << "*"; // Print '*' for each occurrence of the item
        }
        cout << endl;
    }
}

// Function to create a backup data file
void createDataBackup(const map<string, int> &groceryMap)
{
    // Open the output file for writing
    ofstream outputFile("frequency.dat");

    // Check if the file is successfully opened
    if (!outputFile)
    {
        cerr << "Error: Cannot create data backup file." << endl;
        exit(1); // Exit the program with an error code
    }

    // Write the data from the map to the output file
    for (const auto &entry : groceryMap)
    {
        outputFile << entry.first << " " << entry.second << endl;
    }

    // Close the output file
    outputFile.close();
}

int main()
{
    // Create a map to store grocery item frequencies
    map<string, int> groceryMap;

    // Load data from the input file into the map
    loadData(groceryMap);

    string searchItem;
    int choice;

    // Display the menu and process user input until the user chooses to exit
    do
    {
        cout << "Menu Options:\n";
        cout << "1. Search for an item's frequency\n";
        cout << "2. List all items with their frequencies\n";
        cout << "3. Display a histogram of item frequencies\n";
        cout << "4. Exit\n";
        cout << "5. Create backup data file\n";
        
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Menu Option One: Search for an item's frequency
            cout << "Enter the item you want to search for: ";
            cin >> searchItem;
            // Check if the item is found in the records
            if (groceryMap.find(searchItem) != groceryMap.end())
            {
                cout << "Frequency of " << searchItem << ": " << groceryMap[searchItem] << endl;
            }
            else
            {
                cout << "Item not found in the records." << endl;
            }
            break;

        case 2:
            // Menu Option Two: List all items with their frequencies
            listItems(groceryMap);
            break;

        case 3:
            // Menu Option Three: Display a histogram of item frequencies
            displayHistogram(groceryMap);
            break;

        case 4:
            // Menu Option Four: Exit
            cout << "Exiting the program... Goodbye!" << endl;
            break;
            
        case 5:
            // Menu Option Five: Create a backup data file
            createDataBackup(groceryMap);
            cout << "Backup data file 'frequency.dat' created." << endl;
            break;


        default:
            cout << "Invalid choice option. Please select a valid option (1-5)." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
