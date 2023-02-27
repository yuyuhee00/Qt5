import QtTest

Showcase {
    id: root

    TestCase {
        id: testCase

        property int shots: 0

        name: 'showcase'
        when: windowShown

        function test_shoot() {
            var shoot = false
            root.grabToImage(function(result) {
                result.saveToFile("../../assets/showcase.png")
                shots++
            })
            mouseClick(root)
            mouseClick(root)
            mouseClick(root)
            mouseClick(root)
            wait(100)
            root.grabToImage(function(result) {
                result.saveToFile("../../assets/showcase2.png")
                shots++
            })
            wait(100)
            root.grabToImage(function(result) {
                result.saveToFile("../../assets/showcase3.png")
                shots++
            })
            wait(100)
            root.grabToImage(function(result) {
                result.saveToFile("../../assets/showcase4.png")
                shots++
            })
            tryCompare(testCase, "shots", 4)
        }
    }
}

