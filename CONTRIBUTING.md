# Contributing to zorgi

#### Table Of Contents

* [Intro](#intro)
* [Formatting](#formatting)
    * [Spacing and alignment](#spacing-and-alignment)
        * [Namespaces](#namespaces)
        * [Brace location](#brace-location)
        * [`if-else` statement](#if-else-statement)
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

&#x2705; Correct code:

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

&#x2705; Correct code:

```cpp
namespace
{
const QString SomeConstant = "SecretText";
} // namespace
```

[toc](#table-of-contents)



#### Brace location

Curly braces should be placed on separate lines.

&#x2705; Correct code:

```cpp
class MyFavoriteDialog : public QDialog
{
};
```

&#x2705; Correct code:

```cpp
if (condition)
{
    // do some magic
}
```

The use of brackets in multi-level single-line operators is mandatory.

&#x2705; Correct code:

```cpp
if (isAvaliable)
{
    if (isIncredible)
        doSomethingTerrible();
    else
        doSomethingNice();
}
```

&#x274C; Invalid code:

```cpp
if (isAvaliable)
    if (isIncredible)
        doSomethingTerrible();
    else
        doSomethingNice();
```

It is forbidden to write conditions and expressions in one line.

&#x274C; Invalid code:

```cpp
int calculateRow() const { m_row = calculate(); return m_row; }
int row() { return m_row; }
```

&#x274C; Invalid code:

```cpp
if (nullptr == item) return;
if (!object->isValid()) continue;
```

[toc](#table-of-contents)



#### `if-else` statement

If one of the `if-else` statements is surrounded by curly braces, then the rest of the statements must be surrounded too.

&#x2705; Correct code:

```cpp
if (auto item = createItem(context))
{
    item->setParent(parent);
    item->process();
}
else
{
    finalize();
}
```

&#x274C; Invalid code:

```cpp
if (auto item = createItem(context))
{
    item->setParent(parent);
    item->process();
}
else
    finalize();
```

Yoda notation is recommended. https://en.wikipedia.org/wiki/Yoda_conditions

&#x2705; Correct code:

```cpp
if (nullptr == item)
    return false;

if (Qt::AscendingOrder == order)
    sort();
```

[toc](#table-of-contents)



#### `switch` statement

`switch` statement and it `case` labels should be flush.

If it necessary to define a new scope in `case` label, then brackets should be placed at the next level.

&#x2705; Correct code:

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
