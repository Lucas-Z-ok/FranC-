%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <cmath>   
  #include <map>
  #include <vector>
  #include <string>
  #include <iostream>
  #include <stack>

  using namespace std;

  extern int yylex ();
  extern char* yytext;
  extern FILE* yyin;
  int yyerror(char *s);

  class instruction{
  public:
    instruction (const int &c, const double &v=0, const string &n="") {code = c; value = v; name = n;};  
    int code; 
    double value;     
    string name;       
  };

  map<string,double> variables;
  int ic = 0;

  map<string,int> adresses;

  vector <instruction> code_genere;    

  int add_instruction(const int &c, const double &v=0, const string &n="") {
      code_genere.push_back(instruction(c,v,n)); 
      ic++;
      return 0; 
   }; 


%}

%code requires
  {
    typedef struct adr {
        int jmp;  // adresse du jmp
        int jc;  // adrese  du jc
    } type_adresse;
  }

%union {
  double valeur;
  char nom[50];
  type_adresse adresse;  
}

%token <valeur> NUM
%token <nom> VAR
%type <valeur> expr 
%token SIN
%token COS
%token <adresse> SI
%token ALORS
%token SINON
%token FINSI
%token SUP
%token PRINT
%token ASSIGN
%token GOTO
%token <nom> LABEL
%token JMP
%token JMPCOND

%right ADD SUB   
%left MULT DIV

%%
bloc:  /* Epsilon */
     | bloc label instruction '\n'   

label : // Epsilon
      | LABEL ':'  { // Lorsque je rencontre un label
                     // je stocke le numéro d'instruction actelle
                     // dans la table des adresses. C'est tout!   
                     adresses [$1] = ic;}

instruction :   /* Epsilon, ligne vide */
            | expr         {  }
            | PRINT expr   { add_instruction(PRINT); }
            | VAR '=' expr { add_instruction(ASSIGN, 0, $1); }
            | GOTO LABEL   { add_instruction(JMP, -999, $2); }
            | SI '(' condition ')' '\n' { $1.jc = ic;
                                          add_instruction(JMPCOND); }
              ALORS '\n'
                bloc                    { $1.jmp = ic;
                                          add_instruction(JMP);
                                          code_genere[$1.jc].value = ic;
                                        }
              SINON '\n' 
                bloc                                  
              FINSI                     { code_genere[$1.jmp].value = ic;} 
                         

expr:  NUM               { add_instruction (NUM, $1);   }
     | VAR               { add_instruction (VAR, 0, $1);  }
     | SIN '(' expr ')'  {  }
     | COS '(' expr ')'  {  }
     | '(' expr ')'      {  }
     | expr ADD expr     { $$=$1+$3;cout<< $$; }
     | expr SUB expr     { $$=$1-$3;cout<<$$; }   		
     | expr MULT expr    { $$=$1*$3;cout<<$$;}		
     | expr DIV expr     { $$=$1/$3;cout<<$$; }   


condition :  expr          {}
          |  expr SUP expr {}
%%

int yyerror(char *s) {					
    printf("%s : %s\n", s, yytext);
}






int main(int argc, char **argv) {

  if ( argc > 1 )
    yyin = fopen( argv[1], "r" );
  else
    yyin = stdin;

  yyparse();						

  return 0;
}