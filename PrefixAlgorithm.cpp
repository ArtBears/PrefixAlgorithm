/* On my honor,
The following program is a result of personal effort. I have not discussed with
anyone other than my instructor or any appropriate person in charge of the class.
I have not used, or slightly modified  code or portion of code from another
student, or an unauthorized source.
If any C++ language code or documentation used in my program was obtained from
another source, such as a textbook or course notes, that has been clearly noted
with a proper citation in the comments of my program.
I have not designed this program in such a way as to defeat or interfere with the
normal operation of the eniac system or cslab machines at Hunter College .
< Glyne Gittens >
*/
//
// Created by Glyne Gittens on 5/1/16.
//
#include <string>
#include <stack>
#include <iostream>
#include <sstream>

using namespace std;


/*
 * What's the benefit of breaking a string into a stack when the op could be don
 * right away? I'm honestly unsure. Instead of dealing with chars we could deal with strings instead
 * operators could be set as strings.
 */

int main(int argc, char * argv[]){

    string holder;
    string operation;
    string word = "/9899";
    stack<string> operands;
    stack<string> operators;


    for(int i = 0; i < word.length(); i++){
        stringstream ss;
        ss << word[i];
        ss >> holder;
        cout << holder << endl;
        // push + and marker onto operator stack
        if(holder == "+"){
            operators.push("+");
            operands.push("$");
        }
        // push - and marker onto operator stack
        else if(holder == "-"){
            operators.push("-");
            operands.push("$");
        }
        // push * and marker onto operator stack
        else if(holder == "*"){
            operators.push("*");
            operands.push("$");
        }
        // push / and marker onto operator stack
        else if(holder == "/"){
            operators.push("/");
            operands.push("$");
        }
        // else it is an operand
        else{
            // If the top of the operands stack is a marker -> $
            // push holder onto the operands stack
            if(operands.top() == "$"){
                operands.push(holder);
            }

            // else the top of the operand stack is an operand
            else{
                // Prepare operand for equations by pushing onto stack
                operands.push(holder);

                if (!operators.empty()){operation = operators.top();operators.pop();}

                int current = stoi(operands.top());
                operands.pop();
                // while(operand.top()) isn't a marker perform an operation.
                // after the operation is done, push it onto the stack.
                while(operands.top() != "$" && !operands.empty()){
                    if(operation == "+"){
                        current += stoi(operands.top());
                        operands.pop();
                    }
                    else if(operation == "-"){
                        current -= stoi(operands.top());
                        operands.pop();
                    }
                    else if(operation == "*"){
                        current *= stoi(operands.top());
                        operands.pop();
                    }
                    else if(operation == "/"){
                        current /= stoi(operands.top());
                        operands.pop();
                    }

                }
                operands.push(to_string(current));
            }
        }
    }

cout << "answer: " << operands.top() << endl;

}

