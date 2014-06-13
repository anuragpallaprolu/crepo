#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
THE TREE PRINTER

LYNCH-eNVY Computer Corporation 2013
*/

#define MAX 100

struct treenode{
       char *wordptr;
       int count;
       struct treenode *left;
       struct treenode *right;
       };

/*
Every tree package comes with a left node ifndef and a right node def
*/

struct treenode *addnode(struct treenode *init_node, char *word_entry); // Defining a function to add a node to an existing tree
void treeprint(struct treenode *root); //Printing the tree from root
int getword(char *word_entry, int len);//Getting word input from user

main()
{
      struct treenode *root = NULL; //define the root node
      char word[MAX]; //word character array with a MAX size
      while(getword(word, MAX)!='\n'){//while the input character recieved by the routine GETWORD IS NOT a new line...
                          if(isalpha(word[0])){//if the first character is an alphabet
                                                   root = addnode(root, word); //add a new node after root i.e. RECURSION
                                                   }
                          treeprint(root);//print each level of insertion into the TREE
                          }
      getch();
      }

struct treenode *node_alloc(void); //Node Allocator
char *strduplicate(char *str);//copy string to store in a location which is allocated by node_alloc i.e MALLOC char

struct treenode *addnode(struct treenode *node, char *word)
{
       int stat;// status of word comparison used for strcmp out value
       
       if(node == NULL)
       {
               node = node_alloc(); // allocate a node space for the new arrival
               node->wordptr = strduplicate(word); //duplicate the word and store in node_alloc
               node->count = 1; // initialize the counter
               node->left = NULL; // set left child to NULL (INIT)
               node->right = NULL; //set right child to NULL
               }
       
       else if((stat = strcmp(word, node->wordptr))==0){ //if its an exact match
            ++(node->count); //increment the node counter
                             }
       else if(stat < 0){
            node->left = addnode(node->left, word); //if the strcmp < 0 i.e the string is lexically lesser than the node, 
                                                    //then througha recursive allocation, 
                                                    //a new node is created by addnode and the word is inserted into the left or the right depending on the lexical ineq.
            }
       else{
            node->right = addnode(node->right, word);
            }
       return node; //give the new added node
       
       }     

//the treeprint subroutine

void treeprint(struct treenode *node){
     if(node!=NULL){
                    treeprint(node->left);
                    printf("%d %s", node->count, node->wordptr);
                    treeprint(node->right);
                    }
                    
}


#include <stdlib.h>
struct treenode *node_alloc(void){
       return (struct treenode *)malloc(sizeof(struct treenode));
       
       }


char *strduplicate(char *inp)
{
     char *dup = NULL;
     int i;
     for(i=0; i<=MAX; ++i)
     {
              if((inp+1)!=NULL)
              *(dup+i) = *(inp+i);
              }
     return dup;
}

int getword(char *word_entry, int len){
    int i, c;
    for(i=0; i<=len &&(c=getchar())!=
              
     
 
                          
