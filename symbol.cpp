#include "symbol.hh"
#include<stdlib.h>
#include<string.h>
SymbolTable::SymbolTable(){

    for(int i=0;i<MAX;i++)
          hashTable[i]=NULL;
}

//insert into symboltable
int SymbolTable::insert(char *name)
{
    //printf("inserting %s into symboltable\n",name);
    Bucket *newBucket = (Bucket*)malloc(sizeof(Bucket));

     //find length
    int i;
    for(i=0;name[i]!='\0';i++);

    newBucket->symName = (char*)malloc(sizeof(char)*i);
    
    strcpy(newBucket->symName,name);

    newBucket->next = NULL;

    //calculate hash key
    int key = name[0] % MAX;
    
    if(hashTable[key] == NULL)
        hashTable[key] = newBucket;
    //collision
    else
    {
        //add at the end of hashtable[key].
        Bucket *temp = hashTable[key];
 
        while(temp->next!=NULL)
        {
            temp = temp->next;
            // key = key+MAX  to get different key values
            key=key+MAX;
        }
        temp->next = newBucket;
    }

    return key;
}

//search for a symbol in symbol table
int SymbolTable::search(char *name){
   //calculate hash key

    //printf("searching for %s\n", name);
    int key = name[0] % MAX;
    
    if(hashTable[key] == NULL)
        return -1;
    else{
        Bucket *temp;
        do{
            temp=hashTable[key];
            //printf("%s ==== %s \n", temp->name, name);
            if(strcmp(temp->symName, name)==0){
                //printf("found %s", temp->name);
                return key;
            }
            temp = temp->next;
            key=key+MAX;
          } while(temp!=NULL);

          return -1;        
    }
}

