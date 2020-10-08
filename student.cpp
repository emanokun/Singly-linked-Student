//lab 3-1 singly linked list

#include <iostream>
#include <list>

using namespace std;

//new node - Student
class Student{
    public:
        int ID;
        string name;
        Student* next;
        Student* prev;

};

//insert data at the beginning 
void push(Student** head_ref, int new_id, string new_name){

    Student* new_student = new Student();

    new_student->ID   =  new_id;
    new_student->name =  new_name;
    new_student->next =  (*head_ref);

    if ((*head_ref) !=NULL){
            (*head_ref)->prev = new_student;
    }
    new_student->prev = NULL;
    (*head_ref) = new_student;

}

//insert data at the middle
void insertAfterPos(Student** head_ref, int position, int new_id, string new_name){
    Student* new_student = new Student();
    Student* p = *head_ref;
    Student* q = p->next;
    new_student->ID   = new_id;
    new_student->name = new_name;
    int i = 1;
    while (i != position) {
		p = p->next;
		q = q->next;
		i++;
	}
    new_student->next = p->next;
	new_student->prev = p;
	p->next = new_student;
    q->prev = new_student;
}

//insert data at the end
void append(Student** head_ref, int new_id,string new_name){
    
	Student* new_student= new Student();
    Student* last     = *head_ref;

    new_student->ID   = new_id;
    new_student->name = new_name;

    new_student->next = NULL;

	while (last->next != NULL){

		last = last->next;
    }

	last->next = new_student;
	new_student->prev = last;
	return;
}


//delete first item
void deleteFront(Student** head_ref){
    Student* first = *head_ref;
	Student* second = first->next;
	*head_ref = second;
	second->prev = NULL;
	delete first;

}
//delete at the middle 
void deletePosition(Student** head_ref,int position){
    Student* p = *head_ref;
	Student* q = p->next;
    int i = 1;
	while (i != position) {
		p = p->next;
		q = q->next;
		i++;
	}
	Student* temp = q->next;
	p->next = temp;
	temp->prev = p;
	delete q;
    
}

//delete at the end
void deleteLast(Student** head_ref){
    Student* p = *head_ref;
	Student* q = p->next;
   
    while (p->next != NULL){
		p = p->next;
		q = q->next;

}
	p->next = NULL;
	delete p;

}

//display list item
void printList(Student* student){
    Student* last = NULL;
	cout<<"\nList of Student (Name and ID) \n";
	while (student != NULL) {
		cout<< "Name: "<< student->name<<"  "<<endl;
        cout<< "ID: "  <<student->ID<<"  "<<endl;
        cout<<endl;
		
		last = student;
	    student = student->next;
	}
}

//to count number of items
void countStudent(Student* head_ref){
   int count = 0;  
    Student* current = head_ref; 
    while (current != NULL){  
        count++;  
        current = current->next;  
    }  
    cout<<"The number of student is " << count;
    return;
}

int main(){
    //TASK 2
    Student* head = NULL;
    push(&head, 1234, "Aiman Saleh");
    push(&head, 1212, "Chris Ronaldo");
    push(&head, 323232, "Lionel Messi");
    push(&head, 324343, "Gerald Baus");
    push(&head, 54445, "Herraro herra");
   // push(&head, 4893489, "Alif Ba Ta");
    cout<<"Insert 5 students in the list - "<<endl;
    printList(head);
   
    //TASK 3
    insertAfterPos(&head, 2, 4893489, "Alif Ba Ta");
    cout<<"Insert new student after student two - "<<endl;
    printList(head);
    
    //TASK 4
    append(&head, 44344, "Mus Leng");
    cout<<"Insert new student  at the end - "<<endl;
    printList(head);

    //task 5
    
    deleteLast(&head);
    cout<<"Delete last student - "<<endl;
    printList(head);
    
    //task 6
    deletePosition(&head,4);
    cout<<"Delete student number 4- "<<endl;
    printList(head);

    //task 7
    deleteFront(&head);
    cout<<"delete the first student- "<<endl;
    printList(head);

    //task 8
    cout<<"Count the number of student - " <<endl;
    countStudent(head);

   
    return 0;

}