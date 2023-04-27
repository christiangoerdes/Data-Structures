#pragma once // Header guard to avoid multiple inclusion

#include "singlyLinkedListNode.hpp" // Include the SinglyLinkedListNode header file
#include "../listIterator.hpp"

template <typename T> // Template declaration for a generic type T
class SinglyLinkedListIterator : public ListIterator<T>{

};