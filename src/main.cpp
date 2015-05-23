#include <iostream>

template <typename T>
class list
{
public:
	template <typename T1>
	class node
	{
	public:
		T1 data;
		node* next;
		void show(void)
		{
			data.show();
		}
	};
	node<T> * head = nullptr;
	
	list(T data)
	{
		push_front(data);
	}
	
	~list()
	{
		clear();
	}
	
	void clear(void)
	{
		node<T> *tmp = head;
		if(head == nullptr)
			return;
		while(tmp != nullptr)
		{
			tmp = head->next;
			delete head;
			head = tmp;
		}
	}
	
	bool push_back(T data)
	{
		node<T> *tmp;
		node<T> *count = head;
		try
		{
			tmp = new node<T>;
		}
		catch(...)
		{
			return false;
		}
		tmp->data = data;
		tmp->next = nullptr;
		if(head == nullptr)
		{
			head = tmp;
			return true;
		}
		while(count->next != nullptr)
		{
			count = count->next;
		}
		count->next = tmp;
		return true;
	}
	
	bool push_front(T data)
	{
		node<T> *tmp;
		try
		{
			tmp = new node<T>;
		}
		catch(...)
		{
			return false;
		}
		tmp->next = head;
		tmp->data = data;
		head = tmp;
		return true;
	}
	
	node<T> * tail(void)
	{
		if(head == nullptr)
			return head;
		node<T> *count = head;
		while(count->next != nullptr)
		{
			count = count->next;
		}
		return count;
	}
	
	int size(void)
	{
		int count = 0;
		node<T> *tmp = head;
		while(tmp != nullptr)
		{
			count++;
			tmp = tmp->next;
		}
		return count;
	}
	
	void show(void)
	{
		node<T> *count = head;;
		while(count != nullptr)
		{
			count->show();
			count = count->next;
		}
	}
	
	struct iterator
	{
		node<T> *ptr;
		iterator (node<T>* ptr_= nullptr) : ptr(ptr_) { }
		node<T>& operator*() { return *ptr; }
		node<T>* operator->() { return ptr; }
		void operator ++ ()
		{
			ptr = ptr->next;
		}
		iterator operator++(int) { iterator iter(ptr);  ++(*this); return iter; }
		void operator--() 
		{ 
			node<T> *tmp = head;
			if(head == nullptr)
				return head;
			while(tmp->next != ptr)
			{
				tmp = tmp->next;
			}
			ptr = tmp;
		}
		bool operator<(const iterator& other) const { return ptr->data < other.ptr->data; }
		bool operator==(const iterator& other) const { return ptr == other.ptr; }
		bool operator!=(const iterator& other) const { return !(*this == other); }	
	};
	
	iterator begin() { return iterator(head); }
	iterator end() { return iterator(nullptr); }
	
	void swap(iterator one, iterator two)
	{
		T tmp;
		tmp = (*one).data;
		(*one).data = (*two).data;
		(*two).data = tmp;
	}
	
	void sort(iterator begin, iterator end)
	{
		for(auto i0 = begin; i0 != end; ++i0)
			for(auto i1 = begin; i1 != end; ++i1)
				if(i1 < i0)
					swap(i1, i0);
	}
	
};

struct my_type1
{
	std::string name;
	int id;
	bool operator<(struct my_type1 rhv)
	{
		return id < rhv.id;
	}
	void show()
	{
		std::cout << id << " " << name << std::endl;
	}
};

typedef struct my_type1 my_type1;

int main(void)
{
	
	list<my_type1> my_type_list({"minus one", -1});
	
	my_type_list.push_back({"one", 1});
	my_type_list.push_back({"two", 2});
	my_type_list.push_back({"three", 3});
	my_type_list.push_front({"zero", 0});
	my_type_list.show();
	
	std::cout << my_type_list.size() << std::endl;
	
	my_type_list.tail()->show();
	
	for(auto it = my_type_list.begin(); it != my_type_list.end(); it++)
	{
		(*it).show();
	}
	std::cout << "list sorted:" << std::endl;
	
	my_type_list.sort(my_type_list.begin(), my_type_list.end());
	
	my_type_list.show();	
	return 0;
}