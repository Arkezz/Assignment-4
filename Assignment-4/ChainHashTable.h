#pragma once
template <class K, class T>
//Hash table class that uses linked lists and seperate chaining
class ChainHashTable {
	struct node {
		K key;
		T data;
		node* next;
	};
private:
	node* table[10];
	int count;
	//Use a murmur3 hash function to hash the key to an index
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
	int numCollisions;

public:
	//Default constructor
	ChainHashTable() {
		count = 0;
		numCollisions = 0;
		for (int i = 0; i < 10; i++) {
			table[i] = NULL;
		}
	}
	//Insert Function use seperate chaining increase the count if sth is added
	void insert(K key, T value) {
		int index = hash(key);
		node* temp = new node;
		temp->key = key;
		temp->data = value;
		temp->next = NULL;
		if (table[index] == NULL) {
			table[index] = temp;
			count++;
		}
		else {
			numCollisions++;
			node* ptr = table[index];
			while (ptr->next != NULL) {
				ptr = ptr->next;
			}
			ptr->next = temp;
			count++;
		}
	}
	//Remove function decrease the count if sth is removed
	void remove(K key) {
		int index = hash(key);
		node* ptr = table[index];
		node* prev = NULL;
		if (ptr->key == key) {
			table[index] = ptr->next;
			delete ptr;
			count--;
		}
		else {
			while (ptr->key != key) {
				prev = ptr;
				ptr = ptr->next;
			}
			prev->next = ptr->next;
			delete ptr;
			count--;
		}
	}
	//Print functions displays the key(the string) and the data stored in it in an organized layout
	void print() {
		for (int i = 0; i < 10; i++) {
			node* ptr = table[i];
			cout << "Index " << i << ": ";
			while (ptr != NULL) {
				cout << "Key " << ptr->key << ":" << ptr->data.getName() << " " << ptr->data.getAge() << " " << ptr->data.getSalary() << " " << ptr->data.getExperience() << " -> ";
				ptr = ptr->next;
			}
			cout << endl;
		}
	}

	//Function that shows collision rate and number of collisions
	void collisionRate() {
		cout << "Collision rate: " << (double)numCollisions / count << endl;
		cout << "Number of collisions: " << numCollisions << endl;
	}
};
