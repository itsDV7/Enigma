#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<strings.h>


int rotor_select[3]={1,2,3},rotor_orientation[3]={0,0,0},plug_settings[5][2]={{0,0},{0,0},{0,0},{0,0},{0,0}};
int count=0,char_count=0;
int rotor_1[26][2] = {{ 0 , 15 },{ 1 , 4 },{ 2 , 25 },{ 3 , 20 },{ 4 , 14 },{ 5 , 7 },{ 6 , 23 },{ 7 , 18 },{ 8 , 2 },{ 9 , 21 },{ 10 , 5 },{ 11 , 12 },{ 12 , 19 },{ 13 , 1 },{ 14 , 6 },{ 15 , 11 },{ 16 , 17 },{ 17 , 8 },{ 18 , 13 },{ 19 , 16 },{ 20 , 9 },{ 21 , 22 },{ 22 , 0 },{ 23 , 24 },{ 24 , 3 },{ 25 , 10 }};
int rotor_2[26][2] = {{ 0 , 25 },{ 1 , 14 },{ 2 , 20 },{ 3 , 4 },{ 4 , 18 },{ 5 , 24 },{ 6 , 3 },{ 7 , 10 },{ 8 , 5 },{ 9 , 22 },{ 10 , 15 },{ 11 , 2 },{ 12 , 8 },{ 13 , 16 },{ 14 , 23 },{ 15 , 7 },{ 16 , 12 },{ 17 , 21 },{ 18 , 1 },{ 19 , 11 },{ 20 , 6 },{ 21 , 13 },{ 22 , 9 },{ 23 , 17 },{ 24 , 0 },{ 25 , 19 }};
int rotor_3[26][2] = {{ 0 , 4 },{ 1 , 7 },{ 2 , 17 },{ 3 , 21 },{ 4 , 23 },{ 5 , 6 },{ 6 , 0 },{ 7 , 14 },{ 8 , 1 },{ 9 , 16 },{ 10 , 20 },{ 11 , 18 },{ 12 , 8 },{ 13 , 12 },{ 14 , 25 },{ 15 , 5 },{ 16 , 11 },{ 17 , 24 },{ 18 , 13 },{ 19 , 22 },{ 20 , 10 },{ 21 , 19 },{ 22 , 15 },{ 23 , 3 },{ 24 , 9 },{ 25 , 2 }};
int rotor_4[26][2] = {{ 0 , 8 },{ 1 , 12 },{ 2 , 4 },{ 3 , 19 },{ 4 , 2 },{ 5 , 6 },{ 6 , 5 },{ 7 , 17 },{ 8 , 0 },{ 9 , 24 },{ 10 , 18 },{ 11 , 16 },{ 12 , 1 },{ 13 , 25 },{ 14 , 23 },{ 15 , 22 },{ 16 , 11 },{ 17 , 7 },{ 18 , 10 },{ 19 , 3 },{ 20 , 21 },{ 21 , 20 },{ 22 , 15 },{ 23 , 14 },{ 24 , 9 },{ 25 , 13 }};
int rotor_5[26][2] = {{ 0 , 16 },{ 1 , 22 },{ 2 , 4 },{ 3 , 17 },{ 4 , 19 },{ 5 , 25 },{ 6 , 20 },{ 7 , 8 },{ 8 , 14 },{ 9 , 0 },{ 10 , 18 },{ 11 , 3 },{ 12 , 5 },{ 13 , 6 },{ 14 , 7 },{ 15 , 9 },{ 16 , 10 },{ 17 , 15 },{ 18 , 24 },{ 19 , 23 },{ 20 , 2 },{ 21 , 21 },{ 22 , 1 },{ 23 , 13 },{ 24 , 12 },{ 25 , 11 }};
char message[50];
float n_swaps=0, reflector=1;

void rotorSettings();
void plugSettings();
void plugBoard(char tempChar);
void output(char msg);
void rotor_reverse(char tempChar);
void plugBoard_reverse(char tempChar);
void default_settings();
int convert(float reflector);


void default_settings(){
	rotor_select[0]=1;
	rotor_select[1]=2;
	rotor_select[2]=3;
	rotor_orientation[0]=0;
	rotor_orientation[1]=0;
	rotor_orientation[2]=0;
	plug_settings[0][0]=0;
	plug_settings[0][1]=0;
	plug_settings[1][0]=0;
	plug_settings[1][1]=0;
	plug_settings[2][0]=0;
	plug_settings[2][1]=0;
	plug_settings[3][0]=0;
	plug_settings[3][1]=0;
	plug_settings[4][0]=0;
	plug_settings[4][1]=0;
	count=0;
	char_count=0;
	n_swaps=0; 
	reflector=1;
	printf("\n\nSettings set to default.\nPress any key to continue.\n");
	getch();
}


int convert(float reflector){
	int reflector_int = reflector;
	return reflector_int;
}


int settings(){
	char ch;
	system("cls");
	printf("Default Settings:\n");
	printf("Rotor: I-K,II-K,III-K\nReflector: UKW-K\nPlugBoard: None\n");
	printf("Continue with defaut Settings? Y=Yes.\n");
	ch=getch();
	if(ch!='Y'||ch!='y')
		rotorSettings();
		plugSettings();
	return 0;
}


void input(){
	char tempChar;
	int flag=0;
	system("cls");
	printf("Enter Message (50 Characters):\n");
	do{
		tempChar = getch();
		tempChar = toupper(tempChar);
		flag++;
		if(flag==51)
			tempChar='\r';
		if(tempChar=='\r')
			output(tempChar);
		if(tempChar!='\r')
			printf("*");
		plugBoard(tempChar-65);
	}while(tempChar!='\r');
	default_settings();
}


void rotor(char tempChar){
	int i=0;
	switch(rotor_select[2]){
		case 1: for(i=0;i<26;i++)
				if(tempChar == rotor_1[i][0]){
					tempChar=rotor_1[(i+rotor_orientation[2])%26][1];
					break;
				}
			break;
		case 2: for(i=0;i<26;i++)
				if(tempChar == rotor_2[i][0]){
					tempChar=rotor_2[(i+rotor_orientation[2])%26][1];
					break;
				}
			break;
		case 3: for(i=0;i<26;i++)
				if(tempChar == rotor_3[i][0]){
					tempChar=rotor_3[(i+rotor_orientation[2])%26][1];
					break;
				}
			break;
	}
	switch(rotor_select[1]){
		case 1: for(i=0;i<26;i++)
				if(tempChar == rotor_1[i][0]){
					tempChar=rotor_1[(i+rotor_orientation[1])%26][1];
					break;
			}
			break;
		case 2: for(i=0;i<26;i++)
				if(tempChar == rotor_2[i][0]){
					tempChar=rotor_2[(i+rotor_orientation[1])%26][1];
					break;
			}
			break;
		case 3: for(i=0;i<26;i++)
				if(tempChar == rotor_3[i][0]){
					tempChar=rotor_3[(i+rotor_orientation[1])%26][1];
					break;
			}
			break;
	}
	switch(rotor_select[0]){
		case 1: for(i=0;i<26;i++)
				if(tempChar == rotor_1[i][0]){
					tempChar=rotor_1[(i+rotor_orientation[0])%26][1];
					break;
			}
			break;
		case 2: for(i=0;i<26;i++)
				if(tempChar == rotor_2[i][0]){
					tempChar=rotor_2[(i+rotor_orientation[0])%26][1];
					break;
			}
			break;
		case 3: for(i=0;i<26;i++)
				if(tempChar == rotor_3[i][0]){
					tempChar=rotor_3[(i+rotor_orientation[0])%26][1];
					break;
			}
			break;
	}
	switch(convert(reflector)){
		case 1: for(i=0;i<26;i++)
				if(tempChar == rotor_4[i][0]){
					tempChar = rotor_4[i][1];
					break;
			}
			break;
		case 2: for(i=0;i<26;i++)
				if(tempChar == rotor_5[i][0]){
					tempChar = rotor_5[i][1];
					break;
			}
			break;
	}
	rotor_reverse(tempChar);
}


void rotor_reverse(char tempChar){
	int i=0;
	switch(rotor_select[0]){
		case 1: for(i=0;i<26;i++)
				if(tempChar == rotor_1[i][1]){
					tempChar=rotor_1[(i+rotor_orientation[0])%26][0];
					break;
			}
			break;
		case 2: for(i=0;i<26;i++)
				if(tempChar == rotor_2[i][1]){
					tempChar=rotor_2[(i+rotor_orientation[0])%26][0];
					break;
			}
			break;
		case 3: for(i=0;i<26;i++)
				if(tempChar == rotor_3[i][1]){
					tempChar=rotor_3[(i+rotor_orientation[0])%26][0];
					break;
			}
			break;
	}
	switch(rotor_select[1]){
		case 1: for(i=0;i<26;i++)
				if(tempChar == rotor_1[i][1]){
					tempChar=rotor_1[(i+rotor_orientation[1])%26][0];
					break;
			}
			break;
		case 2: for(i=0;i<26;i++)
				if(tempChar == rotor_2[i][1]){
					tempChar=rotor_2[(i+rotor_orientation[1])%26][0];
					break;
			}
			break;
		case 3: for(i=0;i<26;i++)
				if(tempChar == rotor_3[i][1]){
					tempChar=rotor_3[(i+rotor_orientation[1])%26][0];
					break;
			}
			break;
	}
	switch(rotor_select[2]){
		case 1: for(i=0;i<26;i++)
				if(tempChar == rotor_1[i][1]){
					tempChar=rotor_1[(i+rotor_orientation[2])%26][0];
					break;
			}
			break;
		case 2: for(i=0;i<26;i++)
				if(tempChar == rotor_2[i][1]){
					tempChar=rotor_2[(i+rotor_orientation[2])%26][0];
					break;
			}
			break;
		case 3: for(i=0;i<26;i++)
				if(tempChar == rotor_3[i][1]){
					tempChar=rotor_3[(i+rotor_orientation[2])%26][0];
					break;
			}
			break;
	}
	rotor_orientation[0] = (rotor_orientation[0]+1)%26;
	count++;
	if(count%26==0)
		rotor_orientation[1] = (rotor_orientation[1]+1%26);
	if(count%676==0)
		rotor_orientation[2] = (rotor_orientation[2]+1%26);
	plugBoard_reverse(tempChar);
}


void plugBoard(char tempChar){
	int i=0;
	for(i=0;i<n_swaps;i++)
		if(plug_settings[i][0]==tempChar)
			tempChar=plug_settings[i][1];
	rotor(tempChar);
}


void plugBoard_reverse(char tempChar){
	int i=0;
	for(i=0;i<n_swaps;i++)
		if(plug_settings[i][1]==tempChar)
			tempChar=plug_settings[i][0];
	output(tempChar);
}


void output(char msg){
	if(msg!='\r'){
		message[char_count]=msg+65;
		char_count++;
	}
	if(msg=='\r'){
		char_count=0;
		printf("\nEncoded Message:\n");
		while(count!=0){
			printf("%c",message[char_count]);
			count--;
			char_count++;
		}
	}	
}


void rotorSettings(){
	int i=0;
	float test_select=1, test_reflector=1;
	char test_position;
	system("cls");
	printf("Rotor Settings:\n");
	printf("Select Rotor order (Left -> Right):\n");
	printf("1. I-K,2. II-K,3. III-K");
	while(i!=3){
		printf("\nRotor-%d: ",i+1);
		scanf("%f",&test_select);
		// Test for Correct Input.
		test_select = floor(test_select);
		if(test_select<1||test_select>3){
			printf("Please Input from 1-3\n");
			continue;
		}
		rotor_select[i] = test_select;
		if(i==1&&rotor_select[i]==rotor_select[i-1])
			printf("Rotor Already Selected\n");
		else if(i==2&&(rotor_select[i]==rotor_select[i-1]||rotor_select[i]==rotor_select[i-2]))
			printf("Rotor Already Selected\n");
		else
			i++;
	}
	i=0;
	printf("Configure Rotor initial positions (Left -> Right):");
	while(i!=3){
		printf("\nRotor-%d: ",i+1);
		scanf("%s",&test_position);
		test_position = toupper(test_position);
		if(test_position<65||test_position>90){
			printf("Please input a valid character A-Z\n");
			continue;
		}
		rotor_orientation[i] = test_position;
		i++;
	}
	while(1){
		printf("Select Reflector: 1. UKW-K, 2. ETW-K\n");
		scanf("%f",&test_reflector);
		test_reflector = floor(test_reflector);
		if(test_reflector==1||test_reflector==2){
			reflector = test_reflector;
			break;
		}
		else{
			printf("Please enter correct input.\n");
			continue;
		}
	}
}


void plugSettings(){
	float n;
	int i=0,j=0;
	printf("Number of Swaps?\n");
	scanf("%f",&n_swaps);
	n_swaps = floor(n_swaps);
	n = n_swaps;
	if(n<0)
		n=0;
	else if(n>5)
		n=5;
	printf("Swap:SwapTo Array:\n");
	while(n!=0){
		printf("%d\t",i+1);
		scanf("%s %s",&plug_settings[i][j],&plug_settings[i][j+1]);
		plug_settings[i][j] = toupper(plug_settings[i][j]);
		plug_settings[i][j+1] = toupper(plug_settings[i][j+1]);
		n--;
		i++;
	}
}


int main(){
	int ch;
	while(1){
		system("cls");
		printf("Enigma Simulator:\n");
		printf("1. Encode	2. Settings	3. Exit\n");
		ch = getch()-'0';
		switch(ch){
			case 1: input();
			break;
			case 2: settings();
			break;
			case 3: exit(0);
		}
	}
}