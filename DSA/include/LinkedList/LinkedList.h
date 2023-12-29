#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdio.h>
struct Node
{
    int m_iData;     // Data of the Node
    struct Node* m_pNextNode; // Next Node
};
typedef struct Node Node_t;

struct LinkedList
{
    Node_t* m_pHeadNode; // Pointer to the head Node of the LinkedList
    
};
typedef struct LinkedList LinkedList_t;

/********************************************************************
 * LinkedList APIs, Please see src/LinkedList.c for full definitions
 *********************************************************************/

/// @brief sets the head Node of the LinkedList to NULL
/// @param pList Pointer to the LinkedList
/// @return None
/// @note pList should be a pointer to dynamic memory, this function must be called before a call to any other function
void CreateLinkedList(LinkedList_t* pList);

/// @brief Add a Node to the end of LinkedList 
/// @param pList Pointer to the LinkeList to add a node to
/// @param iData A data for the Node
/// @return None
void InsertAtEnd(LinkedList_t *pList, int iData);

/// @brief displays a LinkedList in forward way
/// @param pList Pointer to the LinkeList to display
/// @return None
void Display(LinkedList_t *pList);

/// @brief displays a LinkeList in a reverse order
/// @param pNode pointer to the head Node of LinkedList
/// @return None
void RDisplay(Node_t* pNode);

/// @brief count number of nodes in a LinkedList iteratively
/// @param pList Pointer to the LinkedList to count nodes
/// @return number of elements in a LinkedList
size_t size(LinkedList_t* pList);

/// @brief count number of nodes in a LinkedList recursively
/// @param pNode pointer to the head Node of LinkedList
/// @return  number of elements in a LinkedList
size_t Rsize(Node_t *pNode);

/// @brief finds the sum of all elements in a LinkedList iteratively
/// @param pList Pointer to LinkedList to find sum of its elements
/// @return sum of all elements in a LinkedList
int sum(LinkedList_t* pList);

/// @brief finds the sum of all elements in a LinkedList recursively
/// @param pNode Pointer to  head Node of LinkedList to find sum of its elements
/// @return sum of all elements in a LinkedList
int Rsum(Node_t* pNode);

/// @brief find the maximum element in a LinkedList iteratively
/// @param pList LinkedList Pointer
/// @return maximum element
int max(LinkedList_t *pList);

/// @brief find the maximum element in a LinkedList using Recursion
/// @param pNode Pointer to the head node
/// @return maximum element
int Rmax(Node_t *pNode);

/// @brief find the minimum element in a LinkedList iteratively
/// @param pList LinkedList Pointer
/// @return minimum element
int min(LinkedList_t *pList);

/// @brief find the minimum element in a LinkedList using Recursion
/// @param pNode Pointer to the head node
/// @return minimum element
int Rmin(Node_t *pNode);

/// @brief searches for a given target in  a LinkedList iteratively
/// @param pList Pointer to the LinkedList
/// @param target  what we are searching for in a LinkedList
/// @return Node that has target as data member, NULL if not found
/// @note For effectiveness, Node containing target element is moved to head
Node_t* search(LinkedList_t *pList, int target);

/// @brief searches for a given target in  a LinkedList recursively
/// @param pNode pointer to the head node
/// @param target  what we are searching for in a LinkedList
/// @return Node that has target as data member, NULL if not found
Node_t* Rsearch(Node_t *pNode, int target);

/// @brief release dynamically allocated node
/// @param pNode node to free
/// @return None
void freeNode(Node_t* pNode);

/// @brief releases dynamically allocated LinkedList
/// @param pList Pointer to LinkedList to delete
/// @return None
/// @note Call this before exiting the scope of LinkedList pointer
void FreeList(LinkedList_t *pList);

/// @brief Inserts a Node at a given index
/// @param pList Pointer to the LinkedList
/// @param iIndex Index to insert at
/// @param iData  Data to insert 
/// @return None
/// @note Make sure call to CreateLnkedList has been made
void Insert(LinkedList_t *pList, int iIndex, int iData);

/// @brief Inserts a value in a sorted LinkedList
/// @param pList  Pointer to the LinkedList
/// @param iData  Value to insert
/// @return None
void SortedInsert(LinkedList_t* pList, int iData);

/// @brief Deletes a Node at a given index
/// @param pList  Pointer to the LinkedList
/// @param iIndex  Index to delete the Node at
/// @return Data for deleted Node
int Delete(LinkedList_t* pList, int iIndex);

/// @brief checks if LinkedList is sorted
/// @param pList Pointer to the LinkedList
/// @return 1 if sorted or 0 if not sorted
int IsSorted(LinkedList_t* pList);

/// @brief Removes duplicates from sorted LinkedList
/// @param pList Pointer to the LinkedList
/// @return None
void RemoveDuplicates(LinkedList_t* pList);

/// @brief Reverses a LinkedList iteratively
/// @param pList Pointer to the LinkedList
/// @return None
void Reverse(LinkedList_t* pList);

/// @brief Recursively reverses a LinkedList
/// @param pList Pointer to the LinkedLisr
/// @param pCurrNode Pointer to head Node of pList
/// @param pPrevNode NULL
/// @return None
/// @note Call to RReverse should be like RReverse(pList,pList->m_pHeadNode,NULL)
void RReverse(LinkedList_t* pList,Node_t* pCurrNode, Node_t* pPrevNode);

/// @brief Merges two sorted LinkedList
/// @param pList1 Pointer to first odered linkedlist
/// @param pList2 Pointer to second sorted LinkedList
/// @return Pointer to merged LinkedList
LinkedList_t* Merge(LinkedList_t* pList1, LinkedList_t* pList2);

/// @brief Concatenate two lunkedlists 
/// @param pList1 Pointer to first LinkedList
/// @param pList2  Pointer to second LinkedList
/// @return  Pointer to concatenated LinkedList
LinkedList_t* Concatenate(LinkedList_t* pList1, LinkedList_t* pList2);

/// @brief Copy the contents of one LinkedList to another
/// @param pSrcList pointer to source linkedlist
/// @param pDstList pointer to destination linkedlist
/// @return None
/// @note if pDstList is not empty, it is cleared first
void Copy(LinkedList_t* pSrcList, LinkedList_t* pDstList);

/// @brief Append one LinkedList to another
/// @param pToList  Pointer  to LinkedList to append to
/// @param pThisList Pointer to LinkedList to be appended to pToList
/// @return None
void AppendList(LinkedList_t *pToList, LinkedList_t* pThisList);
/// @brief Checks if LinkedList is a loop or Linear
/// @param pList Pointer to a LinkedList
/// @return 1 if it is a loop 0 if linear
int IsLoop(LinkedList_t* pList);



#endif
