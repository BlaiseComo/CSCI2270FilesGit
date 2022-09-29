#include "WaitlistQueue.hpp"

using namespace std;

WaitlistQueue::WaitlistQueue(int qSize)
{
    /* Already implemented, don't change */
    qFront = qEnd = -1;
    qCapacity = qSize;
    queue = new string[qSize];
}

WaitlistQueue::~WaitlistQueue()
{
    //TODO
    delete [] queue;
}

void WaitlistQueue::enqueue(string value)
{
    //TODO
    int arraySize = size();

    if (arraySize == qCapacity) {
        cout << "Waitlist if full. Cannot enqueue." << endl;
        return;
    }

    if (qFront == -1 && qEnd == -1) {
        qEnd = qFront = 0; 
        queue[0] = value;
    }
    else if (qEnd+1 == qCapacity) {
        queue[0] = value;
        qEnd = 0;
    }
    else {
        queue[qEnd+1] = value;
        qEnd++;
    }

}

void WaitlistQueue::dequeue()
{
    //TODO
    if (size() == 0) {
        cout << "Waitlist is empty. Cannot dequeue." << endl;
        return;
    }
    else if (size() == 1) {
        queue[qFront] = "";
        qFront = -1;
        qEnd = -1;
    }
    else {
        queue[qFront] = "";
        qFront++;
    }

}

string WaitlistQueue::peek()
{
    //TODO
    if (size() == 0) {
        return "<EMPTY QUEUE>";
    }
    else {
        return queue[qFront];
    }
    return "";
}

void WaitlistQueue::resize(int newSize)
{
    //TODO
    string tempArray[qCapacity];
    int count = 0;
    for (int i = qFront; i < qCapacity; i++) {
        if (i == qEnd) {
            break;
        }
        tempArray[count] = queue[i];
        count++;
    }

    int count2 = 0;

    if (count < size()) {
        for (int i = 0; i < qEnd; i++) {
            tempArray[count+i] = queue[i];
            count2++;
        }
    }

    qFront = 0;
    qEnd = count+count2;

    string* queue = new string[newSize];
    qCapacity = newSize;

    for (int i = 0; i < qEnd; i++) {
        queue[i] = tempArray[i];
    }

}

int WaitlistQueue::size()
{
    //TODO
    int arraySize = 0;

    for (int i = 0; i < qCapacity; i++) {
        if (queue[i] != "") {
            arraySize++;
        }
    }
    return arraySize;
}

int WaitlistQueue::capacity()
{
    //TODO
    return qCapacity;
}

bool WaitlistQueue::isEmpty()
{
    //TODO
    if (size() == 0) {
        return true;
    }
    return false;
}

bool WaitlistQueue::isFull()
{
    //TODO
    if (size() == qCapacity) {
        return true;
    }
    return false;
}