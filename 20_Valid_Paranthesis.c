bool isValid(char* s) {
    int len = strlen(s);
    char stack[len];
    int top = -1;
    
    for (int i = 0; i < len; i++) {
        char current = s[i];
        if (current == '(') {
            stack[++top] = ')';
        } 
        else if (current == '[') {
            stack[++top] = ']';
        } 
        else if (current == '{') {
            stack[++top] = '}';
        } 
        else {
            if (top == -1 || stack[top] != current) {
                return false;
            }
            top--; 
        }
    }
    return top == -1;
}
