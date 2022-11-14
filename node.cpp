#include "node.hh"
#include<iostream>
using namespace std;

Node::Node(){
    
}
Node::Node(NodeType t,int li,int ri){
    
    nType=t;   
    symOrConstOrLeftIndex=li;
    rightIndex=ri;
}
//copy constructor
Node::Node(const Node &x){
 
    nType=x.nType;   
    symOrConstOrLeftIndex=x.symOrConstOrLeftIndex;
    rightIndex=x.rightIndex;   
}
bool Node::operator==(Node &o){

    if(nType==o.nType && symOrConstOrLeftIndex==o.symOrConstOrLeftIndex&& rightIndex==o.rightIndex)
                return true;
    else
                return false;
}
void Node::print(){

       switch(nType){

       case IDENTIFIER:
                 cout<<"\n  "<<"ID"<<" "<<symOrConstOrLeftIndex;
                  break;
       case NUMBER:
                cout<<"\n  "<<"NUMBER"<<" "<<symOrConstOrLeftIndex;
                   break;
       case PLUS:
                cout<<"\n  "<<"+"<<" "<<symOrConstOrLeftIndex<<" "<<rightIndex;
                   break;
      case MINUS:
                cout<<"\n  "<<"-"<<" "<<symOrConstOrLeftIndex<<" "<<rightIndex;
                   break;
      case MULTIPLY:
                cout<<"\n  "<<"*"<<" "<<symOrConstOrLeftIndex<<" "<<rightIndex;
                   break;
      case DIVIDE:
                cout<<"\n  "<<"/"<<" "<<symOrConstOrLeftIndex<<" "<<rightIndex;
                   break;
      case ASSIGN:
                cout<<"\n  "<<"="<<" "<<symOrConstOrLeftIndex<<" "<<rightIndex;
                   break;

 
       }
}

DAGNodes::DAGNodes(){
     size=0;
}
int DAGNodes::getSize(){
     return size;
}
    // insert and increment the size
int DAGNodes::insert(Node x){

   arrayOfNodes[size] = x;
   size = size+1;
    return size-1;
}
    // search for node
int DAGNodes::search(Node x){
  
  //linear search
  for(int i=0;i<size;i++){
      if(arrayOfNodes[i]==x)
        return i;
  }

  return -1;
}

void DAGNodes::print(){

  for(int i=0;i<size;i++){
      arrayOfNodes[i].print();
  }
}


void DAGNodes::printToDot(){
// open a file dag.dot and write a->b
  
}