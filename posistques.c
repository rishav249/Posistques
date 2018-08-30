#include<stdio.h>
#include<stdlib.h>
#include <stdint.h>
#define DATA_SIZE(y) sizeof(y[0])
#define Number_Node(x)  sizeof(x)/DATA_SIZE(x)
typedef void *  pVoid;

BitArray P10(BitArray key)
        {
           BitArray permutatedArray = new BitArray(10);
             permutatedArray[0] = key[2];
             permutatedArray[1] = key[4];
            permutatedArray[2] = key[1];
            permutatedArray[3] = key[6];
             permutatedArray[4] = key[3];
              permutatedArray[5] = key[9];
            permutatedArray[6] = key[0];
              permutatedArray[7] = key[8];
             permutatedArray[8] = key[7];
             permutatedArray[9] = key[5];
             return permutatedArray;
        }

 BitArray Circular_left_shift(BitArray a, int bitNumber)
         {
             BitArray shifted = new BitArray(a.Length);
           int index = 0;
             for (int i = bitNumber; index < a.Length; i++)
             {
                shifted[index++] = a[i%a.Length];
             }
             return shifted;
        }


BitArray RIP(BitArray permutedText)
        {
             BitArray permutatedArray = new BitArray(8);
         permutatedArray[0] = permutedText[3];
        permutatedArray[1] = permutedText[0];
        permutatedArray[2] = permutedText[2];
          permutatedArray[3] = permutedText[4];
      permutatedArray[4] = permutedText[6];
         permutatedArray[5] = permutedText[1];
         permutatedArray[6] = permutedText[7];
         permutatedArray[7] = permutedText[5];

            return permutatedArray;
        }

node* fileReader(FILE *file){
    node *i = malloc(sizeof(node));
    char node[20];
    int fileRead = fscanf(file,"%s",node);
    if(fileRead != EOF){
        i->name = strdup(node);
        i->node = fileReader(file);
    }
    if(fileRead == EOF) {
        return NULL;
    }
    return i;
struct Node
{
     char data[];
    time_t timestamp;
    int nodenumber;
    char referencenodeid[];childreferencenode_id[];genesis_referencenodeid[];hashvalue[];
    struct node *left;
    struct node *right;

};
void longestConsecutiveUtil(Node* head, int curLength,
                              int expected, int& res)
{
    if (head == NULL)
        return;
    if (head->data == expected)
        curLength++;
    else
        curLength = 1;
    res = max(res, curLength);
    longestConsecutiveUtil(head->left, curLength,
                           head->data + 1, res);
    longestConsecutiveUtil(head->right, curLength,
                           head->data + 1, res);
}

int longestConsecutive(Node* head)
{
    if (head == NULL)
        return 0;

    int res = 0;

    longestConsecutiveUtil(head, 0, head->data, res);

    return res;
}


typedef  struct Node  NodeType, * NodePointer;

}


void PrintTheInteger(NodePointer pNode)
{

  printf("\nLinked List is: \n\n");
  while (pNode != NULL)
  {
     printf("\n %d\n\n",*((int *)pNode->iData));
     pNode = pNode->pNextNode;
  }

  system("pause");
}


void PrintTheFloat(NodePointer pNode)
{

  printf("\nLinked List is: \n\n");
  while (pNode != NULL)
  {
     printf("\n %f\n\n",*((float *)pNode->iData));
     pNode = pNode->pNextNode;
  }

  system("pause");
}
int InsertNodeAtEnd(NodePointer * pHead, void *InputData, int SizeofData)
{
    int iRetValue = -1;
    int iOffSet = 0;

    NodePointer pLastNode = NULL;
    NodePointer pNewNode = NULL;


    pLastNode  = *pHead;


    pNewNode = malloc(sizeof(NodeType));

    if( pNewNode != NULL)
    {

          pNewNode->iData = malloc(SizeofData);


         for (iOffSet = 0; iOffSet < SizeofData; iOffSet++)
         *((uint8_t *)(pNewNode->iData  + iOffSet)) =  *((uint8_t *)(InputData + iOffSet));


        pNewNode->pNextNode  = NULL;

        iRetValue = 0;

    }

    if(pLastNode == NULL)
    {
        *pHead = pNewNode;
    }
    else
    {

        while( pLastNode ->pNextNode != NULL)
        {
            pLastNode  = pLastNode ->pNextNode;
        }


        pLastNode ->pNextNode = pNewNode;

    }

    return iRetValue;
}





void FreeAllocatedMemory(NodePointer  *pHead)
{
   NodePointer   pTmpNode = NULL;
   NodePointer   pFirstNode = NULL;

   pFirstNode  = *pHead;


   while (pFirstNode  != NULL)
    {


       pTmpNode = pFirstNode  ;


       pFirstNode  = pFirstNode->pNextNode;


       free(pTmpNode->iData);

       free(pTmpNode );

    }

    *pHead = NULL;

}


int CreateLinkedList(NodePointer *pHead , void *InputData, int SizeofData)
{

    int iRetValue = -1;
    int iOffSet = 0;
    NodePointer pNewNode = NULL;


        if((*pHead) == NULL)
        {

              pNewNode = malloc(sizeof(NodeType));
              if( pNewNode != NULL)
              {
                  pNewNode->iData = malloc(SizeofData);



                  for (iOffSet = 0; iOffSet < SizeofData; iOffSet++)
                  *((uint8_t *)(pNewNode->iData  + iOffSet)) =   *((uint8_t *)(InputData + iOffSet));

                  pNewNode->pNextNode  = NULL;

                  *pHead = pNewNode;

                  iRetValue = 0;

    }
        }
        else
        {

            iRetValue = InsertNodeAtEnd(pHead,InputData,SizeofData);

        }


    return iRetValue;
}



int main(void)
{
   int iRetValue = -1;
   int iChoice = 0;
   int iNumberNode =0;
   int iCount = 0;
   int iPosition =0;



   NodePointer head = NULL;


 while(1)
   {

system("cls");

 printf("\n\n\
 1: Create the Linked List of character\n\
 2: Create the Linked List of integer\n\
 3: Create the Linked List of float\n\
 4: terminatethe process \n\n\n");


          printf("\n\nenter your choice = ");
       scanf("%d",&iChoice);
       switch(iChoice)
       {
            case 1:

        {

                   char acBuffer[4] = {'a','b','c','d'};

                   iNumberNode = Number_Node(acBuffer);

               for(iCount =0;iCount <iNumberNode ;iCount++)
               CreateLinkedList(&head, (acBuffer + iCount),DATA_SIZE(acBuffer));

               PrintTheCharater(head);
           }
        break;

        case 2:
            {

               int acBuffer[4] = {1 , 2 , 3 , 4};

                   iNumberNode = Number_Node(acBuffer);

               for(iCount =0;iCount <iNumberNode ;iCount++)
               CreateLinkedList(&head, (acBuffer + iCount),DATA_SIZE(acBuffer));

               PrintTheInteger(head);
           }
        break;

        case 3:
            {

               float acBuffer[4] = {1.1 , 2.2 , 3.3 , 4.4};

                   iNumberNode = Number_Node(acBuffer);

             for(iCount =0;iCount <iNumberNode ;iCount++)
               CreateLinkedList(&head, (acBuffer + iCount),DATA_SIZE(acBuffer));

               PrintTheFloat(head);
           }
        break;

        case 4:

            printf("\n\nprocess is terminated\n ");
            exit(1);

        default:
            printf("Invalid choice\n");
            system("pause");
            break;

       }

       FreeAllocatedMemory(&head);

   }


  return 0;
}
