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
/// @retval None
/// @note pList should be a pointer to dynamic memory, this function must be called before a call to any other function
void CreateLinkedList(LinkedList_t* pList);

/// @brief Add a Node to the LinkedList
/// @param pList Pointer to the LinkeList to add a node to
/// @param iData A data for the Node
/// @retval None
void AddNode(LinkedList_t *pList, int iData);

/// @brief displays a LinkedList in forward way
/// @param pList Pointer to the LinkeList to display
/// @retval None
void Display(LinkedList_t *pList);

/// @brief displays a LinkeList in a reverse order
/// @param pNode pointer to the head Node of LinkedList
/// @retval None
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
int max(LinkedList_t pList);

/// @brief find the maximum element in a LinkedList using Recursion
/// @param pNode Pointer to the head node
/// @return maximum element
int Rmax(Node_t *pNode);



#endif
