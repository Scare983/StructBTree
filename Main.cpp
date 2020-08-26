#include <iostream>
#include "BinaryTree.h"
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

void commandList() {  //basically the menu
	cout << "Commands - " ;
	cout << "insert (i), " ;
	cout << "delete (d), ";
	cout << "retrieve (r), " ;
	cout << "length (l), " ;
	cout << "in-order (n), " ;
	cout << "pre-order (p), ";
	cout << "post-order (o), ";
	cout << "getSameLevelNonSiblings (o), ";
	cout << "quit (q) " << endl;
}

int main(int argc, char *argv[]) {
	if(argc > 2 ) { //case for too many files ,exits
		cout << "Sorry! Too many files inputted, quitting..." << endl;
		return EXIT_SUCCESS;
	}
	if(argc == 1) { //checks if no files inputted, exit
		cout << "Sorry! No file inputted, quitting..." << endl;
		return EXIT_SUCCESS;
	}
	ifstream workingFile; 
	workingFile.open(argv[1], ios::in); //opens file to read from
	commandList();
	int singleNumber;  //placeholder for getting each int in list
	BinaryTree currentList = BinaryTree();	//intilizes list
	ItemType item;
	while(workingFile >> singleNumber) {//iterates to null
		item.initialize(singleNumber);//creates object for values, can go out of scope after loop 
		currentList.insert(item); //inputs data objects into the sortedLinkedList
	}
	
	bool keepLooping = true;  //inifinite menu screen until q
	
	while (keepLooping) {//only leave when q is inputted
		
		string command; //tried char, but couldn't figure out how to look at too long of input
		cout << "Enter a command: ";
		cin >> command;
		while(!cin.good()) {
					
					cin.ignore(2147483647, '\n');			//command = input
					cin.clear();
		}
		if(command.length() > 1) {
			cout << "Extracting first character in given string one moment..." << endl;
			int temp = time(NULL) + 1; //pause for 1 second, adds glitter to code.
			while(temp > time(NULL));  
		}
		switch(command.at(0)) { //takes the first character of the string, fixes the infinite loop when char more than 2 was inputted
			
			case 'i' : {
				
				cout << "Item to insert: " ; 
				
				int number;
				cin >> number;
				
					ItemType allData;
					allData.initialize(number);
					currentList.insert(allData);
					
				
				cin.clear();
				cout << "In-Order:  "; 
				currentList.inOrder();
				cout << endl;
			}
					break;
				
					case 'c' : {
				
				cout << "Item to find same level nonsiblings: " ; 
				
				int number;
				cin >> number;
				
					ItemType allData;
					allData.initialize(number);
					currentList.getSameLevelNonsiblings(allData);
					
				
				cin.clear();
			
				cout << endl;
			}
					break;
				
			
				break;
			case 'd' :	{
				
				cout << "item to delete: ";
				
				int number;
				cin >> number;
					ItemType allData;
					allData.initialize(number);
					
					currentList.deleteItem(allData);
					cout << "In-Order:  "; 
					currentList.inOrder();
					cout << endl;
					cin.clear();
					
			}
				break;
		
			
		
			case 'p' : {
				cout << "Pre-Order:  ";
				currentList.preOrder();
					cout << endl;
			}
				break;
					case 'n' : {
				cout << "In-Order:  ";
				currentList.inOrder();
					cout << endl;
			}
				break;
			case 'l' : {
				cout << "List length is: " << currentList.getLength();
				cout <<endl;
			}
				break;
			case 'o' :  {
				cout << "Post-Order:  ";
				currentList.postOrder();
					cout << endl;
			}
			break;
			case 'r' :  {
				cout << "item to be retrieved: ";
				
				int number;
				cin >> number;
					ItemType allData;
					allData.initialize(number);
					bool check = false;
					currentList.retrieve(allData, check);
					if(check == false) {
							cout << "Item not in tree." << endl;
						
					}
					else {
						cout << "Item found in tree." << endl;
					}
					
					cin.clear();
			}
			break;
					
			case 'q' : {
				keepLooping = false; //quits
				cout << "Quitting program..."  << endl;
			}
				break;
				default: {
					
					cout << "Command not recognized.  Try again." <<  endl;
					
					
				}
				break;
		}
}
	return EXIT_SUCCESS;
}

