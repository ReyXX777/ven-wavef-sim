import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    visible: true
    width: Screen.width * 0.9   // Start at 90% of screen width
    height: Screen.height * 0.9 // Start at 90% of screen height
    minimumWidth: 800           // Enforce minimum usable size
    minimumHeight: 600
    title: "Ventilator Monitor"
    color: "#050505"

    
    Rectangle {
        id: topBar
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: parent.height * 0.06
        color: "#1a1a1a"
        border.color: "#333333"
        border.width: Math.max(1, parent.height * 0.002)
        
        Text {
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            anchors.leftMargin: parent.width * 0.015
            text: "PAT-2026-XXXX  14:28"
            color: "#ffffff"
            font.pixelSize: Math.max(12, parent.height * 0.45)
            font.bold: true
        }
        Text {
            anchors.centerIn: parent
            text: "Normal Operation"
            color: "#00ff00"
            font.pixelSize: Math.max(12, parent.height * 0.45)
            font.bold: true
        }
        Row {
    anchors.right: parent.right
    anchors.verticalCenter: parent.verticalCenter
    anchors.rightMargin: parent.width * 0.015
    spacing: parent.width * 0.01

    
    Rectangle {
        width: parent.parent.height * 0.5
        height: parent.parent.height * 0.35
        radius: 2
        anchors.verticalCenter: parent.verticalCenter
        color: waveformModel.batteryLevel > 50 ? "#00ff00" 
               : waveformModel.batteryLevel > 20 ? "#ffd700" 
               : "#ff3333"

        Rectangle {
            anchors.left: parent.right
            anchors.verticalCenter: parent.verticalCenter
            width: parent.height * 0.2
            height: parent.height * 0.4
            radius: 1
            color: parent.color
        }
    }

    
    Canvas {
        id: wifiCanvas
        width: parent.parent.height * 0.45
        height: parent.parent.height * 0.35
        anchors.verticalCenter: parent.verticalCenter

        property int signalStrength: waveformModel.wifiStrength

        onSignalStrengthChanged: requestPaint()

        onPaint: {
            var ctx = getContext("2d");
            ctx.reset();

            var centerX = width / 2;
            var centerY = height * 0.95; // Origin near the bottom center
            var maxRadius = height * 0.85;
            var numArcs = 4;
            var angleStart = -Math.PI * 0.75;
            var angleEnd = -Math.PI * 0.25;
            var lineWidth = maxRadius / (numArcs * 2);

            var activeColor = signalStrength >= 3 ? "#ffffff" 
                            : signalStrength >= 2 ? "#ffd700" 
                            : "#ff3333";
            var inactiveColor = "#40ffffff"; // Dimmed background arc

            ctx.lineCap = "round";

            
            ctx.beginPath();
            ctx.fillStyle = (signalStrength >= 1) ? activeColor : inactiveColor;
            ctx.arc(centerX, centerY, lineWidth / 1.2, 0, Math.PI * 2);
            ctx.fill();

            
            for (var i = 1; i < numArcs; i++) {
                var r = (maxRadius / (numArcs - 1)) * i;
                ctx.beginPath();
                ctx.strokeStyle = (i < signalStrength) ? activeColor : inactiveColor;
                ctx.lineWidth = lineWidth;
                ctx.arc(centerX, centerY, r, angleStart, angleEnd, false);
                ctx.stroke();
            }
        }
    }
}
    }

        
    Rectangle {
        id: bottomBar
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: parent.height * 0.12
        color: "#1a1a1a"
        border.color: "#333333"
        border.width: Math.max(1, parent.height * 0.002)
        
        
        Item {
            anchors.fill: parent
            anchors.margins: parent.height * 0.015
            
            
            Column {
                id: controlsColumn
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                width: parent.width * 0.45
                spacing: parent.height * 0.08
                
                Row {
                    width: parent.width
                    spacing: parent.width * 0.02
                    
                    Text { 
                        text: "FiO₂ (%)"
                        color: "#aaa"
                        font.pixelSize: Math.max(10, bottomBar.height * 0.22)
                        verticalAlignment: Text.AlignVCenter
                        width: parent.width * 0.45
                    }
                    Slider { 
                        from: 21; to: 100; value: 40
                        width: parent.width * 0.50
                        height: bottomBar.height * 0.25
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
                
                Row {
                    width: parent.width
                    spacing: parent.width * 0.02
                    
                    Text { 
                        text: "Pressure (cmH₂O)"
                        color: "#aaa"
                        font.pixelSize: Math.max(10, bottomBar.height * 0.22)
                        verticalAlignment: Text.AlignVCenter
                        width: parent.width * 0.45
                    }
                    Slider { 
                        from: 10; to: 30; value: 15
                        width: parent.width * 0.50
                        height: bottomBar.height * 0.25
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
            }
            
            
            Text { 
                id: gasMixText
                anchors.left: controlsColumn.right
                anchors.leftMargin: parent.width * 0.02
                anchors.verticalCenter: parent.verticalCenter
                width: parent.width * 0.30
                text: "Air 21% / O₂ 100% → Mix 40%"
                color: "#ccc"
                font.pixelSize: Math.max(11, bottomBar.height * 0.24)
                wrapMode: Text.WordWrap
                horizontalAlignment: Text.AlignLeft
            }
            
            
            Rectangle {
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                width: parent.width * 0.20
                height: bottomBar.height * 0.65
                color: "transparent"
                border.color: "#ff3333"
                border.width: Math.max(1, bottomBar.height * 0.005)
                radius: 4
                
                Text {
                    anchors.centerIn: parent
                    text: "Alarm Silence"
                    color: "#ff3333"
                    font.pixelSize: Math.max(12, bottomBar.height * 0.30)
                    font.bold: true
                }
            }
        }
    }

    
    Row {
        anchors.top: topBar.bottom
        anchors.bottom: bottomBar.top
        anchors.left: parent.left
        anchors.right: parent.right

        
        Item {
            width: parent.width * 0.07
            height: parent.height
            
            Column {
                anchors.fill: parent
                Repeater {
                    model: [
                        { name: "ECG", color: "#00FF00", unit: "" },
                        { name: "Paw", color: "#00bfff", unit: "cmH₂O" },
                        { name: "Flow", color: "#ffd700", unit: "L/min" },
                        { name: "EtCO₂", color: "#ffd700", unit: "mmHg" }
                    ]
                    Item {
                        width: parent.width
                        height: parent.height / 4
                        Column {
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left: parent.left
                            anchors.leftMargin: parent.width * 0.15
                            
                            
                            Text { 
                                text: modelData.name; 
                                color: modelData.color; 
                                font.pixelSize: Math.max(14, parent.parent.height * 0.16); 
                                font.bold: true 
                            }
                            
                            
                            Text { 
                                text: modelData.unit; 
                                color: modelData.color; 
                                font.pixelSize: Math.max(10, parent.parent.height * 0.09); 
                                opacity: 0.8; 
                                visible: modelData.unit !== "" 
                            }
                        }
                    }
                }
            }
        }
        
        
        Item {
            width: parent.width * 0.68  
            height: parent.height
            
            Image {
                id: waveImage
                anchors.fill: parent
                source: "image://waveform/current"
                cache: false
                asynchronous: false
                fillMode: Image.Stretch
                
                Connections {
                    target: waveformModel
                    function onImageReady() { 
                        waveImage.source = "" 
                        waveImage.source = "image://waveform/current" 
                    }
                }
            }
        }
        
        
        Item {
            width: parent.width * 0.25
            height: parent.height
            
            Rectangle {
                anchors.fill: parent
                anchors.margins: parent.width * 0.01
                color: "#111111"
                border.color: "#333333"
                border.width: Math.max(1, parent.height * 0.002)
                radius: 6
                
                Column {
                    anchors.fill: parent
                    anchors.margins: parent.width * 0.02
                    spacing: parent.height * 0.02
                    
                    
                    Row {
                        spacing: parent.width * 0.01
                        Text { 
                            text: Math.round(waveformModel.spo2).toString(); 
                            color: "#00bfff"; 
                            font.pixelSize: Math.max(24, parent.parent.height * 0.18); 
                            font.bold: true; 
                            verticalAlignment: Text.AlignBottom 
                        }
                        Text { 
                            text: "%"; 
                            color: "#00bfff"; 
                            font.pixelSize: Math.max(14, parent.parent.height * 0.08); 
                            font.bold: true; 
                            anchors.bottom: parent.bottom; 
                            anchors.bottomMargin: parent.height * 0.02 
                        }
                    }
                    
                    
                    Row {
                        spacing: parent.width * 0.01
                        Text { 
                            text: Math.round(waveformModel.respiratoryRate).toString(); 
                            color: "#ffd700"; 
                            font.pixelSize: Math.max(20, parent.parent.height * 0.14); 
                            font.bold: true; 
                            verticalAlignment: Text.AlignBottom 
                        }
                        Text { 
                            text: "rpm"; 
                            color: "#ffd700"; 
                            font.pixelSize: Math.max(12, parent.parent.height * 0.07); 
                            font.bold: true; 
                            anchors.bottom: parent.bottom; 
                            anchors.bottomMargin: parent.height * 0.015 
                        }
                    }
                    
                    
                    Row {
                        spacing: parent.width * 0.01
                        Text { 
                            text: Math.round(waveformModel.tidalVolume).toString(); 
                            color: "#ffffff"; 
                            font.pixelSize: Math.max(20, parent.parent.height * 0.14); 
                            font.bold: true; 
                            verticalAlignment: Text.AlignBottom 
                        }
                        Text { 
                            text: "mL"; 
                            color: "#ffffff"; 
                            font.pixelSize: Math.max(12, parent.parent.height * 0.07); 
                            font.bold: true; 
                            anchors.bottom: parent.bottom; 
                            anchors.bottomMargin: parent.height * 0.015 
                        }
                    }
                    
                    Item { height: parent.height * 0.02; width: 1 }
                    
                    
                    Row {
                        spacing: parent.width * 0.015
                        Text { 
                            text: "PEEP"; 
                            color: "#ffd700"; 
                            font.pixelSize: Math.max(12, parent.parent.height * 0.06); 
                            font.bold: true; 
                            anchors.bottom: parent.bottom; 
                            anchors.bottomMargin: parent.height * 0.005 
                        }
                        Text { 
                            text: Math.round(waveformModel.peepValue).toString(); 
                            color: "#ffd700"; 
                            font.pixelSize: Math.max(16, parent.parent.height * 0.09); 
                            font.bold: true 
                        }
                        Text { 
                            text: "cmH₂O"; 
                            color: "#ffd700"; 
                            font.pixelSize: Math.max(10, parent.parent.height * 0.05); 
                            font.bold: true; 
                            anchors.bottom: parent.bottom; 
                            anchors.bottomMargin: parent.height * 0.01 
                        }
                    }
                    
                    
                    Row {
                        spacing: parent.width * 0.02
                        Text { 
                            text: "FiO₂"; 
                            color: "#ffffff"; 
                            font.pixelSize: Math.max(12, parent.parent.height * 0.06); 
                            font.bold: true; 
                            anchors.bottom: parent.bottom; 
                            anchors.bottomMargin: parent.height * 0.005 
                        }
                        Text { 
                            text: Math.round(waveformModel.fio2Value) + "%"; 
                            color: "#ffffff"; 
                            font.pixelSize: Math.max(16, parent.parent.height * 0.09); 
                            font.bold: true 
                        }
                    }
                }
            }
        }
    }
}