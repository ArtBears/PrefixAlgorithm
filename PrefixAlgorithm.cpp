//
// Created by Glyne Gittens on 5/1/16.
//
#include <string>
#include <stack>
#include <iostream>

using namespace std;


bool isMarker(char input){
    if(input != '$'){
        return false;
    }
    return true;
}


void performOperation(int& original, stack<int>& operands ,stack<int>& holder, stack<char>& operators) {
    cout << "Value of Current: " << original << endl;
    while (!holder.empty()) {
        cout << "Starting Perform Op while loop" << endl;
        cout << "While Current Value: " << original << endl;
        cout << "Top of operand stack: " << operands.top() << endl;
        switch (operators.top()) {
            case '*':
                if(holder.top() == 0){
                    holder.pop();
                    holder.push(1);
                }
                original = original * holder.top();
                holder.pop();
                cout << "*: " << original << " and " << holder.top() << endl;
                break;
            case '/':
                if(holder.top() == 0){
                    holder.pop();
                    holder.push(1);
                }
                original = original / holder.top();
                holder.pop();
                cout << "/: " <<original << " and " << holder.top() << endl;
                break;
            case '+':

                cout << "+: " << original  << " and " << holder.top() << endl;
                original = original + holder.top();
                holder.pop();
                break;

            case '-':
                original = original - holder.top();
                holder.pop();
                cout << " -: " << original << " and " << holder.top() << endl;
                break;
            default:
                cerr << "Invalid operator!" << endl;
                cout << original << " and " << holder.top() << endl;
                break;

        }

        cout << "End in Perform Op" << endl;
    }
}



int main(int argc, char * argv[]){


    stack <char> operators;
    stack <int> operands;
    stack <int> op_holder;
    string  word;
    int current;
    int count;
    word = "*223";
    count = word.length();

    try {
        cout << stoi("b") << endl;
    } catch(exception e){

    }

    /* *
     * Better implementation would be to make sure that
     * each input is separated by a space (" ").
     * split() the input string into an array by spaces.
     * */

    int i = 0;
    while(i < count){
        cout << "Stuck in main" << endl;
        cout << "Current letter: " << word[i] << endl;



        switch(word[i]){
            case '*':
                operators.push('*');
                operands.push('$');
                break;
            case '/':
                operators.push('/');
                operands.push('$');
                break;
            case '+':
                operators.push('+');
                operands.push('$');
                cout << "pushed operator +" << endl;
                break;
            case '-':
                operators.push('-');
                operands.push('$');
                break;


            default:
                // Check for a marker on top of operands stack:
                // If there is a marker push the current token onto operand stack.
                if ( isMarker( operands.top() )){
                    try {
                        cout << "Top of Operands: " << operands.top() << endl;
                        cout << "Letter in try block: " << word[i] << endl;
//                        current = word[i] - 48;
                        cout << "Current in try block: " << current << endl;

                        operands.push(word[i] - 48);

                        cout << "Pushed word[i]-48 into operands in try block" << endl;
                    } catch(exception e){
                        cerr << "Illegal Token Found" << endl;
                        break;
                    }
                    if(i == (count - 1)){
                        op_holder.push(operands.top()); // holds operands that will be acted on
                        operands.pop();
                        performOperation(current, operands, op_holder, operators);
                    }

                }




                    // add operands to the other_operands
                // else,
                else{
                    while(!isMarker(operands.top())){
                        try {
                            op_holder.push(current);
                            current = word[i] - 48;
                             // holds operands that will be acted on

                            cout << "popping operand from try" << endl;
                            if(!operands.empty()){
                                op_holder.push(operands.top());
                                operands.pop();
                            }
                            performOperation(current, operands, op_holder, operators);

                            cout << "End of try and else " << endl;

                        }catch (exception e){
                            cerr << "Illegal Token Found 2" << endl;
                            break;
                        }
                    }
                    if(operands.empty()){
                        cout << "This is current: " << current << endl;
                    }

                }



        }
        i++;
    }

    cout << "This is the last current: " << current << " and Top of operands: " << operands.top() << " " << (int) '$' << endl;

}

// Problem is that holder is getting an unconverted char push on top of it.