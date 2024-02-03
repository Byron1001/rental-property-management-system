#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "readCSV_2.h"
//#include<windows.h>
#include <unistd.h>
#include "doubly_circular_linked_list.h"
#include "circular_linked_list.h"
#include "my_stack.h"
#include "my_queue.h"
vector<string> split_(string date){
	vector<string> temp;
	stringstream ss(date);
	string cell;
	while (getline(ss, cell, '_'))
	temp.push_back(cell); 
	return temp;
}
class Tenant{
	private:
		string userID;
		string name;
		string password;
		string email;
		int LastActive;
		queue<string> FavoriteProperty;
		doubly_circular_linked_list<string> RentingRequest;
		circular_linked_list<string> RentingConfirm;
		stack<string> RentingHistory;
	public:
		Tenant(vector<string> tenant){
			userID = tenant.get(0);
			name = tenant.get(1);
			password = tenant.get(2);
			email = tenant.get(3);
			LastActive = stoi(tenant.get(4));
			FavoriteProperty = convert_to_queue(tenant.get(5));
			RentingRequest = convert_to_doubly_circular(tenant.get(6));
			RentingConfirm = convert_to_circular(tenant.get(7));
			RentingHistory = convert_to_stack(tenant.get(8));
		}
		stack<string> convert_to_stack(string str){
			stack<string> temp;
			stringstream ss(str);
			string cell;
			while(getline(ss,cell, ',')){
				temp.push(cell);
			}
			return temp;
		}
		circular_linked_list<string> convert_to_circular(string str){
			circular_linked_list<string> temp;
			stringstream ss(str);
			string cell;
			while(getline(ss,cell, ',')){
				string result;
				for (char c : cell) {
			        if (c != '"') {
			            result += c;
			        }
			    }
				temp.append(result);
			}
			return temp;
		}
		doubly_circular_linked_list<string> convert_to_doubly_circular(string str){
			doubly_circular_linked_list<string>  temp;
			stringstream ss(str);
			string cell;
			while(getline(ss,cell, ',')){
				string result;
				for (char c : cell) {
			        if (c != '"')
			            result += c;
			    }
				temp.append(result);
			}
			return temp;
		}
		queue<string> convert_to_queue(string str){
			queue<string> temp;
			stringstream ss(str);
			string cell;
			while(getline(ss,cell,',')){
				string result;
				for (char c : cell) {
			        if (c != '"')
			            result += c;
			    }
				temp.push(result);
			}
			return temp;
		}
		vector<string> convert_to_vector(string str){
			vector<string> temp;
			stringstream ss(str);
			string cell;
			while(getline(ss,cell,',')){
				string result;
				for (char c : cell) {
			        if (c != '"')
			            result += c;
			    }
				temp.push_back(result);
			}
			return temp;
		}
		string get_userID(){
			return userID;
		}
		string get_name(){
			return name;
		}
		string get_password(){
			return password;
		}
		string get_email(){
			return email;
		}
		string get_LastActive(){
			return to_string(LastActive);
		}
		string get_FavoriteProperty(int index){
			return queue_get(FavoriteProperty,index);
		}
		queue<string> get_FavoriteProperty_queue(){
			return FavoriteProperty;
		}
		int get_FavoriteProperty_length(){
			return FavoriteProperty.len();
		}
		int get_RentingRequest_length(){
			return RentingRequest.len();
		}
		string get_RentingRequest(int index){
			return RentingRequest.get(index);
		}
		string get_RentingConfirm(int index){
			return RentingConfirm.get(index);	
		}
		string get_RentingHistory(int index){
			return stack_get(RentingHistory,index);
		}
		int get_FavoriteProperty_len(){
			return FavoriteProperty.len();
		}
		int get_RentingConfirm_len(){
			return RentingConfirm.len();
		}
		int get_RentingHistory_len(){
			return RentingHistory.len();
		}
		void Display_Renting_Request(){
			cout << setiosflags(ios::left)<< setw(20) << "Option";
			cout << setiosflags(ios::left)<< setw(20) << "ID";
			cout << setiosflags(ios::left)<< setw(20) << "Year";
			cout << setiosflags(ios::left)<< setw(20) << "Month" << endl;
			for(int i=0 ; i<RentingRequest.len() ; i++){
				vector<string> temp = split_(RentingRequest.get(i));
				cout << setiosflags(ios::left)<< setw(20) << i+1;
				cout << setiosflags(ios::left)<< setw(20) << temp.get(0);
				cout << setiosflags(ios::left)<< setw(20) << temp.get(1); 
				cout << setiosflags(ios::left)<< setw(20) << temp.get(2) << endl;
			}
		}
		void Add_Favorite_Property(string favorite_property){
			FavoriteProperty.push(favorite_property);
		}
		void Delete_Favorite_Property(int index){
			queue_remove(FavoriteProperty,index);
		}
		void Add_Renting_Request(string New_Request){
			RentingRequest.append(New_Request);
		}
		void Delete_Renting_Request(int index){
			RentingRequest.remove(index);
		}
		void Add_Renting_Confirm(string New_Renting){
			RentingConfirm.append(New_Renting);
		}
		void Delete_Renting_Confirm(int index){
			RentingConfirm.remove(index);
		}
		void Add_Renting_Property_History(string New_Renting_Property){
			RentingHistory.push(New_Renting_Property);
		}
		void Delete_Renting_Property_History(int index){
			stack_remove(RentingHistory,index);
		}	
		void Display_Renting_Property_History(){
			for(int i=0 ; i< RentingHistory.len() ; i++)
			cout << stack_get(RentingHistory,i) <<endl;
		}
		void Display_Favorite_Property(){
			for(int i=0 ; i<FavoriteProperty.len() ; i++){
				cout << i+1 << "   " << queue_get(FavoriteProperty,i) << endl;
			}
		}
		void Display_Renting_Confirm(){
			cout << "index      id         year         month "<<endl;
			for(int i=0 ; i<RentingConfirm.len() ; i++){
				vector<string> temp = split_(RentingConfirm.get(i));
				cout << i+1 << "          ";
				cout << temp.get(0) << "    ";
				cout << temp.get(1) << "    ";
				cout << temp.get(2) << endl;
			}
		}
		void Display_Renting_History(){
			for(int i=0 ; i<RentingHistory.len() ; i++){
				cout << i+1 << "   " << stack_get(RentingHistory,i) << endl;
			}
		}
		void Update(vector<vector<string>>& tenant){
			vector<string> temp1;
			string temp2 = "";
			temp1.push_back(userID);
			temp1.push_back(name);
			temp1.push_back(password);
			temp1.push_back(email);
			temp1.push_back(to_string(LastActive));
			for(int i=0 ; i<FavoriteProperty.len() ; i++){
				temp2+=queue_get(FavoriteProperty,i);
				if(i!=FavoriteProperty.len()-1)
				temp2+=','; 
			}
			temp1.push_back(temp2);
			temp2= "";

				
			for(int i=0 ; i<RentingRequest.len() ; i++){
				temp2+=RentingRequest.get(i);
				if(i!=RentingRequest.len()-1)
				temp2+=','; 
			}
			temp1.push_back(temp2);
			temp2= "";
			
			for(int i=0 ; i<RentingConfirm.len() ; i++){
				temp2+=RentingConfirm.get(i);
				if(i!=RentingConfirm.len()-1)
				temp2+=','; 
			}
			temp1.push_back(temp2);
			temp2= "";
			
			for(int i=0 ; i<RentingHistory.len() ; i++){
				temp2+=stack_get(RentingHistory,i);
				if(i!=RentingHistory.len()-1)
				temp2+=','; 
			}
			temp1.push_back(temp2);
			temp2= "";
			for(int i=0 ; i<tenant.len() ; i++){
				vector<string> temp = tenant.get(i);
				if(userID == temp.get(0))
				tenant.set(i,temp1);
			}
		}
		void display_all(){
			cout << "userID >>" << userID <<endl;
			cout << "Name >>" << name <<endl;
			cout << "Password >>" << password <<endl;
			cout << "Email >>" << email <<endl;
			cout << "LastActive >>" << LastActive <<endl;
			cout << "Renting Favorite >> ";
			for(int i=0 ; i<FavoriteProperty.len() ; i++){
				cout << FavoriteProperty.get(i) << " " ;
			} 
			cout << "\nRenting Request >> ";
			for(int i=0 ; i<RentingRequest.len() ; i++){
				cout << RentingRequest.get(i) << " " ;
			} 
			cout << "\nRenting Confirm >> ";
			for(int i=0 ; i<RentingConfirm.len() ; i++){
				cout << RentingConfirm.get(i) << " " ;
			} 
			cout << "\nRenting History >> ";
			for(int i=0 ; i<RentingHistory.len() ; i++){
				cout << stack_get(RentingHistory,0) << " " ;
			} 
		}
};
class Manager{
	private:
		string managerID;
		string username;
		string password;
		string email;
		string status;
	public:
		Manager(vector<string> manager){
			managerID = manager.get(0);
			username = manager.get(1);
			password = manager.get(2);
			email = manager.get(3);
			status = manager.get(4);
		}
		string get_username(){
			return username;
		}
		string get_password(){
			return password;
		}
		string get_email(){
			return email;
		}
		void change_status(){
			if(status == "active")
				status = "inactive";
			else
				status = "active";
		}
		void display_all(){
			cout << "managerID >> " << managerID << endl;
			cout << "username >> " << username <<endl;
			cout << "password >> " << password <<endl;
			cout << "email >> " << email <<endl;
			cout << "status >> " << status << endl;
		}
};
class Admin{
	private:
		string adminID;
		string username;
		string password;
		string email;
	public:
		Admin(vector<string> admin){
			adminID = admin.get(0);
			username = admin.get(1);
			password = admin.get(2);
			email = admin.get(3);
		}
		string get_adminID(){
			return adminID;
		}
		string get_username(){
			return username;
		}
		string get_password(){
			return password;
		}
		string get_email(){
			return email;
		}
		void Update_to_CSV(){
			readCSV file("testing.csv");
			vector<string> temp1;
			string temp2 = "";
			temp1.push_back(adminID);
			temp1.push_back(username);
			temp1.push_back(password);
			temp1.push_back(email);
			file.set(file.search(adminID,0),temp1);
		}
		void display_all(){
			cout << "managerID >> " << adminID << endl;
			cout << "username >> " << username <<endl;
			cout << "password >> " << password <<endl;
			cout << "email >> " << email <<endl;
		}
};



