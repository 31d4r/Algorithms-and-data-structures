#include<iostream>

struct node{
    int number; //->data part
    node *next; //->ptr to the next node
};

bool isEmpty(node *head){
    if(head == NULL)
        return true;
    else
        return false;
}

void inputAsFirstElement(node *&head, node *&last, int number){
    
    node *temp = new node;
    temp->number = number; //->assing. a local var to the actual node number part
    temp->next = NULL; //->
    head = temp; //->1st item
    last = temp; //->first and the last item are the same
}

void insert(node *&head, node *&last, int number){
    if(isEmpty(head))
        inputAsFirstElement(head, last, number);
    else {
        node *temp = new node;
        temp->number = number;
        temp->next = NULL;
        last->next = temp; //->set the previous last value the next part to thje spec. temp node, deref. node
        last = temp; //->update the last element
    }
}

void remove(node *&head, node *last){
    if(isEmpty(head))
        std::cout<<"The list is already empty!\n";
    else if(head == last){
        delete head;
        head = NULL;
        last = NULL;
    }else {
        node *temp = head;
        head=head->next;
        delete temp;
    }
}

void showList(node *current){
    if(isEmpty(current))
        std::cout<<"The list is empty!\n";
    else{
        std::cout<<"The list containst: | ";
        while(current!=NULL){
            std::cout<<current->number<<" | ";
            current=current->next;
        }
        std::cout<<"\n";
    }
}

char menu(){
    char choice;
    std::cout<<"\t\tMENU\n\n";
    std::cout<<"\t1. Add an item\n";
    std::cout<<"\t2. Remove an item\n";
    std::cout<<"\t3. Show the list\n";
    std::cout<<"\t4. Exit";
    std::cout<<"\nChoice: ";
    std::cin>>choice;
    return choice;
}

int main(){
    
    node *head=NULL;
    node *last=NULL;
    char choice;
    int number;
    do{
        choice = menu();
        switch (choice) {
            case '1':
                std::cout<<"Please enter the number: ";
                std::cin>>number;
                insert(head, last, number);
                break;
            case '2':
                remove(head, last);
                break;
            case '3':
                showList(head);
                break;
            default:
                std::cout<<"Exiting...";
                break;
        }
    }while(choice!='4');
    return 0;
}
