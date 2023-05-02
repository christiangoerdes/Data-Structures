#pragma once

/**
 * @brief A class representing the abstract base class for linked list data structures
 *
 * This class defines the interface that must be implemented by any derived linked list classes.
 *
 * @tparam T The type of the elements stored in the linked list
 */

class SequenceContainer {

public:

    virtual size_t get_size() const = 0;

};