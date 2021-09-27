#include <iostream>

using namespace std;

class hashtable{
	private:
		struct Node{
			string name;
			int age;
			Node* next;
		};

		Node* getNewNode(string name, int age){
			Node* newNode = new Node;
			newNode->name = name;
			newNode->age = age;
			newNode->next = NULL;
			return newNode; 
		}

		Node** hashTable = new Node*[20];

		int hashFunc(string name){
			int n;
			n = (name[0] + name.size()) % 20;
			return n;
		}
	
	public:
		hashtable(){
			for (int i = 0; i < 20 ; i++){
				hashTable[i] = NULL;
			}
		}

		void Insert(string name, int age){
			int n = hashFunc(name);
			Node* node = getNewNode(name, age);
			if(hashTable[n] == NULL){
				hashTable[n] = node;
			}
			else{
				Node* temp = hashTable[n];
				while(temp->next != NULL){
					temp = temp->next;
				}
				temp->next = node;
			}
		}

		int FindAge(string name){
			int n = hashFunc(name);
			Node* temp = hashTable[n];
			while(temp->name != name){
				temp = temp->next;
			}
			if(temp == NULL) return -1;
			return temp->age;
		}
};

int main(){

	hashtable employee;
	int t;
	cin>>t;
	while(t--){
		string name;
		int age;
		cin>>name>>age;
		employee.Insert(name, age);
	}
	string name;
	cin>>name;
	cout<<employee.FindAge(name);

	return 0;
}