#include<iostream>
using namespace std;

template<typename T>
class Stack{
	T *data;
	int nextitem;
	int capacity;
	
	public:
		//Constructor for initialization
		Stack(){
			data = new T[4];  //Can put any value to intialise
			nextitem = 0;
			capacity = 4;   //Can put any value to intialise
		}
		
		//To get the size of current array
		int size(){
			return nextitem;
		}
		
		//To check weather stack is empty or not
		bool isEmpty(){
			if(nextitem ==0){
				return true;
			}
			else{
				return false;
			}
		}
		
		//To get get top value of Stack
		T top(){
			return data[nextitem-1];
		}
		
		//To insert new element into stack
		void push(T element){
			if(nextitem == capacity){
				T *newdata = new T[2*capacity];
				for(int i=0; i<capacity; i++){
					newdata[i] = data[i];
				}
				capacity = capacity*2;
				delete [] data;
				data = newdata;
			}
			data[nextitem] = element;
			nextitem++;
		}
		
		//To remove top value from stack
		T pop(){
			if(isEmpty()){
				cout<<"Stack is Empty"<<endl;
				return 0;
			}
			nextitem--;
			return data[nextitem];
		}
};


int main(){
	Stack<char> s1;  //at place of char you can use any data type you want to use
	
	s1.push('a');
	s1.push('b');
	s1.push('c');
	s1.push('d');	
	s1.push('e');
	
	cout<<s1.top()<<endl;
	
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;
	
	cout<<s1.size()<<endl;
	cout<<s1.isEmpty()<<endl;
	
	return 0;
}
