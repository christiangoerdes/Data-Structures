#pragma once

/**
 * @brief A class representing the abstract base class sequence container
 *
 * This class defines the interface that must be implemented by any derived sequence container
 */

class SequenceContainer {

public:
    /**
     * @brief Returns the size of the container
     * @return the size of the container.
     */
    virtual size_t get_size() const = 0;

};