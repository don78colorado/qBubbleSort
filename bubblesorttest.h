#ifndef BUBBLESORTTEST_H
#define BUBBLESORTTEST_H

#include <QtTest/QtTest>
#include "bubblesort.h"
class TestBubbleSort: public QObject
{
    Q_OBJECT
private slots:
    void initTestCase()
    { qDebug("called before everything else"); }
    void arrayTest();
    void stdArrayTest();
    void vectorTest();
    void cleanupTestCase()
    { qDebug("called after all tests"); }
};

#endif // BUBBLESORTTEST_H
