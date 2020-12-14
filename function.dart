int calculate(int op1, int op2, {String op = "+"}) {
  switch (op) {
    case "-":
      return op1 - op2;
      break;
    case "*":
      return op1 * op2;
      break;
    case "/":
      return op1 ~/ op2;
      break;
    default:
      return op1 + op2;
  }
}

void main(List<String> args) {
  var testCases = [
    [10, 20, "-"],
    [30, 2, "/"],
    [43, 4, "*"],
  ];
  testCases.where((ele) => ele.length < 4)?.first;
  testCases.forEach((ele) => print(
      " ${ele[0]} ${ele[2]} ${ele[1]} = ${calculate(ele[0], ele[1], op: ele[2])}"));
}
