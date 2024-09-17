%{
	int chars=0,words=0,lines=0;
%}

%%
[^\t\n ]+ {words++;
		chars=chars+yyleng;}
[ ]* {chars++;}
[\n] {lines++;
chars++;}
%%

int main(){
	yyin = fopen("input.txt","r");
	yylex();
	fclose(yyin);
	printf("\nwords = %d",words);
	printf("\ncharacters = %d",chars);
	printf("\nlines = %d\n",lines);
	return 0;
}// trading 123
