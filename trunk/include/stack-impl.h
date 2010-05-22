/*****************************************************************************
 *                               stack-impl.h
 *
 * Implementation for Stack class.
 *
 * Zhang Ming, 2009-10
 *****************************************************************************/


/**
 * constructors and destructor
 */
template <typename Type>
Stack<Type>::Stack( int maxSize ) : top (-1), capacity(maxSize)
{
    elements = new Type[maxSize];
    if( !elements )
    {
        cerr << "Out of memory!" << endl;
        exit(1);
    }
};

template <typename Type>
Stack<Type>::~Stack()
{
    top = -1;
    capacity = INITSIZE;
    delete []elements;
}


/**
 * If the stack is empty, return true.
 */
template <typename Type>
inline bool Stack<Type>::isEmpty() const
{
    return ( top == -1 );
}


/**
 * Make the stack empty.
 */
template <typename Type>
inline void Stack<Type>::makeEmpty()
{
    top = -1;
}


/**
 * Push an element into the stack.
 */
template <typename Type>
inline void Stack<Type>::push( const Type &x )
{
    elements[++top] = x;
    if( top == capacity-1 )
        handleOverflow();
};


/**
 * Pop an element out of stack.
 */
template <typename Type>
inline void Stack<Type>::pop( Type &x )
{
    if( !isEmpty() )
        x = elements[top--];
    else
        handleUnderflow();
};


/**
 * Get the top element of the stack.
 */
template <typename Type>
inline void Stack<Type>::getTop( Type &x )
{
    if( !isEmpty() )
        x = elements[top];
    else
        handleUnderflow();
};


/**
 * If the capability of the stack exceeds the initial size, make it double.
 */
template <typename Type>
void Stack<Type>::handleOverflow()
{
    capacity = EXTFACTOR * capacity ;

    Type *newArray = new Type[capacity];
    if( newArray == NULL )
    {
        cerr << "Out of memory!" << endl;
        exit(1);
    }

    for( int i=0; i<=top; ++i )
        newArray[i] = elements[i];

    delete []elements;
    elements = newArray;
};


/**
 * Handle the error of get element from an empty stack.
 */
template <typename Type>
inline void Stack<Type>::handleUnderflow()
{
    cerr << "The stack is empty!" << endl << endl;
    exit( 1 );
};
