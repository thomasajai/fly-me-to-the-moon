%{
%}

%%
[a-zA-Z]* {
    for(int i=0;i<yyleng-2; i++){
        if(yytext[i] == 'a' && yytext[i+1] == 'b' && yytext[i+2] == 'c'){
            yytext[i] = 'A';
            yytext[i+1] = 'B';
            yytext[i+2] = 'C';
        }
    }
    printf("%s\n",yytext);
}
%%

int main(){
	yylex();
	return 0;
}
Kigditd
Khckdoy
Hfu
