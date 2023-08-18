#include "stack.h"

int main(){
    Stack *s = init_stack();
    push_stack_front(s, (Data){4});
    push_stack_front(s, (Data){5});
    push_stack_front(s, (Data){6});
    push_stack_front(s, (Data){7});
    push_stack_front(s, (Data){8});
    print_stack(s);

    Data d;
    pop_stack_front(s, &d);
    print_stack(s);

    pop_stack_front(s, &d);
    print_stack(s);
   
    pop_stack_front(s, &d);
    print_stack(s);

    push_stack_front(s, (Data){6});
    push_stack_front(s, (Data){7});
    push_stack_front(s, (Data){8});
    print_stack(s);
    
    pop_stack_front(s, &d);
    print_stack(s);

    deinit_stack(s);
    print_stack(s);
   
}