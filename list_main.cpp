#include <iostream> 
#include <string.h> 
#include "MyList.h" 
#include <string> 
 
 
int main() 
{ 
    /*MyList<int> list; 
    list.add(1); 
    list.add(2); 
    list.add(3); 
    cout << list; 
    while (!list.isEmpty()) 
        cout << list.getBegin() << " ";*/ 
    const char znak[5] = "+-*/"; 
    MyStack<string> stack; 
    string str = "56+2*"; 
    string s; 
    for (int i = 0; i < str[i]; i++) { 
        std::cout << str[i] << " "; 
        if (!strchr(znak, str[i])) { 
            char c = str[i]; 
            string s(1, c); 
            // s = to_string(c-'0); 
            stack.push(s); 
        } 
        else { 
            string s = stack.pop(); 
            int a = atoi(s.c_str()); 
            s = stack.pop(); 
            int b = atoi(s.c_str()); 
            char c = str[i]; 
            switch (c) { 
            case '+': a = a + b; break; 
            case '-': a = a - b; break; 
            case '*': a = a * b; break; 
            case '/': a = a / b;  
            } 
            s =std::to_string(a); 
            stack.push(s); 
 
        } 
    } 
    std::cout << "\n count expression 56+2* = " << stack.pop(); 
 
    //stack.addEnd("5"); 
    //stack.addEnd("") 
    //MyQueue<int> queue; 
    //for (int i = 0; i < 5; i++) 
    //    stack.push(i); 
    ////cout << stack; 
    //while (!queue.isEmpty()) 
    //    cout << queue.pop() << " "; 
}
