#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <QString>
#include <QTextStream>
#include <QStringList>
#include "bubblesort.h"
#include "bubblesorttest.h"
#include "time.h"

static QTextStream cout(stdout);

template <class InputIterator>
void print(InputIterator begin, InputIterator end)
{
    cout << "{";
    --end;
    while(begin!=end)
        cout << *(begin++) << ", ";
    cout << *end << "}\n";
    cout.flush();
}


int main(int argc, char *argv[])
{
    TestBubbleSort t;
    QTest::qExec(&t);

#if 0
    QCoreApplication a(argc, argv);

    const int randomListLength = 10;
    const int maxRandomNumber = 100;
    srand(time(NULL));

    QList<int> staticList, staticListCopy, randomList, randomListCopy;
    staticList << 5 << 10 << 60 << 2 << 1243 << 2343 << 12 << 2354 << 6654 << 23 << 1;

    QStringList stringList;
    stringList << "Billy" << "James" << "Herman" << "dog" << "cat" << "zebra" << "horse" << "Peter" << "Sam" << "piano";
    QStringList stringListCopy(stringList);
    cout << "staticList: ";
    print(staticList.begin(), staticList.end());
    using namespace std;

    cout << "staticListCopy: ";
    copy(staticList.begin(), staticList.end(), back_insert_iterator< QList<int> >(staticListCopy));
    print(staticListCopy.begin(), staticListCopy.end());

    /*generate_n(back_insert_iterator< QList<int> >(randomList),
               randomListLength, []() { return rand()%(maxRandomNumber+1); });
               */
    for(int i = 0; i < randomListLength; i++)
        randomList.append(rand()%(maxRandomNumber+1));
    cout << "randomList: ";
    print(randomList.begin(), randomList.end());

    cout << "randomListCopy: ";
    copy(randomList.begin(), randomList.end(), back_insert_iterator< QList<int> >(randomListCopy));
    print(randomListCopy.begin(), randomListCopy.end());

    bubbleSort(staticList.begin(), staticList.end());
    qSort(staticListCopy);

    bubbleSort(randomList.begin()+1, randomList.end()-1);
    qSort(randomListCopy.begin()+1, randomListCopy.end()-1);

    cout << "bubbleSort(staticList.begin(), staticList.end());: ";
    print(staticList.begin(), staticList.end());
    cout << "qSort(staticListCopy);: ";
    print(staticListCopy.begin(), staticListCopy.end());
    cout << "bubbleSort(randomList.begin()+1, randomList.end()-1): ";
    print(randomList.begin(), randomList.end());
    cout << "qSort(randomListCopy.begin()+1, randomListCopy.end()-1): ";
    print(randomListCopy.begin(), randomListCopy.end());

    staticList==staticListCopy ? cout << "staticList==staticListCopy\n" : cout << "staticList!=staticListCopy\n";
    randomList==randomListCopy ? cout << "randomList==randomListCopy\n" : cout << "randomList!=randomListCopy\n";


    cout << "\n\n\nstringList: ";
    print(stringList.begin(), stringList.end());

    cout << "calling bubbleSort on stringList\n";
    bubbleSort(stringList.begin(), stringList.end());

    cout << "stringListCopy: ";
    print(stringListCopy.begin(), stringListCopy.end());
    cout << "stringList: ";
    print(stringList.begin(), stringList.end());

    cout << "calling qSort on stringListCopy\n";
    qSort(stringListCopy.begin(), stringListCopy.end());
    cout << "stringListCopy: ";
    print(stringListCopy.begin(), stringListCopy.end());

    stringList==stringListCopy ? cout << "stringList==stringListCopy\n" : cout << "stringList!=stringListCopy\n";
    cout.flush();
    return a.exec();
#endif
}
