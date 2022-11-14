%{
#include "symbol.hh"
#include "node.hh"
SymbolTable gTable;
#include "dag.tab.h"
%}
%%
[a-zA-Z][a-zA-Z0-9_]*      { 
                                int insertAt;
								int index= gTable.search(yytext);
                                if(index==-1){
                                 	insertAt = gTable.insert(yytext);
                                 	yylval = insertAt;
                                }
                                else{
                                	yylval = index;
                                }

                                return ID;
                            }
[0-9]+                      { 
                                int insertAt;
								int index= gTable.search(yytext);
                                if(index==-1){
                                 	insertAt = gTable.insert(yytext);
                                 	yylval = insertAt;
                                }
                                else{
                                	yylval = index;
                                }

                                return NUM;
                            }                            
[-*/%+=()]                       { return yytext[0];}
 \n                        { return yytext[0];}
%%