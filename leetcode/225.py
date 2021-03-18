# 225. Implement Stack using Queues

class MyStack:

    def __init__(self):
        self.q1 = []
        self.q2 = []
        

    def push(self, x: int) -> None:
        self.q1.append(x)
        

    def pop(self) -> int:
        if len(self.q2) == 0:
            while len(self.q1) != 1:
                self.q2.append(self.q1[0])
                self.q1.remove(self.q1[0])
            return self.q1.pop()
        else:
            while len(self.q2) != 1:
                self.q1.append(self.q2[0])
                self.q2.remove(self.q2[0])
            return self.q2.pop()
            

    def top(self) -> int:
        if len(self.q1) != 0:
            return self.q1[-1]
        else:
            return self.q2[-1]
        

    def empty(self) -> bool:
        return not (len(self.q1) or len(self.q2))

