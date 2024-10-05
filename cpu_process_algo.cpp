#include<iostream>
using namespace std;

class Process
{
    public:
    int process_id;
    int exec_time;
    int remanining_time;

    Process(int process_id, int exec_time, int remaning_time)
    {
        this->process_id=process_id;
        this->exec_time=exec_time;
        this->remanining_time=remaning_time;
    }
};

class Node
{
  public:
  Process* process;
  Node* next;

 Node(Process* p) {
        this->process = p;  // Store pointer to the Process object
        this->next = nullptr;
    }

};

class LinkedList
{
    public:
    Node* list;
    int p_counter;

    LinkedList()
    {
        this->list=nullptr;
        p_counter=4;
    }

    bool IsEmpty()
    {
        return list==nullptr;
    }

    void insert_at_start(Process* value)
    {
        Node* new_node=new Node(value);

        if (IsEmpty())
        {
            // First node in the list
            list = new_node;
            new_node->next = list; // Point to itself
        }
        else
        {
            new_node->next = list->next;
            list->next = new_node;
        }
    }

    void insert_at_end(Process* value)
    {
        Node* new_node=new Node(value);
        if (IsEmpty())
        {
            list = new_node;
            new_node->next = list;
        }
        else
        {
            new_node->next = list->next;
            list->next = new_node;
            list = new_node;
        }
    }

    void printlist()
    {
        Node* temp = list->next;
        do
        {
            cout << "Process ID: " << temp->process->process_id << " , ";
            cout << "Execution Time: " << temp->process->exec_time << " , ";
            cout << "Remaining Time: " << temp->process->remanining_time << "  ";
            temp = temp->next;
            cout << endl;
        }
        while(temp != list->next);
    }

    

void CPU_Scheduling2(int cycles)
{
    for (int i = 0; i < cycles; i++)
    {
        cout << endl<<"Cycle: " << i + 1;
        Node* temp = list->next;
        Node* head = list->next;

        if (temp == nullptr)  // Edge case: empty list
        {
            cout << "No processes in the list." << endl;
            return;
        }

        do  // Use do-while to ensure we iterate over all nodes in circular linked list
        {
            cout << "  ";
            temp->process->remanining_time -= cycles;  // Decrement remaining time by 1 in each cycle

            if (temp->process->remanining_time > 0)
            {
                cout << "(" << temp->process->process_id << ") Remaining: " << temp->process->remanining_time;
                temp = temp->next;
            }
            else
            {
                char choice;
                int e;
                cout << "("<<temp->process->process_id << ") Remaining: Completed ";
                Node* next_node = temp->next;  // Store the next node before deletion
                deleteprocess();   // Delete the current process
                cout<<"\nDo you want to add another process in the cycle?(Y/N)";
                cin>>choice;
                if (choice=='Y')
                {
                    cout<<"Enter execution time:";
                    cin>>e;
                    Process* p_new = new Process(p_counter++, e, e);
                    insert_at_end(p_new);
                    cout<<"\nNew process arrives- Remaining Time: ("<<p_new->process_id<<") "<<p_new->remanining_time;
                }              
                temp = next_node;
            }

            
        } while (temp != head && temp!=nullptr);  // Continue until we loop back to head
    }
}


void deleteprocess()
{
    Node* temp=list->next;
    if(temp->process->remanining_time<=0)
    {
        list->next=list->next->next;
        delete temp;
    }

    if(list->process->remanining_time<=0)
    {
        while(temp->next!=list)
        {
            temp=temp->next;
        }

        temp->next=list->next;
        list=temp;
    }
    Node* curr=list->next->next;
    if (curr->process->remanining_time<=0)
    {
        temp->next=list;
        delete curr;
        curr=nullptr;

    }
}


};

int main()
{
    int e1,e2,e3,c;
    cout<<"Enter execution time for Process 1:";
    cin>>e1;
    cout<<"Enter execution time for Process 2:";
    cin>>e2;
    cout<<"Enter execution time for Process 3:";
    cin>>e3;

    Process p1(1, e1, e1);
    Process p2(2, e2, e2);
    Process p3(3, e3, e3);

    LinkedList list;

    list.insert_at_end(&p1);
    list.insert_at_end(&p2);
    list.insert_at_end(&p3);

    list.printlist();

    cout<<"Enter CPU Time per Process per Cycle:";
    cin>>c;

    list.CPU_Scheduling2(c);

    list.deleteprocess();
    
    cout<<endl;
    cout<<"The processes after execution are: "<<endl;
    list.printlist();

    return 0;
    
}
