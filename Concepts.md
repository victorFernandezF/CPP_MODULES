# CLASSES

### CONCRET CLASS
A concret class is an ordinary class which has no purely virtual functions and hence can be instantiated (create an object from the class).

```
class ConcretClass{
    public:
        ConcretClass();
        ~ConcretClass();
        void method_1(int param);
}
```

### BASE CLASS
A base class is a class from which other classes can inherit.
```
class BaseClass{
    public:
        BaseClass();
        virtual ~BaseClass();
        void method_1(int param);
};
```

### DERIVED CLASS OR SUBCLASSES
A derived class is a class which inherits from another class (base class).
```
class DerivedClass: public BaseClass{
    public:
        DerivedClass();
        ~DerivedClass();
        void method_2(int param);
};
```

### ABSTRACT CLASS
An abstract class is a class which can not be instanciated.
It is used to provide a base class for subclasses.
To consider a class Abstract, at least one of its methods must be pure virtual.
To create a pure virtual method, we use the "virtual" keyword and assign 0 in the declaration.
```
class AbstractClass{
    public:
        AbstractClass();
        ~AbstractClass();
        virtual void method_1(int param) = 0; // Pure virtual method.
};
```

### INTERFACE
An interface is an pure abstract class. Which means all its methods are pure virtual.
In an interface we only declare the functions but not the function definitions. The implementation for pure virtual methods is done at the derived class by method/function overriding.
```
class Interface{
    public:
        virtual ~Interface() = 0;
        virtual void method_1(int param) = 0;
};
```

### STATIC CLASSES
Its operating doesn't depend on an instance.
It can not be instanciated.
All its member methods are static methods.
As its not possible to instanciate, to use a method we must call it this way: {NameOfClass::nameOfMethod(parameters)}.
```
class StaticClass{
    private:
        StaticClass();
        ~StaticClass();
    public:
        static void method_1(int param);
        static void method_2(void);
        static int method_3(int param, int param2);
};
```
Note that the constructor and destructor are private. This way the class will not be able to instanciate.
The call of methos_1 in a main function will look like this:
```
int main(void){
    StaticClass::method_1(42);
    return 0;
}
```