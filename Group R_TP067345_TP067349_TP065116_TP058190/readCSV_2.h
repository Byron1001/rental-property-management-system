#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "my_vector.h"
#include<windows.h>
#include<unistd.h>
#include<iomanip>
using namespace std;
class readCSV{
	protected:
		string fileName;
		int numRows;
		int numCols;
		vector<string>* warehouse = new vector<string>[20000];
	public:
		readCSV(string filename) {
			fileName = filename;
			ifstream file(fileName);
		    if (!file.is_open())
		        cout << "Error opening the file" << endl;
		    string line;
		    numRows = 0;
		    numCols = 0;	
			int n = 0;
			numCols = 0;
		    while (getline(file, line)) {
		        stringstream ss(line);
		        string cell;
		        vector<string> temp2;
				int sentinal = 0;
				string result = "";
		        while (getline(ss, cell, ',')) {
		        	if(sentinal == 0){
						if(cell.length() == 0)
			        		temp2.push_back(""); 
						else if(cell[0]=='\"'){
							result+= cell.substr(1, cell.length() - 1);
							sentinal = 1;
						}else
							temp2.push_back(cell);
					} else {
						if(cell[cell.length()-1] == '\"'){
							result+= ',';
							result+=cell.substr(0, cell.length() - 2);
							temp2.push_back(result);
							result = "";
							sentinal = 0;
						} else {
							result+=',';
							result+=cell; 
						}
					}
		        }
		        	if(temp2.len() < numCols)
		        		temp2.push_back(""); 
		        warehouse[n]=temp2;
		        numRows++;
		        vector<string> temp3 = warehouse[0];
		        numCols = temp3.len();
				n++;
	    	}
		    file.close();
		}
		void tenant_display_apartment(int page){
			vector<string> temp1 = warehouse[0];
			for(int j=0 ; j<numCols-9 ; j++){
					if(j==0)
						cout << setiosflags(ios::left)<< setw(10) << " ";
					if(j==1)
						cout << setiosflags(ios::left)<< setw(45) << temp1.get(j);
					else		
						cout << setiosflags(ios::left)<< setw(20) << temp1.get(j);
				}
			cout << endl;
			int page_start = (page-1)*50+1;
			int page_end = (page-1)*50+51;
			if(page_end > numRows)
				page_end = numRows;
			for(int i=page_start ; i<page_end ; i++){
				vector<string> temp1 = warehouse[i];
				for(int j=0 ; j<numCols-9 ; j++){
					if(j==0)
						cout << setiosflags(ios::left)<< setw(10) << i;
					if(j==1)
						cout << setiosflags(ios::left)<< setw(45) << temp1.get(j);
					else
						cout << setiosflags(ios::left)<< setw(20) << temp1.get(j);
				}
				cout << endl;
			}
		}	
		void tenant_display_apartment(int page, int col){
			int threshold = 5;
			vector<string> temp1 = warehouse[0];
			for(int j=0 ; j<numCols-9 ; j++){
				if(j==0)
					cout << setiosflags(ios::left)<< setw(10) << " ";
				if(j==1)
					cout << setiosflags(ios::left)<< setw(45) << temp1.get(j);
				else if(j==2 && col >= threshold)
					cout << setiosflags(ios::left)<< setw(20) << temp1.get(col);
				else		
					cout << setiosflags(ios::left)<< setw(20) << temp1.get(j);
			}
			cout << endl;
			int page_start = (page-1)*50+1;
			int page_end = (page-1)*50+51;
			if(page_end > numRows)
				page_end = numRows;
			for(int i=page_start ; i<page_end ; i++){
				vector<string> temp1 = warehouse[i];
				for(int j=0 ; j<numCols-9 ; j++){
					if(j==0)
						cout << setiosflags(ios::left)<< setw(10) << i;
					if(j==1)
						cout << setiosflags(ios::left)<< setw(45) << temp1.get(j);
					else if(j==2 && col >= threshold)
						cout << setiosflags(ios::left)<< setw(20) << temp1.get(col);
					else
						cout << setiosflags(ios::left)<< setw(20) << temp1.get(j);
				}
				cout << endl;
			}
		}
		void display_all(){
			for(int i=0 ; i<numRows-1 ; i++){
				vector<string> temp1 = warehouse[i];
				for(int j=0 ; j<numCols-9 ; j++){
					if(j==0)
						cout << setiosflags(ios::left)<< setw(10) << i;
					if(j==1)
						cout << setiosflags(ios::left)<< setw(45) << temp1.get(j);
					else
						cout << setiosflags(ios::left)<< setw(20) << temp1.get(j);
				}
				cout << endl;
			}
		}
		vector<string> get_row(int index){
			vector<string> temp = warehouse[index];
			return temp;
		}
		int get_numRows(){
			return numRows;
		}
		int get_numCols(){
			return numCols;
		}
		int search(string target, int column){
			for(int i = 1 ; i<numRows ; i++){
				vector<string> temp1  = warehouse[i];
				if(temp1.get(column) == target)
					return i;
			}
			return -1;
		}
		void set(int index, vector<string> new_row){
			warehouse[index] = new_row;
		}
		void swap(int index1, int index2){
			vector<string> temp = warehouse[index1];
			warehouse[index1] = warehouse[index2];
			warehouse[index2] = temp;
		}
		int extractInteger(string str){		
			string digits;
			for (char c : str) {
				if (std::isdigit(c)) {
					digits += c;
				}
				if(c=='.')
					break;
		    }
		    if(digits.length()==0){
		    	//cout << digits <<endl;
				return 0;
			}
		    int value;
		    std::stringstream(digits) >> value;
		    return value;
		}
		int s_partition( int low, int high, int column){
			vector<string> temp1 = warehouse[high];
			string pivot = temp1.get(column);
			int i = low-1;
		    for (int j = low; j <= high - 1; j++) {
		    	vector<string> temp2 = warehouse[j];
		        if (temp2.get(column) >= pivot) {
		            i++;
		            swap(i,j);
		        }
		    }
		    swap(i+1,high);
		    return i+1;
		}		
		void s_quickSort(int low, int high, int column ){
			if(low < high){
				int pivotIndex = s_partition(low, high,column);
				s_quickSort(low, pivotIndex-1, column);
				s_quickSort(pivotIndex+1, high, column);
			}
		}
		int i_partition( int low, int high, int column){
			vector<string> temp1 = warehouse[high];
			int pivot = extractInteger(temp1.get(column));
			int i = low-1;
		    for (int j = low; j <= high - 1; j++) {
		    	vector<string> temp2 = warehouse[j];
		        if (extractInteger(temp2.get(column)) >= pivot) {
		            i++;
		            swap(i,j);
		        }
		    }
		    swap(i+1,high);
		    return i+1;
		}		
		void i_quickSort(int low, int high, int column ){
			if(low < high){
				int pivotIndex = i_partition(low, high,column);
				i_quickSort(low, pivotIndex-1, column);
				i_quickSort(pivotIndex+1, high, column);
			}
		}
		void s_merge(int low, int mid, int high, int column) {
			int n1 = mid - low + 1;
	        int n2 = high - mid;
	        vector<vector<string>> left;
	        vector<vector<string>> right;
	        for (int i = 0; i < n1; i++)
	            left.push_back(warehouse[low + i]) ;
	        for (int j = 0; j < n2; j++)
	            right.push_back(warehouse[mid + 1 + j ]);
	        int i = 0;
	        int j = 0;
	        int k = low;
	        while (i < n1 && j < n2) {
	        	vector<string> temp1 = left.get(i);
	        	vector<string> temp2 = right.get(j);
	        	if (temp1.get(column) > temp2.get(column)) { //version1 for string
	                set(k,temp1);
	                i++;
	            }
	            else {
	                set(k,temp2);
	                j++;
	            }
	            k++;
	        }
	        while (i < n1) {
	            set(k,left.get(i));
	            i++;
	            k++;
	        }
	        while (j < n2) {
	            //temp1.get(k) = right.get(j);
	            set(k,right.get(j));
	            j++;
	            k++;
	        }
	    }
	    void s_mergeSort(int low, int high, int column) {
	        if (low < high) {
	            int mid = low + (high - low) / 2;
	            s_mergeSort(low, mid, column);
	            s_mergeSort(mid + 1, high, column);
	            s_merge(low, mid, high, column);
	        }
	    }
	    void i_merge(int low, int mid, int high, int column) {
			int n1 = mid - low + 1;
	        int n2 = high - mid;
	        vector<vector<string>> left;
	        vector<vector<string>> right;
	        for (int i = 0; i < n1; i++)
	            left.push_back(warehouse[low + i]) ;
	        for (int j = 0; j < n2; j++)
	            right.push_back(warehouse[mid + 1 + j ]);
	        int i = 0;
	        int j = 0;
	        int k = low;
	        while (i < n1 && j < n2) {
	        	vector<string> temp1 = left.get(i);
	        	vector<string> temp2 = right.get(j);
	            if (extractInteger(temp1.get(column)) > extractInteger(temp2.get(column))) { //version2 for integer
	                set(k,temp1);
	                i++;
	            } else {
	                set(k,temp2);
	                j++;
	            }
	            k++;
	        }
	        while (i < n1) {
	            set(k,left.get(i));
	            i++;
	            k++;
	        }
	        while (j < n2) {
	            //temp1.get(k) = right.get(j);
	            set(k,right.get(j));
	            j++;
	            k++;
	        }
	    }
	    void i_mergeSort(int low, int high, int column) {
	        if (low < high) {
	            int mid = low + (high - low) / 2;
	            i_mergeSort(low, mid, column);
	            i_mergeSort(mid + 1, high, column);
	            i_merge(low, mid, high, column);
	        }
	    }
		int Binary_Search(int n,int target){ //ID
			int left = 1;
		    int right = numRows - 1;
		    while (left <= right) {
		        int mid = left + (right - left) / 2;
		        if (extractInteger(warehouse[mid].get(n)) == target)
		            return mid;
		        // If the target is greater, ignore the left half
		        if (extractInteger(warehouse[mid].get(n)) > target)
		            left = mid + 1;
		        // If the target is smaller, ignore the right half
		        else
		            right = mid - 1;
    		}
    		return -1;
		}
		int LinearSearch(int n,int target){
			for(int i=0 ; i<numRows ; i++){
				if(extractInteger(warehouse[i].get(n)) == target)
					return i;
			}
			return -1;
		}
		void filter_display(int column, string search){
			int n=0;
			vector<string> temp1 = warehouse[0];
			for(int j=0 ; j<numCols-9 ; j++){
				if(j==0){
					cout << setiosflags(ios::left)<< setw(10) << " ";
				}
				if(j==1)
					cout << setiosflags(ios::left)<< setw(45) << temp1.get(j);
				else		
					cout << setiosflags(ios::left)<< setw(20) << temp1.get(j);
			}
			cout << endl;
			for (char& c : search)
			    c = std::tolower(c);
			for(int i = 1 ; i<numRows ; i++){
				vector<string> temp1 = warehouse[i];
				string str = temp1.get(column);
				for (char& c : str)
			        c = std::tolower(c);
				size_t found = str.find(search);
				if (found != string::npos) {
					for(int j=0 ; j<numCols-9 ; j++){
						if(j==0)
							cout << setiosflags(ios::left)<< setw(10) << " ";
						if(j==1)
							cout << setiosflags(ios::left)<< setw(45) << temp1.get(j);
						else
							cout << setiosflags(ios::left)<< setw(20) << temp1.get(j);
					}
					n++;
					cout << endl;
				} 
				if(n==30)
					return;
			}
		}
		void filter_display2(string search){
			int n=0;
			vector<string> temp1 = warehouse[0];
			for(int j=0 ; j<numCols-9 ; j++){
					if(j==0)
						cout << setiosflags(ios::left)<< setw(10) << " ";
					if(j==1)
						cout << setiosflags(ios::left)<< setw(45) << temp1.get(j);
					else		
						cout << setiosflags(ios::left)<< setw(20) << temp1.get(j);
				}
				cout << endl;
			for (char& c : search)
			    c = std::tolower(c);
			for(int i = 1 ; i<numRows ; i++){
				vector<string> temp1 = warehouse[i];
				for(int column = 0; column<numCols-9 ; column++){ // loop
					string str = temp1.get(column);
					for (char& c : str)
				        c = std::tolower(c);
					size_t found = str.find(search);
					if (found != string::npos) {
						for(int j=0 ; j<numCols-9 ; j++){
								if(j==0)
									cout << setiosflags(ios::left)<< setw(10) << " ";
								if(j==1)
									cout << setiosflags(ios::left)<< setw(45) << temp1.get(j);
								else
									cout << setiosflags(ios::left)<< setw(20) << temp1.get(j);
						}
						n++;
						cout << endl;
						if(n==30){
							return;
						}
						break;
					}
				}
			}
		}
		void filter_display3(string property_type, string furnished,string search){
			int n=0;
			vector<string> temp1 = warehouse[0];
			for(int j=0 ; j<numCols-9 ; j++){
					if(j==0)
						cout << setiosflags(ios::left)<< setw(10) << " ";
					if(j==1)
						cout << setiosflags(ios::left)<< setw(45) << temp1.get(j);
					else		
						cout << setiosflags(ios::left)<< setw(20) << temp1.get(j);
				}
				cout << endl;
			for (char& c : search)
			    c = std::tolower(c);
			for(int i = 1 ; i<numRows ; i++){
				vector<string> temp1 = warehouse[i];
				if(property_type!= "All"){
					if(temp1.get(5)!= property_type)
					continue;
				}
				if(furnished!= "All"){
					if(temp1.get(10)!= furnished)
					continue;
				}
				for(int column = 0; column<numCols-9 ; column++){ // loop
					string str = temp1.get(column);
					for (char& c : str)
				        c = std::tolower(c);
					size_t found = str.find(search);
					if (found != string::npos) {
						for(int j=0 ; j<numCols-9 ; j++){
								if(j==0)
									cout << setiosflags(ios::left)<< setw(10) << " ";
								if(j==1)
									cout << setiosflags(ios::left)<< setw(45) << temp1.get(j);
								else
									cout << setiosflags(ios::left)<< setw(20) << temp1.get(j);
						}
						n++;
						cout << endl;
						if(n==30)
							return;
						break;
					} 
				}
			}
		}
};