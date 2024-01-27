#include<stdio.h>
#include<stdlib.h>
#include "LinkedList/LinkedList.h"

int main(){
    LinkedList_t* pList = CreateLinkedList();


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




    LinkedList_t* pList1 = CreateLinkedList();

    LinkedList_t* pList2 = CreateLinkedList();

    for(int i=-1; i<8; i++){
        InsertAtEnd(pList1,i*3);
    }


    for(int i=1; i<14; i++){
        InsertAtEnd(pList2,i*2);
    }

    SortedInsert(pList1,31);
    SortedInsert(pList1,23);
    SortedInsert(pList1,29);
    SortedInsert(pList1,17);
    SortedInsert(pList1,7);
    SortedInsert(pList1,2);
    SortedInsert(pList1,4);

    SortedInsert(pList2,34);
    SortedInsert(pList2,38);
    SortedInsert(pList2,11);
    SortedInsert(pList2,13);
    SortedInsert(pList2,19);
    SortedInsert(pList2,1);
     printf(".............................................................................................................\n\n");
    printf("List1...\n");
    Display(pList1);
    printf(".............................................................................................................\n\n");
    printf("List2...\n");
    Display(pList2);
    LinkedList_t* pMerged = Merge(pList1,pList2);
    RemoveDuplicates(pMerged);
    LinkedList_t* pConct = Concatenate(pList1,pList2);
    printf(".............................................................................................................\n\n");
    printf("List1...\n");
    Display(pList1);
    printf(".............................................................................................................\n\n");
    printf("List2...\n");
    Display(pList2);
    printf(".............................................................................................................\n\n");
    printf("Merged...\n");
    Display(pMerged);
    printf(".............................................................................................................\n\n");
    printf("Concatenated...\n");
    Display(pConct);
    printf(".............................................................................................................\n\n");

    /*************************************************************
     * IsLoop Test Code, Can be uncommented and comment out line freeing pMerged
     * ***********************************************************
    Node_t* pNode = pMerged->m_pHeadNode->m_pNextNode->m_pNextNode;

    Node_t *pTemp = pMerged->m_pHeadNode;

    while(pTemp->m_pNextNode != NULL){
        pTemp = pTemp->m_pNextNode;
    }
    pTemp->m_pNextNode = pNode;

    printf("Loop...\n");
    printf("IsLoop: %d\n",IsLoop(pMerged));
    **/
    printf("Linear...\n");
    printf("IsLoop: %d\n",IsLoop(pList1));


    free(pList);
    free(pList1);
    free(pList2);
    FreeList(pConct);
    FreeList(pMerged);

    return EXIT_SUCCESS;
}