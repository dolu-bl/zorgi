# Contributing to zorgi

#### Table Of Contents

* [Intro](#intro)
* [Formatting](#formatting)
    * [Spacing and alignment](#spacing-and-alignment)
        * [Namespaces](#namespaces)
        * [`switch` statement](#switch-statement)

## Intro

This standard describes the visual style of code for C++/Qt/QML projects, as well as the use of some idioms and programming patterns.

Following this standard is mandatory when writing new code.

It is also necessary to bring already written code to the standard, if work is being done with it.

This will increase the information content of the code while reading and facilitate its support, help to avoid common mistakes.

[toc](#table-of-contents)



## Formatting



### Spacing and alignment

For indents **only spaces** should be used.

The IDE should use the indentation setting of **4 spaces**.

Wide and long code is hard to read. Code located on more than 3 levels should be divided into several functions.

Code lines which are longer than 120 characters must be split into several.

Logically different parts of the code should be separated by empty lines.

[toc](#table-of-contents)



#### Namespaces

Namespaces and code in it should be located at the same level.

Correct code:

```cpp
namespace Database
{

class Transaction
{
};

class TransactionManager
{
};

} // namespace Database
```

Correct code:

```cpp
namespace
{
const QString SomeConstant = "SecretText";
} // namespace
```

[toc](#table-of-contents)


#### `switch` statement

`switch` statement and it `case` labels should be flush.

If it necessary to define a new scope in `case` label, then brackets should be placed at the next level.

Correct code:

```cpp
switch (type)
{
case Qt::TopLeftCorner:
    {
        const auto value = calculate();
        startFirstLogic(value);
        startLastLogic(value);
    }
    break;

case Qt::BottomLeftCorner:
    finalize();
    break;

default:
    Q_ASSERT_X(false, "Some type logic", "Not implemented yet");
    break;
}
```

[toc](#table-of-contents)
