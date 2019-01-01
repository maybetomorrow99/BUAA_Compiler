const int con = 10;
int glb; 

void testmap{
	int a, b, c;
	a = 1 + 2;
	b = 2;
	c = 3;
	b = 2;
	c = 3;
	c = 3;	
}


void main(){
	const int loc_con = 20;
	int a, b, c, d;
	int array[10];
	char ch;
	glb = 4;
	a = 10 + glb;
	a = a + 2;
	b = 2;
	c = 3;	
	d = -1;
	c = a + b + c;
	
	printf(c);
	c = (a * b * c) + (a * b) + (a + 1) + (2 + 3);
	
	printf(c);
	d = (a + b) + (a + b) + (a + 1);	
	printf(d);
	ch = 'a';
	printf(ch);
	a = c + loc_con + 3 - 1 + (20 * ( 5 - 1) + 30 / 2) * 2 + b;
	return;
}
