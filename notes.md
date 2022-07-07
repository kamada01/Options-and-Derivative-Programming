### Constructors - method that runs every time an object is instantiated

1. Default Constructor 
- Constructor Overloading
  - Same name (name of class) but diff no. and type of args
  - Called depending upon no. and type of args passed
- Doesn't initialize values
- When no value passed with object, default constructor is called
```
class Entity
{
public: 
    float X, Y;

    Entity()
    {
        X = 0.0f;
        Y = 0.0f;
    }
}

int main()
{
    Entity e;
}
```

2. Copy Constructor
- when create new object and assign values to one of them, should contain different values
- called whenever you copy an object of that class
- for dynamic memory allocation e.g. pointers (address of mem)
```
class Person(
public:
    string *name;
    int age;

    Person(string n, int a){
        name = new string(n); //mem leak
        age = a; 
    }

    //copy constructor
    Person(const Person &p){
        name = new string(*p.name); //use value at operator * to get value 
        age = p.age //initialized to avoid garbage values, age not memory address, no need to use * operator
    }

    void change(string name, int age){
        *(this->name) = name;
        this->age = age;
    }

    void introduce(){
        cout << "name = " << *name << ", age = " << age << endl;
    }
)
```

3. Destructor
- runs when object is 'destroyed', uninitialize, claim memory used
- when 'new' used and 'delete' object, destructor called
- virtual members
```
class Entity
{
public: 
    float X, Y;

    Entity()
    {
        X = 0.0f;
        Y = 0.0f;
    }

    ~Entity()
    {
        cout << "Destroyed object";
    }
}

int main()
{
    Entity e;
}
```

4. Assignment operator
```
GenericOption &GenericOption::operator=(const GenericOption &p)
{
    if (this != &p)
    {
        m_type = p.m_type;
        m_strike = p.m_strike;
    }
    return *this;
}
```

```
struct Vector
{
    float x, y;

    Vector(float x, float y)
        : x(x), y(y) {}

    Vector Add(const Vector& other) const
    {
        return Vector(x + other.x, y + other.y)
    }
};
```


