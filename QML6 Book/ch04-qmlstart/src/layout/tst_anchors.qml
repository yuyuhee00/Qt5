import QtTest

AnchorsExample {
    id: root

    TestCase {
        id: testCase
        name: 'anchors'
        when: windowShown

        property int shots: 0;

        function test_shoot() {
            root.grabToImage(function(result) {
                result.saveToFile("../../assets/anchorgrid.png");
                shots++;
            });
            tryCompare(testCase, "shots", 1);
        }
    }
}

