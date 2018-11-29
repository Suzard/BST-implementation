// main test driver for BST
// Created by Frank M. Carrano and Tim Henry.
// modified by 

#include "BinarySearchTree.h"  // BST ADT 
#include "Employee.h" 
#include <fstream>
#include <sstream>

//function for printing out the nodes while traversing the tree
void display(Employee & anItem)
{
	cout << "Displaying item - " << anItem.returnKey() << endl;
}
//prints out welcome to the user
void printWelcome()
{
	cout << "\n\n\t\t *~~*~~* WELCOME *~~*~~*\n\n"
		<< "\tTo the Binary Search Tree Program!\n\n"
		<< "\t\tThis program will: \n"
		<< "\t\t -  Search by a unique key (employee identification number) \n"
		<< "\t\t -  Recursive Depth-First Traversals: inorder, preorder, postorder \n"
		<< "\t\t -  Print tree as an indented list (show level numbers)\n"
		<< "\t\t -  Print smallest or largest key\n"
		<< "\t\t -  Say welcome again\n"
		<< "\t\t - These are the following commands\n"
		<< "\t\t\t - S stands for search\n"
		<< "\t\t\t - D will print out the inorder, preorder, and postorder traversal\n"
		<< "\t\t\t - B will print out the breadth first traversal\n"
		<< "\t\t\t - T will print out the tree as an indented list\n"
		<< "\t\t\t - L will print the smallest key\n"
		<< "\t\t\t - H will print the largest key\n"
		<< "\t\t\t - M will show the menu again\n"
		<< "\t\t\t - Q to quit the program\n";
	cout << "\t\t The ToyList is sorted in ascending order by ToyID\n\n";
}
//builds the BST based on the input file
BinarySearchTree<Employee>* buildBST() {
	BinarySearchTree<Employee>* tree1Ptr = new BinarySearchTree<Employee>();
	ifstream inFile;
	inFile.open("employees.txt");
	string line;
	while (getline(inFile, line))
	{
		string arr[3];
		int i = 0;
		stringstream ssin(line);
		while (ssin.good() && i < 3) {
			ssin >> arr[i];
			++i;
		}
		string name;
		//Name is two values at the end
		name = arr[1] + " " + arr[2];
		//ID is the first value
		Employee x(stoi(arr[0]), name);
		tree1Ptr->insert(x);
	}
	return tree1Ptr;
}
int main()
{
	BinarySearchTree<Employee>* tree1Ptr = buildBST();
	string function;
	printWelcome();
	cout << "Please enter: S,D,B,T,L,H,M,or Q: ";
	//starts program
	while (1) {
		//keep going until you reach Q
		getline(cin, function);
		function[0] = toupper(function[0]);

		if (function == "Q") {
			tree1Ptr->clear();
			return 0;
		}
		//Searches the binary tree depending on the ID with some error handling
		else if (function == "S") {
			string id_input;
			cout << "Please enter an ID to search for: ";
			getline(cin, id_input);
			bool check = true;
			for (char c : id_input) {
				if (!isdigit(c)) {
					check = false;
					break;
				}
			}
			if (check) {
				Employee id(stoi(id_input));
				Employee returnEmployee;
				tree1Ptr->getEntry(id, returnEmployee);
				string name = returnEmployee.returnName();
				if (name != "")
					cout << returnEmployee.returnName() << " with id " << returnEmployee.returnKey() << endl;
				else
					cout << "Employee does not exist" << endl;
			}
			else
				cout << "Invalid input. Please enter an integer " << endl;
		}
		//Iterates through the tree with all three traversals printed out
		else if (function == "D") {
			cout << "Tree 1 Preorder Traversal\n";
			tree1Ptr->preOrder(display);
			cout << "Tree 1 Inorder Traversal\n";
			tree1Ptr->inOrder(display);
			cout << "Tree 1 Postorder Traversal\n";
			tree1Ptr->postOrder(display);
		}
		//Iterates through the tree with breadth first traversal
		else if (function == "B") {
			cout << "Printing breadth first traversal \n";
			tree1Ptr->breadthFirst(display);
		}
		//Prints the list in indented format
		else if (function == "T") {
			cout << "Printing indented list \n";
			tree1Ptr->printIndented();
		}
		//Prints the smallest value
		else if (function == "L") {
			cout << "Find smallest\n";
			tree1Ptr->printSmallest();
		}
		//Prints the largest value
		else if (function == "H") {
			cout << "Find largest\n";
			tree1Ptr->printLargest();
		}
		//Prints the menu again
		else if (function == "M") {
			printWelcome();
		}
		//Hidden option for user
		else if (function == "A") {
			cout << "Edward Chen is the developer \n";
		}
		//Prints if user enters wrong input
		else {
			cout << "Invalid input \n";
		}
		cout << "Please enter: S,D,B,T,L,H,M,or Q: ";

	}
	return 0;
}
/*


				 *~~*~~* WELCOME *~~*~~*

		To the Binary Search Tree Program!

				This program will:
				 -  Search by a unique key (employee identification number)
				 -  Recursive Depth-First Traversals: inorder, preorder, postorder
				 -  Print tree as an indented list (show level numbers)
				 -  Print smallest or largest key
				 -  Say welcome again
				 - These are the following commands
						 - S stands for search
						 - D will print out the inorder, preorder, and postorder traversal
						 - B will print out the breadth first traversal
						 - T will print out the tree as an indented list
						 - L will print the smallest key
						 - H will print the largest key
						 - M will show the menu again
						 - Q to quit the program
				 The ToyList is sorted in ascending order by ToyID

Please enter: S,D,B,T,L,H,M,or Q: S
Please enter an ID to search for: Notvalidinput
Invalid input. Please enter an integer
Please enter: S,D,B,T,L,H,M,or Q: S
Please enter an ID to search for: 99999999
Employee does not exist
Please enter: S,D,B,T,L,H,M,or Q: D
Tree 1 Preorder Traversal
Displaying item - 3022
Displaying item - 1022
Displaying item - 1011
Displaying item - 2077
Displaying item - 2066
Displaying item - 3099
Displaying item - 3088
Displaying item - 3055
Displaying item - 5044
Displaying item - 4033
Tree 1 Inorder Traversal
Displaying item - 1011
Displaying item - 1022
Displaying item - 2066
Displaying item - 2077
Displaying item - 3022
Displaying item - 3055
Displaying item - 3088
Displaying item - 3099
Displaying item - 4033
Displaying item - 5044
Tree 1 Postorder Traversal
Displaying item - 1011
Displaying item - 2066
Displaying item - 2077
Displaying item - 1022
Displaying item - 3055
Displaying item - 3088
Displaying item - 4033
Displaying item - 5044
Displaying item - 3099
Displaying item - 3022
Please enter: S,D,B,T,L,H,M,or Q: B
Printing breadth first traversal
1 ::  [3022]
2 ::  [1022] [3099]
3 ::  [1011] [2077] [3088] [5044]
4 ::  [2066] [3055] [4033]
Please enter: S,D,B,T,L,H,M,or Q: T
Printing indented list
				2.5044
						3.4033
		1.3099
				2.3088
						3.3055
0.3022
				2.2077
						3.2066
		1.1022
				2.1011
Please enter: S,D,B,T,L,H,M,or Q: L
Find smallest
1011
Please enter: S,D,B,T,L,H,M,or Q: h
Find largest
5044
Please enter: S,D,B,T,L,H,M,or Q: M


				 *~~*~~* WELCOME *~~*~~*

		To the Binary Search Tree Program!

				This program will:
				 -  Search by a unique key (employee identification number)
				 -  Recursive Depth-First Traversals: inorder, preorder, postorder
				 -  Print tree as an indented list (show level numbers)
				 -  Print smallest or largest key
				 -  Say welcome again
				 - These are the following commands
						 - S stands for search
						 - D will print out the inorder, preorder, and postorder traversal
						 - B will print out the breadth first traversal
						 - T will print out the tree as an indented list
						 - L will print the smallest key
						 - H will print the largest key
						 - M will show the menu again
						 - Q to quit the program
				 The ToyList is sorted in ascending order by ToyID

Please enter: S,D,B,T,L,H,M,or Q: A
Edward Chen is the developer
Please enter: S,D,B,T,L,H,M,or Q: Wrong function
Invalid input
Please enter: S,D,B,T,L,H,M,or Q: Q
Node deleted: 1011
Node deleted: 2066
Node deleted: 2077
Node deleted: 1022
Node deleted: 3055
Node deleted: 3088
Node deleted: 4033
Node deleted: 5044
Node deleted: 3099
Node deleted: 3022
C:\Users\etern\source\repos\Project4\Debug\Project4.exe (process 7832) exited with code 0.
Press any key to close this window . . .

*/