#include <iostream>
#include <string>
using namespace std;

// Kiem tra neu element la phep cong tru nhan chia
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Ham thuc hien tinh toan tuong ung voi phep toan + - * /
int applyOperation(int b, int a, char op) {
    switch (op) {
    case '+': return b + a;
    case '-': return b - a;
    case '*': return b * a;
    case '/': return b / a; // Gia su a != 0
    default: return 0;
    }
}


int postFixToPrefix(const string& expression) {
    int stack[100];   // Mang stack de mo phong Stack
    int top = -1;   

    for (char ch : expression) {
        if (ch == ' ') continue;

        if (isdigit(ch)) {
            stack[++top] = ch - '0';
        }
        else if (isOperator(ch)) {
            int a = stack[top--];   
            int b = stack[top--];   
            int result = applyOperation(b, a, ch);
            stack[++top] = result;   
        }
    }

    return stack[top];
}

int main() {
    string postfix = "53+62/*35*+";
    int result = postFixToPrefix(postfix);
    cout << "Result: " << result << endl;
    return 0;
}
