%{
#include<iostream>
using namespace std;
extern int yylex();
extern void yyerror(char const*);
#include "node.hh"
DAGNodes dag;
%}
%start line
%token  ID
%left '+'
%%                   /* beginning of rules section */
line  : assignment '\n' { dag.print(); }
assignment: ID '=' expr  {
                            Node *assign = new Node(ASSIGN,$1,$3);
                              	$$=dag.insert(*assign);
	
                          } 
expr:   expr '+' expr   {
                           Node *plus = new Node(PLUS,$1,$3);
                             int index;
                             index= dag.search(*plus);
                             if(index!=-1)
                             	$$=index;
                             else 
                              	$$=dag.insert(*plus);
                                    
                          }
        |  ID             {
                             Node *id = new Node(IDENTIFIER,$1);
                             int index;
                             index= dag.search(*id);
                             if(index!=-1)
                             	$$=index;
                             else 
                              	$$=dag.insert(*id);
                             
                           }
        | '(' expr ')'     {
                                 $$=$2;
                            }
        ;
        
%%
void yyerror(char const*){
  
}
int main()
{
 yyparse();
}
