#include <iostream>
#include <iomanip>
#include <cmath>
#include "Book1.h"

using namespace std;

//STATIC VARIABLE
    //Initializes static variable that for the getNumberOfObjects() function
    int Book::numberOfObjects = 0;

//Book Class Implementation

//NO-ARG CONSTRUCTOR
    //Dynamically creates a "Book" object using the no-arg constructor "Book();" and assigns the object address to the pointer "pBook1".
    //All dynamically created object are stored on the heap.
    Book::Book() {
        pages = 1;
        chapters = 1;
        title = "Kujo";
        author = "Stephen King";
    }

//OVERLOADED CONSTRUCTOR
    //Dynamically creates an object using the constructor with arguments and assigns the object address to the pointer.
    Book::Book(int totalPages, int totalChapters, string ttle, string auth) {
        pages = totalPages;
        chapters = totalChapters;
        title = ttle;
        author = auth;
    }

//GET PAGES
    //Fetch the total number of pages in a book object.
    int Book::getPages() const {
        std::cout << "Number of pages: ";
        return pages;
    }

//GET CHAPTER
    //Fetch the total number of chapters in a book object.
    int Book::getChapter() const {
        std::cout << "Number of chapters: ";
        return chapters;
    }

//GET TITLE
    //Fetch the title of the book object.
    string Book::getTitle() const {
        std::cout << "Title: ";
        return title;
    }

//GET AUTHOR
    //Fetch the author of the book object.
    string Book::getAuthor() const {
        std::cout << "Author: ";
        return author;
    }

//ADD OR SUBTRACT PAGES
    //Add or subtract the number of pages in a book.
    void Book::addOrSubPages(int totalPages) {
        std::cout << "Enter the number of pages: ";
        cin >> totalPages;
        pages = totalPages;
    }

//ADD OR SUBTRACT CHAPTERS
    //Add or subtract the number of chapters in a book.
    void Book::addOrSubChapters(int totalChapters) {
        std::cout << "Enter the number of chapters: ";
        cin >> totalChapters;
        chapters = totalChapters;
    }

////CHANGE TITLE
//    //Change the title of the book.
//    string Book::changeTitle() {
//        std::cout << "Enter the title of the book: ";
//        string titl;
//        std::getline(std::cin, titl);
////        cin >> titl;
//        title = titl;
//        return title;
//    }

////CHANGE AUTHOR
//    //Change the name of the author.
//    string Book::changeAuthor() {
//        std::cout << "Enter the author of the book: ";
//        string auth;
//        std::getline(std::cin, auth);
////        cin >> auth;
//        author = auth;
//        return author;
//    }

//CLASSES, POINTERS AND THE HEAP

    void classesAndPointers() {

        Book Book0;

        Book0.addOrSubPages(0);
        Book0.addOrSubChapters(0);
//        Book0.changeTitle();
//        Book0.changeAuthor();
        std::cout << endl;

        std::cout << Book0.getTitle() << endl;
        std::cout << Book0.getAuthor() << endl;
        std::cout << Book0.getChapter() << endl;
        std::cout << Book0.getPages() << endl;

        cout << endl;

        Book Book1 (492, 27, "Game Of Thrones", "George R. R. Martin");

        std::cout << Book1.getTitle() << endl;
        std::cout << Book1.getAuthor() << endl;
        std::cout << Book1.getChapter() << endl;
        std::cout << Book1.getPages() << endl;

        cout << endl;

        Book* pBook2 = new Book(345, 21, "Hamlet", "William Shakespeare");

        //To access object members via a pointer, you must dereference the pointer and use the dot (.) operator to object’s members. For example:
        std::cout << (*pBook2).getTitle() << endl;
        std::cout << (*pBook2).getAuthor() << endl;
        //You can also use the "arrow" operator (which is easier to read) for the same purpose.
        std::cout << pBook2->getChapter() << endl;
        std::cout << pBook2->getPages() << endl;

        //Always remember to delete the memory in the heap to prevent memory leakage and reassign the pointer to null to prevent it from accessing that memory unintentionally.
        delete pBook2;
        pBook2 = nullptr;

    }

//POINTER BASICS PRINT

    void pointerBasics()
    {
//DECLARING, INITIALIZING AND UNDERSTANDING POINTERS
        //"int count" is initialized
        int count = 5;
        //"int* pCount" declares a pointer that holds the memory address of the variable "count".
        //When the ampersand (&) symbol is put in front of a variable, it works as the address operator and returns the variable's memory address instead of the value stored to that address. For example: (int count = 5), while (int &count = 0x7ffeebf75abc).
        //In essence, the pointer variable "points" to another variable's memory address. This can be seen in the example below.
        //The difference between &count and pCount is that &count is stored at the "0x7ffeebf75abc" memory address while pCount points TO &counts address. pCount is stored at it's own memory address.

        //Here's an illustration: (0x7ffeebf75ab0) = &pCount and *pCount -------(points to)--------> &count = (0x7ffeebf75abc)

        //This is the correct syntax for assigning a pointer to the memory address of a variable
        //Keep in mind, the pointer must be declared and assigned before it can be utilized (dereferenced). So when the pointer is assigned, the * acts as an assignment operator. The second time it is used, when you want to fetch the value the pointer is referencing, the * becomes a "dereference" operator.
        int* pCount = &count; // *pCount is a pointer for count

        //Another way to initialize a pointer is: pCount = &count;

        //The value stored in count's memory address gets printed.
        std::cout << "The value of count is " << count << endl; //Prints 5.
        //The memory address where the count variable is stored gets printed.
        std::cout << "The address of count is " << &count << endl; //Prints something like 0x7ffeebf75abc.
        //The memory address where the count variable is stored gets printed.
        std::cout << "The address of count is " << pCount << endl; //Prints something like 0x7ffeebf75abc.
        //The memory address of the pointer that "points to" the address the count variable is stored gets printed.
        std::cout << "The address of count is " << &pCount << endl; //Prints something like 0x7ffeebf75ab0.
        //Dereferences the pointer, fetches the count variable's value and prints it.
        std::cout << "The value of count is " << *pCount << endl; //Prints 5.

        std::cout << endl;

        //Using "direct reference" to increment the count variable.
        count++;
        std::cout << "Increment of count through direct reference = " << count << endl;

        //Using "indirect (pointer) reference" to increment the count variable.
        //*****NOTE******
        //Always remember to wrap the pointer in parenthesis. Because of conflicts due to operator precedence, the value at the memory address the pointer is pointing to needs to be fetched before the value can be incremented. Encasing the pointer in parenthesis will make that happen.
        (*pCount)++;
        std::cout << "Increment of count through indirect reference = " << count << endl;

//USING TYPEDEF TO DECLARE POINTERS
        //Redefine "int*" with typedef for easier readability
        typedef int* intPointer;

        //Don't forget the p variable
        intPointer p = &count;

        //The value stored in count's memory address gets printed.
        std::cout << "The value of count is " << count << endl;
        //The memory address where the count variable is stored gets printed.
        std::cout << "The address of count is " << &count << endl; //Prints something like 0x7ffeebf75abc.
        //The memory address where the count variable is stored gets printed.
        std::cout << "The address of count is " << p << endl; //Prints something like 0x7ffeebf75abc.
        //The memory address of the pointer that "points to" the address the count variable is stored gets printed.
        std::cout << "The address of the pointer that 'points to' the address the count variable is stored is " << &p << endl; //Prints something like 0x7ffeebf75ab0.
        //Dereferences the pointer, fetches the count variable's value and prints it.
        std::cout << "The value of count is " << *p << endl;

        std::cout << endl;

        //Using "direct reference" to increment the count variable.
        count++;
        std::cout << "Increment of count through direct reference = " << count << endl;

        //Using "indirect (pointer) reference" to increment the count variable.
        //*****NOTE******
        //Always remember to wrap the pointer in parenthesis. Because of conflicts due to operator precedence, the value at the memory address the pointer is pointing to needs to be fetched before the value can be incremented. Encasing the pointer in parenthesis will make that happen.
        (*p)++;
        std::cout << "Increment of count through indirect reference = " << count << endl;

        std::cout << endl;

        double number = 17.53;

        //Redefine double* with typedef for easier readability
        typedef double* doublePointer1;

        //Don't forget the p variable
        doublePointer1 p1 = &number;

        //The value stored in count's memory address gets printed.
        std::cout << "The value of count is " << number << endl;
        //The memory address where the count variable is stored gets printed.
        std::cout << "The address of count is " << &number << endl; //Prints something like 0x7ffeebf75abc.
        //The memory address where the count variable is stored gets printed.
        std::cout << "The address of count is " << p1 << endl; //Prints something like 0x7ffeebf75abc.
        //The memory address of the pointer that "points to" the address the count variable is stored gets printed.
        std::cout << "The address of the pointer that 'points to' the address the count variable is stored is " << &p1 << endl; //Prints something like 0x7ffeebf75ab0.
        //Dereferences the pointer, fetches the count variable's value and prints it.
        std::cout << "The value of count is " << *p1 << endl;

        std::cout << endl;

        //Using "direct reference" to increment the count variable.
        number += 27.91;
        std::cout << "Increment of count through direct reference = " << number << endl;

        //Using "indirect (pointer) reference" to increment the count variable.
        //*****NOTE******
        //Always remember to wrap the pointer in parenthesis. Because of conflicts due to operator precedence, the value at the memory address the pointer is pointing to needs to be fetched before the value can be incremented. Encasing the pointer in parenthesis will make that happen.
        (*p1) += 27.91;
        std::cout << "Increment of count through indirect reference = " << *p1 << endl;
        std::cout << "Variable value and pointer functionality check: number = " << number << endl;

//POINTERS OF POINTERS
        //Redefine double** with typedef for easier readability
        typedef double** doublePointer2;
        //The line below (doublePointer2 p2 = &p1;) is the same as "double** p2 = &p1" which declares/assigns a pointer (p2) that point to another pointer. Or more correctly, it "points to"/stores the memory address of another pointer (p1).
        //Here's an illustration: (0x7ffeebf75ab0) = &p2 -------(points to)--------> &p1 = (0x7ffeebf75abc)
        //*******NOTE********
        //The double asterisk (**) in "double** p2" means: **p2 -------(points to)--------> (the value stored in) *p1, which -------(points to)--------> (the value stored in) "number".
        //Think of the number of asterisks as "levels of dereference". We can make pointers with as many levels pointing back to as many pointers as we want.
        //*******WARNING******
        //If you have a pointer that points back (dereferences) to more levels than there are (for example: double*** p2 ---> double* p1 --> number --> ???), OR if you a pointer pointing back further than it is situated in the chain (for example: you've declared double**p2, but by accident you code something like "cout << ***p2 << endl;"), bad things might happen. For this reason, when I create a pointer typedef, I add a number at the end to denote how many levels (# of *) the pointer looks back. You can look to my previous typedefs (doublePointer1 and doublePointer2) as examples: double* (one * means one level) = doublePointer1 (the 1 digit denotes the number of * (dereference levels) that it points back.
        doublePointer2 p2 = &p1;

        //The value stored in the memory address of the pointer (p1) gets printed, which should be the address of the variable p1 points to (number).
        std::cout << "The value stored in the memory location that *p2 (one dereference level back) points to is " << *p2 << endl;
        //The value stored in the memory address that pointer p1 points to gets printed, which should be the value stored in "number".
        std::cout << "The value stored in the memory location that **p2 (two dereference levels back) points to is " << **p2 << endl;
        //Lets check and confirm that the address of "number" which is stored in p1 is the same address that **p2 points to.
        std::cout << "The value pointed to by *p2 is: " << *p2 << ", which is equal to the address pointed to by p1, (which also equals: " << p1 << "), is the same as the memory addres of 'number', which is: " << &number << endl;

        std::cout << endl;

//NULL POINTERS
        //In some situations, you may want a pointer to point at "nothing".
        //Perhaps you'd only want a pointer to point to a certain address if the value in that address reaches a certain threshold, like and "on/off" binary switch. When the switch is off, the value in that locations memory may be something that you do not want the pointer to point to. So, rather than have it point to any random address while it's not being used, you can have it point to nothing, which is the...point of the null pointer ("nullptr").
        //The purpose is to keep your data safe from any unexpected manipulations due to wayward pointers.

        //Let's go back and make p2 a null pointer.
        p2 = nullptr;

        //The address that p2 is pointing to now should print out as 0x0, which is an "empty" address.
        std::cout << "The address pointed to by p2 is " << p2 << endl; //Prints 0x0

        std::cout << endl;

//POINTERS AND FUNCTIONS
        //Due to not being allowed to define functions inside of functions, I decided to leave a commented out copies of the "doubleVariablePassByValue", "doubleVariablePassByReference", and "doubleVariablePassByPointer" functions for convenience. I put the working copies in the Circle3 header file.

//        void doubleVariablePassByValue(int x) {
//            x = x * 2;
//        }

//        //C++ style
//        void doubleVariablePassByReference(int& x) {
//            x = x * 2;
//        }

//        //C style
//        void doubleVariablePassByPointer(int* x) {
//            Here are the steps:
//                /*
//                1. (num) as seen below, passes the num's address to (int* x)
//                2. (*x) dereferences the value stored at num's address
//                3. That value is then processed (multiplied by 2, in this case)
//                4. The processed value is the assigned (by the assignment "=" operator) to the memory location of num, which is pointed to by *x.
//                Here's an illustration:
//                address of num = (&num) ---gets passed to---> pointer to num address = (int* x)  ---gets passed to---> (*x) which then deferences the variable which then ---gets multiplied by---> 2, which then ---gets assigned to---> *x, which points back to and ---passes the result to---> the memory location of num, which changes it's original value to the result of the function.
//                */
//            //Remember that due to operator precedence, we have encase the "*x" pointer in parenthesis.
//            *x = (*x) * 2;
//        }

        int num = 10;
        //Print the initialized value of num.
        std::cout << "The initial value of num is " << num << endl;
        //The function doubleVariablePassByValue(); passes the num parameter by value.
        //Recall that passing a parameter by value makes a copy of the variable that is being passed and THEN process that copy. Since only the copy is being processed, no changes are renderred to the original. And once the function is done doing it's thing, the processed copy ceases to be. This is not what we want if our goal is to make changes to a variable. For that, we'd need to pass the variable by reference, or by pointer.
        doubleVariablePassByValue(num);
        std::cout << "The value of num (actual) when passed to a function by value is still " << num << endl;
        //The function doubleVariablePassByReference(); passes the num parameter by reference.
        //Recall that passing a parameter by reference creates a direct path to the variable itself for processing. Any changes made by the function are made to the variable directly. If our goal is to use a function to process and return data, this is the way to go.
        //Since the creators of C++ added "pass by reference" as an "alternative" to using pointers, it is recommended that you only use "pass by reference" unless you HAVE TO use pointers...or when the homework mandates it.
        //Process and print num.
        doubleVariablePassByReference(num);
        std::cout << "The value of num when passed to the function by reference is " << num << endl;
        //The function doubleVariablePassByPointer(); passes the num parameter by pointer, which is how things are done in C programming.
        //"pass by reference" and "pass by pointer" accomplish pretty much the same task. However, "pass by pointer" can get more complicated, especially when memory management is concerned. Like I mentioned above, only use pointers when you have to.
        //Process and print num.
        //The argument parameter is written "&num" because it passes the address of the num variable to the pointer (int* x) in the function parameter. See above for a more detailed explanation.
        doubleVariablePassByPointer(&num);
        std::cout << "The value of num when passed to the function by pointer is " << num << endl;

        std::cout << endl;
    }


//DYNAMIC MEMORY ADDRESSING

    void dynamicMemory()
    {
//RETURN POINTERS
            //It is possible to return an address from a function.
            //The addressOfSmaller() function call passes the addresses of two variables (num1, num2) to the main addressOfSmaller() function that then uses an if statement that compares the dereferenced values (read: stored values in memory) and then returns the memory address of the smaller variable. This is useful for dynamic memory allocation.
            //Initialize both int variables that are to be used in the addressOfSmaller() function.
            int num1 = 5;
            int num2 = 10;
            //Declare and initialize the pointer variable (pSmall) that is to be assigned the address of the smaller int variable (num1 or num2) processed by the addressOfSmaller() function.
            int* pSmall = addressOfSmaller(&num1, &num2);
            //Print the result
            std::cout << "The smaller address between " << &num1 << " and " << &num2 << " is " << pSmall << endl;

            std::cout << endl;

//MEMORY MANAGEMENT
            //Function that demonstrates why dynamic memory allocation is important.
            //Declare and initialize the pointer variable (pTen) that is to point to the address of "int x" when the getBadPointer function is called.
            //The function allocates memory for "int x" and pointer variable "int* px" that holds the address of "int x" (both seen in function body) and then returns the address of "int x" (through px) to be assigned to the pointer variable "*pTen".
            int* pTen1 = getBadPointer();
            //The std::cout statement dereferences the *pTen pointer and prints the value of the variable stored in the address that *pTen was pointing to (&x). Once it is done printing, the address that the "int x" (which resides within the scope of the getBadPointer() function only) value was stored to gets erased so that it can reallocated for future use.
            std::cout << "The value stored at memory address " << pTen1 << " is " << *pTen1 << endl;
            //Since the x value is no longer stored in memory, the pointer *pTen is now pointing to unknown/random/unrelated data. So, as a result, the second time the pointer *pTen gets printed, a different value gets printed than the first time.
            //*****NOTE*****
            //Sometimes when I compile and run this function multiple times, the memory does want to take the x value initialized within the getBadPointer function. I don't know what that about, but sometimes, it will print out the same random value both times. It's weird...but trust me, this solution works.
            std::cout << "The reprinted value stored at memory address " << pTen1 << " is now " << *pTen1 << endl;

            std::cout << endl;

            //This function demonstrates how memory in the "heap" can be utilized for dynamic allocation of resources.
            //Reassigns the pointer variable (pTen) to a memory address in the heap.
            int* pTen2 = getGoodPointerToTen();
            //Like above, the std::cout statement dereferences the *pTen pointer and prints the value of the variable stored in the address that that is now in the heap.
            std::cout << "The value stored at memory address " << pTen2 << " is " << *pTen2 << endl;
            //Since memory on the heap can only be accessed explicity by the pointer and does not get erased, reallocated or overwritten once the function that is using it is done with it, it remains stored in the address ready to be used again. So, the second time the dereferenced pointer (*pTen) gets printed, it prints the same value as the previous "cout" statement.
            std::cout << "The reprinted value stored at memory address " << pTen2 << " is still " << *pTen2 << endl;
            //*****WARNING*****
            //Since the memory stored in the heap can only be accessed by a pointer, if said pointer were to cease to exist, that chunk of memory will sit there taking up with no way to access or erase it until the program is closed. Do this enough times, and with enough memory, and you will eventually run low on memory and notice your program slowing down. This is what a memory leak is.
            //How do we keep this from becoming a problem? Keep reading.
            std::cout << endl;

//CLEANING THINGS UP
            //In order to prevent memory and problems stemming from them we need to tell the registry to delete the data stored in the heap when we are done using it. We do this with the "delete" command (see below).
            //The delete command clears the memory in the heap so that it can be utilized in the future. Doing this every time will prevent unusable memory from piling up and causing problems down the road.
            delete pTen2;

            //In addition, since the pointer (*pTen) probably still has access to the memory address in the heap that we just cleared, it is a good idea to nullify it in order to prevent it from accessing that memory address by accident. We do this by reassigning it with the "nullptr".
            //With these two things taken care, we have less potential issues stemming from memory allocation to worry about.
            pTen2 = nullptr;

//ARRAYS AND NEW
            //An array is similar to a pointer in that it points to a memory address.
            //Declares an array of integers with 5 initialized elements that will be stored in the stack.
            int nums[5] = {1, 2, 3, 4, 5};
            //Stores the address of the array (nums) in pointer "pToArray". Now we can use the pointer the same way we can use an array.
            int* pToArray = nums;
            //Use for-loop to print every element of nums array.
            std::cout << "List of elements of nums array : ";
            for (int i = 0; i < 5; i++) {
                std::cout << pToArray[i];
                if (i < 4) {
                    std::cout << ", ";
                }
            }

            std::cout << endl;
            std::cout << endl;

            //Arrays stored in the stack have to be a designated size. Arrays stored in the heap can be any size we want, AND that size can change whenever we want.
            //We're going to build a dynamic array (stored in the heap) with a user defined number of elements (listSize).
            int listSize;
            //Prompts user to enter the number of elements in the array.
            std::cout << "How many elements would you like in your dynamic array? ";
            std::cin >> listSize;
            std::cout << endl;
            //Initialize array in heap with "new".
            int* nums2 = new int[listSize];
            //Populate and prints array with for-loop.
            std::cout << "List of elements in dynamic array:" << endl;
            for (int i = 0; i < listSize; i++) {
                nums2[i] = i + 1;
                std::cout << nums2[i];
                if (i < listSize - 1) {
                    std::cout << ", ";
                }
            }

            std::cout << endl;
            std::cout << endl;

            //Now, we're going to print out the dynamic array we just made, but in reverse order using the reverse function (see below).
            std::cout << "List of elements in reversed dynamic array:" << endl;
            int* backwards = reverse(nums2, listSize);
            for(int i = 0; i < listSize; i++) {
                std::cout << backwards[i];
                if (i < listSize - 1) {
                    std::cout << ", ";
                }
            }

            std::cout << endl;
            std::cout << endl;

            std::cout << "The memory address of the pointer 'backwards' is " << backwards << endl;

            std::cout << endl;

//CLEAN UP AN ARRAY
            //Frees up memory used by nums2
            delete[] nums2;

            //Clears nums2 pointer
            nums2 = nullptr;

//CREATING AND ACCESSING DYNAMIC OBJECTS

    }

//PASS BY VALUE FUNCTION
    void doubleVariablePassByValue(int x) {
        x = x * 2;
        //Since passing by value leaves the original variable unchanged and eventually erases the processed copy, we will print the copy now before it gets erased.
        std::cout << "The value of num (copy) after proccessing by a pass by value function is " << x << endl;
    }

//PASS BY REFERENCE FUNCTION
    //C++ style
    void doubleVariablePassByReference(int& x) {
        x = x * 2;
    }

//PASS BY POINTER FUNCTION
    //C style
    void doubleVariablePassByPointer(int* x) {
        //Remember that due to operator precedence, we have encase the "*x" pointer in parenthesis.
        *x = (*x) * 2;
    }


//RETURN THE ADDRESS OF A FUNCTION
    //Take two addresses and return the one with the smaller value variable.
    int* addressOfSmaller(int* x, int* y) {
        //Compare values at the address
        if ((*x) < (*y))
            return x;
        else
            return y;
    }

//DEMONSTRATE WHAT HAPPENS TO MEMORY WITHIN THE STACK
    int* getBadPointer() {
        int x = 10;
        int* px = &x;
        return px;
    }

//DEMONSTRATE HOW TO USE MEMORY IN THE HEAP
    int* getGoodPointerToTen() {
        //Allocates space on the heap where the *px variable can be stored.
        int* py = new int;
        *py = 10;
        return py;
    }

//RETURNING A DYNAMIC ARRAY
    //Function that takes in a array pointer (from the heap) and returns the array in reverse order.
    int* reverse(const int* list, int size) {
        int* result = new int[size];
        int reverseIndex = size - 1;
        for (int i = 0; i < size; i++) {
            result[reverseIndex] = list[i];
            reverseIndex--;
        }
        return result;
    }


//WEEK-3 EXECUTION

    void executeWeekThree() {

        std::cout << endl;
        std::cout << "Week 3" << endl;
        std::cout << endl;
        std::cout << "Pointer Basics:" << endl;
        std::cout << endl;
        pointerBasics();
        std::cout << "Dynamic Memory Addressing: " << endl;
        std::cout << endl;
        dynamicMemory();
        std::cout << "Classes, Pointers and The Heap: " << endl;
        std::cout << endl;
        classesAndPointers();

}
