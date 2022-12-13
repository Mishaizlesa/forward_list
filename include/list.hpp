#ifndef list_hpp
#define list_hpp

#include <stdio.h>
#include <unordered_map>
#include <exception>
using namespace std;
template <class T> class list{
private:
    struct node{
        T val;
        node* next;
        node(T a){
            val=a;
            next=nullptr;
        }
        node (const node& a){
            val=a.val;
            next=a.next;
        }
    };
    node* first=nullptr;
public:
    list()=default;
    list(const list& a){
        first=new node(*a.first);
        auto tmp1=a.first;
        auto tmp2=first;
        while(tmp1->next){
            tmp2->next=new node(*(tmp1->next));
            tmp2=tmp2->next;
            tmp1=tmp1->next;
        }
    }
    list& operator = (list& a){
        if (first==a.first){
            return *this;
        }
        clear();
        first=new node(*a.first);
        auto tmp1=a.first;
        auto tmp2=first;
        while(tmp1->next){
            tmp2->next=new node(*(tmp1->next));
            tmp2=tmp2->next;
            tmp1=tmp1->next;
        }
        return *this;
    }
    void push_front(const T& val){
        if (!first){
            first=new node(val);
        }else{
            auto tmp=new node(*first);
            first=new node(val);
            first->next=tmp;
            
        }
    }
    void pop_front(){
        if (!first) throw std::out_of_range("empty list");
        auto tmp=first;
        first=first->next;
        delete tmp;
    }
    void insert_after(node* el, T val){
        if (!el){
            push_front(val);
            return;
        }
        auto tmp=el->next;
        el->next=new node(val);
        el->next->next=tmp;
    }
    void erase_after(node* el){
        if (!el->next || !el) throw std::out_of_range("cannot erase not filled cell");
        auto tmp=el->next->next;
        delete el->next;
        el->next=tmp;
    }
    void unique(){
        unordered_map<T,int>used;
        node* prev=nullptr;
        for(node* it=first;it;){
            if (used[it->val]){
                erase_after(prev);
                it=prev->next;

            }else{
                used[it->val]=1;
                prev=it;
                it=it->next;
            }
        }
    }
    void clear(){
        for(auto it=first;it;){
            auto tmp=it->next;
            delete it;
            it=tmp;
        }
        first=nullptr;
    }
    bool operator ==(const list& a){
        auto tmp1=a.first;
        auto tmp2=first;
        while (tmp1 || tmp2) {
            if (!tmp1 || !tmp2) return false;
            if (tmp2->val!=tmp1->val) return false;
            tmp1=tmp1->next;
            tmp2=tmp2->next;
        }
        return true;
    }
    bool operator !=(const list& a){
        return !(*this==a);
    }
    node* begin(){
        return first;
    }
    ~list(){
        clear();
    }
};
#endif /* list_hpp */
