Const Int g_const_ia =+4, g_const_ib= +01 , g_const_ic = +0;
const char g_const_plus = '+' , g_const_minus = '-' ;
const int int_const_c = 0 ;
const int int_const_d = -0 , int_const_e = -03 , int_const_f = -4;
int  g_int_a , g_arr_A[1000] , g_int_32 ;
char _g_ch_r , _g_str_R[1000] ;
int g_qsa[20] ;

void pr_glo_and_local_test {
    const int l_const_ia =3 ;
    const int l_const_ic = -01 , l_const_id = -2 ;
    const char l_const_chA='A' ;
    char l_chB  ; 
    char l_chC , l_ch5 , l_mul  ;
    int l_const_ib  ;
    char l_chd ;

    g_int_a = 1  ;
     l_chB = 'B' ; 
     l_chC = 'C' ; l_ch5='5' ; l_mul = '*' ;
     l_const_ib =2 ;
     l_chd = 'D' ;

     { ; ; }

    printf("  __Welcome__to__ ::  pr_glo_and_local");
    printf(l_ch5);
    printf(g_const_ia);
    printf(l_const_iA);
    printf(l_consT_ib  ); 
    printf( g_const_iB );
    printf(g_Const_ic) ;
    printf(l_cOnst_ic) ;
    printf(l_const_id);
    printf(int_const_e );
    printf( int_const_f );

    printf("print_string_and_ident_test::", l_const_chA);
    printf(l_chB ); printf(l_chC ) ;  printf(l_chD );
    printf( "print_operators_test::" );
    printf(g_const_plus);
    printf(l_mul);
}


int foo1 { ;;
    { { ;
        ; } }
    return (1) ;
}
char foo2(char x){
    return (x);
}

char foo3{
    return ('b');
}
void op_test(int param_1 , char paRam_2 ){
    int l_32  ,l_e[2]  ;
    int l_b ,l_c ;
    int l_d ;

    l_32 = foo1+31   ;

    g_int_32= l_32 ;

    _g_ch_r  = 'r' ;
    l_d = 'D' +    34/foo1 ;    l_c=l_d-1;
    l_b = ('D'-'C'-foo1) + paRam_2 ;
    l_e[1] = param_1 ;
    l_e[0] = l_d*25 + 3*4 /2 -5*3 +(l_d-(l_c+1))+l_b;
    if ( l_e[0] == _g_ch_r )
        printf("Hi_DorMouse:: op_test_passed!");
    else ;

    return ;
}

int while_switch {
    int i   ;
    
    char ch ;
        ch='a';
        do switch(ch){
            case 'a' :{
            	
            printf("This is a !");
                        ch='b';}
    default: ;
                   }while(ch != 'd')

    i = g_const_ib -1 ;
    do 
    {
            switch(i-32/32+1)
            {
                case -0 :   i=1 ;
                case 1  :   i=i+1;
                case 2  :   i= -32 ; 
                default :   ;  
            }
    }while(i>=0)
    if (i != -g_int_32 )
        printf("while_switch_part1_ERROR!!!");
    else {
        printf("while_switch_part1_over...") ;
        i = 'a' + 0;
    }
    do switch(i){
        case 97 : {
                printf("while_switch_part2_start....");
                    do{i =i+1;}while(i <'c' + 0)
                }
        case 99 : 
                do i=i+foo1; while(i == 'd' + 0)
        case -32:
            printf("while_switch_part1_still_ERROR!!!");
        default : 
            {
                if ( i != 'i'+0)
                {    printf("while_switch_part2_should_cycle_4!!!...");
                    i=i+1;
                }
                else {
                    printf("while_switch_part2_over....");
                    return (1) ;    
                    }
            }
    }while(1)
    return (0) ;

} 

void while_switch_test {
    printf("__Welcome__to__:: while_switch_test") ;
    if ( while_switch )
        printf("Hi_DorMouse:: while_switch_test_passed!");
    else ;
}


void if_and_glo_loc_test{
    const int _g_ch_r =1 ;   
    const char g_int_a = 'a' ;
    int i ;
    char ch1 ;
    int g_const_ia  , g_const_plus  ;
    char g_const_ib , g_const_minus ;
    
    i = 0 ;

    g_const_ia = _g_ch_r ; 
    if ( g_const_ia == 4 )
        printf("wrong glo-loc 1 ...") ;
    else if (g_const_ia == 1 ) ; else printf("still wrong glo-loc 1 ...");     

    g_const_ia = 2 ;
    g_const_plus = g_const_ia + i + 1 ;
    g_const_ib = 'b' ;
    
    g_const_minus = '+' ;

    ch1 = int_const_c + 10 ;

    if ( g_const_ia == 2)
        if(g_int_a == 'a')
        if (g_const_ib > '2' ){
            if (g_const_plus < 4)
                if ( g_const_minus >= 43)
                    if(g_const_minus <= 43)
                        ch1 =ch1+6;
                    else ;
                else{ printf("5 or 4 in if_test_wrong!!!..");}
            else ;
        }
        else ;
        else ;
    else printf("1 .. 2 or 3 in if_test_wrong!!!...");

    if (ch1 != 16)
        printf("Hi_DorMouse::if_and_glo-loc_test_passed!");
    else 
        printf("Crystal::Sorry");
    return ;
}


void array_test {
    int i   ; 
    int sum ;
    int answer ;
    i = 0 ; 
    answer  = 0;
    do{
        g_arr_A[i]=i+1 ;
        i = i+1 ;
    }while(i<=999)
    sum = 0 ;  
    i = 0;
    do{
        sum= sum + g_arr_A[i] ; 
        i = i+ g_const_ib ;
    }while (i < 1000)

    printf("array_test_part_1_ans::",sum);
    if ( sum == 5050) ;
    else answer= answer + 3 ; 

    _g_str_R[97]= 'a';

    if (_g_str_R[97]=='a') answer=answer+3     ; else answer=answer+1024;
    printf("array_test_part_2_ans::",answer);

    return ;
}

int quick_sort(int low ,int high ){
    int i , j , x , flag ;
    if (low<high)
    {
        i =low ;
        j = high ; 
        x= g_qsa[i];
        flag = 0; 
        do
        {
            do {
                if(i<j)
                    if (g_qsa[j] > x)
                        j=j-1 ;
                    else flag = 1;
                else flag = 1 ;
            }while(flag == 0)
            if(i<j)
            {
                g_qsa[i]= g_qsa[j];
                i= i + 1;
                flag =0;
            }else ;

            do {
                if(i<j)
                    if (g_qsa[i] < x)
                        i=i+1 ;
                    else flag = 1;
                else flag = 1 ;
            }while(flag == 0)
            if(i<j)
            {
                g_qsa[j]= g_qsa[i];
                j= j - 1;
                flag =0;
            } else ;
        }while(i<j)
        g_qsa[i]=x;
        quick_sort(low,i-1);
        quick_sort(i+1,high);
    }
    else ;
    return (0);
}

void quick_sort_test {
    int n ,key;
    int i ;
    i =0 ;
    printf("__Welcome__to__::quick_sort_test...");
    printf("DorMouse,please Input the length(1..20)" );
    scanf(n);
    do{
        if(n<=0)
            if(n>20)
            {
            printf("Invalid length,sorry,agian please::");
            scanf(n);
            }else ;
        else;
    } while( n <= 0)
    do{
        scanf(key);
        g_qsa[i] = key ;
        i=i+1;
    }while( i < n )
    
    quick_sort(0, n- 1 );
    

    i =0 ;
    do{
        printf(g_qsa[i] );
        i=i+1 ;
    }while(i<n-1)

    return ;
}
int gcd(int a,int b)
{
    int tmp;
    if (b>0)
    {
        tmp= a- a/b*b ; 
        return (gcd(b,tmp));
    }
    else return (a);
}
void gcd_test {
    int m , answer, n ;
    printf("__Welcome__to__::gcd_test...");
    printf("Ringo,please Input a number" );
    scanf(m);
    do{
        if(m<0){
            printf("Invalid integer ,sorry,agian please::");
            scanf(m);
        }
        else ;
    } while( m < 0)
    scanf(n);
    do{
        if(n<0){
            printf("Invalid integer ,sorry,agian please::");
            scanf(n);
        }
        else ;
    } while( n < 0)
    answer = gcd(m,n);
    printf("answer is:: ",answer);
}
void main(){
    int i ;
    printf("__Welcome__to__DorMouse_C");
    printf("Input 0, and skip quick_sort_test & gcd_test ");
    scanf(i);

    pr_glo_and_local_test ;
    if( i ==0 )
        op_test(1,foo2('b')) ;
    else
        op_test(1,foo3);
    while_switch_test ;
    if_and_glo_loc_test ;
    array_test ;

    if( i != 0 )
    {    quick_sort_test;
        gcd_test;
    }
    else ;
    return ;
}
