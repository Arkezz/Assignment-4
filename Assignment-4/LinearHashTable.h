#pragma once
//Hash table class that - The one that uses a dynamic array should use linear probing to solve collisions.
template<class K, class T>
class LinearHashTable {
private:
	int size;
	int count;
	int numCollisions;
	T* table;
	K* keys;
	//hash function
	int hash(K key) {
		//Murmur 3 algorithim
		//https://en.wikipedia.org/wiki/MurmurHash
		uint32_t h = 0;
		for (int i = 0; i < key.length(); i++) {
			h ^= key[i];
			h *= 0x5bd1e995;
			h ^= h >> 15;
		}
		return h % 10;
	}
public:
	//Default Constructor
	LinearHashTable() {
		size = 10;
		count = 0;
		numCollisions = 0;
		table = new T[size];
		keys = new K[size];
	}
	//Insert function takes a string and an employee
	void insert(K key, T value) {
		int index = hash(key);
		if (count == size) {
			cout << "Table is full" << endl;
		}
		else {
			if (keys[index] != "") {
				numCollisions++;
			}
			while (keys[index] != "") {
				index++;
				if (index == size) {
					index = 0;
				}
			}
			keys[index] = key;
			table[index] = value;
			count++;
		}
	}
	//Remove function
	void remove(string key) {
		//Employee object is removed associated with the key
		int index = hash(key);
		if (keys[index] == key) {
			keys[index] = "";
			//Remove the employee object without using NULL
			table[index] = T();
			count--;
		}
		else {
			while (keys[index] != key) {
				index++;
				if (index == size) {
					index = 0;
				}
			}
			keys[index] = "";
			table[index] = T();
			count--;
		}
	}

	//Print function
	void print() {
		//sHOW THE index then the key and then the employee object
		for (int i = 0; i < size; i++) {
			if (keys[i] != "") {
				//Print all the employee's inforation
				cout << i << ": " << keys[i] << " " << table[i].getName() << " " << table[i].getAge() << " " << table[i].getSalary() << endl;
			}
		}
	}
	//collisionrate function shows collisionrate and number of collisions
	void collisionRate() {
		//If we hash M values and total possible hash values is T, then the expected number of collisions will be C = M * (M-1) / 2T.
		cout << "Collision Rate: " << (double)numCollisions / size << endl;
		cout << "Number of Collisions: " << numCollisions << endl;
	}
};