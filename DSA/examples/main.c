#include<stdio.h>
#include<stdlib.h>
#include "LinkedList/LinkedList.h"

int main(){
    LinkedList_t* pList = (LinkedList_t* )malloc(sizeof(LinkedList_t));
    // Create a LinkedList
    CreateLinkedList(pList);


    for (int i=0; i<20; i++){
        InsertAtEnd(pList,i);
    }

    InsertAtEnd(pList,23);
    Display(pList);
    printf("\n..........................................................................................................\n\n");

    SortedInsert(pList,22);
    Display(pList);
    printf("\n..........................................................................................................\n\n");

    SortedInsert(pList,-22);
    Display(pList);
    printf("\n..........................................................................................................\n\n");

    SortedInsert(pList,28);
    SortedInsert(pList,27);
    SortedInsert(pList,26);
    SortedInsert(pList,25);
    SortedInsert(pList,24);
    SortedInsert(pList,21);
    SortedInsert(pList,20);
    Display(pList);
    printf("\n..........................................................................................................\n\n");

    Delete(pList,0);
    Display(pList);
    printf("\n..........................................................................................................\n\n");\

    Delete(pList,1);
    Display(pList);
    printf("\n..........................................................................................................\n\n");

    printf("%d\n",(pList,20));
    Delete(pList,4);
    Delete(pList,19);
    Delete(pList,0);
    Delete(pList,10);
    Delete(pList,22);
    Delete(pList,21);
    Delete(pList,10);
    Delete(pList,11);
    printf("%d\n",(pList,0));
    Delete(pList,0);
    Display(pList);
    printf("\n..........................................................................................................\n\n");

    Node_t* node = search(pList,-22);
    if(node){
        printf("Found: %d\n",node->m_iData);
    }
    else{
        printf("Not Found\n");
    }
    Display(pList);
    printf("............................................................................................................\n\n");

    printf("size: %ld\n",Rsize(pList->m_pHeadNode));
    printf(".............................................................................................................\n\n");

    printf("SUM: %d\n",sum(pList));
    printf("RSUM: %d\n",Rsum(pList->m_pHeadNode));
    printf("...............................................................................................................\n\n");

    printf("MAX: %d\n",max(pList));
    printf("RMAX: %d\n",Rmax(pList->m_pHeadNode));

    printf("................................................................................................................\n\n");
    printf("MIN: %d\n",min(pList));
    printf("RMIN: %d\n",Rmin(pList->m_pHeadNode));

    printf("IsSorted: %d\n",IsSorted(pList));


    Insert(pList,17,25);
    Insert(pList,18,25);
    Insert(pList,0,3);
    Insert(pList,1,3);
    Display(pList);
    printf("............................................................................................................\n\n");

    RemoveDuplicates(pList);
    Display(pList);
    RReverse(pList,pList->m_pHeadNode,NULL);
    Display(pList);
    printf("............................................................................................................\n\n");

    FreeList(pList);
    printf("size: %ld\n",size(pList));
    printf(".............................................................................................................\n\n");

    free(pList);

    return EXIT_SUCCESS;
}