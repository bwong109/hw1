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
  if (tail_ == NULL || tail_->last == ARRSIZE){

    // Create new item to add
    Item* newItem = new Item();
    newItem -> prev = tail_;
    newItem -> next = NULL;

    // Add new node if no existing nodes
    if (head_ == NULL){
      head_ = newItem;
    }
    else{
      tail_ -> next = newItem;
    }
    
    // Set tail to the new item
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
  
void ULListStr::push_front(const std::string& val){

  // If there is no head, or first node is at very beginning
  if (head_ == NULL || head_->first == 0){

    // Create new item to add
    Item* newItem = new Item();
    newItem->next = head_;
    newItem->prev = NULL;

    // Add new node if no existing nodes
    if (tail_ == NULL){
      tail_ = newItem;
    }
    else{
      head_->prev = newItem;
    }

    // Set head to the new item
    head_ = newItem;
  }

  // Decrement first and add value (will be -1 when first = 0 to last index)
  head_->first--;
  head_->val[head_->first] = val;
  size_++;
}

void ULListStr::pop_front(){

  // Check if the list is empty
  if (empty()){
    return;
  }

  // Increment first and decrement size as long as it is in the scope of the array
  if (head_->first < ARRSIZE - 1) {
    head_->first++;
    size_--;

    // Remove first node if it is empty and is not the only node
    if (head_->first == ARRSIZE - 1 && head_->next != NULL) {
      Item* temp = head_;
      head_ = head_->next;
      head_->prev = NULL;
      delete temp;
    }
  }
}

  
std::string const & ULListStr::back() const{
  
  // Error if empty
  if (empty()){
    throw std::out_of_range("Empty list");
  }

  // Last is index one after final value
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const{
  // Error if empty
  if (empty()){
    throw std::out_of_range("Empty list");
  }

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

/** 
* Returns a pointer to the item at index, loc,
*  if loc is valid and NULL otherwise
*   - MUST RUN in O(n) 
*/
std::string* ULListStr::getValAtLoc(size_t loc) const{
  if (loc >= size_) {
    return NULL;
  }

  Item* curr = head_;
  size_t remaining = loc;

  while (remaining >= ARRSIZE || curr == NULL) {
    remaining -= curr->last - curr->first;
    curr = curr->next;
  }

  return &(curr->val[curr->first + remaining]);

}