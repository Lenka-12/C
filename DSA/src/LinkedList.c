#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "LinkedList/LinkedList.h"
void CreateLinkedList(LinkedList_t* pList){
    pList->m_pHeadNode = NULL;
}

void AddNode(LinkedList_t *pList, int iData){
    if(pList->m_pHeadNode==NULL){
        pList->m_pHeadNode = (Node_t*)malloc(sizeof(Node_t));
        pList->m_pHeadNode->m_iData = iData;
        pList->m_pHeadNode->m_pNextNode = NULL;
    }

    else{
        Node_t* pTempHead = pList->m_pHeadNode;

        while(pTempHead->m_pNextNode!=NULL){
            pTempHead = pTempHead->m_pNextNode;
        }
        Node_t* pTempNode = (Node_t* )malloc(sizeof(Node_t));
        pTempNode->m_iData = iData;
        pTempNode->m_pNextNode= NULL;
        pTempHead->m_pNextNode = pTempNode;
    }

}

void Display(LinkedList_t *pList){
    Node_t* pTempHead = pList->m_pHeadNode;

    while (pTempHead!=NULL)
    {
        printf("%d ",pTempHead->m_iData);
        pTempHead = pTempHead->m_pNextNode;
    }
    printf("\n");
    
}

void RDisplay(Node_t* pNode){
    if(pNode!=NULL){
        RDisplay(pNode->m_pNextNode);
        printf("%d ",pNode->m_iData);
    }
}

size_t size(LinkedList_t* pList){
     Node_t* pTempHead = pList->m_pHeadNode;
     size_t uiLen = 0;
     while (pTempHead!=NULL)
     {
        uiLen++;
        pTempHead=pTempHead->m_pNextNode;
     }

     return uiLen;
     
}

size_t Rsize(Node_t *pNode){
    if(pNode==NULL){
        return 0;
    }
    else{
        return Rsize(pNode->m_pNextNode)+1;
    }
}

int sum(LinkedList_t* pList){
    Node_t *pHead = pList->m_pHeadNode;
    int iSum = 0l;

    while(pHead!=NULL){
        iSum+=pHead->m_iData;
        pHead=pHead->m_pNextNode;
    }

    return iSum;
}

int Rsum(Node_t* pNode){
    if(pNode==NULL){
        return 0;
    }

    else{
        return Rsum(pNode->m_pNextNode) + pNode->m_iData;
    }
}

int Rmax(Node_t *pNode){
    int imax = 0;
    if (pNode==NULL){
        return INTMAX_MIN;
    }
    imax = Rmax(pNode->m_pNextNode);
    return  ((imax>pNode->m_iData) ? imax : pNode->m_iData);
}