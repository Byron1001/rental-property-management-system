#include<iostream>
#include "all_user.h"
#include "map.h"
#include <conio.h>
#include <cstdlib>
#include<unistd.h>

bool Timetable_is_in(vector<string>& TimeTable,string temp){
	for(int i=0 ; i<TimeTable.len() ; i++){
		if(TimeTable.get(i) == temp)
		return true;
	}
	return false;
}
void Add_Manager(vector<vector<string>>& manager){ 
	vector<string> temp1;
	string temp2;
	vector<string> temp4;
	for(int i=0 ; i<manager.len() ; i++){
		vector<string> temp3 = manager.get(i);
		temp4.push_back(temp3.get(0)); 
	}
	string largestNumber = temp4.get(0);
	for (int i = 1; i < temp4.len(); i++) {
        if (temp4.get(i) > largestNumber) {
            largestNumber = temp4.get(i);
        }
    }
    std::string nextLargest = largestNumber;
    int numericPart = std::stoi(nextLargest.substr(1)) + 1;
    int temp = numericPart;
    int numericPart_length = 0;
    while(temp){
    	numericPart_length++;
    	temp = temp/10;
	}
	nextLargest = "M";
	for(int i=0 ; i<4-numericPart_length ; i++){
		nextLargest+="0";
	}
    nextLargest += std::to_string(numericPart);
	temp2 = nextLargest;
	cout << "New Manager ID >> " << temp2 << endl;
	temp1.push_back(temp2);
	cout << "Name >> ";
	cin >> temp2;
	temp1.push_back(temp2);
	cout << "Password >> ";
	cin >> temp2;
	temp1.push_back(temp2);
	cout << "Email >> ";
	cin >> temp2;
	temp1.push_back(temp2);
	temp1.push_back("active");
	manager.push_back(temp1); 
}
void Modify_Status(vector<vector<string>>& manager){
	cout << setiosflags(ios::left)<< setw(20) << "Manager ID";
	cout << setiosflags(ios::left)<< setw(20) << "Name";
	cout << setiosflags(ios::left)<< setw(20) << "Password";
	cout << setiosflags(ios::left)<< setw(20) << "Email";
	cout << setiosflags(ios::left)<< setw(20) << "Status" << endl;
	for(int i=0 ; i<manager.len() ; i++){
		vector<string> temp = manager.get(i);
			cout << setiosflags(ios::left)<< setw(20) << temp.get(0);
			cout << setiosflags(ios::left)<< setw(20) << temp.get(1);
			cout << setiosflags(ios::left)<< setw(20) << temp.get(2);
			cout << setiosflags(ios::left)<< setw(20) << temp.get(3);
			cout << setiosflags(ios::left)<< setw(20) << temp.get(4) << endl;
	}
	string userID;
	cout << "ManagerID >>" ;
	cin >> userID;
	for(int i=0 ; i<manager.len() ;i++){
		vector<string> temp = manager.get(i);
		if(userID == temp.get(0)){
			if(temp.get(4)=="active"){
				temp.set(4,"inactive");
				cout << "The status has turned into Inactive! " << endl;
			}	
			else{
				temp.set(4,"active");
				cout << "The status has turned into Inactive! " << endl;
			}
		}
	}
	system("pause");
	system("cls");
}
void Delete_Tenant(vector<vector<string>>& tenant){
	cout << setiosflags(ios::left)<< setw(20) << "Tenant ID";
	cout << setiosflags(ios::left)<< setw(20) << "Name";
	cout << setiosflags(ios::left)<< setw(20) << "Password";
	cout << setiosflags(ios::left)<< setw(20) << "Email";
	cout << setiosflags(ios::left)<< setw(20) << "Last Actice Day`" << endl;
	for(int i=0 ; i<tenant.len() ; i++){
		vector<string> temp = tenant.get(i);
			cout << setiosflags(ios::left)<< setw(20) << temp.get(0);
			cout << setiosflags(ios::left)<< setw(20) << temp.get(1);
			cout << setiosflags(ios::left)<< setw(20) << temp.get(2);
			cout << setiosflags(ios::left)<< setw(20) << temp.get(3);
			cout << setiosflags(ios::left)<< setw(20) << temp.get(4) << endl;
	}
	string tenantID;
	string answer;
	cout << "Enter Tenant ID >>";
	cin >> tenantID;
	for(int i=0 ; i<tenant.len() ;i++){
		vector<string> temp = tenant.get(i);
		if(tenantID == temp.get(0)){
			cout << "Are you want to remove" << tenantID  << "? (enter \'y\' to proceed) >> ";
			cin >> answer;
			if(answer == "y"){
				cout << "  remove sucessfully!" << endl;
				tenant.remove(i);
				system("pause");
				system("cls");
			} else {
				cout << "  remove unsucessfully!" << endl;
				system("pause");
				system("cls");
				return;
			}
		} else
			cout << " Invalid ID !" << endl;
	}
	system("cls");
}
void Display_Manager(vector<vector<string>>& manager){
	cout << setiosflags(ios::left)<< setw(20) << "Manager ID";
	cout << setiosflags(ios::left)<< setw(20) << "Name";
	cout << setiosflags(ios::left)<< setw(20) << "Password";
	cout << setiosflags(ios::left)<< setw(20) << "Email";
	cout << setiosflags(ios::left)<< setw(20) << "Status" << endl;
	for(int i=0 ; i<manager.len() ; i++){
		vector<string> temp = manager.get(i);
			cout << setiosflags(ios::left)<< setw(20) << temp.get(0);
			cout << setiosflags(ios::left)<< setw(20) << temp.get(1);
			cout << setiosflags(ios::left)<< setw(20) << temp.get(2);
			cout << setiosflags(ios::left)<< setw(20) << temp.get(3);
			cout << setiosflags(ios::left)<< setw(20) << temp.get(4) << endl;
	}
}
void display_tenant(vector<vector<string>>& tenant){
	cout << setiosflags(ios::left)<< setw(20) << "Tenant ID";
	cout << setiosflags(ios::left)<< setw(20) << "Name";
	cout << setiosflags(ios::left)<< setw(20) << "Password";
	cout << setiosflags(ios::left)<< setw(20) << "Email";
	cout << setiosflags(ios::left)<< setw(20) << "Last Actice Day`" << endl;
	for(int i=0 ; i<tenant.len() ; i++){
		vector<string> temp = tenant.get(i);
		cout << setiosflags(ios::left)<< setw(20) << temp.get(0);
		cout << setiosflags(ios::left)<< setw(20) << temp.get(1);
		cout << setiosflags(ios::left)<< setw(20) << temp.get(2);
		cout << setiosflags(ios::left)<< setw(20) << temp.get(3);
		cout << setiosflags(ios::left)<< setw(20) << temp.get(4);
		int temp2 = stoi(temp.get(4));
		if(temp2<10)
			cout << setiosflags(ios::left)<< setw(20) << "Active" << endl;
		else
			cout << setiosflags(ios::left)<< setw(20) << "Inactive" << endl;
	}
}
void property_filter(){
	string property_type, furnished;
	string option;
	cout << "Select the property type " << endl;
	cout << "1.  Condominium" << endl;
	cout << "2.  Apartment" << endl;
	cout << "3.  Service Residence" << endl;
	cout << "4.  Studio" << endl;
	cout << "5.  Flat" << endl;
	cout << "6.  Duplex" << endl;
	cout << "7.  Townhouse Condo" << endl;
	cout << "8.  Condo / Services residence / Penthouse / Townhouse" << endl;
	cout << "9.  Residential" << endl;
	cout << "10. Bungalow House" << endl;
	cout << "11. Houses" << endl;
	cout << "12. Soho" << endl;
	cout << "13. Others"  << endl;
	cout << "14. All of above" << endl; 
	cout << "Enter your selection >> ";
	cin >> option;
	system("cls");
	if(option == "1"){
		property_type = "Condominium";
	}else if(option == "2"){
		property_type = "Apartment";
	}else if(option == "3"){
		property_type = "Service Residence";
	}else if(option == "4"){
		property_type = "Studio";
	}else if(option == "5"){
		property_type = "Flat";
	}else if(option == "6"){
		property_type = "Duplex";
	}else if(option == "7"){
		property_type = "Townhouse Condo";
	}else if(option == "8"){
		property_type = "Condo / Services residence / Penthouse / Townhouse";
	}else if(option == "9"){
		property_type = "Residential";
	}else if(option == "10"){
		property_type = "Bungalow House";
	}else if(option == "11"){
		property_type = "Houses";
	}else if(option == "12"){
		property_type = "Soho";
	}else if(option == "13"){
		property_type = "Others";
	}else if(option == "14"){
		property_type = "All";
	}
	cout << "Select the property type " << endl;
	cout << "1.  Fully Furnished" << endl;
	cout << "2.  Partially Furnished" << endl;
	cout << "3.  Not Furnished" << endl;
	cout << "4. All of above" << endl;
	cout << "Enter your selection >> ";
	cin >> option;
	system("cls");
	if(option == "1"){
		furnished = "Fully Furnished";
	}else if(option == "2"){
		furnished = "Partially Furnished";
	}else if(option == "3"){
		furnished = "Not Furnished";
	}else if(option == "4"){
		furnished = "All";
	}
	readCSV temp("mudah-apartment-kl-selangor.csv");
	char search[50];
    int i = 0;
    char ch;
    cout << "Property Type: " << property_type << "\nFurnished    : "<< furnished << "\nSearch >> " << endl;
    temp.filter_display3(property_type,furnished,"");
    while (ch = _getch()) {
    	system("cls");
    	search[i] = '\0'; 
    	cout << "Property Type: " << property_type << "\nFurnished    : "<< furnished << "\nSearch >> " << search;
        if (ch == 13){ // Enter key pressed
        	system("cls");
            return;
    	}    
        else if (ch == 8) { // Backspace key pressed
            if (i > 0) {
                cout << "\b \b"; // Move cursor back, erase character, move cursor back again
                i--;
                search[i] = '\0'; 
            }
        } else {
            if (i < sizeof(search) - 1) {
                search[i] = ch;
                cout << ch;
                i++;
                search[i] = '\0'; 
            }
        }
        cout << endl;
        temp.filter_display3(property_type,furnished,search);
    }
}
void tenant_filter(vector<vector<string>>& tenant){	
	char search[50];
    int i = 0;
    char ch;
    cout << "Search >> " << endl;
    cout << setiosflags(ios::left)<< setw(20) << "Tenant ID";
	cout << setiosflags(ios::left)<< setw(20) << "Name";
	cout << setiosflags(ios::left)<< setw(20) << "Password";
	cout << setiosflags(ios::left)<< setw(20) << "Email";
	cout << setiosflags(ios::left)<< setw(20) << "Last Actice Day`" << endl;
    for(int row = 0 ; row<tenant.len() ; row++){
    	vector<string> temp = tenant.get(row);
    	cout << setiosflags(ios::left)<< setw(20) << temp.get(0);
		cout << setiosflags(ios::left)<< setw(20) << temp.get(1);
		cout << setiosflags(ios::left)<< setw(20) << temp.get(2);
		cout << setiosflags(ios::left)<< setw(20) << temp.get(3);
		cout << setiosflags(ios::left)<< setw(20) << temp.get(4) << endl;
	}
    while (ch = _getch()) {
    	system("cls");
    	search[i] = '\0'; 
    	cout << "Search >> " << search;
        if (ch == 13){ // Enter key pressed
        	system("cls");
            return;
    	}    
        else if (ch == 8) { // Backspace key pressed
            if (i > 0) {
                cout << "\b \b"; // Move cursor back, erase character, move cursor back again
                i--;
                search[i] = '\0'; 
            }
        } else {
            if (i < sizeof(search) - 1) {
                search[i] = ch;
                cout << ch;
                i++;
                search[i] = '\0'; 
            }
        }
        cout << endl;
        cout << setiosflags(ios::left)<< setw(20) << "Tenant ID";
		cout << setiosflags(ios::left)<< setw(20) << "Name";
		cout << setiosflags(ios::left)<< setw(20) << "Password";
		cout << setiosflags(ios::left)<< setw(20) << "Email";
		cout << setiosflags(ios::left)<< setw(20) << "Last Actice Day`" << endl;
		string search_temp = search;
		for (char& c : search_temp) {
			c = std::tolower(c);
		}
		for(int row = 0 ; row<tenant.len() ; row++){
	    	vector<string> temp = tenant.get(row);
			for(int column = 0; column<5 ; column++){ // loop
				string str = temp.get(column);
				for (char& c : str)
					c = std::tolower(c);
				size_t found = str.find(search_temp);
				if (found != string::npos) {
					cout << setiosflags(ios::left)<< setw(20) << temp.get(0);
					cout << setiosflags(ios::left)<< setw(20) << temp.get(1);
					cout << setiosflags(ios::left)<< setw(20) << temp.get(2);
					cout << setiosflags(ios::left)<< setw(20) << temp.get(3);
					cout << setiosflags(ios::left)<< setw(20) << temp.get(4) << endl;
					break;
				} 
			}
		}
	}
}

void Admin_Menu(vector<vector<string>>& manager,vector<vector<string>>& tenant, string ID){
	while(true){
		cout << "1. Add New Manager " << endl;
		cout << "2. Modify the manager\'s status " << endl;
		cout << "3. Delete tenant\'s account" << endl;
		cout << "4. Display Manager " << endl; 
		cout << "5. Display Tenants" << endl;
		cout << "6. Property Information " << endl;
		cout << "7. Tenant Information " << endl;
		cout << "8. Exit " << endl;
		cout << "Enter >> ";
		string option;
		cin >> option ;
		if(option == "1"){
			system("cls");
			Add_Manager(manager);
		}
		else if(option == "2"){
			system("cls");
			Modify_Status(manager);
		}
		else if(option == "3"){
			system("cls");
			Delete_Tenant(tenant);
		}
		else if(option == "4"){
			system("cls");
			Display_Manager(manager);
		}
		else if(option == "5"){
			system("cls");
			display_tenant(tenant);
		}
		else if(option == "6"){
			system("cls");
			property_filter();
		}
		else if(option == "7"){
			system("cls");
			tenant_filter(tenant);
		}
		else if(option == "8"){
			system("cls");
			return;
		} else {
			system("cls");
			cout << endl;
			cout << endl;
			cout << "     Invalid Option" << endl;
		}
	}
}
//====================================================================================//

void Display_Registered_Tenant(vector<vector<string>>& tenant){
	cout << endl;
	cout << setiosflags(ios::left)<< setw(20) << "Tenant ID";
	cout << setiosflags(ios::left)<< setw(20) << "Name";
	cout << setiosflags(ios::left)<< setw(20) << "Password";
	cout << setiosflags(ios::left)<< setw(20) << "Email";
	cout << setiosflags(ios::left)<< setw(20) << "Last Actice Day";
	cout << setiosflags(ios::left)<< setw(20) << "Status" << endl;
	for(int i=0 ; i<tenant.len() ; i++){
		vector<string> temp = tenant.get(i);
		cout << setiosflags(ios::left)<< setw(20) << temp.get(0);
		cout << setiosflags(ios::left)<< setw(20) << temp.get(1);
		cout << setiosflags(ios::left)<< setw(20) << temp.get(2);
		cout << setiosflags(ios::left)<< setw(20) << temp.get(3);
		cout << setiosflags(ios::left)<< setw(20) << temp.get(4);
		int temp2 = stoi(temp.get(4));
		if(temp2<10)
			cout << setiosflags(ios::left)<< setw(20) << "Active" << endl;
		else
			cout << setiosflags(ios::left)<< setw(20) << "Inactive" << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
}
void Search_Tenant(vector<vector<string>>& tenant){
	cout << endl;
	cout << endl;
	cout << setiosflags(ios::left)<< setw(20) << "Tenant ID";
	cout << setiosflags(ios::left)<< setw(20) << "Name";
	cout << setiosflags(ios::left)<< setw(20) << "Password";
	cout << setiosflags(ios::left)<< setw(20) << "Email";
	cout << setiosflags(ios::left)<< setw(20) << "Last Actice Day`" << endl;
	for(int i=0 ; i<tenant.len() ; i++){
		vector<string> temp = tenant.get(i);
		cout << setiosflags(ios::left)<< setw(20) << temp.get(0);
		cout << setiosflags(ios::left)<< setw(20) << temp.get(1);
		cout << setiosflags(ios::left)<< setw(20) << temp.get(2);
		cout << setiosflags(ios::left)<< setw(20) << temp.get(3);
		cout << setiosflags(ios::left)<< setw(20) << temp.get(4) << endl;
	}
	string userID;
	cout << endl;
	cout << endl;
	cout << "      Enter the user's ID >> " ;
	cin >> userID ;
	vector<string> temp; 
	bool found = false;
	for(int i=0 ; i<tenant.len() ; i++){
		if(tenant.get(i).get(0) == userID){
			temp = tenant.get(i);
			found = true;
		}
	}
	if(found){
		system("cls");
		cout << endl;
		cout << setiosflags(ios::left)<< setw(20) << "ID";
		cout << setiosflags(ios::left)<< setw(20) << temp.get(0) << endl;
		cout << setiosflags(ios::left)<< setw(20) << "Name";
		cout << setiosflags(ios::left)<< setw(20) << temp.get(1) << endl;
		cout << setiosflags(ios::left)<< setw(20) << "Password";
		cout << setiosflags(ios::left)<< setw(20) << temp.get(2) << endl;
		cout << setiosflags(ios::left)<< setw(20) << "LastActive";
		cout << setiosflags(ios::left)<< setw(20) << temp.get(3) << endl;
		cout << setiosflags(ios::left)<< setw(20) << "Favorite Property";
		cout << setiosflags(ios::left)<< setw(20) << temp.get(4) << endl;
		cout << setiosflags(ios::left)<< setw(20) << "Renting Request";
		cout << setiosflags(ios::left)<< setw(20) << temp.get(5) << endl;
		cout << setiosflags(ios::left)<< setw(20) << "Renting Confirm";
		cout << setiosflags(ios::left)<< setw(20) << temp.get(6) << endl;
		cout << setiosflags(ios::left)<< setw(20) << "Renting History";
		cout << setiosflags(ios::left)<< setw(20) << temp.get(7) << endl;
		cout << endl;
	} else {
		system("cls");
		cout << endl;
		cout << endl;
		cout << "       Invalid Tenant's ID ! "  << endl;
		cout << endl;
		cout << endl;
	}
	system("pause");
	system("cls");
}
void List_Top10_Favorite_Property(vector<vector<string>>& tenant){
	map<string,int> map1;
	for(int i=0 ; i<tenant.len() ; i++){
		vector<string> temp1 = tenant.get(i);
		Tenant user(temp1);
		queue<string> temp2 = user.get_FavoriteProperty_queue();
		
		for(int j=0 ; j<temp2.len() ; j++){
			if(map1.contains(temp2.get(j)))
			map1.plus_one(temp2.get(j));
			else
			map1.insert(temp2.get(j),1);
		}	
	}
	map1.sort();
	map1.report();
	system("pause");
	system("cls");
}
void Confirm_Renting_Request(vector<string>& TimeTable,vector<vector<string>>& tenant){
	vector<string> temp1;
	string userID;
	cout << "new request :" <<endl;
	for(int i=0 ; i<tenant.len() ; i++){
		temp1 = tenant.get(i); 
		if(temp1.get(6)!=""){
			cout << temp1.get(0) << " : ";
			cout << temp1.get(6) << endl;
		}
	}
	cout << "Enter user's ID >> ";
	cin >> userID;
	for(int i=0 ; i<tenant.len() ; i++){
		vector<string> temp = tenant.get(i);
		if(userID == temp.get(0)){
			temp1 = tenant.get(i); 		
		}
	}
	Tenant user(temp1);
	user.Display_Renting_Request();
	cout << "Confirm ID option >> " ;
	int option;
	cin >> option;
	if(option <= 0 || option >user.get_RentingRequest_length()){
		cout << " Invalid Option" <<endl;
		system("pause");
		system("cls");
	} else {
		cout << " confirmed renting request successfully!" <<endl;
		system("pause");
		system("cls");
	}
	string ID = user.get_RentingRequest(option-2);
	TimeTable.push_back(user.get_RentingRequest(option-2));
	user.Add_Renting_Confirm(user.get_RentingRequest(option-2));
	user.Delete_Renting_Request(option-1);
	user.Update(tenant);
	for(int i=0 ; i<tenant.len(); i++){
		vector<string>temp1 = tenant.get(i);
		Tenant user(temp1);
		cout << "Tenant " << user.get_name() << endl; 
		for(int j=0 ; j<user.get_RentingRequest_length() ; j++){
			if(user.get_RentingRequest(j) == ID){
				user.Delete_Renting_Request(j);
				user.Update(tenant);
				continue;
			}
		}
	}
}
void Manager_Menu(vector<string>& TimeTable,vector<vector<string>>& tenant, string ID){
	while(true){
		cout << "1. Display All Registered Tenant " << endl;
		cout << "2. Search tenant\'s Details " << endl;
		cout << "3. Delete tenant\'s account" << endl;
		cout << "4. List top 10 property" << endl;
		cout << "5. Confirm Renting Request" << endl;
		cout << "6. Exit " << endl;
		cout << "Enter >> ";
		string option;
		cin >> option ;
		if(option == "1"){
			system("cls");
			Display_Registered_Tenant(tenant);
		}
		else if(option == "2"){
			system("cls");
			Search_Tenant(tenant);
		}
		else if(option == "3"){
			system("cls");
			Delete_Tenant(tenant);
		}
		else if(option == "4"){
			system("cls");
			List_Top10_Favorite_Property(tenant);
		}
		else if(option == "5"){
			system("cls");
			Confirm_Renting_Request( TimeTable,tenant);
		}
		else if(option == "6"){
			system("cls");
			return;
		} else {
			system("cls");
			cout << endl;
			cout << endl;
			cout << "     Invalid Option" << endl;
			cout << endl;
			cout << endl;
			system("pause");
			system("cls");
		}
	}
}

//================================================================
bool containsAlphabets(const std::string& input) {
    for (char c : input) {
        if (std::isalpha(c)) {
            return true;
        }
    }
    return false;
}
//==========================================
void Apartment_Information(){
	clock_t start, end;
	double time_taken = 0;
	readCSV temp("mudah-apartment-kl-selangor.csv");
	string option = "0";
	int page=1;
	int sorting_column =0;
	string sorting_method;
	temp.tenant_display_apartment(page);
	while(option!="4"){
		cout << "1. Previous Page " << endl;
		cout << "2. Next Page " << endl;
		cout << "3. Sorting column " << endl;
		cout << "4. Exit" << endl;
		cout << "Select an option >> " ;
		cin >> option;
		if(option == "1"){
			if(page!=1)
				page--;
			system("cls");
			temp.tenant_display_apartment(page);
		}else if(option == "2"){
			if(page!=400)
				page++;
			system("cls");
			temp.tenant_display_apartment(page);
		}else if(option == "3"){
				cout << "Sorting Column >> " << endl;
				cout << "1.  ID " << endl;
				cout << "2.  Property Name " << endl;
				cout << "3.  Completion Year "<< endl;
				cout << "4.  Monthly Rent " << endl;
				cout << "5.  Location " << endl;
				cout << "6.  Property Type " << endl;
				cout << "7.  Number of Rooms " << endl;
				cout << "8.  Number of Parking " << endl;
				cout << "9.  Number of Bathroom " << endl;
				cout << "10. Square Feet " << endl;
				cout << "11. Furnishing Status " << endl;
				cout << "12. Facilities " << endl;
				cout << "13. Additional Facilities " << endl;
				cout << "Sorting which column? >> ";
				cin >> sorting_column ;
				cout << "Sorting Method >> " << endl;
				cout << "1.  Quick Sort " << endl;
				cout << "2.  Merge Sort " << endl;
				cout << "With which method? >> ";
				cin >> sorting_method;
				if(sorting_method == "1"){
					if(sorting_column==1||sorting_column==4||sorting_column==10){
						start = clock();
						temp.i_quickSort(1,temp.get_numRows()-1,sorting_column-1);
						end = clock();
						time_taken = double(end - start) / double(CLOCKS_PER_SEC);
					} else {
						start = clock();
						temp.s_quickSort(1,temp.get_numRows()-1,sorting_column-1);
						end = clock();
						time_taken = double(end - start) / double(CLOCKS_PER_SEC);
					}
				} else if(sorting_method == "2"){
					if(sorting_column==1||sorting_column==4||sorting_column==10){
						start = clock();
						temp.i_mergeSort(1,temp.get_numRows()-1,sorting_column-1);
						end = clock();
						time_taken = double(end - start) / double(CLOCKS_PER_SEC);
					} else {
						start = clock();
						temp.s_mergeSort(1,temp.get_numRows()-1,sorting_column-1);
						end = clock();
						time_taken = double(end - start) / double(CLOCKS_PER_SEC);
					}
				} else {
					cout << "Invalid Option" << endl;
				}
				system("cls");
				temp.tenant_display_apartment(page, sorting_column-1);
				cout << "Time Taken >> " << time_taken << endl;
				cout << "Data read >> " << temp.get_numRows() << " rows" << endl;
		} else if(option == "4"){
			system("cls");
			return;
		} else {
			system("cls");
			cout << endl;
			cout << endl;
			cout << "     Invalid Option!" << endl;
			cout << endl;
			cout << endl;
			system("pause");
			system("cls");
			temp.tenant_display_apartment(page, sorting_column-1);
		}
	}
}
//==========================================
void Search_Apartment_Information(){
	readCSV temp1("mudah-apartment-kl-selangor.csv");
	double time_taken = 0;
	clock_t start, end;
	int column;
	string target;
	string search_method;
	cout << endl;
	cout << endl;
	cout << "   Enter the ID >> " ;
	cin >> target;
	cout << "   Select Search Method " <<endl;
	cout << "   1. Linear Search " <<endl;
	cout << "   2. Binary Search " <<endl;
	cout << "   Select Search Method >> " ;
	cin >> search_method;
	int number;
	if(search_method =="1"){
		start = clock();
		number = temp1.LinearSearch(0,stoi(target));
		end = clock();
		time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	} else if(search_method=="2"){
		temp1.i_mergeSort(1, temp1.get_numRows()-1,0);
		start = clock();
		number = temp1.Binary_Search(0,stoi(target));
		end = clock();
		time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	} else if(search_method !="1" && search_method !="2")
		number = -2;
	if(number == -1){
		cout << endl;
		cout << endl;
		cout << "         Invalid ID                " << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		system("pause");
		system("cls");
		return;
	}else if(number == -2){
		cout << endl;
		cout << endl;
		cout << "         Invalid Search Method                " << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<string> temp2 = temp1.get_row(temp1.search(target, 0));
	system("cls");
	cout << "====================================" << endl;
	cout << "ads_id          >> " << temp2.get(0) << endl;
	cout << "prop_name       >> " << temp2.get(1) << endl;
	cout << "completion_year >> " << temp2.get(2) << endl;
	cout << "monthly_rent    >> " << temp2.get(3) << endl;
	cout << "location        >> " << temp2.get(4) << endl;
	cout << "property_type   >> " << temp2.get(5) << endl;
	cout << "rooms           >> " << temp2.get(6) << endl;
	cout << "parking         >> " << temp2.get(7) << endl;
	cout << "bathroom        >> " << temp2.get(8) << endl;
	cout << "size            >> " << temp2.get(9) << endl;
	cout << "fuinished       >> " << temp2.get(10) << endl;
	cout << "facilities      >> " << temp2.get(11) << endl;
	cout << "additional      >> " << temp2.get(12) << endl;
	cout << "region          >> " << temp2.get(13) << endl;
	cout << "====================================" << endl;
	cout << "Time Taken >> " << time_taken << endl;
	system("pause");
	system("cls");
}
void Add_to_Favorite(vector<vector<string>>& tenant, string Tenant_ID){
	string favorite_property;
	readCSV file("mudah-apartment-kl-selangor.csv");
	Tenant user(tenant.get(0));
	cout << endl;
	cout << endl;
	cout << "Enter your Favorite Property ID >> " ;
	cin >> favorite_property;
	if(containsAlphabets(favorite_property)||file.LinearSearch(0,std::stoi(favorite_property))<0){
		cout << endl;
		cout << "        Invalid Property ID!  "<<endl;
		cout << endl;
		cout << endl;
		system("pause");
		system("cls");
	} else {
		cout << endl;
		cout << "        Add Successfully!  "<<endl;
		cout << endl;
		cout << endl;
		user.Add_Favorite_Property(favorite_property);
		user.Update(tenant);
		system("pause");
		system("cls");
	} 
}
void Place_Rent_Request(vector<string>& TimeTable,vector<vector<string>>& tenant, string Tenant_ID){
	vector<string> temp1;
	string date;
	for(int i=0 ; i<tenant.len() ; i++){
		vector<string> temp = tenant.get(i);
		if(Tenant_ID == temp.get(0))
		temp1 = tenant.get(i);
	}
	Tenant user(temp1);
	if(user.get_FavoriteProperty_len()==0){
		cout << " ======= Your Favorite Property List is empty ======== " << endl;
		return;
	}
	int option;
	user.Display_Favorite_Property();
	cout << "Decided to Rent >> " ;
	cin >> option;
	int sentinal1 = 0;
	if(option<0)
		return;
	while(sentinal1 == 0){
		cout << "Enter the Renting Month yyyy_mm (enter \'q\' to return )>> ";
		cin >> date;
		if(date == "q"){
			system("cls");
			return;	
		}
		int sentinal2 = 1;
		string temp = user.get_FavoriteProperty(option-1)+"_"+date;
		if(Timetable_is_in(TimeTable,temp)){
			cout << " Schedule has reserved!" << endl;
			sentinal2 = 0;
			continue;
		}
		if(date.size()!=7 || containsAlphabets(date)){
			sentinal2 = 0;
			cout << "Invalid Date Format, Enter Again " << endl;
			continue;
		}else if(date.length()!=7){
			sentinal2 = 0;
			cout << "Invalid Date Format, Enter Again " << endl;
			continue;
		}
		stringstream ss(date);
		string token;
		for(int i =0 ; i<2 ; i++){
			getline(ss, token, '_');
			if(i == 0){
				if(std::stoi(token)<2024){
					sentinal2 = 0;
					cout << "Invalid Date Format, Enter Again " << endl;
				}
			}
			if(i == 1){
				if(std::stoi(token)<1 || std::stoi(token)>12){
					sentinal2 = 0;
					cout << "Invalid Date Format, Enter Again " << endl;	
				}

			}
		}
		if(sentinal2 == 0){
		} else {
			sentinal1 = 1;
			cout << " Place Successfully! " << endl;
			system("pause");
			system("cls");
		}
	}
	user.Add_Renting_Request(user.get_FavoriteProperty(option-1)+"_"+date);
	cout << endl;
}
void Renting_History(vector<vector<string>>& tenant, string Tenant_ID){
	vector<string> temp1;
	for(int i=0 ; i<tenant.len() ; i++){
		vector<string> temp = tenant.get(i);
		if(Tenant_ID == temp.get(0))
		temp1 = tenant.get(i);
	}
	Tenant user(temp1);
	user.Display_Renting_Property_History();
}
void Confirm_Payment(vector<vector<string>> tenant, string Tenant_ID){
	vector<string> temp1;
	for(int i=0 ; i<tenant.len() ; i++){
		vector<string> temp = tenant.get(i);
		if(Tenant_ID == temp.get(0))
		temp1 = tenant.get(i);
	}
	Tenant user(temp1);
	if(user.get_RentingHistory_len()==0){
		cout << endl;
		cout << endl;
		cout << "There is no any Confimation\n\n" << endl;
		system("pause");
		system("cls");
		return;
	}
	user.Display_Renting_Confirm();
	int option;
	cout << "Enter the option that you want to pay >> ";
	cin >> option;
	vector<string> temp = split_(user.get_RentingConfirm(option-1));
	readCSV file2("mudah-apartment-kl-selangor.csv");
	vector<string> temp2 = file2.get_row(file2.search(temp.get(0),0));
	cout << temp2.get(3) <<endl;
	string answer;
	cout << "Confirm to pay?";
	cin >> answer;
	if(answer  == "yes"){
		user.Add_Renting_Property_History(user.get_RentingConfirm(option-1));;
		user.Delete_Renting_Confirm(option-1);
		user.Update(tenant);
		cout << " Successful Payment! " << endl;
	} else {
		cout << " Unsuccessful Payment! " << endl;
	}
	cout << endl;
}
void Self_Information(vector<vector<string>> tenant,string ID){
	string userID = ID;
	vector<string> temp; 
	for(int i=0 ; i<tenant.len() ; i++){
		if(tenant.get(i).get(0) == userID)
			temp = tenant.get(i);
	}
	cout << "=================================================" << endl;
	cout << setiosflags(ios::left)<< setw(20) << "ID";
	cout << setiosflags(ios::left)<< setw(20) << temp.get(0) << endl;
	cout << setiosflags(ios::left)<< setw(20) << "Name";
	cout << setiosflags(ios::left)<< setw(20) << temp.get(1) << endl;
	cout << setiosflags(ios::left)<< setw(20) << "Password";
	cout << setiosflags(ios::left)<< setw(20) << temp.get(2) << endl;
	cout << setiosflags(ios::left)<< setw(20) << "Email";
	cout << setiosflags(ios::left)<< setw(20) << temp.get(3) << endl;
	cout << setiosflags(ios::left)<< setw(20) << "LastActive";
	cout << setiosflags(ios::left)<< setw(20) << temp.get(4) << endl;
	cout << setiosflags(ios::left)<< setw(20) << "Favorite Property";
	cout << setiosflags(ios::left)<< setw(20) << temp.get(5) << endl;
	cout << setiosflags(ios::left)<< setw(20) << "Renting Request";
	cout << setiosflags(ios::left)<< setw(20) << temp.get(6) << endl;
	cout << setiosflags(ios::left)<< setw(20) << "Renting Confirm";
	cout << setiosflags(ios::left)<< setw(20) << temp.get(7) << endl;
	cout << setiosflags(ios::left)<< setw(20) << "Renting History";
	cout << setiosflags(ios::left)<< setw(20) << temp.get(8) << endl;
	cout << "=================================================" << endl;
	system("pause");
	system("cls");
} 
void Tenant_Menu(vector<string> TimeTable,vector<vector<string>> tenant,string ID){
	while(true){
		cout << "====================================" << endl;
		cout << "1. Apartment Information " << endl;
		cout << "2. Search Apartment Information " << endl;
		cout << "3. Add to Favorite Property" << endl;
		cout << "4. Place a Rent Request" << endl;
		cout << "5. Property Renting History" << endl;
		cout << "6. Confirm Payment " <<endl;
		cout << "7. Profile " <<endl;
		cout << "8. Exit " << endl;
		cout << "====================================" << endl;
		cout << "Enter >> ";
		string option;
		cin >> option ;
		if(option == "1"){
			system("cls");
			Apartment_Information();
		}
		else if(option == "2"){
			system("cls");
			Search_Apartment_Information();
		}
		else if(option == "3"){
			system("cls");
			Add_to_Favorite(tenant,ID);
		}
		else if(option == "4"){
			system("cls");
			Place_Rent_Request(TimeTable,tenant,ID);
		}
		else if(option == "5"){
			system("cls");
			Renting_History(tenant,ID);
		}
		else if(option == "6"){
			system("cls");
			Confirm_Payment(tenant,ID);
		}
		else if(option == "7"){
			system("cls");
			Self_Information(tenant,ID);
		}
		else if(option == "8"){
			system("cls");
			return;
		}
		else{
			system("cls");
			cout << "====================================" << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "         Invalid Option!" << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "====================================" << endl;
			system("pause");
			system("cls");
		}
	}	
}

int extractInteger(string str){		
	string digits;
	for (char c : str) {
		if (std::isdigit(c))
			digits += c;
		if(c=='.')
			break;
		}
	if(digits.length()==0){
		cout << digits <<endl;
		return 0;
	}
	int value;
	std::stringstream(digits) >> value;
	return value;
}		
void initial_admin(vector<vector<string>>& admin){
	vector<string> temp1; 
	vector<string> temp2; 
	vector<string> temp3;
	temp1.push_back("A0001");
	temp1.push_back("John");
	temp1.push_back("123456");
	temp1.push_back("john@gmail.com");
	temp2.push_back("A0002");
	temp2.push_back("Alice");
	temp2.push_back("123456");
	temp2.push_back("alice@gmail.com");	
	temp3.push_back("A0003");
	temp3.push_back("Jessie");
	temp3.push_back("123456");
	temp3.push_back("jessie@gmail.com");	
	admin.push_back(temp1);
	admin.push_back(temp2);
	admin.push_back(temp3);
}
void initial_manager(vector<vector<string>>& manager){
	vector<string> temp1; 
	vector<string> temp2; 
	vector<string> temp3;
	temp1.push_back("M0001");
	temp1.push_back("Mingliang");
	temp1.push_back("123456");
	temp1.push_back("mingliang@gmail.com");
	temp1.push_back("active");
	temp2.push_back("M0002");
	temp2.push_back("Joel");
	temp2.push_back("123456");
	temp2.push_back("joel@gmail.com");	
	temp2.push_back("inactive");
	temp3.push_back("M0003");
	temp3.push_back("Zahir");
	temp3.push_back("123456");
	temp3.push_back("zahir@gmail.com");	
	temp3.push_back("active");
	manager.push_back(temp1);
	manager.push_back(temp2);
	manager.push_back(temp3);
}
void initial_tenant(vector<vector<string>>& tenant){
	vector<string> temp1; 
	vector<string> temp2; 
	vector<string> temp3;
	temp1.push_back("U0001");
	temp1.push_back("Edmund");
	temp1.push_back("123456");
	temp1.push_back("edmund@gmail.com");
	temp1.push_back("10");
	temp1.push_back("100322866");
	temp1.push_back("100203973_2024_01,100203973_2024_02");
	temp1.push_back("100203973_2024_03");
	temp1.push_back("100203973_2024_02,100203973_2024_01");
	temp2.push_back("U0002");
	temp2.push_back("Nadila");
	temp2.push_back("123456");
	temp2.push_back("nadila@gmail.com");
	temp2.push_back("1");	
	temp2.push_back("100322212");
	temp2.push_back("100203973_2024_01");
	temp2.push_back("");
	temp2.push_back("");
	temp3.push_back("U0003");
	temp3.push_back("Qieff");
	temp3.push_back("123456");
	temp3.push_back("qieff@gmail.com");	
	temp3.push_back("2");
	temp3.push_back("99263112");
	temp3.push_back("100203973_2024_01,00203973_2024_03");
	temp3.push_back("");
	temp3.push_back("100203973_2024_09");
	tenant.push_back(temp1);
	tenant.push_back(temp2);
	tenant.push_back(temp3);
}
void initial_timetable(vector<string>& TimeTable,vector<vector<string>>& tenant){
	for(int i=0 ; i<tenant.len() ; i++){
		vector<string> temp = tenant.get(i);
		if(!temp.get(8).empty())
			TimeTable.push_back(temp.get(8));
	}	
}
void Tenant_Register(vector<vector<string>>& Tenant){
	vector<string> temp1;
	string temp2;
	vector<string> temp4;
	for(int i=0 ; i<Tenant.len() ; i++){
		vector<string> temp3 = Tenant.get(i);
		temp4.push_back(temp3.get(0)); 
	}
	string largestNumber = temp4.get(0);
	for (int i = 1; i < temp4.len(); i++) {
        if (temp4.get(i) > largestNumber) {
            largestNumber = temp4.get(i);
        }
    }
    std::string nextLargest = largestNumber;
    int numericPart = std::stoi(nextLargest.substr(1)) + 1;
    int temp = numericPart;
    int numericPart_length = 0;
    while(temp){
    	numericPart_length++;
    	temp = temp/10;
	}
	nextLargest = "U";
	for(int i=0 ; i<4-numericPart_length ; i++)
		nextLargest+="0";
    nextLargest += std::to_string(numericPart);
	temp2 = nextLargest;
	cout << "Your New Tenant ID >> " << temp2 << endl;
	temp1.push_back(temp2);
	cout << "Name >> ";
	cin >> temp2;
	temp1.push_back(temp2);
	cout << "Password >> ";
	cin >> temp2;
	temp1.push_back(temp2);
	cout << "Email >> ";
	cin >> temp2;
	temp1.push_back(temp2);
	temp1.push_back("0");
	temp1.push_back("");
	temp1.push_back("");
	temp1.push_back("");
	temp1.push_back("");
	Tenant.push_back(temp1); 
}
void Enter_ID(vector<string>& TimeTable,vector<vector<string>>& Admin, vector<vector<string>>& Manager,vector<vector<string>>& Tenant){
		system("cls");
		string ID;
		char password[50];
		int i = 0;
    	char ch;
    	cout << endl;
    	cout << endl;
		cout << "      ID       >> " ;
		cin >> ID;
		cout << "      Password >> ";
		while (true) {
	        ch = _getch();
	        if (ch == 13) // Enter key pressed
	            break;
	        else if (ch == 8) { // Backspace key pressed
	            if (i > 0) {
	                cout << "\b \b"; // Move cursor back, erase character, move cursor back again
	                i--;
	            }
	        } else {
	            if (i < sizeof(password) - 1) {
	                password[i] = ch;
	                cout << '*';
	                i++;
	            }
	        }
    	}	
    password[i] = '\0';
		cout << endl;
		if(ID[0] == 'U'){
			for(int i=0 ; i<Tenant.len() ; i++){
				vector<string> temp = Tenant.get(i);
				if(ID == temp.get(0) && password == temp.get(2)){
					system("cls");
					cout << endl;
    				cout << endl;
					cout << "     Login successful!" << endl;
					cout << endl;
    				cout << endl;
					system("pause");
					system("cls");
					Tenant_Menu(TimeTable,Tenant,ID);
				}	
			}
		} else if(ID[0] == 'M'){
			for(int i=0 ; i<Manager.len() ; i++){
				vector<string> temp = Manager.get(i);
				if(ID == temp.get(0) && password == temp.get(2)){
					if(temp.get(4) == "active"){
						system("cls");
						cout << endl;
	    				cout << endl;
						cout << "     Login successful!" << endl;
						cout << endl;
	    				cout << endl;
						system("pause");
						system("cls");
						Manager_Menu(TimeTable,Tenant,ID);
					} else {
						system("cls");
						cout << endl;
	    				cout << endl;
						cout << "     Your Account is Inactive" << endl;
						cout << endl;
	    				cout << endl;
						system("pause");
						system("cls");
					}
				}
			}
		}
		else if(ID[0] == 'A'){
			for(int i=0 ; i<Admin.len() ; i++){
				vector<string> temp = Admin.get(i);
				if(ID == temp.get(0) && password == temp.get(2)){
					system("cls");
					cout << endl;
    				cout << endl;
					cout << "     Login successful!" << endl;
					cout << endl;
    				cout << endl;
					system("pause");
					system("cls");
					Admin_Menu(Manager,Tenant,ID);
				}
			}
		} else {
			system("cls");
			cout << endl;
    		cout << endl;
			cout << "     Invalid ID or Password!" <<endl;
			cout << endl;
    		cout << endl;
			system("pause");
			system("cls");
			return;
		}
	}
int main(){
	vector<vector<string>> Admin;
	vector<vector<string>> Manager;
	vector<vector<string>> Tenant;
	vector<string> TimeTable;
	initial_admin(Admin);
	initial_manager(Manager);
	initial_tenant(Tenant);
	initial_timetable(TimeTable, Tenant);	
	while(true){
		string option;
		cout << "===================================" << endl;
		cout << endl;
		cout << "     1. Sign Up(Tenant)" << endl;
		cout << "     2. Log in"			 << endl;
		cout << "     3. Exit " 			 << endl;
		cout << endl;
		cout << "====================================" << endl;
		cout << "\n     Enter you option >> ";
		cin >> option;
		if(option == "1"){
			Tenant_Register(Tenant);
		}else if(option == "2"){
			Enter_ID(TimeTable,Admin, Manager, Tenant);
		}else if(option == "3"){
			system("cls");
			cout << "===================================" << endl;
			cout << endl;
			cout << "     Thank You !" <<endl;
			cout << endl;
			cout << "===================================" << endl;
			system("pause");
			return 0;
		} else {
			system("cls");
			cout << "===================================" << endl;
			cout << endl;
			cout << "     Invalid Option! " <<endl;
			cout << endl;
			cout << "===================================" << endl;
			system("pause");
			system("cls");
		}
	}
	return 0;
}
	

