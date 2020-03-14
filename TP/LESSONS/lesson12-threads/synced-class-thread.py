# Python multithreading example to demonstrate locking.
# 1. Define a subclass using threading.Thread class.
# 2. Instantiate the subclass and trigger the thread.
# 3. Implement locks in thread's run method.

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
        # Acquire lock to synchronize thread
        thread_lock.acquire()

        i = 0
        while i < 15:
            print_date(self.name, self.counter)
            i = i + 1

        # Release lock for the next thread
        thread_lock.release()
        print("Exiting " + self.name)


def print_date(thread_name, counter):
    datefields = []
    today = datetime.date.today()
    datefields.append(today)
    print("{}[{}]: {}".format(thread_name, counter, datefields[0]))


thread_lock = threading.Lock()
threads = []

# Create new threads
thread1 = MyThread("Thread", 1)
thread2 = MyThread("Thread", 2)

# Start new Threads
thread1.start()
thread2.start()

# Add threads to thread list
threads.append(thread1)
threads.append(thread2)

# Wait for all threads to complete
for thread in threads:
    thread.join()

print("\nExiting the Program!!!")
