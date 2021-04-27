// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

int stackqueue (char sq){
switch (sq){
default: return -1;
case '(': return 0; break;
case ')': return 1; break;
case '+': return 2; break;
case '-': return 2; break;
case '/': return 3; break;
case '*': return 3; break;
}}
int operations (char oper, int before, int after){
switch (oper) {
default: return -1;   
case '+': return before + after; break;
case '-': return before - after; break;
case '*': return before * after; break;
case '/': return before / after; break;	
}}
std::string infx2pstfx(std::string inf) {
TStack <char> stack1;
std::string str;
char current = 0, symbol;
int queue;
for (int i = 0; i < inf.length(); i++) {
symbol = inf[i];
queue = stackqueue(symbol);
if (queue > -1) {
if ((queue == 0 || queue > stackqueue(current) || stack1.isEmpty()) && symbol != ')'){
if (stack1.isEmpty()){
current = symbol;
stack1.push(symbol)
}
else if (symbol == ')') {
while (stack1.get() != '(') {
str.push_back(stack1.get());
str.push_back(' ');
stack1.pop();
}
if (stack1.isEmpty())
current = 0;
}
else {
while (!stack1.isEmpty() && stackqueue(stack1.get()) >= queue)){
str.push_back(stack1.get());
str.push_back(' ');
stack1.pop();
if (stack1.isEmpty()){
current = inf[i];
stack1.push(inf[i]);
}}}
}
else {
str.push_back(symbol);
str.push_back(' ');
}}
while (!stack1.isEmpty()) {
str.push_back(stack1.get());
str.push_back(' ');
stack1.pop();
}
str.erase(str.end() - 1, str.end());
return str;  
}
int eval(std::string pst) {
TStack<int> stack2;
std::string str2;
int before, after, result;
for (int i = 0; i < pst.length(); i++) {
if (pst[i] >= '0' && pst[i] <= '9') {
str2 = pst[i];
stack2.push(pst[i] - '0');
} 
else if (pst[i] != ' ') {
after = stack2.get();
stack2.pop();
before = stack2.get();
stack2.pop();
if (pst[i] == '*'||pst[i] =='-'||pst[i] =='/'||pst[i] =='+'){
result = operations(pst[i], before, after);
}}
return stack2.get();
}
