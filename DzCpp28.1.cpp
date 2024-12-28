#include <iostream>
#include <string>
#include "MyArray.h"
using namespace std;

int main()
{
    MyArray<int> myArray;
    int choice;

    do 
    {
        std::cout << "\nMenu:" << endl;
        std::cout << "1. Set array size" << endl;
        std::cout << "2. Add an element" << endl;
        std::cout << "3. Insert an element at a position" << endl;
        std::cout << "4. Remove an element by index" << endl;
        std::cout << "5. Display all elements" << endl;
        std::cout << "6. Get array size" << endl;
        std::cout << "7. Check if the array is empty" << endl;
        std::cout << "8. Exit" << endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) 
        {
        case 1: 
        {
            int size, grow;
            std::cout << "Enter new array size: ";
            std::cin >> size;
            std::cout << "Enter growth factor (grow): ";
            std::cin >> grow;
            myArray.SetSize(size, grow);
            break;
        }
        case 2: 
        {
            int element;
            std::cout << "Enter an element to add: ";
            std::cin >> element;
            myArray.Add(element);
            std::cout << "Element added!\n";
            break;
        }
        case 3: 
        {
            int index, element;
            std::cout << "Enter the index for insertion: ";
            std::cin >> index;
            std::cout << "Enter the element to insert: ";
            std::cin >> element;
            if (myArray.InsertAt(index, element)) 
            {
                std::cout << "Element inserted!\n";
            }
            else 
            {
                std::cout << "Invalid index!\n";
            }
            break;
        }
        case 4: 
        {
            int index;
            std::cout << "Enter the index to remove: ";
            std::cin >> index;
            if (myArray.RemoveAt(index)) 
            {
                std::cout << "Element removed!\n";
            }
            else 
            {
                std::cout << "Invalid index!\n";
            }
            break;
        }
        case 5: 
        {
            std::cout << "Array elements:\n";
            for (int i = 0; i <= myArray.GetUpperBound(); ++i) 
            {
                std::cout << myArray[i] << " ";
            }
            std::cout << "\n";
            break;
        }
        case 6: 
        {
            std::cout << "Array size: " << myArray.GetSize() << "\n";
            break;
        }
        case 7: 
        {
            if (myArray.IsEmpty()) 
            {
                std::cout << "The array is empty.\n";
            }
            else 
            {
                std::cout << "The array is not empty.\n";
            }
            break;
        }
        case 8: 
        {
            std::cout << "Exiting the program.\n";
            break;
        }
        default: 
        {
            std::cout << "Invalid.\n";
            break;
        }
        }
    } while (choice != 8);

    return 0;
}