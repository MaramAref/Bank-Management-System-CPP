#pragma once

#include<iostream>
#include<vector>
#include<cctype>
#include <string> 
#include <iomanip>
#include <fstream>
using namespace std;

struct stClient
{ 

string AccountNumber;
string PinCode;
string Name;
string Phone;
double AccountBalance=0;
bool MarkForDelete = false; 
 
};

namespace library
{
	void ShowMenu()
	{
			
		system("cls");
	    cout << "===========================================\n";
	    cout << "\t\tMain Menue Screen\n";
	    cout << "===========================================\n";
	    cout << "\t[1] Show Client List.\n";
	    cout << "\t[2] Add New Client.\n";
	    cout << "\t[3] Delete Client.\n";
	    cout << "\t[4] Update Client Info.\n";
	    cout << "\t[5] Find Client.\n";
	     cout <<"\t[6] Transactions.\n";
	    cout << "\t[7] Exit.\n";
	    cout << "===========================================\n";
			
	}
		
	void ReturnToMenu()
	{
				
			cout<<"\n\nPress enter to return to main menu ...\n";
			system("pause>nul");
			
	}
	
	void GoBackToTransactionsMenue()
	{
	    cout << "\n\nPress any key to go back to Transactions Menue...";
	    system("pause>0");
	
	}
	
	void PrintHeader(string Header)
	{
			cout << "\n-----------------------------------\n";
			    cout << "\t"<<Header;
			    cout << "\n-----------------------------------\n";
	}
	
	void print_div()
	{
			
			cout << "\n---------------------------------------------------------"; 
		       cout << "-------------------------------------------\n" << endl;
	       
	}
		
	vector <string> SplitString(string S1, string Delim)
	{ 
	       vector <string> vString;
	       size_t pos = 0; 
	       string sWord;
	       
	       while ((pos = S1.find(Delim)) != std::string::npos)
		   { 
			sWord=S1.substr(0,pos);
			if(sWord !="")
			{
			vString.push_back(sWord);
			}
			S1.erase(0,pos+Delim.length());
		}
		
	       if (S1 != ""){ 
	       vString.push_back(S1); 
	 } 
	 
	 return vString; 
	}
	
	
	
	string ConvertRecordToLine(const stClient &Client, string Delim="#//#")
	{
		string stClientRecord="";
		stClientRecord+=Client.AccountNumber+Delim;
		stClientRecord+=Client.PinCode+Delim;
		stClientRecord+=Client.Name+Delim;
		stClientRecord+=Client.Phone+Delim;
		stClientRecord+=to_string(Client.AccountBalance);
		
		return stClientRecord;
	}
	
	stClient ConvertLineToRecord(string Line,string Delim="#//#")
	{
		     stClient Client;
			vector <string> vClientData; 
			
			vClientData=SplitString(Line,Delim);
			
			if(vClientData.size()<5){
				return Client;
			}
			
			
			
			Client.AccountNumber=vClientData[0];
			Client.PinCode=vClientData[1];
			Client.Name=vClientData[2];
			Client.Phone=vClientData[3];
			Client.AccountBalance=stod(vClientData[4]);
			
			return Client;
	}
	
    vector<stClient> LoadClientsDataFromFile(string filename)
    {
	
	vector<stClient>vCilent;
	fstream MyFile;
	
	MyFile.open(filename,ios::in);
	
	if(MyFile.is_open()){
		string Line;
		stClient Clinet;
		
		while(getline(MyFile,Line)){
			
			Clinet=ConvertLineToRecord(Line);
			vCilent.push_back(Clinet);
		}
		
		MyFile.close();
	}
	 else
	{
 		cout<<"error opining file\n";
 	}
     
        return vCilent;
   }

    void PrintClientRecordLine(const stClient &Client)
	{
	    cout << "| " << setw(15) << left << Client.AccountNumber;
	    cout << "| " << setw(10) << left << Client.PinCode;
	    cout << "| " << setw(40) << left << Client.Name;
	    cout << "| " << setw(12) << left << Client.Phone;
	    cout << "| " << setw(12) << left << Client.AccountBalance;
	}
	
	void PrintClientCard(stClient Client)
	{
	    cout << "\nThe following are the client details:\n";
	    cout << "-----------------------------------";
	    cout << "\nAccout Number: " << Client.AccountNumber;
	    cout << "\nPin Code     : " << Client.PinCode;
	    cout << "\nName         : " << Client.Name;
	    cout << "\nPhone        : " << Client.Phone;
	    cout << "\nAccount Balance: " << Client.AccountBalance;
	    cout << "\n-----------------------------------\n";
	}
	

	void ShowAllClientsScreen(string FileName)
    {
    	vector <stClient> vClients;
        vClients=LoadClientsDataFromFile(FileName);
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    
    print_div();

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    
    print_div();

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (stClient Client : vClients)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }

    print_div();
    
    }
    
    bool IsClientAccountNumberExist(string AccountNumber,string filename)
	{ 
	          vector<stClient>vClients=LoadClientsDataFromFile(filename);
			 for (stClient C : vClients){ 
			 
			if (C.AccountNumber == AccountNumber)
			   return true; 
			   
			} 
			
			return false; 
	}
	
    stClient ReadClientData(string AccountNumber)
	{
		stClient Client; 
		
		Client.AccountNumber = AccountNumber; 
		
		cout << "Enter PinCode ? "; 
	      getline(cin >> ws, Client.PinCode);
		
		cout << "Enter Name ? "; 
	      getline(cin, Client.Name); 
		
		cout << "Enter Phone ? "; 
	      getline(cin, Client.Phone);
		
		cout << "Enter Account Balance ? "; 
	       cin >> Client.AccountBalance; 
		 
		 return Client; 
		 
	}
	
	string ReadClientAccountNumber()
	{
			string AccountNumber;
			cout<<"Please enter AccountNumber : \n";
			cin>>AccountNumber;
			return AccountNumber;
	}
	
	char ReadChar(string Message)
		 {
		 	char Ch;
		 	
			cout<<Message<<endl;
			cin>>Ch;
			
			 return Ch;
		 }
		 
	void AddDataLineToFile(string  FileName, string strDataLine)
	{
			fstream  MyFile;
			MyFile.open(FileName, ios::out | ios::app);
			
			if(MyFile.is_open()){
				MyFile<<strDataLine<<endl;
				MyFile.close();
			}
			
	}
		
	void AddNewClient(string filename)
	{
			stClient Client;
			string AccountNumber="";
			
			AccountNumber=ReadClientAccountNumber();
			
					while(IsClientAccountNumberExist(AccountNumber,filename))
					{
						
						cout<<"Client with ["<<AccountNumber<<"] already exists, Enter another Account Number: \n";
							AccountNumber=ReadClientAccountNumber();
					}
					
			Client=ReadClientData(AccountNumber);
			AddDataLineToFile(filename,ConvertRecordToLine(Client));
			
	}
		
	void AddClients(string filename)
	{
			char Answer='y';
			
			do
			{
			
			   cout<<"Adding new Client : \n\n";
			   AddNewClient(filename);	
			   Answer=ReadChar("Client Added Successfully , do you want to add more clients (y,n)");
			}while(tolower(Answer)=='y');
			
	}
		
	
	bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <stClient>& vClients)
	{ 
	   for (stClient& C : vClients){ 
	 
	   if (C.AccountNumber == AccountNumber)
	   { 
	    C.MarkForDelete = true; 
	    return true; 
	   
	  } 
	  } 
	 
	 return false; 
	 
	} 
	
	
	void SaveClientsDataToFile(string FileName, const vector <stClient> &vClients)
	{ 
	
	 fstream MyFile; 
	 MyFile.open(FileName, ios::out); 
	 
	 string DataLine; 
	  if (MyFile.is_open())
	  { 
	 
	  for (const stClient &C : vClients)
	  { 
	  
	   if (C.MarkForDelete == false)
	    { 
	   
	    DataLine = ConvertRecordToLine(C); 
	    MyFile << DataLine << endl; 
	    
	    } 
	 } 
	    
	  MyFile.close(); 
	  
	  } 
	 
	} 
	
	bool FindClientByAccountNumber(string AccountNumber,const vector <stClient> &vClients, stClient& Client) 
	{ 
		 for (const stClient &C : vClients){ 
		 
		  if (C.AccountNumber == AccountNumber) 
		    { 
		   Client = C; 
		   return true; 
		    } 
	        } 
		 return false; 
	} 
		
	bool DeleteClientByAccountNumber(string AccountNumber, vector <stClient> &vClients,string fileName)
	{ 
	
	    stClient Client; 
	    char Answer = 'n'; 
	
	    if (!FindClientByAccountNumber(AccountNumber,vClients, Client)){ 
	 
	   cout << "\nClient with Account Number (" << AccountNumber << ") is NOT Found! \n"; 
	   return false;
	 
	 }
	 
	   PrintClientCard(Client); 
	   system("color 0C");
	 
	   cout << "\n\n";
	   Answer=ReadChar("Are you sure you want delete client ? n/y ?"); 
	   
	 
	   if (Answer == 'y' || Answer == 'Y') 
	   { 
	   MarkClientForDeleteByAccountNumber(AccountNumber, vClients); 
	   SaveClientsDataToFile(fileName, vClients); 
	 
	   vClients = LoadClientsDataFromFile(fileName); 
	 
	   cout << "\n\n Client Deleted Successfully. \n"; 
	   return true; 
	   
	  } 
	  
	  cout<<"\n Delete Operation cancelled\n";
	  return false;
	  
	} 
	  
	bool UpdateClientByAccountNumber(string AccountNumber, vector <stClient>& vClients,string filename)
	{ 
	  	 stClient Client; 
	  	 char Answer = 'n';
	  	  
	  	 
	  	 if (!FindClientByAccountNumber(AccountNumber, vClients, Client)){
	  	 	
	  	 	cout << "\nClient with Account Number (" << AccountNumber << ") is NOT Found! \n"; 
	  	 	return false;
	  	 	
	  	  }
	  	  PrintClientCard(Client); 
	  	 
	  	  cout << "\n\n";
			Answer=ReadChar("are you sure you want Update client ? "); 
	  	 
	  	  if (Answer == 'y' || Answer == 'Y'){ 
	  	  
	  	   for (stClient& C : vClients){ 
	  	   
	  	    if (C.AccountNumber == AccountNumber){ 
	  	     C = ReadClientData(AccountNumber); 
	  	     break; 
	  	     
	  	    } 
	  	    
	  	 } 
	  	 
	  	   SaveClientsDataToFile(filename, vClients); 
	  	   
	  	   vClients = LoadClientsDataFromFile(filename); 
	  	 
	  	   cout << "\n\n Client Updated Successfully. \n"; 
	  	     return true; 
	  	      } 
	  	      
	  	      cout<<"\n Update operation cancelled\n";
	  	      return false;
	  	      
	  	} 
	  	 
	  	void FindClient(string filename)
		{
		      stClient Client; 
		     vector<stClient>VClient=LoadClientsDataFromFile(filename);
		    string AccountNumber = ReadClientAccountNumber(); 
		    
		    if (FindClientByAccountNumber(AccountNumber,VClient,Client)){ 
		     PrintClientCard(Client); 
		    } 
		       
		    else 
		      { 
		     cout << "\nClient with Account Number (" << AccountNumber << ") is NOT Found! \n"; 
		     } 
		}
	
	 
	 void ShowTransactionsMenu()
	 	{
	 			
	 		system("cls");
	 	    cout << "===========================================\n";
	 	    cout << "\t\tTransactions Menue Screen\n";
	 	    cout << "===========================================\n";
	 	    cout << "\t[1] Deposit.\n";
	 	    cout << "\t[2] Withdraw.\n";
	 	    cout << "\t[3] Total Balance.\n";
	 	    cout << "\t[4] Main Menu.\n";
	 	    cout << "===========================================\n";
	 			
	 	}
	 	
	 	double ReadPositiveNumber(string Message)
		 	{
		 		double Number;
		 		
		 		do{
		 		cout<<Message;
		 		cin>>Number;
		 		}while(Number<=0);
		 		
		 	   return Number;	
		    }
		 	
		 	 
	 
	 
	 
bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector <stClient>& vClients,string FileName)
{


    char Answer = 'n';


    cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {

        for (stClient& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;
                SaveClientsDataToFile(FileName,vClients);
                cout << "\n\nDone Successfully. New balance is: " << C.AccountBalance;

                return true;
            }

        }

        return false;
    }

}
	  
	  void ShowDepositScreen(string FileName)
	  {
	  
	      stClient Client;
	  
	      vector <stClient> vClients = LoadClientsDataFromFile(FileName);
	      string AccountNumber = ReadClientAccountNumber();
	  
	  
	      while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
	      {
	          cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
	          AccountNumber = ReadClientAccountNumber();
	      }
	  
	  
	      PrintClientCard(Client);
	  
	      double Amount = 0;
	      cout << "\nPlease enter deposit amount? ";
	      cin >> Amount;
	  
	      DepositBalanceToClientByAccountNumber(AccountNumber, Amount, vClients,FileName);
	  
	  }
	  
	 
	 void ShowWithDrawScreen(string FileName)
	 {
	     stClient Client;
	 
	     vector <stClient> vClients = LoadClientsDataFromFile(FileName);
	     string AccountNumber = ReadClientAccountNumber();
	 
	 
	     while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
	     {
	         cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
	         AccountNumber = ReadClientAccountNumber();
	     }
	 
	     PrintClientCard(Client);
	 
	     double Amount = 0;
	     cout << "\nPlease enter withdraw amount? ";
	     cin >> Amount;
	 
	     while (Amount > Client.AccountBalance)
	     {
	         cout << "\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance << endl;
	         cout << "Please enter another amount? ";
	         cin >> Amount;
	     }
	 
	     DepositBalanceToClientByAccountNumber(AccountNumber, Amount * -1, vClients,FileName);
	 
	 }
	 
	 	 void PrintShorterClientRecord(const stClient &Client)
		  	{
		  	    cout << "| " << setw(15) << left << Client.AccountNumber;
		  	    cout << "| " << setw(40) << left << Client.Name;
		  	    cout << "| " << setw(12) << left << Client.AccountBalance;
		  	}
	 	 void ShowTotalBalance(string FileName)
		  {
		  	vector <stClient> vClients;
			vClients=LoadClientsDataFromFile(FileName);
			cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
			  		     
			print_div();
			
			cout << "| " << left << setw(15) << "Accout Number";
					    
			cout << "| " << left << setw(40) << "Client Name";
					     
			cout << "| " << left << setw(12) << "Balance";
			
			print_div();
					 
			if (vClients.size() == 0)
			 cout << "\t\t\t\tNo Clients Available In the System!";
			 
			else
					 
				for (const stClient &Client : vClients)
				{
					 
					PrintShorterClientRecord(Client);
					cout << endl;
				}
					 
					     print_div();
		  }
		  
	
	 

}
