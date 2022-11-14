#ifndef SYMBOL_HH
#define SYMBOL_HH
#define MAX 10

class Bucket;
class Bucket{
  public:
	char *symName;
	Bucket *next;
};

//hash table implementation
 class SymbolTable{
 	
  Bucket *hashTable[MAX];

   public:

   	SymbolTable();

   	int insert(char *);

   	int search(char *);

 };

#endif