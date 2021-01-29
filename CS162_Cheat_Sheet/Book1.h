#ifndef BOOK1_H
#define BOOK1_H

#include <string>

class Book {
public:

    //CONSTRUCTORS
    Book();
    Book(int totalPages, int totalChapters, std::string title, std::string author);

    //BEHAVIORS - ACCESSOR FUNCTIONS
    int getPages() const;
    int getChapter() const;
    std::string getTitle() const;
    std::string getAuthor() const;

    //BEHAVIORS - MUTATOR FUNCTIONS
    void addOrSubPages(int totalPages);
    void addOrSubChapters(int totalChapters);
//    std::string changeTitle();
//    std::string changeAuthor();

private:

    //STATE - PROPERTIES
    int pages;
    int chapters;
    std::string author;
    std::string title;

    static int numberOfObjects;

};

void classesAndPointers();

void pointerBasics();

void dynamicMemory();

void doubleVariablePassByValue(int x);

void doubleVariablePassByReference(int& x);

void doubleVariablePassByPointer(int* x);

int* addressOfSmaller(int* x, int* y);

int* getBadPointer();

int* getGoodPointerToTen();

int* reverse(const int* list, int size);


//Function that runs all Week-3 code.
void executeWeekThree();

#endif // BOOK1_H
