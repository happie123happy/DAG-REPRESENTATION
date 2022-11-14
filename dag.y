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
%token  NUM
%left '+' '-'
%left '*' '/'
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
        | expr '-' expr   {
                           Node *minus = new Node(MINUS,$1,$3);
                             int index;
                             index= dag.search(*minus);
                             if(index!=-1)
                             	$$=index;
                             else 
                              	$$=dag.insert(*minus);
                                    
                          }
        | expr '*' expr   {
                           Node *m = new Node(MULTIPLY,$1,$3);
                             int index;
                             index= dag.search(*m);
                             if(index!=-1)
                             	$$=index;
                             else 
                              	$$=dag.insert(*m);
                                    
                          }
        | expr '/' expr   {
                           Node *m = new Node(DIVIDE,$1,$3);
                             int index;
                             index= dag.search(*m);
                             if(index!=-1)
                             	$$=index;
                             else 
                              	$$=dag.insert(*m);
                                    
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
        |  NUM             {
                             Node *id = new Node(NUMBER,$1);
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
