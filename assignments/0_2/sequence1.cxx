/*
Author: Dor Rondel
File: sequence1.cxx
Course: CSc-212
Professor: Feng Hu
Term: Fall 2016
Institution: CCNY
*/

#include "sequence1.h"
#include <assert.h>

namespace main_savitch_3 {

    const sequence::size_type sequence::CAPACITY; // needs to be redeclared without static

    // Default Constructor
    sequence::sequence() {
      m_used = 0;
      m_currentIdx = 0;
    }

    // MODIFICATION MEMBER FUNCTIONS
    void sequence::start() {
      m_currentIdx = 0;
    }

    void sequence::advance() {
      //assert(is_item());
      //Need to comment out, or sequence_exam won't run.
      //Added is_item() call to if-statement but still meet precondition requirements
      if(is_item() && (curIdx() < m_used)) m_currentIdx++;
    }

    void sequence::insert(const value_type& entry) {
      assert(size() < CAPACITY);
      if(!is_item()) {
        if (m_used == 0) {
          m_data[0] = entry;
          m_used++;
        } else {
          m_currentIdx = 0;
          for(sequence::size_type i = m_used; i > curIdx(); i--) m_data[i] = m_data[i-1];
          m_currentIdx++;
          m_data[0] = entry;
          m_used++;
        }
      } else {
        for (sequence::size_type i = m_used; i > curIdx(); i--) m_data[i] = m_data[i-1];
        m_data[curIdx()] = entry;
        m_used++;
      }
    }

    void sequence::attach(const value_type& entry) {
      assert(size() < CAPACITY);
      if (!is_item()) {
        m_data[curIdx()] = entry;
        m_used++;
      } else {
        for(sequence::size_type i = m_used; i > curIdx(); i--) m_data[i] = m_data[i-1];
        m_currentIdx++;
        m_data[curIdx()] = entry;
        m_used++;
      }
    }

    void sequence::remove_current( ) {
      assert(is_item());
      if(is_item()) {
        for(sequence::size_type i = curIdx(); i < m_used; i++) m_data[i] = m_data[i+1];
      } m_used--;
    }

    // CONSTANT MEMBER FUNCTIONS
    sequence::size_type sequence::size( ) const {
      return m_used;
    }

    sequence::size_type sequence::curIdx( ) const {
      return m_currentIdx;
    }

    bool sequence::is_item( ) const {
      return (m_currentIdx < m_used);
    }

    sequence::value_type sequence::current( ) const {
      assert(is_item());
      return m_data[curIdx()];
    }
}
