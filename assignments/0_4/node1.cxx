// FILE: node1.cxx
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field, and the link in link_field.

#include "node1.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
using namespace std;

namespace main_savitch_5
{
    size_t list_length(const node* head_ptr)
    // Library facilities used: cstdlib
    {
	const node *currentItem_ptr;
	size_t answer;

	answer = 0;
	for (currentItem_ptr = head_ptr; currentItem_ptr != NULL; currentItem_ptr = currentItem_ptr->link( ))
	    ++answer;

	return answer;
    }

    void list_head_insert(node*& head_ptr, const node::value_type& entry)
    {
	head_ptr = new node(entry, head_ptr);
    }

    void list_insert(node* previous_ptr, const node::value_type& entry)
    {
	node *insert_ptr;

	insert_ptr = new node(entry, previous_ptr->link( ));
	previous_ptr->set_link(insert_ptr);
    }

    node* list_search(node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
	node *currentItem_ptr;

	for (currentItem_ptr = head_ptr; currentItem_ptr != NULL; currentItem_ptr = currentItem_ptr->link( ))
	    if (target == currentItem_ptr->data( ))
		return currentItem_ptr;
	return NULL;
    }

    const node* list_search(const node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
	const node *currentItem_ptr;

	for (currentItem_ptr = head_ptr; currentItem_ptr != NULL; currentItem_ptr = currentItem_ptr->link( ))
	    if (target == currentItem_ptr->data( ))
		return currentItem_ptr;
	return NULL;
    }

    node* list_locate(node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
	node *currentItem_ptr;
	size_t i;

	assert (0 < position);
	currentItem_ptr = head_ptr;
	for (i = 1; (i < position) && (currentItem_ptr != NULL); i++)
	    currentItem_ptr = currentItem_ptr->link( );
	return currentItem_ptr;
    }

    const node* list_locate(const node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
	const node *currentItem_ptr;
	size_t i;

	assert (0 < position);
	currentItem_ptr = head_ptr;
	for (i = 1; (i < position) && (currentItem_ptr != NULL); i++)
	    currentItem_ptr = currentItem_ptr->link( );
	return currentItem_ptr;
    }

    void list_head_remove(node*& head_ptr)
    {
	node *remove_ptr;

	remove_ptr = head_ptr;
	head_ptr = head_ptr->link( );
	delete remove_ptr;
    }

    void list_remove(node* previous_ptr)
    {
	node *remove_ptr;

	remove_ptr = previous_ptr->link( );
	previous_ptr->set_link( remove_ptr->link( ) );
	delete remove_ptr;
    }

    void list_clear(node*& head_ptr)
    // Library facilities used: cstdlib
    {
	while (head_ptr != NULL)
	    list_head_remove(head_ptr);
    }

    void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
    // Library facilities used: cstdlib
    {
	head_ptr = NULL;
	tail_ptr = NULL;

	// Handle the case of the empty list.
	if (source_ptr == NULL)
	    return;

	// Make the head node for the newly created list, and put data in it.
	list_head_insert(head_ptr, source_ptr->data( ));
	tail_ptr = head_ptr;

	// Copy the rest of the nodes one at a time, adding at the tail of new list.
	source_ptr = source_ptr->link( );
	while (source_ptr != NULL)
	{
	    list_insert(tail_ptr, source_ptr->data( ));
	    tail_ptr = tail_ptr->link( );
	    source_ptr = source_ptr->link( );
	}
    }

}
