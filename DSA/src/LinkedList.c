#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "LinkedList/LinkedList.h"
void CreateLinkedList(LinkedList_t* pList){
    pList->m_pHeadNode = NULL;
}

void InsertAtEnd(LinkedList_t *pList, int iData){
    // Improve inserting at end by keeping track of last Node
    static Node_t* pLastNode = NULL;
    if(pList->m_pHeadNode==NULL){
        pList->m_pHeadNode = (Node_t*)malloc(sizeof(Node_t));
        pList->m_pHeadNode->m_iData = iData;
        pList->m_pHeadNode->m_pNextNode = NULL;
        pLastNode = pList->m_pHeadNode;
    }

    else{
        if(pLastNode==NULL){
            pLastNode = pList->m_pHeadNode;
            while(pLastNode->m_pNextNode!=NULL){
                pLastNode = pLastNode->m_pNextNode;
            }

        }
        Node_t* pTempNode = (Node_t* )malloc(sizeof(Node_t));
        pTempNode->m_iData = iData;
        pTempNode->m_pNextNode= NULL;
        pLastNode->m_pNextNode = pTempNode;
        pLastNode = pLastNode->m_pNextNode;
    }

}

void Display(LinkedList_t *pList){
    Node_t* pCurrNode = pList->m_pHeadNode;

    while (pCurrNode!=NULL)
    {
        printf("%d ",pCurrNode->m_iData);
        pCurrNode = pCurrNode->m_pNextNode;
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
     Node_t* pCurrNode = pList->m_pHeadNode;
     size_t uiLen = 0;
     while (pCurrNode!=NULL)
     {
        uiLen++;
        pCurrNode=pCurrNode->m_pNextNode;
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
    Node_t *pCurrNode = pList->m_pHeadNode;
    int iSum = 0l;

    while(pCurrNode!=NULL){
        iSum+=pCurrNode->m_iData;
        pCurrNode=pCurrNode->m_pNextNode;
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
    int iMax = 0;
    if (pNode==NULL){
        return INT32_MIN;
    }
    iMax = Rmax(pNode->m_pNextNode);
    return  ((iMax>pNode->m_iData) ? iMax : pNode->m_iData);
}

int max(LinkedList_t *pList){
    Node_t *pCurrNode = pList->m_pHeadNode;

    int iMax = INT32_MIN;

    while(pCurrNode!=NULL){
        if (pCurrNode->m_iData > iMax){
            iMax = pCurrNode->m_iData;
        }
        pCurrNode = pCurrNode->m_pNextNode;
    }

    return iMax;
}

int min(LinkedList_t *pList){
    Node_t *pCurrNode = pList->m_pHeadNode;

    int iMin = INT32_MAX;

    while(pCurrNode!=NULL){
        if (pCurrNode->m_iData < iMin){
            iMin = pCurrNode->m_iData;
        }
        pCurrNode = pCurrNode->m_pNextNode;
    }

    return iMin;
}

int Rmin(Node_t *pNode){
    int iMin = 0;
    if (pNode==NULL){
        return INT32_MAX;
    }
    iMin = Rmin(pNode->m_pNextNode);
    return  ((iMin<pNode->m_iData) ? iMin: pNode->m_iData);
}

Node_t* search(LinkedList_t *pList, int target){
       Node_t *pCurrNode = pList->m_pHeadNode;
       Node_t *pPrevNode = NULL;

       while(pCurrNode!=NULL){
            if(target==pCurrNode->m_iData){
                if (pPrevNode!=NULL){
                    pPrevNode->m_pNextNode = pCurrNode->m_pNextNode;
                    pCurrNode->m_pNextNode = pList->m_pHeadNode;
                    pList->m_pHeadNode = pCurrNode;

                }

                return pCurrNode;
            }
            pPrevNode = pCurrNode;
            pCurrNode = pCurrNode->m_pNextNode;
       }
       return NULL;
}

Node_t* Rsearch(Node_t *pNode, int target){
    if (pNode==NULL){
        return NULL;
    }

    if (target==pNode->m_iData){
        return pNode;
    }

    return Rsearch(pNode->m_pNextNode,target);
}

void freeNode(Node_t* pNode){
    if(pNode!=NULL){
        free(pNode);
    }

}

void FreeList(LinkedList_t *pList){
    Node_t* pCurrNode = pList->m_pHeadNode;
    Node_t* pNextNode = NULL;

    while(pCurrNode!=NULL){
        pNextNode= pCurrNode->m_pNextNode;
        freeNode(pCurrNode);
        

        pCurrNode = pNextNode;
    }
    pList->m_pHeadNode= NULL;
}

void Insert(LinkedList_t *pList, int iIndex, int iData){
    if (iIndex < 0 || iIndex > (int)size(pList)){
        // Invalid index
        printf("Error: Index out of bound\n");
        return;

    }
    Node_t* pTempNode = (Node_t *)malloc(sizeof(Node_t));
    pTempNode->m_iData = iData;

    if (iIndex==0){
        // Insert before head node
        pTempNode->m_pNextNode = pList->m_pHeadNode;
        pList->m_pHeadNode = pTempNode;
    }
    else{
        // Insert at any position
        Node_t* pCurrNode = pList->m_pHeadNode;
        for (int i=0; (i<(iIndex-1));i++){
            pCurrNode=pCurrNode->m_pNextNode;
        }
        pTempNode->m_pNextNode = pCurrNode->m_pNextNode;
        pCurrNode->m_pNextNode = pTempNode;

    }

    
}

void SortedInsert(LinkedList_t* pList, int iData){
     Node_t* pCurrNode = pList->m_pHeadNode;
     Node_t* pPrevNode = NULL;
     Node_t* pTempNode = (Node_t*)malloc(sizeof(Node_t));
     pTempNode->m_iData = iData;
     pTempNode->m_pNextNode = NULL;

     if(pCurrNode==NULL){
        pList->m_pHeadNode = pTempNode;
     }
     else{
        while(pCurrNode!=NULL && pCurrNode->m_iData<iData){

            pPrevNode = pCurrNode;
            pCurrNode = pCurrNode->m_pNextNode;
        }

        if(pCurrNode==pList->m_pHeadNode){
            // Insert before head Node
            pTempNode->m_pNextNode = pList->m_pHeadNode;
            pList->m_pHeadNode = pTempNode;
        }
        else{
            // Insert at any position
            pTempNode->m_pNextNode = pPrevNode->m_pNextNode;
            pPrevNode->m_pNextNode = pTempNode;
        }
     }

}

int Delete(LinkedList_t* pList, int iIndex){
    Node_t* pCurrNode = pList->m_pHeadNode;
    int iValue = INT32_MIN;

    if(iIndex<0 || iIndex> ((int)size(pList) - 1)){
        return iValue;
    }

    else{
        if(iIndex==0){
            iValue = pList->m_pHeadNode->m_iData;
            pList->m_pHeadNode = pList->m_pHeadNode->m_pNextNode;
            freeNode(pCurrNode);
            return iValue;

        }
        else{
             Node_t* pPrevNode = NULL;

             for (int i=0; i<iIndex; i++){
                pPrevNode=pCurrNode;
                pCurrNode=pCurrNode->m_pNextNode;
             }
             pPrevNode->m_pNextNode = pCurrNode->m_pNextNode;
             iValue = pCurrNode->m_iData;
             freeNode(pCurrNode);
             return iValue;

        }

    }
}

int IsSorted(LinkedList_t* pList){
    int iNum = INT32_MIN;
    Node_t* pCurrNode = pList->m_pHeadNode;

    while(pCurrNode!=NULL){
        if (pCurrNode->m_iData < iNum){
            return 0;
        }

        else{
            iNum = pCurrNode->m_iData;
            pCurrNode= pCurrNode->m_pNextNode;
        }
    }
    return 1;
}

void RemoveDuplicates(LinkedList_t* pList){
    Node_t* pCurrNode = pList->m_pHeadNode->m_pNextNode;
    Node_t *pPrevNode  = pList->m_pHeadNode;

    while(pCurrNode!=NULL){
        if(pPrevNode->m_iData != pCurrNode->m_iData){
            pPrevNode = pCurrNode;
            pCurrNode = pCurrNode->m_pNextNode;
        }
        else{
            pPrevNode->m_pNextNode = pCurrNode->m_pNextNode;
            freeNode(pCurrNode);
            pCurrNode = pPrevNode->m_pNextNode;
        }
    }
}

void Reverse(LinkedList_t* pList){
    Node_t* pNextNode  = pList->m_pHeadNode;
    Node_t* pPrevNode  = NULL;
    Node_t* pCurrNode  = NULL;

    while(pNextNode!=NULL){
        pPrevNode = pCurrNode;
        pCurrNode = pNextNode;

        pNextNode = pNextNode->m_pNextNode;

        // Update Link
        pCurrNode->m_pNextNode = pPrevNode;

    }
    pList->m_pHeadNode = pCurrNode;

}
void RReverse(LinkedList_t* pList,Node_t* pCurrNode, Node_t* pPrevNode){
    if (pCurrNode!=NULL){
        RReverse(pList,pCurrNode->m_pNextNode,pCurrNode);
        pCurrNode->m_pNextNode=pPrevNode;
    }

    else{
        pList->m_pHeadNode= pPrevNode;
    }
}