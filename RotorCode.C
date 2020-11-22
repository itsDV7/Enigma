// Generate array code for rotors.

#include<stdio.h>
#include<string.h>
int main(){
	char s[26];
	int i;
	gets(s); // Input rotor encryption
	printf("rotor_#[26][2] = {"); // Replace # with rotor number
	for(i=0;i<=24;i++){
		printf("{ %d , %d },",i,s[i]-65);
	}
	printf("{ %d , %d }};",25,s[25]-65);
	return 0;
}
