#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "ulliststr.h"
using namespace std; // delete later

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

// WRITE YOUR CODE HERE

//PUSH FRONT
void ULListStr::push_front(const std::string& val) {

	//EMPTY LIST
	if(head_ == NULL) {
		Item *temp = new Item();
		temp->val[9] = val;
		temp->first = 9;
		temp->last = 10;
		//set head and tail as same
		head_ = temp;
		tail_ = temp;
		size_++;
	}

	//SPACE IN FRONT //SWAP 47 and 48 MAYBE
	else if (head_->first != 0) {
		head_->first --;
		head_->val[head_->first] = val;
		size_++;
	}
	
	//NO SPACE IN FRONT, NEW NODE
	else if(head_->first == 0) {
		size_++;
		//new item
		Item *temp = new Item();
		temp->val[9] = val;
		temp->first = 9;
		temp->last = 10;
		head_->prev = temp;
		temp->next = head_;
		temp->prev = NULL;
		head_ = temp;
	}
}

//PUSH BACK
void ULListStr::push_back(const std::string& val) {

	//EMPTY LIST
	if(tail_ == NULL) {
		Item *temp = new Item();
		temp->val[9] = val;
		temp->first = 9;
		temp->last = 10;
		//set head and tail as same
		head_ = temp;
		tail_ = temp;
		size_++;
	}

	//SPACE IN BACK
	else if (tail_->last < ARRSIZE - 1) {
		tail_->val[tail_->last] = val;
		tail_->last--;
		size_++;
	}
	
	//NO SPACE IN BACK, NEW NODE
	else {
		size_++;
		//new item
		Item *temp = new Item();
		temp->val[9] = val;
		temp->first = 9;
		temp->last = 10;
		temp->prev = tail_;
		tail_->next = temp;
		tail_ = temp;
	}
}

void ULListStr::pop_front() {
		//if last item in node then delete
		//else delete first item
		if ((head_->last - head_->first) == 1) {
			Item *temp = head_->next;
			head_->val[head_->first] = nullptr;
			delete head_;
			size_--;
			head_ = temp;
		}

		else {
			size_--;
			head_->first++;
		}
}

void ULListStr::pop_back() {
		//if last item in node then delete
		//else delete first item
		if ((tail_->last - tail_->first) == 1) {
			Item *temp = tail_->prev;
			//tail_->val[tail_->first] = nullptr;
			delete tail_;
			size_--;
			tail_ = temp;
		}

		else {
			size_--;
			tail_->last--;
		}
}

std::string const & ULListStr::front() const {
	std::string & stringRef = head_->val[head_->first];
	return stringRef;
}

std::string const & ULListStr::back() const {
	std::string & stringRef = tail_->val[tail_->last-1];
	return stringRef;
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
		if(loc >= size_) {
			return NULL;
		}

		if(loc < 0) {
			return NULL;
		}
		//std::cout << "PRINT" << loc << std::endl;
		Item *temp = head_;
		while ((temp->last) - (temp->first) <= loc) {
			loc -= ((temp->last) - (temp->first));
			temp = temp->next;
		}
		return &temp->val[temp->first + loc];
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
