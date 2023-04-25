#ifndef PROJEKTALPHA_LISTNODE_HPP
#define PROJEKTALPHA_LISTNODE_HPP

#include <memory>

template<class T>

class ListNode {

public:
    ListNode(T data);

    // Getter
    std::shared_ptr<ListNode<T>> get_next();
    T get_data();

    // Setter
    void set_next(std::shared_ptr<ListNode<T>> nextNode);
    void set_data(T newData);

private:
    T data;
    std::shared_ptr<ListNode<T>> next;
};

#endif //PROJEKTALPHA_LISTNODE_HPP