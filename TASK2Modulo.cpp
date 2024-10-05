#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

class Node
{
    public:
    uint64_t data;
    Node* next;

    Node(uint64_t value)
    {
        this->data=value;
        this->next=nullptr;
    }
};

class LargeNumber
{
    public:
    Node*head;
    LargeNumber()
    {
        this->head=nullptr;
    }

    void create_large_number()
    {
        const int totalbits=1024;
        const int nodebits=64;
        const int no_of_nodes=totalbits/nodebits;

         random_device rd;
         mt19937_64 gen(rd());  // 64-bit Mersenne Twister engine
         uniform_int_distribution<uint64_t> dist(0, UINT64_MAX);

        for(int i=0; i<no_of_nodes; i++)
        {
           

            Node* new_node= new Node(dist(gen));

            if(head==nullptr)
            {
                head=new_node;
            }

            else  //inserting nodes at end
            {
                Node*temp=head;
                while(temp->next!=nullptr)
                {
                    temp=temp->next;
                }

                new_node->next=nullptr;
                temp->next=new_node;
            }
            //dist(gen) creates random number
        }

    }


    void print_number()
    {
        Node* temp= head;
        while(temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }


        // Modulo function to divide by a smaller number
    uint64_t modulo(uint64_t divisor) {
        Node* temp = head;
        uint64_t remainder = 0;

        // Apply long division over each 64-bit block of the large number
        while (temp != nullptr) {
            __uint128_t current_value = ((__uint128_t)remainder << 64) + temp->data;  // Combine remainder with next block
            remainder = current_value % divisor;  // Get remainder
            temp = temp->next;
        }
        return remainder;  // Final remainder after division
    }

    // Simple primality test for smaller divisors
    bool is_prime() {
        if (modulo(2) == 0) return false;  // Check divisibility by 2
        for (uint64_t i = 3; i * i <= UINT64_MAX; i += 2) {
            if (modulo(i) == 0) return false;  // Check divisibility by odd numbers
        }
        return true;
    }

    
};

int main()
{
    LargeNumber number;
    number.create_large_number();
    number.print_number();

    if (number.is_prime())
        cout << "The large number is prime." << endl;
    else
        cout << "The large number is not prime." << endl;


}