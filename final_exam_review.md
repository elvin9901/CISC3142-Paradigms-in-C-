Table of Contents

Mindmap

1.  Access Control

Access Control specifiers define how the members (attributes and
methods) of a class can be accessed. In C++, there are three access
control specifiers:

-   public - members are accessible & modified from outside the class

-   private - members cannot be accessed (or viewed) from outside the
    class

-   protected - members cannot be accessed from outside the class,
    however, they can be accessed in inherited classes.

[Example:]{.ul}

> class MyClass {
>
> public: // Public access specifier
>
> int x; // Public attribute
>
> private: // Private access specifier
>
> int y; // Private attribute

protected:

> int z; // Protected attribute
>
> };
>
> int main() {
>
> MyClass myObj;
>
> myObj.x = 25; // Allowed (public)
>
> myObj.y = 50; // Not allowed (private)
>
> return 0;
>
> }

By default, all members of a class are private if you don\'t specify an
access specifier. Such as-

> class MyClass {
>
> int x; // Private attribute
>
> int y; // Private attribute
>
> };

2.  Classes

A class in C++ is the building block that leads to Object-Oriented
programming. It is a user-defined data type, which holds its own **data
members and member functions**, which can be accessed and used by
creating an object of that class.

For Example: Consider the Class of Cars. There may be many cars with
different names and brand but all of them will share some common
properties like all of them will have 4 wheels, Speed Limit, Mileage
range etc. So here, Car is the class and wheels, speed limits, mileage
are their properties.

[Example:]{.ul}

> class class_name{

Access specifier; // cab be private, public, protected

Data members; // variables to be used

Member function() {} // Methods/function to access data member

> }; // class name ends with a semocolon

3.  Class Scope

When the scope of a declaration extends to or past the end of a class
definition, the regions defined by the member definitions of that class
are included in the scope of the class. Members defined lexically
outside of the class are also in this scope. In addition, the scope of
the declaration includes any portion of the declarator following the
identifier in the member definitions.

The name of a class member has class scope and can only be used in the
following cases:

-   In a member function of that class

-   In a member function of a class derived from that class

-   After the . (dot) operator applied to an instance of that class

-   After the . (dot) operator applied to an instance of a class derived
    from that class, as long as the derived class does not hide the name

-   After the -\> (arrow) operator applied to a pointer to an instance
    of that class

-   After the -\> (arrow) operator applied to a pointer to an instance
    of a class derived from that class, as long as the derived class
    does not hide the name

-   After the:: (scope resolution) operator applied to the name of a
    class

-   After the:: (scope resolution) operator applied to a class derived
    from that class

4.  Constructor Functions

A constructor is a special type of member function of a class which
initializes objects of a class. In C++, Constructor is automatically
called when object(instance of class) is created. It is special member
function of the class because it does not have any return type.

A constructor is different from normal functions in following ways:

-   Constructor has same name as the class itself

-   Default Constructors don't have input argument.

-   Constructors don't have return type

-   A constructor is automatically called when an object is created.

-   It must be placed in public section of class.

-   If we do not specify a constructor, C++ compiler generates a default
    constructor for object (expects no parameters and has an empty
    body).

Types of Constructors:

1.  **[Default Constructors:]{.ul}** Default constructor is the
    constructor which doesn't take any argument.

> Example:
>
> class construct
>
> {
>
> public:
>
> int a, b;
>
> construct() // Default Constructor
>
> {
>
> a = 10;
>
> b = 20;
>
> }};

2.  **[Parameterized Constructors:]{.ul}** It is possible to pass
    arguments to constructors. Typically, these arguments help
    initialize an object when it is created. When you define the
    constructor's body, use the parameters to initialize the object.

**[Example:]{.ul}**

class Point

{

private:

int x, y;

public:

// Parameterized Constructor

Point(int x1, int y1)

{

x = x1;

y = y1;

}

int getX()

{

return x;

}

int getY()

{

return y;

}

};

5.  Data Members

> Data members include members that are declared with any of the
> fundamental types, as well as other types, including pointer,
> reference, array types, bit fields, and user-defined types. You can
> declare a data member the same way as a variable, except that explicit
> initializer are not allowed inside the class definition. However, a
> const static data member of integral or enumeration type may have an
> explicit initializer. A class X cannot have a member that is of type
> X, but it can contain pointers to X, references to X, and static
> objects of X. Member functions of X can take arguments of type X and
> have a return type of X. For example:
>
> class X
>
> {
>
> X();
>
> X \*xptr;
>
> X &xlref;
>
> X &&xrref;
>
> static X xcount;
>
> X xfunc(X);
>
> };

6.  Default Arguments

> A default argument is a value provided in a function declaration that
> is automatically assigned by the compiler if the caller of the
> function doesn't provide a value for the argument with a default
> value. In case any value is passed the default value is overridden.
>
> Following is a simple C++ example to demonstrate the use of default
> arguments. Here, we don't have to write 3 sum functions, only one
> function works by using default values for 3rd and 4th arguments.
>
> int sum(int x, int y, int z = 0, int w = 0)
>
> {
>
> return (x + y + z + w);
>
> }
>
> // Driver Code
>
> int main()
>
> {
>
> // Statement 1
>
> cout \<\< sum(10, 15) \<\< endl;
>
> // Statement 2
>
> cout \<\< sum(10, 15, 25) \<\< endl;
>
> // Statement 3
>
> cout \<\< sum(10, 15, 25, 30) \<\< endl;
>
> return 0;
>
> }

7.  Destructor Functions

> Destructor is an instance member function which is invoked
> automatically whenever an object is going to be destroyed. Meaning, a
> destructor is the last function that is going to be called before an
> object is destroyed.
>
> Syntax:

\~constructor-name();

Example:

class String {

> private:
>
> char\* s;
>
> int size;
>
> public:
>
> String(char\*); // constructor
>
> \~String(); // destructor
>
> };
>
> String::String(char\* c)
>
> {
>
> size = strlen(c);
>
> s = new char\[size + 1\];
>
> strcpy(s, c);
>
> }
>
> String::\~String() { delete\[\] s; }

8.  Dynamic Allocation

A good understanding of how dynamic memory really works in C++ is
essential to becoming a good C++ programmer. Memory in your C++ program
is divided into two parts −

-   The stack − All variables declared inside the function will take up
    memory from the stack.

-   The heap − This is unused memory of the program and can be used to
    allocate the memory dynamically when program runs.

Many times, you are not aware in advance how much memory you will need
to store particular information in a defined variable and the size of
required memory can be determined at run time.

Consider you want to allocate memory for an array of characters, i.e.,
string of 20 characters. Using the same syntax what we have used above
we can allocate memory dynamically as shown below.

> char\* pvalue = NULL; // Pointer initialized with null
>
> pvalue = new char\[20\]; // Request memory for the variable

To remove the array that we have just created the statement would look
like this −

delete \[\] pvalue; // Delete array pointed to by pvalue

Following the similar generic syntax of new operator, you can allocate
for a multi-dimensional array as follows −

> double\*\* pvalue = NULL; // Pointer initialized with null
>
> pvalue = new double \[3\]\[4\]; // Allocate memory for a 3x4 array

However, the syntax to release the memory for multi-dimensional array
will still remain same as above −

delete \[\] pvalue; // Delete array pointed to by pvalue

9.  Encapsulation

In normal terms Encapsulation is defined as wrapping up of data and
information under a single unit. In Object Oriented Programming,
Encapsulation is defined as binding together the data and the functions
that manipulates them. Encapsulation also lead to data abstraction or
hiding. As using encapsulation also hides the data. In the above example
the data of any of the section like sales, finance or accounts is hidden
from any other section.

In C++ encapsulation can be implemented using Class and access
modifiers. Look at the below program:

> class Encapsulation
>
> {
>
> private:
>
> // data hidden from outside world
>
> int x;
>
> public:
>
> // function to set value of
>
> // variable x
>
> void set(int a)
>
> {
>
> x =a;
>
> }
>
> // function to return value of
>
> // variable x
>
> int get()
>
> {
>
> return x;
>
> }
>
> };
>
> // main function
>
> int main()
>
> {
>
> Encapsulation obj;
>
> obj.set(5);
>
> cout\<\<obj.get();
>
> return 0;
>
> }

10. File Scope

If the declarator or type specifier that declares the identifier appears
outside of any block or list of parameters, the identifier has file
scope, which terminates at the end of the translation unit.

So, placement of an identifier\'s declaration (in a declarator or type
specifier) outside any block or list of parameters means that the
identifier has file scope. File scope of an identifier extends from the
declaration to the end of the translation unit in which the declaration
appears.

Example:

int a = 1;

> static int b = 2;
>
> void f (void) {printf(\"from function f()\\n\");}
>
> static void g (void) {printf(\"from function g()\\n\");}
>
> int main(void)
>
> {
>
> f();
>
> g();
>
> return 0;
>
> }

11. Function Member

Member functions are operators and functions that are declared as
members of a class. Member functions do not include operators and
functions declared with the friend specifier. These are called friends
of a class. You can declare a member function as static; this is called
a static member function. A member function that is not declared as
static is called a nonstatic member function.

The definition of a member function is within the scope of its enclosing
class. The body of a member function is analyzed after the class
declaration so that members of that class can be used in the member
function body, even if the member function definition appears before the
declaration of that member in the class member list. When the function
add() is called in the following example, the data variables a, b, and c
can be used in the body of add().

Example:

> class x
>
> {
>
> public:
>
> int add() // inline member function add
>
> {return a+b+c;};
>
> private:
>
> int a,b,c;
>
> };

12. Function Scope

A label has function scope, which means it is visible throughout a
function body even before its point of declaration. Function scope makes
it possible to write statements like goto cleanup before the cleanup
label is declared.

13. Inheritance

The capability of a class to derive properties and characteristics from
another class is called Inheritance. The class that inherits properties
from another class is called Sub class or Derived Class. The class whose
properties are inherited by sub class is called Base Class or Super
class.

Syntax:

> class subclass_name : access_mode base_class_name
>
> {
>
> // body of subclass
>
> };

Example:

// Base class

> class Parent
>
> {
>
> public:
>
> int id_p;
>
> };
>
> // Sub class inheriting from Base Class(Parent)
>
> class Child : public Parent
>
> {
>
> public:
>
> int id_c;
>
> };
>
> // main function
>
> int main()
>
> {
>
> Child obj1;
>
> // An object of class child has all data members
>
> // and member functions of class parent
>
> obj1.id_c = 7;
>
> obj1.id_p = 91;
>
> cout \<\< \"Child id is: \" \<\< obj1.id_c \<\< \'\\n\';
>
> cout \<\< \"Parent id is: \" \<\< obj1.id_p \<\< \'\\n\';
>
> return 0;
>
> }

**Modes of Inheritance**

**Public mode:** If we derive a sub class from a public base class. Then
the public member of the base class will become public in the derived
class and protected members of the base class will become protected in
derived class.

**Protected mode:** If we derive a sub class from a Protected base
class. Then both public member and protected members of the base class
will become protected in derived class.

**Private mode:** If we derive a sub class from a Private base class.
Then both public member and protected members of the base class will
become Private in derived class.

14. Member Access

Member access determines if a class member is accessible in an
expression or declaration. Suppose x is a member of class A. Class
member x can be declared to have one of the following levels of
accessibility:

-   public: x can be used anywhere without the access restrictions
    defined by private or protected.

-   private: x can be used only by the members and friends of class A.

-   protected: x can be used only by the members and friends of class A,
    and the members and friends of classes derived from class A.

Members of classes declared with the keyword class are private by
default. Members of classes declared with the keyword struct or union
are public by default.

15. Names

All C++ variables must be identified with unique names. These unique
names are called identifiers. Identifiers can be short names (like x and
y) or more descriptive names (age, sum, totalVolume). The general rules
for naming variables are:

-   Names can contain letters, digits and underscores

-   Names must begin with a letter or an underscore (\_)

-   Names are case sensitive (myVar and myvar are different variables)

-   Names cannot contain whitespaces or special characters like !, \#,
    %, etc.

-   Reserved words (like C++ keywords, such as int) cannot be used as
    names

16. Namespace

Namespaces allow us to group named entities that otherwise would have
global scope into narrower scopes, giving them namespace scope. This
allows organizing the elements of programs into different logical scopes
referred to by names. Namespace is a feature added in C++ and not
present in C. A namespace is a declarative region that provides a scope
to the identifiers (names of the types, function, variables etc) inside
it. Multiple namespace blocks with the same name are allowed. All
declarations within those blocks are declared in the named scope.

A namespace definition begins with the keyword namespace followed by the
namespace name as follows:

> namespace namespace_name
>
> {
>
> int x, y; // code declarations where
>
> // x and y are declared in
>
> // namespace_name\'s scope
>
> }

17. Objects

An Object is an instance of a Class. When a class is defined, no memory
is allocated but when it is instantiated (i.e. an object is created)
memory is allocated.

**Declaring Objects:** When a class is defined, only the specification
for the object is defined; no memory or storage is allocated. To use the
data and access functions defined in the class, you need to create
objects.

Syntax:

ClassName ObjectName;

18. Operator Functions

In C++, we can make operators to work for user defined classes. This
means C++ has the ability to provide the operators with a special
meaning for a data type, this ability is known as operator overloading.
For example, we can overload an operator '+' in a class like String so
that we can concatenate two strings by just using +. Other example
classes where arithmetic operators may be overloaded are Complex Number,
Fractional Number, Big Integer, etc.

Example:

> class Complex {
>
> private:
>
> int real, imag;
>
> public:
>
> Complex(int r = 0, int i = 0) {real = r; imag = i;}
>
> // This is automatically called when \'+\' is used with
>
> // between two Complex objects
>
> Complex operator + (Complex const &obj) {
>
> Complex res;
>
> res.real = real + obj.real;
>
> res.imag = imag + obj.imag;
>
> return res;
>
> }
>
> void print() { cout \<\< real \<\< \" + i\" \<\< imag \<\< \'\\n\'; }
>
> };
>
> int main()
>
> {
>
> Complex c1(10, 5), c2(2, 4);
>
> Complex c3 = c1 + c2;
>
> c3.print();
>
> }

19. Overloading

This type of polymorphism is achieved by function overloading or
operator overloading.

When there are multiple functions with same name but different
parameters then these functions are said to be overloaded. Functions can
be overloaded by change in number of arguments or/and change in type of
arguments

Example:

class Geeks

{

public:

void func(int x) // function with 1 int parameter

{cout \<\< \"value of x is \" \<\< x \<\< endl; }

void func(double x) // function with same name but 1 double parameter

{cout \<\< \"value of x is \" \<\< x \<\< endl; }

void func(int x, int y) // function with same name and 2 int parameters

{cout \<\< \"value of x and y is \" \<\< x \<\< \", \" \<\< y \<\< endl;
}

};

int main() {

Geeks obj1;

obj1.func(7); // The first \'func\' is called

obj1.func(9.132); // The second \'func\' is called

obj1.func(85,64); // The third \'func\' is called

return 0;

}

20. Pointers

Pointers are symbolic representation of addresses. They enable programs
to simulate call-by-reference as well as to create and manipulate
dynamic data structures. It's general declaration in C/C++ has the
format:

Syntax:

> datatype \*var_name;
>
> int \*ptr; //ptr can point to an address which holds int data

How to use a pointer?

-   Define a pointer variable

-   Assigning the address of a variable to a pointer using unary
    operator (&) which returns the address of that variable.

-   Accessing the value stored in the address using unary operator (\*)
    which returns the value of the variable located at the address
    specified by its operand.

21. Polymorphism (include the 4 types)

The word polymorphism means having many forms. In simple words, we can
define polymorphism as the ability of a message to be displayed in more
than one form.

These polymorphisms has four types. Such as:

-   Subtype polymorphism is also known as runtime polymorphism.

-   Parametric polymorphism is also known as compile-time polymorphism.

-   Ad-hoc polymorphism is also known as overloading.

-   Coercion is also known as (implicit or explicit) casting.

I.  **Runtime polymorphism:**

This type of polymorphism is achieved by Function Overriding. It occurs
when a derived class has a definition for one of the member functions of
the base class. That base function is said to be **overridden**.

Example:

class base

{

> public:
>
> virtual void print ()
>
> { cout\<\< \"print base class\" \<\<endl; }
>
> void show ()
>
> { cout\<\< \"show base class\" \<\<endl; }

};

class derived: public base

{

> public:
>
> void print () //print () is already virtual function in derived class,
> we could also declared as virtual void print () explicitly
>
> { cout\<\< \"print derived class\" \<\<endl; }
>
> void show ()
>
> { cout\<\< \"show derived class\" \<\<endl; }

};

//main function

int main()

{

base \*bptr;

derived d;

bptr = &d;

bptr-\>print(); //virtual function, binded at runtime (Runtime
polymorphism)

bptr-\>show(); // Non-virtual function, binded at compile time

return 0;

}

II. **Compile-time polymorphism:**

This type of polymorphism is achieved by function overloading or
operator overloading.

When there are multiple functions with same name but different
parameters then these functions are said to be overloaded. Functions can
be overloaded by change in number of arguments or/and change in type of
arguments

Example:

class Geeks

{

public:

void func(int x) // function with 1 int parameter

{cout \<\< \"value of x is \" \<\< x \<\< endl; }

void func(double x) // function with same name but 1 double parameter

{cout \<\< \"value of x is \" \<\< x \<\< endl; }

void func(int x, int y) // function with same name and 2 int parameters

{cout \<\< \"value of x and y is \" \<\< x \<\< \", \" \<\< y \<\< endl;
}

};

int main() {

Geeks obj1;

> obj1.func(7); // The first \'func\' is called

obj1.func(9.132); // The second \'func\' is called

obj1.func(85,64); // The third \'func\' is called

return 0;

}

III. **Overloading:**

Ad-hoc polymorphism allows functions with the same name act differently
for each type. For example, given two ints and the + operator, it adds
them together. Given two std::strings it concatenates them together.
This is called overloading.

Example:

int add(int a, int b) {

return a + b;

}

std::string add(const char \*a, const char \*b) {

std::string result(a);

result += b;

return result;

}

int main() {

std::cout \<\< add(5, 9) \<\< std::endl;

std::cout \<\< add(\"hello \", \"world\") \<\< std::endl;

}

IV. **Casting:**

Coercion happens when an object or a primitive is cast into another
object type or primitive type. For example,

> float b = 6; // int gets promoted (cast) to float implicitly
>
> int a = 9.99 // float gets demoted to int implicitly

Example:

class A {

> int foo;
>
> public:
>
> A(int ffoo) : foo(ffoo) {}
>
> void giggidy() { std::cout \<\< foo \<\< std::endl; }
>
> };
>
> void moo(A a) {
>
> a.giggidy();
>
> }
>
> int main() {
>
> moo(55); // prints 55
>
> }

22. References

When a variable is declared as a reference, it becomes an alternative
name for an existing variable. A variable can be declared as a reference
by putting '&' in the declaration.

Example:

int main()

{

> int x = 10;
>
> int& ref = x; // ref is a reference to x.
>
> ref = 20; // Value of x is now changed to 20
>
> cout \<\< \"x = \" \<\< x \<\< \'\\n\';
>
> x = 30; // Value of x is now changed to 30
>
> cout \<\< \"ref = \" \<\< ref \<\< \'\\n\';
>
> return 0;

}

23. Scope

When you declare a program element such as a class, function, or
variable, its name can only be \"seen\" and used in certain parts of
your program. The context in which a name is visible is called its
scope. For example, if you declare a variable x within a function, x is
only visible within that function body. It has local scope. You may have
other variables by the same name in your program; as long as they are in
different scopes, they do not violate the One Definition Rule and no
error is raised. There are six kinds of scope:

**Global scope**: A global name is one that is declared outside of any
class, function, or namespace. However, in C++ even these names exist
with an implicit global namespace.

**Namespace scope:** A name that is declared within a namespace, outside
of any class or enum definition or function block, is visible from its
point of declaration to the end of the namespace.

**Local scope**: A name declared within a function or lambda, including
the parameter names, have local scope. They are often referred to as
\"locals\". They are only visible from their point of declaration to the
end of the function or lambda body.

**Class scope:** Names of class members have class scope, which extends
throughout the class definition regardless of the point of declaration.
Class member accessibility is further controlled by the public, private,
and protected keywords. Public or protected members can be accessed only
by using the member-selection operators (. or -\>) or pointer-to-member
operators (.\* or -\>\*).

**Statement scope:** Names declared in a for, if, while, or switch
statement are visible until the end of the statement block.

**Function scope:** A label has function scope, which means it is
visible throughout a function body even before its point of declaration.
Function scope makes it possible to write statements like goto cleanup
before the cleanup label is declared.

24. Signatures

Signatures are type abstractions or interfaces of classes. The main
language constructs added are signatures and signature pointers.

[Syntax:]{.ul}

> signature S
>
> {
>
> int foo (void);
>
> int bar (int);
>
> };

Which defines a new abstract type S with member functions int foo (void)
and int bar (int). Signature types cannot be instantiated since they
don\'t provide any implementation. Only signature pointers and signature
references can be defined. For example,

> C obj;
>
> S \* p = &obj;

defines a signature pointer p and initializes it to point to an object
of class type C, where C is required to contain the public member
functions int foo (void) and int bar (int). The member function call

> int i = p-\>foo ();

executes then obj.foo ().

Class C is called an implementation of the abstract type S. In this
example, we could have made S an abstract virtual class and C a subclass
of S, and we would have had the same effect.

25. Structures

We often come around situations where we need to store a group of data
whether of similar data types or non-similar data types. We have seen
Arrays in C++ which are used to store set of data of similar data types
at contiguous memory locations.

A structure is a user-defined data type in C/C++. A structure creates a
data type that can be used to group items of possibly different types
into a single type.

The **'struct'** keyword is used to create a structure. The general
syntax to create a structure is as shown below:

> struct structureName{
>
> member1;
>
> member2;
>
> member3;
>
> };

[Example:]{.ul}

> struct Point // A variable declaration with structure declaration.
>
> {
>
> int x, y;
>
> } p1; // The variable p1 is declared with \'Point\'
>
> struct Point // A variable declaration like basic data types
>
> {
>
> int x, y;
>
> };
>
> int main()
>
> {
>
> struct Point p1; // The variable p1 is declared like a normal variable
>
> }

26. Sub-types

The capability of a class to derive properties and characteristics from
another class is called Inheritance. The class that inherits properties
from another class is called Sub class or Derived Class.

Syntax:

> class subclass_name : access_mode base_class_name
>
> {
>
> // body of subclass or sub-types
>
> };

27. Super-types

The class whose properties are inherited by sub class is called Base
Class or Super class.

Syntax:

Class super-classs{

> // body of super class

};

> class subclass_name : access_mode super-class_name
>
> {
>
> // body of subclass or sub-types
>
> };

28. Virtual Functions

A virtual function is a member function which is declared within a base
class and is re-defined by a derived class. When you refer to a derived
class object using a pointer or a reference to the base class, you can
call a virtual function for that object and execute the derived class's
version of the function. They are mainly used to achieve Runtime
polymorphism

**Rules for Virtual Functions**

1.  Virtual functions cannot be static.

2.  Functions are declared with a virtual keyword in base class.

3.  A virtual function can be a friend function of another class.

4.  Virtual functions should be accessed using pointer or reference of
    base class type to achieve runtime polymorphism.

5.  The prototype of virtual functions should be the same in the base as
    well as derived class.

6.  They are always defined in the base class and overridden in a
    derived class. It is not mandatory for the derived class to
    override.

7.  A class may have virtual destructor but it cannot have a virtual
    constructor.

**[Example:]{.ul}**

class base {

> public:
>
> **virtual** void print()
>
> {cout \<\< \"print base class\\n\";}
>
> void show()
>
> {cout \<\< \"show base class\\n\";}

};

class derived: public base {

> public:
>
> void print()
>
> {cout \<\< \"print derived class\\n\";}
>
> void show()
>
> {cout \<\< \"show derived class\\n\";}

};

int main()

{

base \*bptr;

derived d;

bptr = &d;

bptr-\>print();// Virtual function, binded at runtime

bptr-\>show();// Non-virtual function, binded at compile time

return 0;}

29. Visibility

When a base class is derived by a derived class with inheritance, the
accessibility of base class by the derived class is controlled by
visibility modes. The derived class doesn't inherit access to private
data members. However, it does inherit a full parent object, which
contains any private members which that class declares.

[Example:]{.ul}

> class A {
>
> public:
>
> int x;
>
> protected:
>
> int y;
>
> private:
>
> int z;
>
> };
>
> // Derived class, Class B will inherit Class A
>
> class B : public A {
>
> };
>
> int main()
>
> {
>
> B b;
>
> cout \<\< b.x \<\< endl; // x is public, so its value will be printed
>
> cout \<\< b.y \<\< endl; // y is protected, so it will give visibility
> error
>
> cout \<\< b.z \<\< endl; // z is not accessible from B, so it will
> give visibility error
>
> };

-   Since the member 'x' in A is public, its visibility will be open to
    all. It means that any class can access and use this x. That is the
    reason there is no error in 'b.x'.

-   The member 'y' in A is protected, its visibility will be only to the
    derived class. It means that any derived class can access and use
    this y.

-   The member 'z' in A is private, its visibility will not be open to
    any other class. It means that any derived class cannot access and
    use this z.
