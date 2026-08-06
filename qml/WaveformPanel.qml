import QtQuick 2.15

Item {
    property string label
    property string unit
    property real value
    property string annotation: ""
    property color traceColor

    
    Text {
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 8
        text: label
        color: traceColor
        font.pixelSize: parent.height * 0.15
        font.bold: true
    }

    
    Text {
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.margins: 8
        text: value.toFixed(value === Math.floor(value) ? 0 : 1) + " " + unit
        color: traceColor
        font.pixelSize: parent.height * 0.25
        font.bold: true
    }

    
    Text {
        visible: annotation !== ""
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.margins: 8
        text: annotation
        color: traceColor
        font.pixelSize: parent.height * 0.12
        opacity: 0.7
    }
}