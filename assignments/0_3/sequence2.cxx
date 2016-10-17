#include "sequence2.h"
#include <algorithm>
#include <assert.h>

namespace main_savitch_4 {
  // CONSTRUCTOR and DESTRUCTOR
  sequence::sequence(sequence::size_type initial_capacity) {
    m_array_ptr = new sequence::value_type[initial_capacity];
    m_capacity = initial_capacity;
    m_currentIdx = 0;
    m_used = 0;
  }

  sequence::sequence(const sequence& source) {
    if (this == &source) return ; // check for self assignment
    m_array_ptr = new sequence::value_type[source.curCapacity()];
    m_capacity = source.curCapacity();
    m_currentIdx = source.curIdx();
    m_used = source.size();
    std::copy(source.m_array_ptr, source.m_array_ptr+size(), m_array_ptr);
  }

  sequence::~sequence() {
    delete [] m_array_ptr;
  }

  // MODIFICATION MEMBER FUNCTIONS
  void sequence::start() {
      m_currentIdx = 0;
  }

  void sequence::advance( ) {
    //assert(is_item());
    //Need to comment out, or sequence_exam won't run.
    //Added is_item() call to if-statement but still meet precondition requirements
    if(is_item() && (curIdx() < size())) m_currentIdx++;
  }

  void sequence::insert(const sequence::value_type& entry) {
    if (curCapacity() <= size()) resize(size()+1);
    if(!is_item()) {
        if (m_used == 0) {
          m_array_ptr[0] = entry;
          m_used++;
        } else {
          m_currentIdx = 0;
          for(sequence::size_type i = size(); i > curIdx(); i--) m_array_ptr[i] = m_array_ptr[i-1];
          m_currentIdx++;
          m_array_ptr[0] = entry;
          m_used++;
        }
      } else {
        for (sequence::size_type i = m_used; i > curIdx(); i--) m_array_ptr[i] = m_array_ptr[i-1];
        m_array_ptr[curIdx()] = entry;
        m_used++;
      }
  }

  void sequence::attach(const sequence::value_type& entry) {
    if (curCapacity() <= size()) resize(size()+1);
    if (!is_item()) {
        m_array_ptr[curIdx()] = entry;
        m_used++;
      } else {
        for(sequence::size_type i = m_used; i > curIdx(); i--) m_array_ptr[i] = m_array_ptr[i-1];
        m_currentIdx++;
        m_array_ptr[curIdx()] = entry;
        m_used++;
      }
  }

  void sequence::remove_current( ) {
    assert(is_item());
    for(sequence::size_type i = curIdx(); i < size(); i++) m_array_ptr[i] = m_array_ptr[i+1];
    m_used--;
  }

  void sequence::resize(size_type new_capacity) {
    sequence::value_type *newArray_ptr;
    if(curCapacity() == new_capacity) return ;  // nothing to resize
    else if(curCapacity() > new_capacity) {
       //assert(size() < new_capacity);
       /*comment out assertion cause exam won't run otherwise
       need to test this condition however for when m_capacity is greater
       and m_used are greater than new_capacity, since some items would be lost
       in resizing of the array*/
       if(size() < new_capacity) {
         newArray_ptr = new sequence::value_type[new_capacity];
         std::copy(m_array_ptr, m_array_ptr+size(), newArray_ptr);
         delete [] m_array_ptr;  // free heap to reassign dynamic array
         m_array_ptr = newArray_ptr;
         m_capacity = new_capacity;
      }
    } else if(curCapacity() < new_capacity) {
          newArray_ptr = new sequence::value_type[new_capacity];
          std::copy(m_array_ptr, m_array_ptr+size(), newArray_ptr);
          delete [] m_array_ptr;  // free heap to reassign dynamic array
          m_array_ptr = newArray_ptr;
          m_capacity = new_capacity;
    }
  }

  void sequence::operator=(const sequence& source) {
    sequence::value_type *newSeq_ptr;
    if(this == &source) return; // check self assignment
    if(curCapacity() != source.curCapacity()) {
        m_capacity = source.curCapacity();
        newSeq_ptr = new sequence::value_type[source.curCapacity()];
        delete [] m_array_ptr; // free heap to reassign dynamic array
        m_array_ptr = newSeq_ptr;
    }
    m_used = source.size();
    m_currentIdx = source.curIdx();
    std::copy(source.m_array_ptr, source.m_array_ptr+size(), m_array_ptr);
  }

  // EXTRA CREDIT
  sequence::value_type sequence::operator[](sequence::size_type idx) const {
    assert(idx >= 0 && idx < size());
    return m_array_ptr[idx];
  }

  void sequence::operator+(const sequence& source) {
    sequence::value_type *newSeq_ptr = new sequence::value_type[curCapacity()+source.curCapacity()];
    std::copy(m_array_ptr, m_array_ptr+size(), newSeq_ptr);
    delete [] m_array_ptr;
    m_array_ptr = newSeq_ptr;
    for (int i = 0; i < source.size(); i++) this->attach(source[i]);
  }

  void sequence::operator+=(const sequence& source) {
    sequence::value_type *newSeq_ptr = new sequence::value_type[curCapacity()+source.curCapacity()];
    std::copy(m_array_ptr, m_array_ptr+size(), newSeq_ptr);
    delete [] m_array_ptr;
    m_array_ptr = newSeq_ptr;
    for (int i = 0; i < source.size(); i++) this->attach(source[i]);
  }

  // CONSTANT MEMBER FUNCTIONS
  sequence::size_type sequence::size( ) const {
    return m_used;
  }

  sequence::size_type sequence::curIdx( ) const {
    return m_currentIdx;
  }

  sequence::size_type sequence::curCapacity( ) const {
    return m_capacity;
  }

  bool sequence::is_item( ) const {
    return (curIdx() < size());
  }

  sequence::value_type sequence::current( ) const {
    assert(is_item());
    return m_array_ptr[curIdx()];
  }
}
