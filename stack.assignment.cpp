#include<iostream>
#include <climits>
using namespace std;

class Stack {
private:
	struct Node {
		int item;
		Node *next;
	};

	Node *top;

public:
	Stack() {
		top = NULL;
	}

	bool isEmpty() {
		return top == NULL;
	}

	void push(int newItem) {
		Node *newNode = new Node;

		newNode -> item = newItem;
		newNode -> next = top;
		top = newNode;
		
	}
	
	void pop() {
		if (isEmpty()){
		    cout << "Stack empty on pop";
		}
		
		else {
			Node *temp = top;
			top = top -> next;
			delete temp;
		}
	}
	
	int getTop() {
        if (isEmpty()) {
            cout << "Stack empty on getTop" << endl;
            return INT_MIN;
        }
        
        return top->item;
    }

	
	void display(){
		Node *curr = top;
		
		cout << "Items in the stack are: ";
		cout << "[ ";
		
		while (curr != NULL){
			cout << curr -> item << " ";
			curr = curr -> next;
		}
		
		cout << "]\n";
	}
};
bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

bool checkDelimiters(const string& expr) {
    Stack s;

    for (int i = 0; i < expr.length(); ++i) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) return false;
            char topChar = s.getTop();
            s.pop();
            if (!isMatchingPair(topChar, ch)) return false;
        }
    }

    return s.isEmpty(); 
}

int main() {
    string input;
    cout << "Enter a sequence of symbols: ";
    getline(cin, input);

    if (checkDelimiters(input)) {
        cout << "The sequence is balanced." << endl;
    } else {
        cout << "The sequence is not balanced." << endl;
    }

    return 0;
}
  