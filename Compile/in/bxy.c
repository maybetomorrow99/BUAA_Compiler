const int _const_int_0 = +0, _const_int_1 = +00001, _const_int_2 = -00003;
const CHAR _const_char_0 = '*', _const_char_1 = '0';
Const int MAX
 = 1000;

int ERROR;
int numbers_to_be_selected, amount;
int f[1000];
int _var_int_0, _var_int_arr_0[1];
Int _var_int_1, _var_int_arr_1[16];
char _var_char_0, _var_char_arr_0[1];
char _var_char_1, _var_char_arr_1[16];
char _char;

void testDo{
    int i;
    i = 0;
    do{
        _var_int_arr_1[i] = i;
        i = i + 1;
    }while(i <= 15);
    i = 0;
    do{
        _var_int_arr_1[i] = _var_int_arr_1[2*i-i] + _var_int_arr_1[9+2*3-i];
        i = i + 1;
    }while(i <= 15);
    if(_var_int_arr_1[1] == _var_int_arr_1[5])
        ;
    else{
        printf("Error in Array & Loop Check!");
        ERROR = 1;
    }
    if(_var_int_arr_1[15] == 30)
        printf("Array & Loop Check Succeed!");
    else{
        printf("Error in Array & Loop Check!");
        ERROR = 1;
    }
}

void testArithmetic{
    const int standard = 100, ten = 10;
    int temp;
    temp = --10 -+ 10 + ten * (_const_char_1 - _const_char_0) / _const_int_2 + standard / (ten + _const_int_2 - _const_int_1);
    if(temp)
        printf("Arithmetic Check Succeed!");
    else{
        printf("Arithmetic Check Failed!");
        ERROR = 1;
    }
    temp = (standard + _const_int_1 * 15) / ten;
    if(temp == 11)
        printf("Division Check Passed!");
    else{
        printf("Error in Division Unit!");
        ERROR = 1;
    }
}

void testValue{
    _var_int_0 = -0;
    if(_var_int_0 == _const_int_0)
        if(_var_int_0 < _const_int_1)
            if(_var_int_0 > _const_int_2)
                printf("Value Assignment Succeed!");
            else{
                printf("Negative Assignment Failed!");
                ERROR = 1;
            }
        else{
            printf("Positive Assignment Failed!");
            ERROR = 1;
        }
    else{
        printf("Basic Assignment Failed!");
        ERROR = 1;
    }
}

void testCaseInsensitive{
    int Temp;
    Temp = -0;
    temp = _const_int_1;
    switch(temp){
        case 0: {
            printf("Case Sensitive Detected!");
            ERROR = 1;
        }
        case 1: printf("Case Insensitive Passed!");
        default: {
            printf("Error in testing Case Insensitive!");
            ERROR = 1;
        }
    }
}

void testSwitch(int i){
    int Temp;
    Temp = i;
    _var_int_1 = +0001;
    switch(Temp + _const_int_2 + _var_int_1 * _const_int_1){
        case 1: {
            printf("Switch Parse Check Succeed!");
        }
        default: {
            printf("Switch Logic Error!");
            ERROR = 1;
        }
    }
}

void testIf{
    if(_const_char_1 - _const_char_0 != 2 * 3){
        printf("If Statement Error!");
        ERROR = 1;
    }
    else
        printf("Passed If Statement Testing!");
}

void calRecursive(int cur_pointer, int min) {
    int i;
    if (cur_pointer == amount) {
        printf(f[0]);
        i=1;
        if(i < amount)
        do{
            printf(f[i]);
            i = i+1;
        }while(i < amount)
        else;
        printf("");
        return;
    }else;
    i = min;
    if(i <= cur_pointer + numbers_to_be_selected - amount + 1)
        do{
            f[cur_pointer] = i;
            calRecursive(cur_pointer + 1, i + 1);
            i = i + 1;
        }while(i <= cur_pointer + numbers_to_be_selected - amount + 1)
    else;
}

void initPermutation(int var, int lenth) {
    int i;
    i = 0;
    do
    {
        f[i] = var;
        i = i + 1;
    } while (i <= lenth)
    return;
}

int seqSum(int i){
    if(i == 1)
        return (1);
    else
        return (i + seqSum(i - 1));
}

void printTable{
        printf("INPUT 0: Basic Test        [Arithmetic, Case Inseneitive, Control Flow Logics]");
        printf("INPUT 1: Value Type Test   [Char Return, Char Operation, Char Conversion, Escape Char]");
        printf("INPUT 2: Structure Test    [Loop, Array, Structures]");
        printf("INPUT 3: Recursive Test    [Permutation, Sequential Sum]");
        printf("INPUT 4: Exit Program");
}

int AND(int a, int b){
    if(b == 4)
        return (0);
    else
        if(a == 0)
            return (1);
        else
            return (0); 
}

char helpChar{
    char temp;
    temp = '-';
    return (temp);
}

void typeCorrosion{
    int temp;
    char _char;
    _char = 'i';
    temp = 8;
    printf('H');
    printf(_char);
    printf(helpChar);
    printf(" ");
    printf(2);
    printf(2*1009-1-2017);
    printf('c'-'a'-('b'-'a'));
    printf(temp);
}

void testEmptyFunction{{}}

void testStructure(int a, int b, char c, char d, char e){
    int t1, t2;
    {
        {
            {
                {
                    {
                        {{{{{{{}}}}}}}
                    }
                }
            }
        }
    }
    switch(a + b + d - c - (c - e)){
        case 66666:{
            printf("Structure Check Succeed!");
            t1 = 0;
            t2 = 0;
        }
        case 0:{
            printf("Error In Register Name!");
            ERROR = 1;
        }
        default:
        ERROR = 1;
    }
    {;{;{;;;};};}
    
}


void main() {
    char choice;
    int select;
    ERROR = 0;
    _char = '0';
    do {
        printTable;
        scanf(select);
        switch(select){
            case 0:
            {
                testValue;
                testArithmetic;
                testIf;
                testSwitch(-1 * _const_int_2);
            }
            case 1:
            {
                printf("The Following Test Should Output 'Hi- 2018'");
                typeCorrosion;
                printf("This Test Should Output '\n\t\r~!@#$%^&*`' Rather Than Escape Them");
                printf("#t1");
                printf("$t1");
            }
            case 2:
            {
                _var_char_0 = '1';
                _var_char_1 = '2';
                _var_int_0 = 0012345;
                _var_int_1 = 54321;
                testDo;
                testEmptyFunction;
                testStructure(_var_int_0, _var_int_1, _var_char_0, _var_char_1, _char);
            }
            case 3:
            {
                printf("INPUT P: Permutation Output");
                printf("INPUT S: Sequential Sum");
                scanf(choice);
                switch(choice){
                    case 'P':
                    {
                        printf("INPUT INT0 INT1: Select INT1 From INT0 To Do Permutation");
                        scanf(numbers_to_be_selected, amount);
                        printf("");
                        if (amount + 1 > MAX){
                            printf("ERROR!");
                            return;
                        }else;
                        initPermutation(0, amount + 1);
                        calRecursive(0, 1);
                    }
                    case 'S':
                    {
                        printf("INPUT N: Calculate Sum From 1 To N");
                        scanf(select);
                        printf("Sequential Sum Result is: ", seqSum(select));
                        if(seqSum(10) == 55)
                                printf("Recursive Check Succeed!");
                        else{
                                ERROR = 1;
                                printf("Error in Recursive Check!");
                        }
                        select = 3;
                    }
                    default:printf("Illigal Input Detected!");
                }
                
            }
            case 4:
                    ;
            default:printf("Illigal Input Detected!");
        }
    }while(AND(ERROR, select));
    if(ERROR >= 1)
        printf("Critical Error Occurred During Testing...");
    else
        printf("Test Passed!");
    printf("Test End");
}
