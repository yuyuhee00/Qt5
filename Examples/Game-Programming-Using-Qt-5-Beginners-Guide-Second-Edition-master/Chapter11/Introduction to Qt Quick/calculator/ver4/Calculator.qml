import QtQuick 2.4

CalculatorForm {
    state: {
        if (operationFactorial.checked) {
            return "single_argument";
        } else {
            return "";
        }
    }
    transitions: Transition {
        PropertyAnimation {
            property: "opacity"
            duration: 300
        }
    }
    reset.onClicked: {
        argument1.text = "0";
        argument2.text = "0";
        operationAdd.checked = true;
    }
    result.text: {
        var value1 = parseFloat(argument1.text);
        var value2 = parseFloat(argument2.text);
        if(operationMultiply.checked) {
            return value1 * value2;
        } else if (operationFactorial.checked) {
            return advancedCalculator.factorial(value1);
        } else {
            return value1 + value2;
        }
    }
}
