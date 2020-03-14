# Python multithreading example to print current date.
# 1. Define a subclass using threading.Thread class.
# 2. Instantiate the subclass and trigger the thread.

import threading
import datetime


class MyThread(threading.Thread):
    def __init__(self, name, counter):
        threading.Thread.__init__(self)
        self.threadID = counter
        self.name = name
        self.counter = counter

    def run(self):
        print("\nStarting " + self.name)
        i = 0
        while i < 5:
            print_date(self.name, self.counter)
            i = i + 1

        print("Exiting " + self.name)


def print_date(thread_name, counter):
    datefields = []
    today = datetime.datetime.now()
    datefields.append(today)
    print("{}[{}]: {}".format(thread_name, counter, datefields[0]))


# Create new threads
thread1 = MyThread("Thread", 1)
thread2 = MyThread("Thread", 2)

# Start new Threads
thread1.start()
thread2.start()

thread1.join()
thread2.join()

print("\nExiting the Program!!!")
