#include<stdio.h>
#include<stdlib.h>
#include "LinkedList/LinkedList.h"

int main(){
    LinkedList_t* pList = (LinkedList_t* )malloc(sizeof(LinkedList_t));
    // Create a LinkedList
    CreateLinkedList(pList);

    for (int i=0; i<20; i++){
        AddNode(pList,i);
    }

    Display(pList);
    RDisplay(pList->m_pHeadNode);
    printf("\n");
    printf("size: %ld\n",Rsize(pList->m_pHeadNode));

    printf("SUM: %d\n",sum(pList));
    printf("RSUM: %d\n",Rsum(pList->m_pHeadNode));
}