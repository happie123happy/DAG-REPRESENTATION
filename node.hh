#ifndef NODE_HH
#define NODE_HH

#define MAXSIZE 100

typedef enum{
  IDENTIFIER,
  NUMBER,
  PLUS,
  MINUS,
  MULTIPLY,
  DIVIDE,
  ASSIGN
}NodeType;

class Node{
 
   NodeType nType;   
   int symOrConstOrLeftIndex;
   int rightIndex;
 public:
    Node(NodeType,int,int=-1);
    Node();
 	
 	//copy constructor
 	Node(const Node &);

 	bool operator==(Node&);
 	void print();

};

class DAGNodes{
    //simple array representation
    Node arrayOfNodes[MAXSIZE];
    int size;
  public:
    // set size to 0
    DAGNodes();

   int getSize();
    // insert and increment the size
   int insert(Node);
    // search for node
   int search(Node);

   void print();
   void printToDot();
};


#endif