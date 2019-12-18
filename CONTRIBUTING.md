# Contributing to zorgi

#### Table Of Contents

* [Intro](#intro)
* [Formatting](#formatting)
    * [Spacing and alignment](#spacing-and-alignment)
        * [References and pointers](#references-and-pointers)
        * [Namespaces](#namespaces)
        * [Brace location](#brace-location)
        * [`if-else` statement](#if-else-statement)
        * [`switch` statement](#switch-statement)
        * [Preprocessor directives](#preprocessor-directives)
    * [Naming conventions](#naming-conventions)
        * [Files](#files)
        * [Namespaces, Data Types, Enums and Constants](#namespaces-data-types-enums-and-constants)
        * [Variables](#variables)
        * [Methods and Functions](#methods-and-functions)
            * [Accessors](#accessors)
        * [Macro Definitions](#macro-definitions)
* [Files](#files)
    * [Declaration and implementation](#declaration-and-implementation)
    * [How to include header files](#how-to-include-header-files)
    * [Include guards](#include-guards)

## Intro

This standard describes the visual style of code for C++/Qt/QML projects, as well as the use of some idioms and programming patterns.

Following this standard is mandatory when writing new code.

It is also necessary to bring already written code to the standard, if work is being done with it.

This will increase the information content of the code while reading and facilitate its support, help to avoid common mistakes.

[Table Of Contents](#table-of-contents)



## Formatting



### Spacing and alignment

For indents **only spaces** should be used.

The IDE should use the indentation setting of **4 spaces**.

Wide and long code is hard to read. Code located on more than 3 levels should be divided into several functions.

Code lines which are longer than 120 characters must be split into several.

Logically different parts of the code should be separated by empty lines.

Spaces are required after (or around):
* after the keywords `if`, `else if`, `switch`, `for`, `while`, `return`;
* operators: arithmetic, comparison, logical, bitwise, compound assignment;
* characters `,` and `;` if this is not the end of the line.

Spaces are prohibited:
* after function names;
* between unary operators and their arguments.

Spaces can be added:
* around (inside) expressions enclosed in parentheses, braces, and angle brackets.

The `sizeof`,` alignof`, `countof` and similar operators can only be used with parentheses without a space in front of them.

&#x2705; Correct code:

```cpp
const size_t doubleSize = sizeof(double);

for (auto i = 0; i < count; ++i)
    container.append(i);

while (isGood && !isBad)
{
    const auto profit = getProfit();
    haveFun(profit);
}

qInfo() << "And we got the result: " << (x || y);

void foo(const int firstValue, const int lastValue)
{
    int x = -firstValue;
    x += lastValue;
}
```

&#x274C; Invalid code:

```cpp
const size_t doubleSize=sizeof (double);

for(auto i=0;i<count;++i)
    container.append(i);

if(isGood&&!isBad)
    haveFun(getProfit());

void foo (const int firstValue,const int lastValue);
```

[Table Of Contents](#table-of-contents)



### References and pointers

When declaring pointers and references, passing arguments to a function, the `*` and `&` characters must be bound to the data type.

&#x2705; Correct code:

```cpp
double value = 0.0;
double* valuePtr = &value;
double& valueRef = value;

Item* itemByName(const QString& name, bool* isAlone = nullptr);

typedef QVector<Item*> ItemsContainer;
```

&#x274C; Invalid code:

```cpp
double value = 0.0;
double * valuePtr = &value;
double &valueRef = value;

Item * itemByName(const QString &name, bool *isAlone = nullptr);

typedef QVector<Item *> ItemsContainer;
```

[Table Of Contents](#table-of-contents)



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

[Table Of Contents](#table-of-contents)



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
int calculateRow() { m_row = calculate(); return m_row; }
int row() const { return m_row; }
```

&#x274C; Invalid code:

```cpp
if (nullptr == item) return;
if (!object->isValid()) continue;
```

For an empty virtual destructor, curly brackets are allowed on the same line.
But it is preferable in this situation to use the keyword `default`.

&#x2705; Correct code:

```cpp
virtual ~MainWindow() {}
virtual ~MainWindow() = default;
```

[Table Of Contents](#table-of-contents)



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

[Table Of Contents](#table-of-contents)



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

[Table Of Contents](#table-of-contents)



### Preprocessor directives

The preprocessor directives must not be indented and must begin at the beginning of the line.

&#x2705; Correct code:

```cpp
int main()
{
    QApplication app();

#ifdef EXTRA_LOG
    qInfo() << "So, let go... we hope that everything will be fine...";
#endif // EXTRA_LOG

    return app.exec();
}
```

[Table Of Contents](#table-of-contents)



## Naming conventions

Names must comply with the following rules:

* The name should be compact and informative.
* The components of the name should not contain spelling errors.
* The same logical entities in the project should be called the same.
* Avoid using prepositions, conjunctions, articles in names.

Names should be as informative as is appropriate in order to describe the purpose and behavior of the entity.

Long names should be used for entities with a long lifetime and short names for entities with a short lifetime.

| Entity                  | Style                        | Example                      |
| ----------------------- | ---------------------------- | ---------------------------- |
| File                    | Lower Case                   | mainwindow.cpp, mainwindow.h |
| Type                    | Upper Camel Case             | MainWindow                   |
| Namespace               | Upper Camel Case             | Widgets                      |
| Constant                | Upper Camel Case             | MagicNumberConstant          |
| Enum                    | Upper Camel Case             | Qt::AlignmentFlag            |
| Function/method         | Lower Camel Case             | setValue()                   |
| Class member            | Lower Camel Case with Prefix | m_value, m_targetScore       |
| Variable                | Lower Camel Case             | value, targetScore           |
| Macro Definition        | Upper Case with Underscores  | FUNCTION_MAKER               |

[Table Of Contents](#table-of-contents)



### Files

File names should contain only lowercase characters.

All file names used in the code must be strictly case-sensitive to the names in the file system.

Examples of errors:

File name — `MainWindow.h`
In code: `#include "mainwindow.h"`

The path — `./Logs`
In code: `QString path = "./logs";`

&#x2705; Exceptions:
```
CMakeLists.txt
CONTRIBUTING.md
LICENSE
README.md
```
and QML Modules, for example `ModuleName.qml`

[Table Of Contents](#table-of-contents)



### Namespaces, Data Types, Enums and Constants

Names of namespaces, data types, enumeration values and constants must begin with an uppercase character, each new word in a type name must also begin with an uppercase character.

Names must not contain underscores.

&#x2705; Correct code:

```cpp
namespace DataLayer
{
}

class Logger;
struct MessageInfo;

enum Qt::SortOrder
{
    AscendingOrder = 0,
    DescendingOrder = 1,
};

typedef QVector<QVector<Item>> ItemMatrix;
```

[Table Of Contents](#table-of-contents)



### Variables

The first word in the variable name must begin with a lowercase character, and each subsequent word with a capital letter.

Class members must begin with the `m_` prefix.

It is not recommended to duplicate its type in the variable name, it is better to use the plural, in this case.

&#x2705; Correct code:

```cpp
QList<Items> items;
```

&#x274C; Invalid code:

```cpp
QList<Items> list;
```

[Table Of Contents](#table-of-contents)



### Methods and Functions

The names of methods and functions must be verbs.

&#x2705; Correct code:

```cpp
class LogicItem
{
public:
    void setValue(const QVariant& value);
    QVariant calculate() const;

public slots:
    void onTargetChanged();

};
```

[Table Of Contents](#table-of-contents)



#### Accessors

Setter names must begin with the `set` prefix.

Getter names are written without a prefix.

&#x2705; Correct code:

```cpp
class MegaLogicItem
{
public:
    void setValue(const QVariant& value);
    QVariant value() const;

private:
    QVariant m_value;
};
```

[Table Of Contents](#table-of-contents)



### Macro Definitions

Macro names must be written in all capital letters.

An underscore must be used as a word separator.

[Table Of Contents](#table-of-contents)



## Files

All files must use **UTF-8** encoding without BOM tags.

[Table Of Contents](#table-of-contents)



### Declaration and implementation

Declaration in h-files, implementation in cpp-files.

It is strongly discouraged to describe the implementation of classes/functions in the header files, which leads to greater coherence of the project files and unnecessary dependencies.

Header files should only provide information about the methods available, the classes and libraries used.

[Table Of Contents](#table-of-contents)



### How to include header files

Follow the specified order:

1. Main Framework Files (Qt for example)
1. Standard Library Files
1. Boost Files
1. External Library Files
1. Own Project Files

&#x2705; Correct code:

```cpp
#include <QHash>
#include <QDialog>

#include <map>
#include <vector>

#include <boost/algorithm/string.hpp>
#include <boost/numeric/ublas/vector.hpp>

#include <Poco/zlib.h>

#include "model.h"
#include "model_item.h"
```

[Table Of Contents](#table-of-contents)



### Include guards

All header files must have include guards.

Include guard format: `PATH_FILENAME_H`

&#x2705; Correct code for file `model/item.h`:

```cpp
#ifndef MODEL_ITEM_H
#define MODEL_ITEM_H

#endif // MODEL_ITEM_H
```

Only the file name and extension are allowed in the macro name.

It is allowed to use the `#pragma once` statement.

&#x2705; Correct code:

```cpp
#pragma once
```

[Table Of Contents](#table-of-contents)
