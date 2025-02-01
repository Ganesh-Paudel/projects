#include <iostream>
#include <string>
#include <vector>
#include <fstream>


void printVector(std::vector<std::string> list);


int main() {

	char first;
	char choice;
	std::string task;
	bool running = true;
	std::vector<std::string> collection;
	std::string fileName;

	std::cout << "Do you want to open a file or create a new file: (y for new file n for existing file) " << std::endl;
	std::cin >> first;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (first == 'y') {
		std::cout << "Enter the new file Name: ";
        std::getline(std::cin, fileName);
	}
	else if (first == 'n') {
		std::cout << "Enter the existing file name: ";
		std::getline(std::cin, fileName);
		std::ifstream ToDoFile(fileName + ".txt");

		if (ToDoFile.is_open()) {

			while (std::getline(ToDoFile, task)) {
				collection.push_back(task);
			}
			ToDoFile.close();
		}
		else {
			std::cout << "Error Loading the file" << std::endl;
			return -1;
		}

	}



	std::cout << "Welcome to the Console ToDo List: " << std::endl;

	std::cout << "A for add a Task \nC to denote completed Task \nQ for quit" << std::endl;
	std::cout << std::string(50, '-') << std::endl;

	while (running) {
		
		printVector(collection);

		std::cout << "Enter a choice: " << std::endl;

		std::cin >> choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (choice == 'Q' || choice == 'q') {
			running = false;
		}

		else if (choice == 'A' || choice == 'a') {
			std::cout << "Enter the Task: " << std::endl;
			std::getline(std::cin, task);
			collection.push_back(task);
		}


		

	}

	std::ofstream ToDoFile(fileName + ".txt");
	if (ToDoFile.is_open()) {
		for (std::string task : collection) {
			ToDoFile << task << "\n";
		}
		ToDoFile.close();
	}
	else {
		std::cout << "Error Loadin the file!!!";
		return -1;
	}
	std::cout << "The following Task was Stored\n" << std::endl;
	printVector(collection);
	
	std::cout << std::string(50, '-') << std::endl;
	std::cout << "Thank you for your Time" << std::endl;

}


void printVector(std::vector<std::string> list) {
	for (std::string task : list) {
		std::cout << "=> " << task << std::endl;
	}
}