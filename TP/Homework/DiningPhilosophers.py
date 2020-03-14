import threading
import time


class Philosophers(threading.Thread):
    def __init__(self, name, leftFork, rightFork):
        threading.Thread.__init__(self)
        self.name = name
        self.leftFork = leftFork
        self.rightFork = rightFork

    def run(self):
        while True:
            time.sleep(3.0)
            print('Philosopher', self.name, 'is hungry.')
            self.dining()

    def dining(self):
        left = self.leftFork
        right = self.rightFork
        while True:
            left.acquire()
            right.acquire()
            if right.acquire:
                break
            left.release()

        print('Philosopher', self.name, 'starts eating.')
        time.sleep(12.0)
        print('Philosopher', self.name, 'finishes eating and goes to think.')
        left.release()
        right.release()


def sit_on_the_table():
    forks = [threading.Lock() for i in range(5)]

    philosopheres = []

    philosopheres.append(Philosophers('Aristotel', forks[0], forks[1]))
    philosopheres.append(Philosophers('Epikur', forks[1], forks[2]))
    philosopheres.append(Philosophers('Demokrit', forks[2], forks[3]))
    philosopheres.append(Philosophers('Sokrat', forks[3], forks[4]))
    philosopheres.append(Philosophers('Heraklit', forks[4], forks[0]))

    return philosopheres


philosopheres = sit_on_the_table()
for i in philosopheres:
    i.start()
time.sleep(15.0)
for i in philosopheres:
    i.join()
