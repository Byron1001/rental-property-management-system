#include <iostream>
#include "my_vector.h"
#include <iomanip>
template<typename KeyType, typename ValueType>
class map {
private:
    vector<KeyType> keys;
    vector<ValueType> values;
public:
    void insert(const KeyType& key, const ValueType& value) {
        // Check if the key already exists in the map
        for (size_t i = 0; i < keys.len(); i++) {
            if (keys.get(i) == key) {
                // Key already exists, update the value
                values.push_back(value);
                return;
            }
        }

        // Key does not exist, add a new key-value pair
        keys.push_back(key);
        values.push_back(value);
    }
    bool contains(const KeyType& key) {
        // Check if the key exists in the map
        for(int i=0 ; i<keys.len() ; i++){
        	if(keys.get(i) == key){
        		return true;
			}
		}
    }
    ValueType operator[](const KeyType& key) {
        // Return the value associated with the key
        for (int i = 0; i < keys.len(); i++) {
            if (keys.get(i) == key) {
                return values.get(i);
            }
        }

        // Key does not exist, create a new key-value pair
        keys.push_back(key);
        values.push_back(ValueType()); // Use default-constructed value
        return values.get(values.len()-1);
    }
    void plus_one(const KeyType& key){
    	for(int i=0 ; i<keys.len() ; i++){
        	if(keys.get(i) == key){
        		values.set(i,values.get(i)+1);
			}
		}
	}
	void sort(){
		for(int i=0 ; i<keys.len() ; i++){
			for(int j=i ; j<keys.len() ; j++){
				if(values.get(i)<values.get(j)){
					keys.swap(i,j);
					values.swap(i,j); 
				}
			}
		}
	}
	void report(){
		cout << "============================" << endl;
		
		for(int i=0 ; i<keys.len() ; i++){
			cout << setiosflags(ios::left)<< setw(15) << keys.get(i);
			cout << setiosflags(ios::left)<< setw(2) << values.get(i);
			for(int j=0 ; j<values.get(i) ; j++)
			cout << " * ";
			cout << endl;
		}
		
		cout << "============================" << endl;
	}
};