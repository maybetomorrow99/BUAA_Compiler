CoNst int num_1= 23,num_2 = 24;
conSt char char_1 = 'a',char_2 = 'm';

inT var_1,var_2,count;
iNt var_arr[12];
int vchar_arr[12];
char A ;
int test_recursion(int n){
    if(n==1)
        return (1);
    else if(n==2)
        return (2);
    else
        return (test_recursion(n-1)*test_recursion(n-2));
}

void array_create{
    var_arr[count] = count;
    vchar_arr[count] = 'a' + count;
    {;;;;;;;;;;;;;;;;;}
   {;;;;;;;;;;;;;;;;;;}
   {{{;;;;;}}}
}


void test_switch(int x_x,char y_y){
    switch(x_x){
        case +0: var_1 = var_1 + 1;
        case +1: var_2 = var_2 + 1;
        default: var_1 = -1;
    }
    switch(y_y){
        case 'a': var_1 = var_1 + 1;
        case 'b': var_2 = var_2 + 1;
        default:var_1 = var_1 - 1;
    }
    return ;
}


int return_add(int a,int b,int c,int d){
    int sum;
    sum = a + b + c + d;
    return (sum);
}
int return_sub(int a,int b,int c,int d){
   int sum;
   sum = a - b - c - d;
   return (sum);
}
char returnA{
    A = 'A';
    return (A);
}

void testIfElse(char target){
    if((target)!=('A'))
        printf("if-else and return test failed!");
    else
        printf("if-else test  and return success!");
}

void main(){
    int x,y;
    int recursion_1,input;
    char input_1;

    count = 0;
    do{
        array_create;
        do{
            count = count + 1;
        }while(0);
        if(count > 10)
            printf("do_while_do_while test success!!!");
        else ;
    }while(count <11);


    x = ((((-+000054--100))))-num_1/num_2+char_1*char_2+((1 + 3) * 'a' + var_arr[4]) * (return_add(((((-+000054--100))))-num_1/num_2+char_1*char_2,2,3,4))-(666/var_arr[2])/111*(return_sub(10,4,((((-+000054--100))))-num_1/num_2+char_1*char_2,2));
    printf(x);


    x = 0;var_1 = 0;var_2 = 0;
    test_switch(x+10-100/10,'a');
    if(var_1==2)
    printf("test switch_1 success!");
    else printf("test switch_1 failed!");

    test_switch(x+1-100+10+3*30,'b');
    if(var_2==2)
    printf("test switch_2 success!");
    else printf("test switch_2 failed!");

    test_switch('d'-'-','s');
    if(var_1>=-2)
        if(var_1<=-2)
            printf("test switch_3 success!");
        else printf("test switch_3 failed!");
    else printf("test switch_3 failed!");

    x = var_arr[((1+2)*3-5)+(20-10)-(100/10)];
    y = vchar_arr[((1+2)*3-5)+(20-10)-(100/10)];
    printf(x);
    printf(y);
    printf("!@#$%^&*()+=-_,./;<=>?[]\|{}~");

    testIfElse(returnA);

    scanf(input,input_1);
    recursion_1 = test_recursion((input+input_1-'a')/2);
    printf(recursion_1);

    return;

}
