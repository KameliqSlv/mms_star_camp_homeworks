#include "stack.h"


int main(){
    Stack *s = init_stack();
    push_stack_front(s, 4);
    push_stack_front(s, 5);
    push_stack_front(s, 6);
    push_stack_front(s, 7);
    push_stack_front(s, 8);
    push_stack_front(s, 9);
    print_stack(s);

    int res;
    pop_stack_front(s, &res);
    print_stack(s);

    pop_stack_front(s, &res);
    print_stack(s);

    pop_stack_front(s, &res);
    print_stack(s);

    pop_stack_front(s, &res);
    print_stack(s);


    deinit_stack(s);
    return 0;
}