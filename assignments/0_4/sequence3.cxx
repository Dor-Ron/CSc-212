#include <assert.h>
#include "node1.h"
#include "sequence3.h"

namespace main_savitch_5 {
    /* CLASS INVARIANT
        1. The items in the bag are stored in a linked list
        2. The head pointer of the list is stored in the member variable head_ptr
        3. The total number of items in the list is stored in the member variable m_nodeCount */

    sequence::sequence( ) {
      // O(1) - constant time
        head_ptr = NULL;
        tail_ptr = NULL;
        currentItem_ptr = NULL;
        prevItem_ptr = NULL;
        m_nodeCount = 0;
    }

    sequence::sequence(const sequence& source) {
      // O(N) - linear time, copies nodes one at a time
        list_copy(source.getHead(), head_ptr, tail_ptr);
        list_copy(source.getCur(), currentItem_ptr, prevItem_ptr);
        m_nodeCount = source.size();
	  }

    sequence::~sequence( ) {
      // O(1) - constant time
        list_clear(head_ptr);
    }

    void sequence::start( ) {
      // O(1) - constant time
        currentItem_ptr = getHead();
        prevItem_ptr = NULL;
    }

    void sequence::advance( ) {
      // O(1) - constant time
        assert(is_item());
        prevItem_ptr = getCur();
        currentItem_ptr = currentItem_ptr->link();
    }

    void sequence::insert(const value_type& entry) {
      // O(1) - constant time
        if(is_item()) {
            if((prevItem_ptr == NULL)) {
                list_head_insert(head_ptr, entry);
                currentItem_ptr = getHead();
                prevItem_ptr = NULL;
            } else {
                list_insert(prevItem_ptr, entry);
                currentItem_ptr = prevItem_ptr->link();
            }
        } if(!is_item()) {
            list_head_insert(head_ptr, entry);
            currentItem_ptr = getHead();
            prevItem_ptr = NULL;
        } m_nodeCount++;
    }

    void sequence::attach(const value_type& entry) {
      // O(1) -  constant time
        if(is_item()) {
            prevItem_ptr = getCur();
            list_insert(currentItem_ptr, entry);
            currentItem_ptr = currentItem_ptr->link();
        } if(!is_item()) {
            if((prevItem_ptr == NULL)) {
                list_head_insert(head_ptr, entry);
                currentItem_ptr = getHead();
                prevItem_ptr = NULL;
            } else {
                currentItem_ptr = list_locate(head_ptr, list_length(head_ptr));
                list_insert(currentItem_ptr, entry);
                currentItem_ptr = prevItem_ptr->link();
            }
        } m_nodeCount++;
    }

    void sequence::remove_current( ) {
      // O(1) - constant time
        assert(is_item());
        if(currentItem_ptr == getHead()) {
            list_head_remove(head_ptr);
            currentItem_ptr = getHead();
            prevItem_ptr = NULL;
        } else {
            currentItem_ptr = currentItem_ptr->link();
            list_remove(getPrev());
        } m_nodeCount--;
    }

    void sequence::operator =(const sequence& source) {
      // O(N) - linear time
        if(this == &source) return;
        else {
            list_clear(head_ptr);
            list_copy(source.getHead(), head_ptr, tail_ptr);
            if(source.getPrev() == NULL) {
                if(source.getCur() == NULL) {
                    currentItem_ptr = NULL;
                    prevItem_ptr = NULL;
                } else {
                    currentItem_ptr = getHead();
                    prevItem_ptr = NULL;
                }
            } else {
                node *tmp_ptr = getHead();
                node *source_ptr = source.getHead();
                while(source_ptr != source.getPrev()) {
                    source_ptr = source_ptr->link();
                    tmp_ptr = tmp_ptr->link();
                }
                currentItem_ptr = tmp_ptr->link();
                prevItem_ptr = tmp_ptr;
            } m_nodeCount = source.size();
        }
    }

    sequence::size_type sequence::size( ) const {
      // O(1) - constant time
        return m_nodeCount;
    }

    bool sequence::is_item( ) const {
      // O(1)  - constant time
        return ((getCur() != NULL) && (size() > 0));
    }

    sequence::value_type sequence::current( ) const {
      // O(1)  - constant time
        assert(is_item());
        return currentItem_ptr->data();
    }

    node* sequence::getHead( ) const {
      // O(1)  - constant time
      return head_ptr;
    }

    node* sequence::getTail( ) const {
      // O(1)  - constant time
      return tail_ptr;
    }

    node* sequence::getCur( ) const {
      // O(1)  - constant time
      return currentItem_ptr;
    }

    node* sequence::getPrev( ) const {
      // O(1)  - constant time
      return prevItem_ptr;
    }
}
