#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

void ULListStr::push_back(const std::string& val){

  // If there is no tail, or end of array is reached
  if (!tail_ || tail_->last == ARRSIZE){

    // Create new item to add
    Item* newItem = new Item();
    newItem -> prev = tail_;
    newItem -> next = NULL;

    // Add new node if no existing nodes
    if (!head_){
      head_ = newItem;
    } 
    else{
      tail_ -> next = newItem;
    }
    
    // Set value to first in new item
    tail_ = newItem;
  }
  
  // Set new value to last index and increment size and last
  tail_->val[tail_->last] = val;
  tail_->last++;
  size_++;

}

void ULListStr::pop_back(){

  // Check if the list is empty
  if (empty()){
    return;
  }

  // Decrement last and size as long as the last node has elements
  if (tail_->last > 0){
    tail_->last--;
    size_--;

    // Remove last node if it is empty and is not the only node
    if (tail_->prev != NULL && tail_->last == 0){
      Item* temp = tail_;
      tail_ = tail_->prev;
      tail_->next = NULL;
      delete temp;
    }
  }

}
  
void ULListStr::push_front(const std::string& val) {

  // If there are no nodes or no space at the beginning
  if (!head_ || head_->first == 0) {
    
    // Create new item to add
    Item* newItem = new Item();
    newItem->next = head_;
    newItem->prev = NULL;

    // Update the previous pointer of the existing head
    if (head_) {
      head_->prev = newItem;
    // If there are no nodes, set the tail to the new item
    } else {
      tail_ = newItem;
    }

    // Initialize members to the end of array and add it
    newItem->first = ARRSIZE-1;
    newItem->last = ARRSIZE;
    newItem->val[newItem->first] = val;
    head_ = newItem;
    size_++;
  
  }
  // Otherwise, decrement first and add value
  else {
    head_->first--;
    head_->val[head_->first] = val;
    size_++;
  }
}


void ULListStr::pop_front(){

  // Check if the list is empty
  if (empty()){
    return;
  }

  // Increment first and decrement size as long as it is in the scope of the array
  if (head_->first < ARRSIZE) {
    size_--;
    head_->first++;

    // Remove first node if it is empty and is not the only node
    if (head_->first == ARRSIZE && head_->next != NULL) {
      Item* temp = head_;
      head_ = head_->next;
      head_->prev = NULL;
      delete temp;
    }
  }
}

  
std::string const & ULListStr::back() const{

  // Last is index one after final value
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const{

  return head_->val[head_->first];
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

std::string* ULListStr::getValAtLoc(size_t loc) const {

  // Check if location valid
  if (loc >= size_) {
      return NULL;
  }

  // Find node containing the desired location
  Item* curr = head_;
  size_t index = 0;

  // Look through list nodes
  while (curr != NULL) {

      // Calculate the size of current node
      size_t nodeSize = curr->last - curr->first;

      // Check if location is within the current node
      if (index + nodeSize > loc) {

          // Calculate the local index within the node
          size_t localIndex = loc - index;

          // Return the pointer to the value of calculated local index
          return &(curr-> val[curr->first + localIndex]);
        
      // Adjust index to reflect the position in the next node
      } else {
          index += nodeSize;
          curr = curr->next;
      }
  }
  return NULL;
}
