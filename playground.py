class A:
    def __init__(self):
        self.a=666

    def A_print(self):
        print(B().b+1)

class B:
    def __init__(self):
        self.b=3

    def B_print(self):
        print(A().a+1)

a = A()
a.A_print()