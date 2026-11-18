#include <iostream> 
#include "Library.h"

using namespace std; 

const string ClientsFileName = "Clients.txt";

enum enMainMenueOptions { eListClients = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6, eExit = 7 };

enum enTransactionsMenueOptions { eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3, eShowMainMenue = 4 };

enMainMenueOptions Choice()
{
	short Choice;
		do{
			
		  library::ShowMenu();
			cin>>Choice;
			
		} while(Choice<1||Choice>7);
		return (enMainMenueOptions)Choice;
}

enTransactionsMenueOptions choiceFTransactions(){
	short Choice;
	
	do {
		library::ShowTransactionsMenu();
		cin>>Choice;
		
	  } while(Choice<1||Choice>4);
	  
	  return (enTransactionsMenueOptions)Choice;
}


void choose(enMainMenueOptions choice)
{
   vector <stClient> vClients;
	switch(choice)
	{
	case enMainMenueOptions::eListClients:
		
	system("cls");
	library::ShowAllClientsScreen(ClientsFileName);
	library::ReturnToMenu();
	   break;
	
	case enMainMenueOptions::eAddNewClient:
		
	system("cls");
	library::PrintHeader("Add New Clients Screen");
	library::AddClients(ClientsFileName);
	library::ReturnToMenu();
	   break;
	
	case enMainMenueOptions::eDeleteClient:
	system("cls");
	library::PrintHeader("Delete Client Screen");
	vClients=library::LoadClientsDataFromFile(ClientsFileName);
    library::DeleteClientByAccountNumber(library::ReadClientAccountNumber(),vClients,ClientsFileName);
    library::ReturnToMenu();
	   break;
	
	case enMainMenueOptions::eUpdateClient:
	system("cls");
	library::PrintHeader("Update Client Screen");
	vClients=library::LoadClientsDataFromFile(ClientsFileName);
	library::UpdateClientByAccountNumber(library::ReadClientAccountNumber(),vClients,ClientsFileName);
	library::ReturnToMenu();
	   break;
	
	case enMainMenueOptions::eFindClient:
	system("cls");
	library::PrintHeader("Find Clients Screen");
	library::FindClient(ClientsFileName);
	library::ReturnToMenu();
	   break;
	
	case enMainMenueOptions::eShowTransactionsMenue:
	
     	break;
		
	case enMainMenueOptions::eExit:
	system("cls");
	library::PrintHeader("Program Ends :-)");
	library::ReturnToMenu();
	   break;
	 
	default:
		cout<<"invalid choice\n";
	}
	
}


void Transactionschoose(enTransactionsMenueOptions Choice)
{
	vector <stClient> vClients;
	switch (Choice)
	 {
		case enTransactionsMenueOptions::eDeposit:
		system("cls");
		library::PrintHeader("Deposit Screen");
		vClients=library::LoadClientsDataFromFile(ClientsFileName);
		library::ShowDepositScreen(ClientsFileName);
		library::GoBackToTransactionsMenue();
			break;
			
		case enTransactionsMenueOptions::eWithdraw:
		system("cls");
		library::PrintHeader("withdraw Screen");
		vClients=library::LoadClientsDataFromFile(ClientsFileName);
		library::ShowWithDrawScreen(ClientsFileName);
		library::GoBackToTransactionsMenue();
			break;
			
		case enTransactionsMenueOptions::eShowTotalBalance:
			system("cls");
			library::ShowTotalBalance(ClientsFileName);
			library::GoBackToTransactionsMenue();
			break;
			
		case enTransactionsMenueOptions::eShowMainMenue:
			system("cls");
			break;
			
		default:
			cout<<"invalid choice\n";
			break;
	}
}



int main()
{
	
	enMainMenueOptions CH;
	enTransactionsMenueOptions CH2;
	do{
		system("cls");
		system("color 0F");
		CH=Choice();
		if(CH==enMainMenueOptions::eShowTransactionsMenue){
			
			do{
				system("cls");
				system("color 0F");
				CH2=choiceFTransactions();
			Transactionschoose(CH2);
			}while(CH2!=enTransactionsMenueOptions::eShowMainMenue);
			
			
		}
		choose(CH);
		
	}
	while(CH!=enMainMenueOptions::eExit);
	
	system("pause>0");
}
