from simplestack import Stack


class PostFixEvaluation:
    def __init__(self):
        self.s = Stack(20)

    def evaluate(self, exp):
        for e in exp:
            if e.isdigit():
                self.s.push(e)
            elif e.isalpha():
                value = int(input('Enter value of alphabet:'))
                self.s.push(value)

            else:
                op1 = self.s.pop()
                op2 = self.s.pop()

                if e == '+':
                    r = op1 + op2
                elif e == '-':
                    r = op2 - op1
                elif e == '*':
                    r = op2 * op1
                elif e == '/':
                    r = op2 / op1
                elif e == '**':
                    r = op2 ** op1
                else:
                    print('Wrong')

                self.s.push(r)
        return self.s.pop()


a = PostFixEvaluation()
print('Postfix Expression Evaluator')
exp = input('Enter the postfix expression:')
re = a.evaluate(exp)
print(f'Your Final Output is {re}')
