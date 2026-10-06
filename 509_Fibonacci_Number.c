

int fib(int n){
    int a = -1, b = 1, c, i;
    for( i = 0; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;

}
