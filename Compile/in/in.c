
int ret{
	char c;
	c = 'a';
	return (('a'));	
} 

void main(){
	const int loc_con = 20;
	int a, b, c, i;
	i = 2;
	a = 1;
	b = 3;
	
	b = a * i;
	c = i + i;
	a = a * i;
	a = a + b + c;
	a = 5;
	b = a;
	c = b;
	printf(a);
	
	printf(ret);
	
	return;
}
