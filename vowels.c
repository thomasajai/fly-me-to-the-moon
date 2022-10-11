%{
	int vowels=0,cons=0;
%}

%%
[aeiouAEIOU] { vowels++;}
[a-zA-Z] { cons++; }
%%

int main(){
	yylex();
	printf("\nno of vowels = %d",vowels);
	printf("\nno of consonants = %d\n",cons);
	return 0;
}
