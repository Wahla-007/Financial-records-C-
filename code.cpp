#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include<iomanip>
#include<chrono>
using namespace std;

class Transaction {
private:
    int trans_id;
    double amount;
    int no;
    string date;
    string descp;

public:
    
    Transaction() : trans_id(0), amount(0), no(0), date(""), descp("") {}

    
    void addTransaction() {
        ifstream inFile("transaction.txt");
        string line;
        int temp = 0;

       
        while (getline(inFile, line)) {
            stringstream ss(line);
            string _id;
            getline(ss, _id, ',');
            int num = stoi(_id); 
            if (num > temp) {
                temp = num;
            }
        }
        inFile.close();
        trans_id = temp + 1;
 
        cout << "Enter the product description: ";
        cin >> descp;
        cout << "Enter the price: ";
        cin >> amount;
        cout << "Enter the number of items: ";
        cin >> no;
        while (no <= 0) {
            cout << "The number of items must be greater than 0. Please enter again: ";
            cin >> no;
        }
        auto now = chrono::system_clock::now();
        time_t now_time = chrono::system_clock::to_time_t(now);
        struct tm timeinfo;

        
        if (gmtime_s(&timeinfo, &now_time) != 0) {
            cerr << "Error getting current time.\n";
            return;
        }

       
        stringstream ss;
        ss << (timeinfo.tm_year + 1900) << '-'
            << setw(2) << setfill('0') << (timeinfo.tm_mon + 1) << '-'
            << setw(2) << setfill('0') << timeinfo.tm_mday;
        date = ss.str();
        
        ofstream outFile("transaction.txt", ios::app); 
        outFile << trans_id << "," << amount << "," << date << "," << descp << "," << no << endl;
        outFile.close();
    }
    void removeTransaction(int idToRemove) {
        ifstream inFile("transaction.txt");
        ofstream outFile("temp.txt");

        if (!inFile || !outFile) {
            cerr << "Failed to open files for reading or writing." << endl;
            return;
        }

        string line;
        bool found = false;

        while (getline(inFile, line)) {
            stringstream ss(line);
            string _id;
            getline(ss, _id, ',');
            int transId = stoi(_id); 

            if (transId == idToRemove) {
                found = true;
                continue; 
            }

            outFile << line << endl;
        }
        inFile.close();
        outFile.close();

        if (found) {
            remove("transaction.txt");
            if (rename("temp.txt", "transaction.txt") != 0) {
                cerr << "Error renaming file." << endl;
            }
            else {
                cout << "Transaction with ID " << idToRemove << " has been removed." << endl;
            }
            cout << "Transaction with ID " << idToRemove << " has been removed." << endl;
        }
        else {
            cout << "Transaction with ID " << idToRemove << " not found." << endl;
        }
    }
    double calculateTotalTransactionAmount() {
        ifstream inFile("transaction.txt");
        double total = 0.0;
        string line;

        while (getline(inFile, line)) {
            stringstream ss(line);
            string _id, _amount, _date, _descp, _no;
            getline(ss, _id, ',');     
            getline(ss, _amount, ','); 
            getline(ss, _date, ',');   
            getline(ss, _descp, ',');  
            getline(ss, _no, ',');     
            

            double amount = stod(_amount); 
            total += amount;
        }

        inFile.close();
        cout << " ***************************************\n\tThe calculated sum of alll the transactions is ( " << total << " )\n";
        return total;
    }
    void view() {
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        cout << "-----------------The data of Transactions----------------\n";
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
        ifstream file("transaction.txt");
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        cout << "\n";
    }
};

int main() {
    while (true) {
        cout << "===============================================\n";
        cout << "                  Menu                         \n";
        cout << "===============================================\n";
        cout << "1. Add Transaction\n";
        cout << " 2. Remove entry" << endl;
        
        cout << " 3. Analysis of Transaction\n";
        cout << " 4. View Transaction History\n";
        cout << " 5. Exit\n";

        int choice;
        cin >> choice;

         Transaction storageTransaction;
        if (choice == 1) {
            storageTransaction.addTransaction();
        }
        else if (choice == 2) {
            
            int idToRemove;
            cout << "Enter the transaction ID to remove: ";
            cin >> idToRemove;
            storageTransaction.removeTransaction(idToRemove);
        }
        else if (choice == 3) {
            storageTransaction.calculateTotalTransactionAmount();
           
        }
        else if (choice == 4) {
            storageTransaction.view();
            
        }
        else if (choice == 5) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid input. Please enter a number from 1 to 5.\n";
        }
    }

    return 0;
}
